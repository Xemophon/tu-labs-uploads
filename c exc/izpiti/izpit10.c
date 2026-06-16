#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    int id;
    char date[11];
    char name[31];
    char issue[51];
}Repair;

int count_repairs(Repair*arr, int size, char*name, char*issue){
    int count = 0;
    for(int i=0;i<size;i++){
        if(strcmp(name, arr[i].name)==0 && strcmp(issue, arr[i].issue)==0){
            count++;
        }
    }
    return count;
}

Repair*add_new_repair(Repair*arr, int*size){
    Repair entry;
    scanf("%30[^\n]",entry.name);
    int day, month, year;
    scanf(" %2d.%2d.%4d", &day, &month, &year);
    sprintf(entry.date, "%02d.%02d.%04d", day, month, year);
    scanf(" %50[^\n]",entry.name);
    scanf("%d",&entry.id);
    ++(*size);
    Repair*temparr = (Repair*)realloc(arr, (*size)*sizeof(Repair));
    if(temparr == NULL) return NULL;
    return arr;
}

int write_text_file(Repair*arr, int size, char*issue){
    FILE*txt = fopen("service.txt", "a");
    if(txt == NULL) return -1;
    int count = 0;
    for(int i=0;i<size;i++){
        if(strcmp(arr[i].issue, issue)==0){
            ++count;
            fprintf(txt,"%s\n%s\n%s\n\n", arr[i].name, arr[i].issue, arr[i].date);
        }
    }
    return count;
}

int main() {
    FILE*bin=fopen("repairs.bin", "rb");
    if(bin == NULL) return 1;
    fseek(bin,0,SEEK_END);
    int n = ftell(bin)/sizeof(Repair);
    rewind(bin);
    Repair*list=malloc(n*sizeof(Repair));
    if(list==NULL){
        fclose(bin)
        return 1;
    }
    for(int i=0;i<n;i++){
        fread(&list[i], sizeof(Repair),1,bin);
    }
    fclose(bin);
    free(list);
    return 0;
}