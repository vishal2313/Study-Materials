#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct node{
	int key, val;
}Node;

void insert(int, Node[],int);
void printHT(Node[],int);
int CompHash1(int,int);
int CompHash2(int,int);
void initializeHT(Node[],int);


int main() {
    int N = 11; //size of the Hash table
    Node HashTable[N];
    int key;
    char c[5];
	//initialize the Hash Table to all -9999
    initializeHT(HashTable,N);
    while(1){
        printf("\nWill you enter another number (yes/no) ->");
        scanf("%s",c);
       
        // fflush(stdin); -- fflush is not flushing input buffer
        // flushes the standard input --- (clears the input buffer)
    	  while ((getchar()) != '\n');
   
        //printf("\nThe value of c entered is -> %s\n",c);
        if(strcmp(c,"no")==0){
            //printf("\nI am here - if construct\n");
            break;
        }
        else{
            //printf("\nI am here - else-if construct\n");fflush(stdin);
            printf("\nEnter another number ->");
            scanf("%d",&key);
            printf("\nInserting %d in the Hash Table\n",key);fflush(stdin);
            //insert the number in the Hash Table;
            insert(key,HashTable,N);
            printf("\nEntered %d in the Hash Table .....\n",key);fflush(stdin);

            
        }//end of else    
       
    }//end of while
    //printf("\nI am here - out of while construct.\n");fflush(stdin);
    printf("\nPrinting the Hash table ..........\n");fflush(stdin);
    printHT(HashTable,N);fflush(stdin);
    printf("\n");fflush(stdin);
    return 0;
}

void initializeHT(Node HashTable[],int N){
	int i;
	for(i=0;i<N;i++){
		HashTable[i].key=-9999;
		HashTable[i].val=-9999;		
	}
}



void printHT(Node HashTable[],int N){
	int i;
	for(i=0;i<N;i++){
		if(HashTable[i].key!=-9999){
			
			printf("\n%d-->%d\n",i,HashTable[i].key);
		}
		else{
			printf("\n%d-->nil",i);fflush(stdin);
		}
	}
	//printf("\n");
}

int CompHash1(int key, int i){
   	int p = 47; // prime number to be used for hashing
   	int slot;
   	slot = ((key%p)+i)%p;//hashing by division
   	printf("\nSlot (%d) for the key - > %d computed successfully\n",slot, key);fflush(stdin);
   	//printf("\nReturning %d ......",slot);
   	return slot;
}


int CompHash2(int key, int i){
	double A = sqrt(5)-1/2;
   	int m = 64; // m is a power of 2 in the case of multiplication
   	int slot;
   	slot = floor(m*(key*A - floor(key*A)));//hashing by multiplication
   	printf("\nSlot (%d) for the key - > %d computed successfully\n",slot, key);fflush(stdin);
   	//printf("\nReturning %d ......",slot);
   	return slot;
}

void insert(int key, Node HashTable[],int N){
 	//printf("\n...... Inserting %d in the Hash Table .......\n",val);fflush(stdin);

	//first -- apply the hash function
	int slot;
	int i=0;//probe number
	do{
		slot = CompHash1(key,i); 
		if(HashTable[slot].key==-999){//slot is empty
			HashTable[slot].key = key;
			HashTable[slot].val = key;
			return;
		}
		else i=i+1;
	}while(i==N);

	printf("\nHash Table Overflow.....\n");

}
