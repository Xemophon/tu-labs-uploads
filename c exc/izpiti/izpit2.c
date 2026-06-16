#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char name[31];
    char chip[8];
    float price;
}Pet;

Pet createANDsave(){
    Pet patients;
    FILE* fptr = fopen("animalsText.txt", "a");
    if(fptr==NULL){
        perror("Error");
        exit(1);
    }
    fgets(patients.name, 31, stdin);
    patients.name[strcspn(patients.name, "\n")] = 0;
    char chip[8];
    fgets(patients.chip, 8, stdin);
    patients.chip[strcspn(patients.chip, "\n")] = 0;
    scanf("%f",&patients.price);
    getchar();
    fprintf(fptr, "%s,%.2f\n",patients.name,patients.price);
    fclose(fptr);
    return patients;
}

void searchByPrice(int count, Pets patients[], float price){
    int flag = 0;
    for(int i=0; i<count; i++){
        if(patients[i].price == price){
            flag++;
            printf("%s - %s\n", patients[i].name, patients[i].chip);
        }
    }
    if(flag==0){
        printf("Not found");
    }
}

void processBinaryFile(float minPrice) {
    FILE *binFile = fopen("animalsBin.bin", "rb");
    if (binFile == NULL) {
        printf("Binary file not found.\n");
        return;
    }
   Patient temp;
    while (fread(&temp, sizeof(Pet), 1, binFile)) {
        if (temp.visitPrice >= minPrice) {
            printf("Bin OwnerName: %s\n", temp.name);
            printf("Bin Chip: %s\n", temp.chip);
            printf("Bin Price: %.2f\n", temp.price);
            printf("----------\n");
        }
    }
    fclose(binFile);
}

int main()
{
//zad1
    int count;
    scanf("%d", &count);
    getchar();
    Pet patients[count];
    for(int i=0; i<count; i++){
        patients[i]=createANDsave();
    }
//zad2
    searchByPrice(count, patients, 38.90);
//zad3
    processBinaryFile(38.90);
    return 0;
}