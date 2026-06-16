#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char manuf[21];
	char model[6];
	int engine;
	float price;
	char reg;
}Vehicle;

void new_record(Vehicle*kol){
	char manuf[51];
	scanf("%[\n]",manuf);
	strcpy(kol->manuf, manuf);
	char model[6];
	scanf("%[\n]",model);
	strcpy(kol->model, model);
	scanf("%d",&kol->engine);
	scanf("%f",&kol->price);
	scanf("%c",&kol->reg);
}

int main(){
//zad1
	FILE*fptr=fopen("niggers.bin","wb+");
	int i,counter_odd = counter_even = 0;
	if(fread(&i,sizeof(int),1,fptr)==1) return 1;
	int arr[i];
	for(int j = 0;j<i;j++){
		int num;
		if(fread(&num,fptr,sizeof(int),1,fptr)==1) return 1;
		arr[j] = num;
		if(num%2==0){
			counter_even++;
		} else{
			counter_odd++;
		}
	}
	for(int j=0;j<i-1;j++){
		for(int k=0; k<i-j-1;k++){
			if(arr[k]>arr[k+1]){
				int temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
	fclose(fptr);
	FILE*fptr=fopen("niggers.txt","a");
	for(int j=0;j<i;j++){
		fprintf(fptr,"%d", arr[j]);
	}
	fclose(fptr);
//zad2
	FILE*fptr=fopen("niggers.bin","wb+");
	int counter_odd = counter_even = 0;
	fseek(fptr,0,SEEK_END);
	int i = ftell(fptr)/sizeof(int);
	fseek(fptr,0,SEEK_SET);
	int arr[i];
	for(int j = 0;j<i;j++){
		int num;
		if(fread(&num,fptr,sizeof(int),1,fptr)==1) return 1;
		arr[j] = num;
		if(num%2==0){
			counter_even++;
		} else{
			counter_odd++;
		}
	}
	for(int j=0;j<i-1;j++){
		for(int k=0; k<i-j-1;k++){
			if(arr[k]>arr[k+1]){
				int temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
	fclose(fptr);
	FILE*fptr=fopen("niggers.txt","a");
	for(int j=0;j<i;j++){
		fprintf(fptr,"%d", arr[j]);
	}
	fclose(fptr);
//zad3
	FILE*bin=fopen("pedali.bin","wb+");
	FILE*txt=fopen("pedali.txt","w+");
	Vehicle kolichka;
	if(fwrite(&kolichka,sizeof(Vehicle),1,bin)!=1) return 1;
	fprintf(txt,"%s %s %d %f %c", kolichka.manuf, kolichka.model, kolichka.engine,kolichka.price,kolichka.reg);
	Vehicle kol;
	new_record(&kol);
	fclose(bin);
	fclose(txt);
	
	FILE*bin=fopen("pedali.bin","rb+");
	FILE*txt=fopen("pedali.txt","r+");
	Vehicle vk1;
	Vehicle vk2;
	if(fread(&vk1,sizeof(Vehicle),1,bin)!=1) return 1;
	if(fscanf(txt,"%s %s %d %f %c", &vk2.manuf, &vk2.model, &vk2.engine,&vk2.price,&vk2.reg)!=1) return 1;
	return 0;
}