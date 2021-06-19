#include <stdio.h>
#include <stdlib.h>
#define MOD_VALUE 13
typedef struct data
{
    int key,value;
    struct data * next;
}data;
data *table[MOD_VALUE];
void initializeTable(void);
void printTable(void);
void put(data data);
int removeItem(data data);
void search(data data);
int hash(data data);
int main(){
    initializeTable();
    data d1; data d2; data d3;data d4;
    d1.key = 1;d1.value=1111;d1.next = NULL;put(d1);
    d2.key = 14;d2.value=2222;d2.next = NULL;put(d2);
    d3.key = 27;d3.value=3333;d3.next = NULL;put(d3);
    d4.key = 27;d4.value=89375;d4.next = NULL;
    printTable();
    printf("%d\n",removeItem(d2));
    printf("%d\n",removeItem(d4));
    search(d4);
    printTable();

    return 0;
}
void put(data d){
    data * newData =  malloc(sizeof(data));
    newData->key = d.key;
    newData->value = d.value;
    newData->next = NULL;
    if(table[hash(d)] == NULL){
        table[hash(d)] = newData;
    } 
    else{
        data * temp = table[hash(d)];
        while (temp->next!= NULL)
        {
            temp = temp->next;
        }
        temp->next = newData;
    }
}

void search(data d){
    data * temp = table[hash(d)];
    while (temp)
    {
        if(temp->value == d.value){
            printf("The value is here : (Key : %d , Value : %d )\n",d.key,d.value);
            return;   
        }
        temp = temp->next;
    }
    printf("The value isn't here!!");
    
    
}

int removeItem(data d){
    data * temp = table[hash(d)];
    if(temp!=NULL){
        if(temp->value == d.value){
            data * freetemp = temp;
            int value = freetemp->value;
            temp = temp->next;            
            free(freetemp);
            return value;
        }else
        {
            while(temp->next)
            {
                if(temp->next->value == d.value){
                    data * freetemp = temp->next;
                    int value = freetemp->value;
                    temp->next = temp->next->next;
                    free(freetemp);
                    return value; 
                }
                temp = temp->next;
                }
    }
    }
    return -1;
}

int hash(data data){
    return (data.key)%MOD_VALUE;
}

void printTable(){
    printf("\n");
    for (int i = 0; i < MOD_VALUE; i++){
        data * temp = table[i]; 
        printf("Index %d |",i);
        while(temp){
            printf("(Key : %d , Value : %d )--> ",temp->key,temp->value);
            temp = temp->next;
        }
        printf("(Key : NULL , Value : NULL )\n");
        
    }
    printf("\n");
}

void initializeTable(){
    for (int i = 0; i < MOD_VALUE; i++){
            table[i] = NULL;        
    }
}
