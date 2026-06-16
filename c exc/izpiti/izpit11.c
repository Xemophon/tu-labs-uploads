#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char name[56];
    char id[7];
    float price;
    int pin;
}Stream;

void add_entry(Stream*arr){
    int size = sizeof(arr)/sizeof(Stream);
    Stream entry;
    scanf("%50[^\n]",entry.name);
    char letters[2];
    int nums;
    scanf(" %c%c%4d",&letters[0],&letters[1],&nums);
    sprintf(entry.id,"%c%c%04d",letters[0],letters[1],nums);
    scanf("%f %4d", &entry.price, &entry.pin);
    ++size;
    Stream*temparr=(Stream*)realloc(arr,size*sizeof(Stream));
    if(temparr==NULL) return;
    arr = temparr;
    arr[size-1] = entry;
    FILE*txt=fopen("usersText.txt","a");
    if(txt==NULL) return;
    fprintf(txt,"%d;%s;%s;%.2f;%d",sizeof(entry.name), entry.name, entry.id, entry.price, entry.pin);
    fclose(txt);
}

void out_avg(Stream*arr){
    int size = sizeof(arr)/sizeof(Stream);
    float sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i].price;
    }
    float avg=sum/size;
    for(int i=0;i<size;i++){
        if(arr[i].price<avg){
            printf("%s - %s - %.2f",arr[i].name,arr[i].id,arr[i].price);
        }
    }
}

void search_bin(char*id){
    FILE*bin=fopen("users.bin","rb");
    if(bin==NULL) return;
    fseek(bin,0,SEEK_END);int size=ftell(bin);rewind(bin);
    while(ftell(bin)<size){
        Stream entry;
        int sname = 0;
        fread(&sname, sizeof(int),1,bin);
        fread(entry.name, sname, 1,bin);
        fread(entry.id,6,1,bin);
        fread(&entry.price,sizeof(float),1,bin);
        fread(&entry.pin,sizeof(int),1,bin);
        if(strcmp(entry.id,id)==0){
            printf("%s\n%s\n%.2f\n%d\n\n",entry.name,entry.id,entry.price,entry.pin);
            break;
        }
    }
}

int main() {
    printf("Start small. Ship something.");
    return 0;
}