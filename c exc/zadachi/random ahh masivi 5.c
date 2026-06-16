#include <stdio.h>

void get_main_diag(int size,int arr[size][size]){
    printf("Glaven: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i][i]);
    }
}

void get_rev_diag(int size,int arr[size][size]){
    printf("Obraten: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i][size - i - 1]);
    }
}

void get_secondary_diags(int size,int arr[size][size]){
    printf("Nad glaven: ");
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            printf("%d ", arr[i][j]);
        }
    }
    printf("\n");
    printf("Pod glaven: ");
    for(int i = 1; i < size; i++){
        for(int j = 0; j < i; j++){
            printf("%d ", arr[i][j]);
        }
    }
}

int check_sum(int *sum, int *temp){
    if(sum==temp){
        return 1;
    }else{
        return 0;
    }
}

int check_magic(int size,int arr[size][size]){
    int sum = 0;
    int temp = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i][i];
    }
    for(int i = 0; i < size; i++){
        temp += arr[i][size - i - 1];
    }
    if(check_sum(&sum, &temp) == 0){
        return 0;
    }
    temp = 0;
    for(int i = 1; i<size; i++){
        for(int j = 0; j<size; j++){
            temp += arr[i][j];
        }
        if(check_sum(&sum, &temp) == 0){
            return 0;
        }
        temp = 0;
    }
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            temp += arr[j][i];
        }
        if(check_sum(&sum, &temp) == 0){
            return 0;
        }
        temp = 0;
    }
    return 1;
}

int find_minor(int m, int n, int arr[m][n], int p, int minor[p][p]){
    for(int row=0; row<=m-p; row++){
        for(int column=0;column<=n-p;column++){
            int match=1;
            for(int j=0; j<p; j++){
                for(int k=0; k<p; k++){
                    if(minor[j][k]!=arr[j+row][k+column]){
                        match=0;
                        break;
                    }
                }
            if (!match) break;
            }
        if (match) return 1;
        }
    }
    return 0;
}

int main() {
    int size = 5;
    int arr1[size][size];
    int counter = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr1[i][j] = counter++;
        }
    }
// zad vurtene
    int arr2[][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr2[j][size - 1 - i] = arr1[i][j];
        }
    }
// zad mxn
    int n,m;
    scanf("%d%d",&n,&m);
    int arr[n][m];
    counter = 1;
    for(int i = 0; i<n;i++){
        if(i%2==0){
            for(int k =0; k<m; k++){
                arr[i][k] = counter++;
            }
        } else{
            for(int k=m-1; k>=0; k--){
                arr[i][k] = counter++;
            }
        }
    }
//zad podmatrica
    const int m=4,n=3;
    const int p=2;
    int arr[4][3] = { 
        {1,2,3}, 
        {4,5,8}, 
        {6,7,9}, 
        {0,1,2} };
    int minor[2][2] = { {6,7}, {0,1} };
    printf("%d",find_minor(m,n,arr,p,minor));
    return 0;
}