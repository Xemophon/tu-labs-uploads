#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Point {
    float x;
    float y;
    float z;
};

typedef struct {
    char name[11];
    int year;
}Specs;

typedef struct {
    char type[21];
    Specs specs;
}Vehicle;

typedef struct {
    char name[11];
    char class;
    float mark;
}Student;

typedef struct {
    char class;
    float avg_mark;
    Student arr[10];
}Class;

typedef struct {
    int year;
    float avg_mark;
    Class arr[10];
}Vipusk;


float length(float a, float b, float c, float d){
    return sqrt(pow(a-c, 2)+pow(b-d, 2));
}

void compare_vehicles(Vehicle vehicle1, Vehicle vehicle2){
    if(strcmp(vehicle1.type,vehicle2.type)==0){
        printf("Same type");
    }
    if(strcmp(vehicle1.specs.name,vehicle2.specs.name)==0){
        printf("Same model");
    }
    if(vehicle1.specs.year == vehicle2.specs.year){
        printf("Same year");
    }
}

void calculate_avg_class(Class* class, int students){
    float avg = 0;
    float sum = 0;
    for(int i=0; i<students; i++){
        sum+=class->arr[i].mark;
    }
    avg = sum/students;
    class->avg_mark = avg;
}

void calculate_avg_vipusk(Vipusk* vipusk, int classes){
    float sum = 0;
    for(int i=0; i<classes; i++){
        sum+=vipusk->arr[i].avg_mark;
    }
    vipusk->avg_mark = sum/classes;
}

typedef struct{
    char title[41];
    char author[21];
    int year;
    float price;
}Book;

void review_prices(Book bookstore[], int broiki){
    float sum=0.0;
    float max=min=bookstore[0].price;
    for(int i=0; i<broiki; i++){
        sum+=bookstore[i].price;
        if(max<bookstore[i].price){
            max=bookstore[i].price;
        }
        if(min>bookstore[i].price){
            min=bookstore[i].price;
        }
    }
    printf("%f, %f, %f", sum/broiki,max,min);
}

int main(){
//zad1 
    // float a=0,b=0;
    // int n=5;
    // struct Point points[n];
    // for(int i=0; i<n; i++){
    //     scanf("%f%f", &a,&b);
    //     points[i].x=a;
    //     points[i].y=b;
    // }
    // for(int i=1; i<n; i++){
    //     printf("\nSide %d - %.2f",i,lenght(points[i-1].x, points[i-1].y, points[i].x, points[i].y));
    // }
//zad5
    Book bookstore[10];
    for(int i=0;i<10;i++){
        char title[41], author[21];
        scanf("%40[^n]", title);
        scanf("%20[^n]", author);
        strcpy(bookstore[i].title;title);
        strcpy(bookstore[i].author;author);
        scanf("%d%f",bookstore[i].year,bookstore[i].price);
    }
    return 0;
}