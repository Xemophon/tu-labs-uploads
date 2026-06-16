#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char name[51];
    char date[11];
    int count;
    float price;
}Event;

void discount(Event*arr, int size, int ind){
    if(ind < 0 || ind >= size){
        printf("Index out of bounds");
        return;
    }
    arr[ind].price *= 0.8;
    printf("%.2f lv. - %s - %s",arr[ind].price,arr[ind].name,arr[ind].date);
}

int availability(Event*arr, int size, int max, int min){
    FILE*fpt=fopen("availability.txt","a");
    if(fpt==NULL) return -1;
    int found = 0;
    for(int i=0; i<size; i++){
        if(arr[i].count >= min && arr[i].count<=max){
            found++;
            fprintf(fpt,"%s\n%s\n%d bileta\n%.2f lv.\n\n", arr[i].name,arr[i].date,arr[i].count,arr[i].price);
        }
    }
    fclose(fpt);
    return found;
}

Event*cancel(Event*arr, int*size, char*name, char*date){
    int ind = -1;
    for(int i=0; i<*size; i++){
        if(strcmp(name, arr[i].name)==0 && strcmp(date, arr[i].date)==0){
            ind = i;
            break;
        }
    }
    if(ind==-1) return NULL;
    --(*size);
    for(int i=ind; i<*size; i++){
        arr[i] = arr[i+1];
    }
    Event*temparr=(Event*)realloc(arr,(*size)*sizeof(Event));
    if(temparr==NULL) return NULL;
    arr = temparr;
    return arr;
}

int main() {
    FILE*fp=fopen("events.bin","rb");
    if(fp==NULL) return 1;
    int n = 1;
    if(fread(&n, sizeof(int),1,fp)!=1) return 1;
    Event*events = (Event*)malloc(n*sizeof(Event));
    if(events==NULL) return 1;
    for(int i=0;i<n;i++){
        Event new_ev;
        if(fread(&new_ev, sizeof(Event),1,fp)!=1){
            return 1;
        } else{
            int found = 0;
            for(int j=0; j<i; j++){
                if(strcmp(new_ev.date, events[j].date)==0&&strcmp(new_ev.name, events[j].name)==0){
                    --n;
                    --i;
                    found++;
                    break;
                }
            }
            if(found==0){
                events[i] = new_ev;
            }
        }
    }
    Event*temparr = (Event*)realloc(events,n*sizeof(Event));
    if(temparr==NULL) return 1;
    events=temparr;
    fclose(fp);
    free(events);
    return 0;
}