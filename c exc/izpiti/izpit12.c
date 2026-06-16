#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    int id;
    char date[11];
    char name[31];
    char type[51];
}Reservation;

int count_reservations(Reservation*arr,int size, char*name, char*type){
    int count = 0;
    for(int i=0;i<size;i++){
        if(strcmp(name,arr[i].name)==0&&strcmp(type,arr[i].type)==0){
            count++;
        }
    }
    return count;
}

Reservation*add_new_reservation(Reservation*arr,int*size){
    Reservation entry;
    scanf("%d",&entry.id);
    int day,month,year;
    scanf("%2d.%2d.%4d",&day, &month, &year);
    sprintf(entry.date,"%02d.%02d.%04d",day,month,year);
    scanf(" %30[^\n]",entry.name);
    scanf(" %50[^\n]",entry.type);
    ++(*size);
    Reservation*temparr=(Reservation*)realloc(arr,(*size)*sizeof(Reservation));
    if(temparr == NULL) return NULL;
    arr = temparr;
    arr[(*size)-1] = entry;
    return arr;
}

int write_text_file(Reservation*arr,int size, char*type){
    int count = -1;
    FILE*txt=fopen("rooms.txt","a");
    if(txt==NULL){
        return count;
    } else{
        count++;
    }
    for(int i=0;i<size;i++){
        if(strcmp(type, arr[i].type)==0){
            fprintf(txt,"%s\n%s\n%s\n\n",arr[i].name,arr[i].type,arr[i].date);
            count++;
        }
    }
    fclose(txt);
    return count;
}

int main() {
    FILE*bin=fopen("history.bin","rb");
    if(bin==NULL) return 1;
    fseek(bin,0,SEEK_END);
    int size = ftell(bin)/sizeof(Reservation);
    rewind(bin);
    Reservation*history=(Reservation*)malloc(size*sizeof(Reservation));
    if(history==NULL){
        fclose(bin);
        return 1;
    }
    for(int i=0;i<size;i++){
        fread(&history[i],sizeof(Reservation),1,bin);
    }
    fclose(bin);
    free(history);
    return 0;
}