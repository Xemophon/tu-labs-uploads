#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct{
    long long id;
    char name[129];
    char date[11];
    float price;
    int enroll;
    char type[21];
}Course;

typedef struct{
    char name[81];
    long long s_id;
    int courses;
    long long c_id[8]; 
}Student;

void remove_course(Course**arr, int*size, char*type, char*date){
    int day,month,year;
    sscanf(date,"%2d.%2d.%4d",&month,&day,&year);
    for(int i=0;i<*size;i++){
        int ind = -1;
        int aday,amonth,ayear;
        sscanf((*arr)[i].date,"%2d.%2d.%4d",&amonth,&aday,&ayear);
        if((ayear > year) || (ayear == year && amonth > month) || (ayear == year && amonth == month && aday > day)){
            if(strcmp(type, (*arr)[i].type)==0 && (*arr)[i].enroll < 8){
                ind = i;
                --(*size);
                --i;
                for(int j=ind; j<*size; j++){
                    (*arr)[j] = (*arr)[j+1];
                }
            }
        }
    }
    Course*temp = (Course*)realloc(*arr, (*size)*sizeof(Course));
    if(temp==NULL) return;
    *arr = temp;
}

int write_to_txt(Course*arr1,int size_c, Student*arr2, int size_s, long long s_id, long long id){
    FILE*txt=fopen("students_info.txt","w");
    if(txt == NULL) return -1;
    for(int i=0;i<size_c;i++){
        for(int j=0;j<size_s;j++){
            int unavailable = 0;
            if(arr1[i].id==id && arr2[j].s_id == s_id){
                for(int k = 0; k < 7; k++) {
                    if(arr2[j].c_id[k] == id || arr1[i].enroll >= 50) {
                        unavailable = 1;
                        break;
                    }
                }
                }
                if(unavailable == 0){
                    fprintf(txt,"%lld;%lld;%s;%.2f", arr1[i].id, arr2[j].s_id, arr1[i].date,arr1[i].price);
                    break;
                }
            }
        }
    if(ftell(txt)==0){
        return 0;
    }
    fclose(txt);
    return 1;
}

Course*find_occ(Course*arr,int size_c){
    int size = 0;
    float sum = 0, avg;
    for(int i=0;i<size_c;i++){
        sum += arr[i].price;
    }
    avg = sum/size_c;
    for(int i=0;i<size_c;i++){
        if(arr[i].price<avg && arr[i].enroll<50){
            ++size;
        }
    }
    Course*temp=(Course*)malloc(size*sizeof(Course));
    int j = -1;
    for(int i=0;i<size_c;i++){
        if(arr[i].price<avg && arr[i].enroll<50){
            temp[++j] = arr[i];
        }
    }
    if(size==0 || temp==NULL){
        free(temp);
        return NULL;
    }
    return temp;
}

int main() {
    FILE*bin1 = fopen("courses.bin","rb");
    FILE*bin2 = fopen("students.bin","rb");
    fseek(bin1,0,SEEK_END);fseek(bin2,0,SEEK_END);
    long size1=ftell(bin1)/sizeof(Course);long size2=ftell(bin2)/sizeof(Student);
    rewind(bin1);rewind(bin2);
    Student*list1=(Student*)malloc(size2*sizeof(Student));
    Course*list2=(Course*)malloc(size1*sizeof(Course));
    for(int i=0;i<size1;i++){
        fread(&list1[i],sizeof(Student),1,bin2);
    }
    for(int i=0;i<size1;i++){
        fread(&list2[i],sizeof(Course),1,bin1);
    }
    fclose(bin1);fclose(bin2);
    free(list1);free(list2);
    return 0;
}