#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char ref[51];
    char date[11];
    int size;
    float price;
}Property;

void discount(Property*arr, int size, int ind){
    if(ind<0 || ind>=size) return;
    arr[ind].price *= 0.9;
    printf("%.2f - %s - %s",arr[ind].price, arr[ind].ref, arr[ind].date);
}

int inscribe(Property*arr, int size, int min, int max){
    FILE*txt=fopen("catalog.txt","a");
    int counter = -1;
    if(txt==NULL) return counter;
    counter=0;
    for(int i=0;i<size;i++){
        if(arr[i]>=min && arr[i]<=max){
            fprintf(txt,"%s\n%s\n%d\n%.2f\n\n",arr[i].ref,arr[i].date,arr[i].size,arr[i].price);
            counter++;
        }
    }
    fclose(txt);
    return counter;
}

Property*delete_occ(Property*arr, int *size, char*ref,char*date){
    int ind;
    for(int i=0;i<*size;i++){
        if(strcmp(ref, arr[i].ref)==0&&strcmp(obj.date, date)==0){
            ind = i;
            --(*size);
            break;
        }
    }
    for(int i=0;i<*size;i++){
        arr[i] = arr[i+1];
    }
    Property*temparr=(Property*)realloc(arr, (*size)*sizeof(Property));
    if(temparr==NULL) return NULL;
    arr = temparr;
    return arr;
}

int main() {
    FILE*bin=fopen("properties.bin","rb");
    if(bin==NULL) return 1;
    fseek(bin,0,SEEK_END);
    int n = ftell(bin)/sizeof(Property);
    rewind(bin);
    Property*properties=(Property*)malloc(sizeof(Property)*n);
    for(int i=0;i<n;i++){
        int duplicate = 0;
        Property obj;
        if(fread(&obj, sizeof(Property),1,bin)!=1) return 1;
        for(int j=0;j<i;j++){
            if(strcmp(obj.ref, properties[j].ref)==0&&strcmp(obj.date, properties[j].date)==0){
                --n;
                --i;
                duplicate=1;
                break;
            }
        }
        if(duplicate==0){
            arr[i] = obj;
        }
    }
    fclose(bin);
    free(properties);
    return 0;
}