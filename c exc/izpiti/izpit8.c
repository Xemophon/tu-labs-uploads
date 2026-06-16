#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char name[56];
    char id[7];
    float price;
    int lock;
}Member;

Member*add_member(Member*arr, FILE*fp){
    Member newM;
    int new_size = sizeof(arr)/sizeof(Member)+1;
    int name_len=0;
    scanf("%[^\n]s",newM.name);
    name_len = sizeof(newM.name);
    scanf("%6s", newM.id);
    scanf("%d %f",&newM.lock, &newM.price);
    Member*temparr=(Member*)realloc(arr,new_size*sizeof(Member));
    if(temparr == NULL) return arr;
    if(fprintf(fp,"%d;%s;%s;%.2f;%d", name_len, newM.name, newM.id,newM.price,newM.lock)!=5) return arr;
    arr = temparr;
    return arr;
}

void find_id(char*id){
    FILE*bin = fopen("members,bin", "rb");
    if(bin==NULL) return;
    fseek(bin,0,SEEK_END);
    int size = ftell(bin);
    rewind(bin);
    while(ftell(bin)<size){
        int name_size;
        Member reat;
        fread(&name_size, sizeof(int), 1, bin);
        fread(reat.name, name_size, 1, bin);
        fread(reat.id,6,1,bin);
        fread(&reat.price, sizeof(float), 1, bin);
        fread(&reat.locker, sizeof(int), 1, bin);
        if(strcmp(reat.id, id)==0){
            printf("Bin Names:%s\nBin Id:%s\nBin M_Price:%.2f\nBin Locker:%d",reat.name, reat.id, reat.price, reat.locker);
            break;
        }
    }
    fclose(bin);
}

void below_average(Member*arr){
    if(arr==NULL) return;
    int size = sizeof(arr)/sizeof(Member);
    float sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i].price;
    }
    float avg = sum/size;
    for(int i=0;i<size;i++){
        if(arr[i].price<avg){
            printf("%s - %s - %.2f",arr[i].name, arr[i].id, arr[i].price);
        }
    }
}

int main() {
    FILE*txt = fopen("membersTXT.txt","r");
    if(txt==NULL) return 1;
    Member*list = (Member*)malloc(sizeof(Member));
    fclose(txt);
    free(list);
    return 0;
}