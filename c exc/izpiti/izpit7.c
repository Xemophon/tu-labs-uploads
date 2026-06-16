// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[31];
    int id;
    char date[11];
    float price;
}Product;

Product*add_new(Product newp,Product*arr, int*n, FILE*fp){
    if(fwrite(&newp, sizeof(Product),1,fp)!=1) return arr;
    ++(*n);
    Product*temparr = (Product*)realloc(arr, (*n)*sizeof(Product));
    if(temparr == NULL) return arr;
    arr = temparr;
    arr[(*n)-1] = newp;
    return arr;
}

Product*enlist(Product*arr, int*n,float price){
    int size=0;
    for(int i=0;i<*n;i++){
        if(arr[i].price>price) ++size;
    }
    Product*arr2 = malloc(size*sizeof(Product));
    if(arr2==NULL) return NULL;
    int pos=0;
    for(int i=0; i<*n;i++){
        if(arr[i].price>price){
            arr2[pos] = arr[i];
            ++pos;
        }
    }
    return arr2;
}

void file_handle(FILE*bin, int count){
    fseek(bin,0,SEEK_SET);
    FILE*txt = fopen("outTXT.txt", "a+");
    if(txt==NULL) return;
    for(int i=0; i<count;i++){
        Product prod;
        if(fread(&prod, sizeof(Product), 1, bin)!=1) return;
        if(fprintf(txt,"%s\n%d\n%s\n%.2f\n",prod.name,prod.id,prod.date,prod.price)!=4) return;
    }
    fseek(txt,0,SEEK_SET);
    fseek(bin,0,SEEK_SET);
    for(int i=0; i<count;i++){
        Product prodb;
        Product prodt;
        if(fread(&prodb, sizeof(Product), 1, bin)!=1) return;
        if(fscanf(txt,"%s\n%d\n%s\n%f\n",prodt.name,&prodt.id,prodt.date,&prodt.price)!=4) return;
        printf("Binary Item: %s\n%d\n%s\n%.2f\n",prodb.name,prodb.id,prodb.date,prodb.price);
        printf("Text Item: %s\n%d\n%s\n%.2f\n", prodt.name,prodt.id,prodt.date,prodt.price);
    }
    fclose(txt);
}

int main() {
    int n=1;
    FILE*fp=fopen("in.bin","ab+");
    if(fp==NULL) return 1;
    Product*list=(Product*)malloc(n*sizeof(Product));
    if(list==NULL) return 1;
    Product*expensive;
    expensive = enlist(list,&n, 7.5);
    free(expensive);
    free(list);
    fclose(fp);
    return 0;
}