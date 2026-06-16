#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[41];
    char id[6];
    float price;
    int cal;
}Meal;

void add_meal(Meal**arr, int*size){
    Meal ent;
    scanf(" %40[^\n]",ent.name);
    int ssize = strlen(ent.name);
    char lA,lB;int num;
    scanf(" %c%c%3d", &lA,&lB,&num);
    sprintf(ent.id,"%c%c%03d",lA,lB,num);
    scanf("%f %d",&ent.price, &ent.cal);
    Meal*temp=(Meal*)realloc((*arr),((*size)+1)*sizeof(Meal));
    if(temp==NULL) return;
    ++(*size);
    *arr = temp;
    (*arr)[*size-1] = ent;
    FILE*txt = fopen("menuText.txt","a");
    if(txt==NULL) return;
    fprintf(txt,"%d;%s;%s;%.2f;%d",ssize, ent.name,ent.id,ent.price,ent.cal);
    fclose(txt);
}

void avg_cal(Meal*arr, int size){
    float sum = 0;
    for(int i=0;i<size;i++){
        sum+=arr[i].cal;
    }
    float avg = sum/size;
    for(int i=0;i<size;i++){
        if(arr[i].cal>=avg){
            printf("%s - %s - %d\n",arr[i].name,arr[i].id,arr[i].cal);
        }
    }
}

void search_meal_bin(char*id){
    FILE*bin = fopen("menu.bin","rb");
    if(bin==NULL) return;
    fseek(bin,0,SEEK_END);
    int size = ftell(bin);rewind(bin);
    while(ftell(bin)<size){
        Menu ent;int ssize;
        fread(&ssize,sizeof(int),1,bin);
        fread(ent.name, ssize, 1, bin);
        ent.name[ssize] = '\0';
        fread(ent.id,5,1,bin);
        ent.id[5] = '\0';
        fread(&ent.price, sizeof(float),1,bin);
        fread(&ent.cal,sizeof(int),1,bin);
        if(strcmp(ent.id, id)==0){
            printf("Bin Food: %s\nBin Code: %s\nBin Price: %.2f\nBin Calories: %d\n\n",ent.name,ent.id,ent.price,ent.cal);
            break;
        }
    }
    fclose(bin);
}

typedef struct{
    char name[31];
    char date[8];
    long long vin;
    float price;
    int kms;
}Vehicle;

Vehicle*after_date(Vehicle*arr, int size, char*date){
    int month,year,count=0,j=0;
    sscanf(date,"%2d.%4d",&month,&year);
    Vehicle*arr2 = (Vehicle*)malloc(size*sizeof(Vehicle));
    if(arr2 == NULL) return NULL;
    for(int i=0;i<size;i++){
        int vMon, vYear;
        sscanf(arr[i].date, "%2d.%4d", &vMon, &vYear);
        if(vYear>year || (vYear==year && vMon>month)){
            arr2[j]=arr[i];
            j++;
            count++;
        }
    }
    if(count==0){
        free(arr2);
        return NULL;
    } else{
        Vehicle*temp = (Vehicle*)realloc(arr2, count*sizeof(Vehicle));
        if(temp==NULL) return arr2;
        return temp;
    }
}

int write_kms(Vehicle*arr, int size,int min, int max){
    FILE*txt = fopen("selection.txt","a");
    if(txt==NULL) return -1;
    int count = 0;
    for(int i=0;i<size;i++){
        if(arr[i].kms>=min && arr[i].kms<=max){
            fprintf(txt,"%s\n%s\n%lld\n%d\n\n",arr[i].name,arr[i].date,arr[i].vin,arr[i].kms);
            count++;
        }
    }
    fclose(txt);
    return count;
}

Vehicle*sell_vehicle(Vehicle**arr, int*size, char*name, char*date){
    int ind = -1;
    for(int i=0;i<*size;i++){
        if(strcmp(name, (*arr)[i].name)==0 && strcmp(date, (*arr)[i].date)==0){
            ind = i;
            for(int j=ind;j<(*size)-1;j++){
                (*arr)[j]=(*arr)[j+1];
            }
            break;
        }
    }
    if(ind==-1) return *arr;
    Vehicle*temp = (Vehicle*)realloc((*arr),((*size)-1)*sizeof(Vehicle));
    if(temp == NULL) return *arr;
    --(*size);*arr=temp;
    return *arr;
}

typedef struct{
    int id;
    char date[11];
    char name[31];
    char spec[51];
}Exam;

int count_attempts(Exam*arr,int size,char*name,char*spec){
    int count = 0;
    for(int i=0;i<size;i++){
        if(strcmp(name,arr[i].name)==0 && strcmp(spec,arr[i].spec)==0){
            count++;
        }
    }
    return count;
}

Exam*add_new_record(Exam*arr,int*size){
    Exam ent;
    scanf("%d",&ent.id);
    int day,month,year;
    scanf("%2d.%2d.%4d",&day,&month,&year);
    sprintf(ent.day,"%02d.%02d.%04d",day,month,year);
    scanf(" %30[^\n]",ent.name);
    scanf(" %50[^\n]",ent.spec);
    Exam*temp=(Exam*)realloc(arr,((*size)+1)*sizeof(Exam))
    if(temp == NULL) return NULL;
    ++(*size);
    temp[(*size)-1]=ent;
    return temp;
}

int write_text_file(Exam*arr,int size, char*spec){
    FILE*txt=fopen("subject_stats.txt","a");
    if(txt==NULL) return -1;
    int count = 0;
    for(int i=0;i<size;i++){
        if(strcmp(spec,arr[i].spec)==0){
            fprintf(txt,"%s - %s - %s\n",arr[i].name, arr[i].spec,arr[i].name);
            count++;
        }
    }
    fclose(txt);
    return count;
}

int main(){
    FILE*bin = fopen("cars.bin","rb");
    if(bin==NULL) return 1;
    fseek(bin,0,SEEK_END);
    int size = ftell(bin)/sizeof(Vehicle);rewind(bin);
    Vehicle*vehicles = (Vehicle*)malloc(size*sizeof(Vehicle));
    if(fread(vehicles, sizeof(Vehicle),size,bin)!=size){
        fclose(bin);free(vehicles);return 1;
    }
    fclose(bin);free(vehicles);
    FILE*bin = fopen("exams.bin","rb");
    if(bin==NULL) return 1;
    int n; fread(&n,sizeof(int),1,bin);
    Exam*record=(Exam*)malloc(n*sizeof(Exam));
    if(record==NULL){
        fclose(bin);
        return 1;
    }
    if(fread(record, sizeof(Exam),n,bin)!=n) return 1;
    fclose(bin);free(record);
    return 0;
}