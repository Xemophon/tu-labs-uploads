#include <stdio.h>
#include <stdlib.h>

int find_max(int *arr, int *size){
    int max = arr[0];
    for(int i=0;i<*size;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}

int find_min(int *arr, int *size){
    int min = arr[0];
    for(int i=0;i<*size;i++){
        if(min>arr[i]){
            min=arr[i];
        }
    }
    return min;
}

int find_avg(int *arr, int *size){
    int sum = 0;
    for(int i=0; i<*size;i++){
        sum+=arr[i];
    }
    return sum / *size;
}

void move_backwards(int *arr, int size, int index){
    for(int i=index; i<size; i++){
        arr[i]=arr[i+1];
    }
}

void move_forward(int *arr, int size, int index){
    for(int i=size-1; i>index; i--){
        arr[i+1]=arr[i];
    }
}

int main(){
//zad1
    int size=1;
    scanf("%d", &size);
    int *arr1=(int*)malloc(size*sizeof(int));
    for(int i=0; i<size; i++){
        scanf("%d", &arr1[i]);
    }
    int avg = find_avg(arr1, &size);
    for(int i=0; i<size; i++){
        if(arr1[i]<avg){
            move_backwards(arr1, size, i);
            int *arr1 = (int*)realloc(arr1, (--size)*sizeof(int));
            i--;
        }
    }
    for(int i=0; i<size; i++){
        for(int j=0; j<size-1;j++){
            if(arr1[j]>arr1[j+1]){
                int temp = arr1[j];
                arr1[j] = arr1[j+1];
                arr1[j+1] = temp;
            }
        }
    }
    free(arr1);
//zad2 
    int n,k,num,ind;
    scanf("%d");
    int *arr2 =(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;){
        scanf("%d", &arr2[i]);
    }
    scanf("%d", &k);
    for(int i=0; i<=k; i++){
        scanf("%d%d",&num,&ind);
        int* arr2=(int*)realloc(arr2, (n++)*sizeof(int));
        move_forward(arr2, n, ind);
        arr2[ind] = num;
    }
    free(arr2)
//zad3
    int counter = 0;
    int* arr3 =(int*)malloc(12*sizeof(int));
    for(int i=0; i<12; i++){
        for(int j=0; j<12;j++ ){
            if(arr3[i]==arr[j]){
                move_backwards(arr3, 12, j);
                int *arr3 = (int*)realloc(arr3,(12-(--counter))*sizeof(int));
            }
        }
    }
    free(arr3);
//zad4
    int n,m;
    scanf("%d%d", &n, &m);
    int* arr4 = (int*)malloc((n*m)*sizeof(int));
    for(int i = 0; i<n*m; i++){
        scanf("%d", &arr[i]);
    }
    int clim_sum=0, clim_ind = 0;
    int sum = clim_sum;
    for(int i=0; i<n; i++){
        sum = 0;
        for(int j=0; j<m; j++){
            sum += arr4[i*m+j];
        }
        if(sum>clim_sum){
                clim_ind=i;
                clim_sum = sum;
            }
    }
    printf("%d on row %d",clim_sum,clim_ind);
    for(int i=0; i<m; i++){
        sum = 0;
        for(int j=0; j<n; j++){
            sum += arr4[j*m+i];
        }
        if(sum<clim_sum){
                clim_ind=i;
                clim_sum=sum;
            }
    }
    printf("%d on row %d",clim_sum,clim_ind);
    free(arr4)
//zad5
    int n,m, temp =0;
    scanf("%d%d", &n, &m);
    int* arr5 = (int*)malloc((n*m)*sizeof(int));
    for(int i = 0; i<n*m; i++){
        scanf("%d", &arr5[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<m-1; k++){
                if(arr5[i*m+k]>arr5[i*m+k+1]){
                    int temp=arr5[i*m+k];
                    arr5[i*m+k] = arr5[i*m+k+1];
                    arr5[i*m+k+1] = temp;
                }
            }
        }
    }
    int* arr6=(int*)malloc(n*sizeof(int));
    for(int i=0; i<n;i++){
        arr6[i] = arr5[i*m+(m-1)];
    }
//zad6
    return 0;
}