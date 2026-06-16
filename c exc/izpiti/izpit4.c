// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tell_size(FILE*fptr, int data_size){
    fseek(fptr,0,SEEK_END);
    int size = ftell(fptr)/data_size;
    fseek(fptr,0,SEEK_SET);
    return size;
}

typedef struct{
    char name[30];
    char date[8];
    long long id;
    float price;
    int quantity;
}Medicine;

int month_conv(char*date){
    int d_month = (date[0]-'0')*10+date[1]-'0';
    return d_month;
}

int year_conv(char*date){
    int d_year = (date[3]-'0')*1000+(date[4]-'0')*100+(date[5]-'0')*10 + (date[6]-'0');
    return d_year;
}

void date_check(Medicine*arr, int size, char*date){
    int found=0;
    int l_month = month_conv(date);
    int l_year = year_conv(date);
    for(int i=0;i<size;i++){
        int month = month_conv(arr[i].date);
        int year = year_conv(arr[i].date);
        if(year>l_year || (month>l_month && year==l_year)){
            found++;
            printf("%lld\n", arr[i].id);
        }
    }
    if(found==0){
        printf("NULL");
    }
}

int offers(Medicine*arr, int size, float min, float max){
    FILE*fp=fopen("offer.txt","a");
    if(fp==NULL) return -1;
    int found = 0;
    for(int i=0;i<size;i++){
        if(arr[i].price>min && arr[i].price<max){
            found+=1;
            fprintf(fp,"%s\n%s\n%lld\n%.2fleva\n",arr[i].name,arr[i].date,arr[i].id,arr[i].price);
        }
    }
    fclose(fp);
    return found;
}

Medicine*delete_med(Medicine*arr, int*size, char*name, char*date){
    int found =0, ind = 0;
    for(int i=0; i<*size;i++){
        if(strcmp(arr[i].name, name)==0&&strcmp(date, arr[i].date)==0){
            ind = i;
            found++;
            break;
        }
    }
    if(found==0) return arr;
    for(int i=ind; i<*size-1; i++){
        arr[i] = arr[i+1];
    }
    (*size)--;
    Medicine*temparr=(Medicine*)realloc(arr,(*size)*sizeof(Medicine));
    if(temparr==NULL) return arr;
    arr = temparr;
    return arr;
}

int main(){
    FILE*fptr = fopen("medicines.bin", "rb");
    if(fptr==NULL) return 1;
    int size = 1;
    size = tell_size(fptr, sizeof(Medicine));
    Medicine*medicines=(Medicine*)malloc(size*sizeof(Medicine));
    if(medicines==NULL) return 1;
    for(int i=0; i<size; i++){
        Medicine med;
        if(fread(&med, sizeof(Medicine),1,fptr)!=1) return 1;
        medicines[i]=med;
    }
    fclose(fptr);
    free(medicines);
    return 0;
}