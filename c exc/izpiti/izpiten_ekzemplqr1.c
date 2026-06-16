#include <stdlib.h>
#include <stdio.h>

typedef struct{
    char name[50];
    char date[11];
    int lessons;
    float price;
} Course;

Course* readCourses(const char* filename, int* n) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Грешка при отваряне на двоичния файл!\n");
        *n = 0;
        return NULL;
    }
    if (fread(n, sizeof(int), 1, file) != 1 || *n <= 0) {
        *n = 0;
        fclose(file);
        return NULL;
    }
    Course* courses = (Course*)malloc((*n) * sizeof(Course));
    if (courses == NULL) {
        printf("Грешка при заделяне на памет!\n");
        *n = 0;
        fclose(file);
        return NULL;
    }
    fread(courses, sizeof(Course), *n, file);
    fclose(file);
    return courses;
}

void applyDiscount(Course* courses, int n, int index){
    if(index>n-1){
        printf("Невалидна позиция!\n");
        return;
    }
    course[index].price -= courses[index].price * 0.10;
    printf("Нова цена на курса %.2f лв. - %s - %s", course[index].price, course[index].name, course[index].date)
}

int exportOffers(Course* courses, int n, float min, float max){
    int counter = -1;
    FILE* fptr = fopen("offer.txt","w");
    if (fptr == NULL) {
        printf("Грешка при създаване на текстовия файл!\n");
        return counter;
    }
    counter++;
    fprintf(fptr, "Оферти:\n");
    fclose(fptr);
    FILE* fptr = fopen("offer.txt","a");
    for(int i = 0; i<n; i++){
        if(courses[i].price >= min && courses[i].price<=max){
            fprintf(fptr, "\n%s",courses[i].name);
            fprintf(fptr, "\n%s",courses[i].date);
            fprintf(fptr, "\n%d",courses[i].lessons);
            fprintf(fptr, "\n%.2f",courses[i].price);
            fprintf(fptr,"\n")
            counter++;
        }
    }
    fclose(fptr);
    return counter;
}

Course* deleteCourse(Course* courses, int* n, const char* name, const char* startDate){
    if (courses == NULL || *n <= 0) {
        return NULL; 
    }
    int targetIndex = -1;
    for (int i = 0; i < *n; ++i) {
        if (strcmp(courses[i].name, name) == 0 && strcmp(courses[i].startDate, startDate) == 0) {
            targetIndex = i;
            break;
        }
    }
    if (targetIndex == -1) {
        return courses; 
    }
    Courses* renewed_courses = (Courses*)malloc((*n-1)*sizeof(Courses));
    if(renewed_courses = NULL){
        printf("Грешка при заделяне на памет за новия масив!\n");
        return courses;
    }
    int j = 0;
    for(int i = 0; i<*n; i++){
        if(i!=targetIndex){
            renewed_courses[j++]=courses[i];
        }
    }
    free(courses);
    (*n)--;
    return newCourses;
}

int main()
{   
    int n = 0;
    Course* courses = readCourses("courses.bin", &n);
    if (courses != NULL) {
        printf("Успешно заредени %d курса.\n\n", n);
        applyDiscount(courses, n, 0);
        int written = exportOffers(courses, n, 500.0, 1500.0);
        printf("Записани курсове в offer.txt: %d\n", written);
        courses = deleteCourse(courses, &n, "Java приложения в облака", "2023.04.10");
        printf("Брой курсове след изтриването: %d\n", n);
        free(courses);
    }
    return 0;
}