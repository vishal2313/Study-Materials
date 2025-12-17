#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct node{
	int key, val;
	struct node* next;
}Node;

void insert(int, Node*[]);
void printHT(Node*[],int);
int CompHashVal(int);
void initializeHT(Node*[],int);


int main() {
    int N = 47; //size of the Hash table
    Node* HashTable[N];
    int val;
    char c[5];
	//initialize the Hash Table to all NULL
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
            scanf("%d",&val);
            printf("\nInserting %d in the Hash Table\n",val);fflush(stdin);
            //insert the number in the Hash Table;
            insert(val,HashTable);
            printf("\nEntered %d in the Hash Table .....\n",val);fflush(stdin);

            
        }//end of else    
       
    }//end of while
    //printf("\nI am here - out of while construct.\n");fflush(stdin);
    printf("\nPrinting the Hash table ..........\n");fflush(stdin);
    printHT(HashTable,N);fflush(stdin);
    printf("\n");fflush(stdin);
    return 0;
}

void initializeHT(Node* HashTable[],int N){
	int i;
	for(i=0;i<N;i++)
		HashTable[i]=NULL;

}



void printHT(Node* HashTable[],int N){
	int i;
	for(i=0;i<N;i++){
		if(HashTable[i]!=NULL){
			//print the chain
			Node* Ptr = HashTable[i];
			printf("\n\n%d-->",i);fflush(stdin);
			while(Ptr!=NULL){
				printf("->%d",Ptr->val);fflush(stdin);
				Ptr = Ptr->next;
				//getchar();
			}
			printf("\n");
		}
		else{
			printf("\n%d-->nil",i);fflush(stdin);
		}
	}
	//printf("\n");
}

int CompHashVal(int val){
   	int p = 47; // prime number to be used for hashing
   	int slot;
   	slot = val%p;//hashing by multiplication
   	printf("\nSlot (%d) for the key - > %d computed successfully\n",slot, val);fflush(stdin);
   	//printf("\nReturning %d ......",slot);
   	return slot;
}

void insert(int val, Node* HashTable[]){
 	//printf("\n...... Inserting %d in the Hash Table .......\n",val);fflush(stdin);

	//first -- apply the hash function
	int slot;
	slot = CompHashVal(val); 

	//printf("\nSlot (%d) for the key (%d) computed successfully ......",slot, val);fflush(stdin);
	//check for collision and chain accordingly.

	if(HashTable[slot]==NULL){//there is no collision - simply put the data in that slot.
		//create a new node and attach it to the slot;
		printf("\n\nThere is no collision - Create a new chain for the slot ->%d\n",slot);
		Node* New = (Node*)malloc(sizeof(Node));
		New->key = val;
		New->val = val;
		New->next = NULL;
		HashTable[slot] = New;
	}
	else{//there is collision in this case - attach the data to the front of the chain
		printf("\n\nThere is collision - Add a node to the (front of the) chain in the slot ->%d\n",slot);		
		Node* New = (Node*)malloc(sizeof(Node));
		New->key = val;
		New->val = val;
		//Node* Chain = HashTable[slot];		
		New->next = HashTable[slot];
		HashTable[slot] = New;
			
	}

}
