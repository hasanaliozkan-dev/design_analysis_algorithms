#include <stdio.h>
#define MOD_VALUE 13
typedef struct data
{
    int key,value;
}data;
data table[MOD_VALUE];
void initializeTable(void);
void printTable(void);
void put(data data);
int removeItem(data data);
void search(data data);
int hash(data data);
int main(){
initializeTable();
data d;
for (int i = 0; i < MOD_VALUE; i++){
    d.key = (i*3+5);d.value=(i+1)*10;
    put(d);
}
printf("Elements are getting\n\n");
for (int i = 0; i < MOD_VALUE; i++)
{
    d.key = (i*3+5);d.value=(i+1)*10;
    search(d);
}
d.key=2132;
d.value = 00000;
search(d);
d.key=26;
d.value = 80;
removeItem(d);



printTable();
return 0;

}
void put(data data){
    if(table[hash(data)].key == -1){
        table[hash(data)].key = data.key;
        table[hash(data)].value = data.value;
    
    }else{
        int index = hash(data);
        int cycle =0;
        while (table[index].key != -1 && table[index].key != data.key){
            index++; //In the quadratic probing we place the item "(i++)^2" just this everything is same.
            if(index>=MOD_VALUE){
                if(cycle == 1){
                    printf("\nThe table is full!!\n");
                    return;
                }
                index = index%MOD_VALUE; 
                cycle++;
            }
        }
        table[index].key = data.key;
        table[index].value = data.value;
    }
    
    
}
int removeItem(data data){
    int temp = 0;
    if(table[hash(data)].key == data.key){
        temp = table[hash(data)].value;
        table[hash(data)].key = -1;
        table[hash(data)].value = -1;
    }else{
        int index = hash(data);
        int cycle =0;
        while (table[index].key != data.key){
            index++;
            if(index>=MOD_VALUE){
                if(cycle == 1){
                    printf("\nThe data was not found !!\n");
                    return -1;
                }
                index = index%MOD_VALUE;
                cycle++;
            }
        }
        temp = table[index].value;
        table[index].key = -1;
        table[index].value = -1;
    }
    return temp;    

}
void search(data data){
 if(table[hash(data)].key == data.key){
        printf("The data is here : (Key : %d , Value : %d)\n",table[hash(data)].key,table[hash(data)].value);
    
    }else{
        int index = hash(data);
        int cycle =0;
        while (table[index].key != data.key){
            index++;
            if(index>=MOD_VALUE){
                if(cycle == 1){
                    printf("\nThe data was not found !!\n");
                    return;
                }
                index = index%MOD_VALUE;
                cycle++;
            }
        }
        printf("The data is here : (Key : %d , Value : %d)\n",table[index].key,table[index].value);
    }
}
int hash(data data){
    return (data.key)%MOD_VALUE;
}
void printTable(){
    printf("\n");
    for (int i = 0; i < MOD_VALUE; i++)
    {
        printf(" %d -> (Key : %d , Value : %d)\n",i,table[i].key,table[i].value);
    }
    printf("\n");
}
void initializeTable(){
    for (int i = 0; i < MOD_VALUE; i++){
    table[i].key=-1;
    table[i].value=-1;
    }
}