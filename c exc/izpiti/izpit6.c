#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char reg[21];
    char date[11];
    int rent;
    float price;
}Rental;

void new_day(Rental*arr, int size, int ind){
    if(ind<0 || ind>=size) return;
    arr[ind].price *= 1.1;
    printf("%.2f lv. - %s - %s", arr[ind].price, arr[ind].reg, arr[ind].date);
}

int premium(Rental*arr, int size, float max, float min){
    int found = 0;
    FILE*bin = fopen("premium_rentals.bin","ab");
    if(bin == NULL) return -1;
    for(int i=0;i<size;i++){
        if(arr[i].price>=min && arr[i].price<=max){
            if(fwrite(&arr[i], sizeof(Rental),1,bin)!=1){
                fclose(bin);
                return -1;
            }
            found++;
        }
    }
    fclose(bin);
    return found;
}

Rental*cancel_r(Rental*arr, int*size, char*reg, char*date){
    int ind = -1;
    for(int i=0;i<*size;i++){
        if(strcmp(reg,arr[i].reg)==0 && strcmp(date,arr[i].date)==0){
            ind = i;
            --(*size);
            break;
        }
    }
    if(ind<0) return arr;
    for(int i=ind;i<*size;i++){
        arr[i] = arr[i+1];
    }
    Rental*temparr = (Rental*)realloc(arr,(*size)*sizeof(Rental));
    if(temparr==NULL) return NULL;
    arr = temparr;
    return arr;
}

int main() {
    FILE*fp = fopen("rentals.txt","r");
    if (fp == NULL) return 1;
    int n = 0;
    fscanf(fp,"%d",&n);
    Rental*rents=(Rental*)malloc(n*sizeof(Rental));
    if(rents==NULL) return 1;
    for(int i=0;i<n;i++){
        Rental rent;
        fscanf(fp,"%s %s %d %f", rent.reg,rent.date,&rent.rent,&rent.price);
        int is_duplicate = 0;
        for(int j=0; j<i;j++){
            if(strcmp(rent.reg,rents[j].reg)==0 && strcmp(rent.date,rents[j].date)==0){
                --n;
                --i;
                is_duplicate = 1;
                break;
            }
        }
        if (is_duplicate == 0) {
            rents[i] = rent;
        }
    }
    Rental*temprents = (Rental*)realloc(rents, n*sizeof(Rental));
    if(temprents == NULL) return 1;
    rents = temprents;
    free(rents);
    fclose(fp);
    return 0;
}