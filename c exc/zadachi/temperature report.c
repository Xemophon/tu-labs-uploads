#include <stdio.h>

char days[7][10] = {
    "Monday", "Tuesday", "Wednesday", "Thursday", 
    "Friday", "Saturday", "Sunday"};

void inputTemperatures(int temps[], int size){
    int temp;
    for(int i = 0; i<size; i++){
        printf("Input temp for %s:", days[i]);
        scanf("%d", &temp);
        printf("\n");
        temps[i] = temp;
    }
}

float calculateAverage(int temps[], int size){
    float sum = 0;
    for(int i = 0; i<size; i++){
        sum += temps[i];
    }
    return sum/size;
}

int findMaxTemp(int temps[], int size){
    int max = temps[0];
    for(int i = 0; i<size; i++){
        if(max<temps[i]){
            max = temps[i];
        }
    }
    return max;
}

int findMinTemp(int temps[], int size){
    int min = temps[0];
    for(int i = 0; i<size; i++){
        if(min>temps[i]){
            min = temps[i];
        }
    }
    return min;
}

int main(){
    int temps[7];
    inputTemperatures(temps, 7);
    printf("Temps are: ");
    for(int i = 0; i<7; i++){
        printf("%d,", temps[i]);
    }
    printf("\n--- Weekly Weather Report ---\n");
    printf("Average - %.2f\n", calculateAverage(temps, 7));
    printf("Max - %d\n", findMaxTemp(temps, 7));
    printf("Min - %d", findMinTemp(temps, 7));
    return 0;
}