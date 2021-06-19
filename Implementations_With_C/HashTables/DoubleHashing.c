#include <stdio.h>
#define MOD_VALUE 13
typedef struct data
{
    int key,value;
}data;
data table[MOD_VALUE];
int isPrime(int number);
int secondPrime(int number,int which);
int hash1(data data);
int hash2(data data);
void put(data data);
int removeItem(data data);
void search(data data);
void initializeTable();
void printTable();
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
    if(table[hash1(data)].key == -1){
        table[hash1(data)].key = data.key;
        table[hash1(data)].value = data.value;
    }else if (table[hash2(data)].key == -1){
       table[hash2(data)].key = data.key;
       table[hash2(data)].value = data.value; 
    }else{
        int index = hash2(data);
        int cycle =0;
        while (table[index].key != -1 && table[index].key != data.key){
            index++; 
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
    if(table[hash1(data)].key == data.key){
        temp = table[hash1(data)].value;
        table[hash1(data)].key = -1;
        table[hash1(data)].value = -1;
        
    }else if (table[hash2(data)].key == data.key)
    {
        temp = table[hash2(data)].value;
        table[hash2(data)].key = -1;
        table[hash2(data)].value = -1;

    }
    
    else{
        int index = hash2(data);
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
 if(table[hash1(data)].key == data.key){
        printf("The data is here : (Key : %d , Value : %d)\n",table[hash1(data)].key,table[hash1(data)].value);
        
 }else if (table[hash2(data)].key == data.key){
    printf("The data is here : (Key : %d , Value : %d)\n",table[hash2(data)].key,table[hash2(data)].value); 
 }
    else{
        int index = hash2(data);
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
int secondPrime(int number,int which){
    int counter = 1;
    for(int i = number-1;i>0;i--){
        if(isPrime(i) == 1 ){
            if(counter == which){
                
                return i;
            }else{
                counter++;
            }
            
        }
    }
    return -1;
}

int isPrime(int number){
    if(number == 1){
        return 0;
    }
    else if (number == 2)
    {
        return 1;
    }
    
    for (int i = 2; i < number; i++)
    {
        if(number%i== 0){
           return 0;
        }
    }
    return 1;
}

int hash1(data data){
    return (data.key)%MOD_VALUE;
}

int hash2(data data){
    int anotherPrime = secondPrime(MOD_VALUE,2);
    return (data.key)%anotherPrime + hash1(data); 
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