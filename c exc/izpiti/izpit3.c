#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[51];
    char date[11];
    int tickets;
    float price;
}Event;

void last_minute(Event *list,int size,int index){
    if(index > size-1){
        return;
    }
    list[index].price *= 0.85;
    printf("%.2fлв. - %s - %s",list[index].price,list[index].name,list[index].date);
}

int budget_events(Event list[], int size,float min,float max){
    FILE*fptr = fopen("budget_events.txt","a");
    int count = 0;
    if(fptr == NULL){
        return 0;
    }
    for(int i=0;i<size;i++){
        if(list[i].price>min && list[i].price<max){
            count++;
            fprintf(fptr,"%s\n%s\n%d билета\n%.2f лв.\n", list[i].name,list[i].date,list[i].tickets,list[i].price);
        }
    }
    fclose(fptr);
    return count;
}

Event* delete_event(Event*list, int*size,char name[],char date[]){
    int found = 0;
    for(int i = 0; i<*size; i++){
        if(strcmp(list[i].name,name)==0 && strcmp(list[i].date,date)==0){
            for(int j=i;j<*size-1;j++){
                list[j]=list[j+1];
            }
            found++;
            (*size)--;
        }
        if(found!=0){
            break;
        }
    }
    if(found ==0){
        return NULL;
    }
    Event*templist=(Event*)realloc(list,*size*sizeof(Event));
    if(templist==NULL){
        return list;
    }
    return templist;
}

int main(){
    FILE *fptr = fopen("events.bin", "rb"); 
    if (fptr == NULL) {                     
        printf("Грешка при отваряне на бинарния файл!\n");
        return 1;
    }
    int n = 0;
    if (fread(&n, sizeof(int), 1, fptr) != 1) {
        fclose(fptr);
        return 1;
    }
    Event* list = (Event*)malloc(n * sizeof(Event));
    if (list == NULL) {
        fclose(fptr);
        return 1;
    }
    fread(list, sizeof(Event), n, fptr);
    fclose(fptr);
    free(list);
    return 0;
}