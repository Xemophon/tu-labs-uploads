#include <stdlib.h>
#include <stdio.h>

int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int main()
{
// zad1
    int n,m;
    float sum = 0;
    scanf("%d%d", &n, &m);
    int *arr1 = (int*)malloc(n * sizeof(int));
    int *arr2 = (int*)malloc(m * sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d", &arr1[i]);
        sum += arr1[i];
    }
    for(int i=0; i<n; i++){
        scanf("%d", &arr1[i]);
        sum += arr2[i];
    }
    
    printf("%d\n", sum);
    printf("%d", sum/n+m)
    free(arr1);
    free(arr2);
// zad2
    int m2;
    int *arr3 = (int*)malloc(n * sizeof(int));
    int iskash_li = 0;
    printf("Ako nqma da dobavqsh napishi 0");
    scanf("%d", &iskash_li);
    if(iskash_li!=0){
        scanf("%d",&m2);
        int* ptrArr = NULL;
        ptrArr = (int*)realloc(arr3, (m2+n)*sizeof(int));
    }
    for(int i=0; i<n; i++){
        scanf("%d", &ptrArr[i]);
    }
    arr3 = ptrArr;
    free(arr3);
    free(ptrArr);
//zad3
    int n, target, found = -1;
    scanf("%d", &n);
    int *arr4 = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &target);
    for(int i=0; i<n; i++){
        if(target==arr4[i]){
            found=i;
            break;
        }
    }
    if(found!=-1){
        int* ptrArr = NULL;
        for(int i=found; i<n-1;i++){
            arr[i] = arr[i + 1];
        }
        arr4 = (int*)realloc(arr3, --n*sizeof(int));
    }
    free(arr4)
//zad4
    int n,m,k;
    scanf("%d%d", &n, &m);
    int *arr5 = (int*)malloc(n * sizeof(int));
    int *arr6 = (int*)malloc(m * sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d",&arr5[k])
    }
    for(int i=0; i<m; i++){
        scanf("%d",&arr6[k])
    }
    arr5 = (int*)realloc(arr5, n+m*sizeof(int));
    for(int i=n-1,j=0;i<m;i++, j++){
        arr5[i] = arr6[j];
    }
    qsort(arr5, n+m, compare);
    free(arr5);
    free(arr6);
//zad5
    int n = 10;
    int **triangle = (int**)malloc(n*sizeof(int*))
    for(int i =0; i<n; i++){
        triangle[i] = (int*)malloc((i+1) * sizeof(int));
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for(int j=1; j<i; j++){
            triangle[i][j] = triangle[i-1][j-1]+triangle[i-1][j];
        }
    }
    for(int i=0; i<n; i++){
        free(triangle[i]);
    }
    free(triangle);
    return 0;
}