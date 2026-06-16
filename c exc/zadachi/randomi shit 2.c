#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct{
    int chair;
    int table;
    int cups;
    int dishes;
}Party;
 
void buy_more(Party*party,int people){
    int chair = party->chair;
    int table = party->table*8;
    int cups = party->cups*6;
    int dishes = party->dishes*6;
    if(chair<people){
        for(int i = 1; chair==people; i++){
            chair++;
            party->chair++;
        }
    }
    if(table<people){
        for(int i = 1; table==people; i++){
            table++;
            party->table = table/8;
        }
    }
    if(cups<people){
        for(int i = 1; chair==people; i++){
            cups++;
            party->cups = cups/6;
        }
    }
    if(cups<people){
        for(int i = 1; chair==people; i++){
            dishes++;
            party->dishes = dishes/6;
        }
    }
}
 
typedef struct{
    char name[31];
    float price;
    char id[11];
}Product;
 
typedef struct{
    char address[51];
    char id[11];
}Order;
 
Product new_product(){
    Product product;
    char name[31];
    scanf("%[^\n]", name);
    strcpy(product.name, name);
    scanf("%f", &product.price);
    char id[11];
    scanf("%[^\n]", id);
    strcpy(product.id, id);
    return product;
}
 
Order new_order(){
    Order order;
    char address[51];
    scanf("%[^\n]", address);
    strcpy(order.address, address);
    char id[11];
    scanf("%[^\n]", id);
    strcpy(order.id, id);
    return order;
}
 
void delete_product(Product*arr, int ind){
    int size = sizeof(arr)/sizeof(Product);
    for(int i=ind; i<size; i++){
        arr[i]=arr[i+1];
    }
    Product*arr = (Product*)realloc(arr, size-1*sizeof(Product));
    return arr;
}
 
void delete_order(Order*arr, int ind){
    int size = sizeof(arr)/sizeof(Order);
    for(int i=ind; i<size; i++){
        arr[i]=arr[i+1];
    }
    Order*arr = (Order*)realloc(arr, size-1*sizeof(Order));
    return arr;
}
 
int occurence1(Product*arr, Order*arr2){
    int size1 = sizeof(arr)/sizeof(Product);
    int size2 = sizeof(arr2)/sizeof(Order);
    for(int i=0; i<size1; i++){
        for(int j=0; j<size2; j++){
            if(strcmp(arr[i].id, arr[j].id)==0){
                return i;
            }
        }
    }
    return NULL;
}
 
int occurence2(Product*arr, Order*arr2){
    int size1 = sizeof(arr)/sizeof(Product);
    int size2 = sizeof(arr2)/sizeof(Order);
    for(int i=0; i<size1; i++){
        for(int j=0; j<size2; j++){
            if(strcmp(arr[i].id, arr[j].id)==0){
                return j;
            }
        }
    }
    return NULL;
}
 
int anagrams(char*word1, char*word2){
    if(strlen(word1,word2)!=0){
        return 0;
    }
    while(word1[i]!='\0'){
        int size = sizeof(word2)/sizeof(char);
        for(int j=0; j<size; j++){
            if(word1[i]==word1[j]){
                flag1++;
            }
        }
        for(int j=0; j<size; j++){
            if(word1[i]==word2[j]){
                flag2++;
            }
        }
        if(flag1!=flag2){
            return 0;
        }
        flag1=flag2=0;
        i++;
    }
    return 1;
}
 
int find_size(char name[]){
    FILE*fptr=fopen(name,"r");
    fseek(fptr,0,SEEK_END);
    int size = ftell(fptr);
    fclose(fptr);
    return size;
}

typedef char eng_string[51];

int main()
{
//zad1
    int people;
    Party haralam;
    char command[11];
    scanf("%d",&people);
    for(;;){
        scanf("%s",&command);
        if(strcmp(command,"Chair")==0){
            haralam.chair++;
        } else if(strcmp(command,"Table")==0){
            haralam.table++;
        } else if(strcmp(command,"Cups")==0){
            haralam.cups++;
        } else if(strcmp(command,"Dishes")==0){
            haralam.dishes++;
        } else if(strcmp(command,"PARTY!")==0){
            break;
        }
    }
    buy_more(&haralam; people);
    int sum=haralam.chair*13.99+haralam.table*42.00+haralam.cups*5.98+haralam.dishes*21.02;
    printf("%.2f", sum);
//zad2
    int n=m=1;
    Product*list=(Product*)malloc(n*sizeof(Product));
    Order*orders=(Order*)malloc(m*sizeof(Order));
    char intent[11];
    for(;;){
        scanf("%[^\n]", intent);
        if(strcmp("Product", intent)==0){
            n++;
            Product product=new_product();
            Product*list=(Product*)realloc(list,n*sizeof(Product));
            list[n-1]=product;
        } else if(strcmp("Order", intent)==0){
            m++;
            Order order=new_order();
            Order*orders=(Order*)realloc(orders,m*sizeof(Order));
            orders[n-1]=order;
        } else if(strcmp("END", intent)==0){
            break;
        }
        if(occurence1!=NULL){
            int i = occurence1(list, orders);
            int j = occurence2(list, orders);
            printf("Client on address %s got %s",orders[j].address, list[i].name);
            list = delete_product(list, i);
            orders = delete_order(orders, j);
        }
    }
    free(list);
    free(orders);
//zad3
    int size = find_size("input.txt");
    FILE*fptr=fopen("input.txt","r");
//zad5
    char word[21] = "concatenation";
    char hidden[21];
    int i=0;
    while(word[i]!='\0'){
        hidden[i]='_';
        i++;
    }
    for(int j=0; j<i+2;j++){
        printf("%s\n",hidden);
        char letter;
        scanf("%c", &letter);
        for(int k=0;k<i;k++){
            if(letter==word[k]){
                hidden[k] = word[k];
            }
        }
    }
//zad6
    int flag1,flag2;
    char word1[21] = "cheap"
    char word2[21] = "peach"
    int result = anagrams(word1,word2);
    if(result == 1){
        printf("%s and %s are anagrams", word1,word2);
    }
    return 0;
}