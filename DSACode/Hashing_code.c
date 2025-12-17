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
    int N = 47; //size of the Address table
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
   
        printf("\nThe value of c entered is -> %s\n",c);
        if(strcmp(c,"no")==0){
            printf("\nI am here - if construct\n");
            break;
        }
        else{
            printf("\nI am here - else-if construct\n");fflush(stdin);
            printf("\nEnter another number ->");
            scanf("%d",&val);
            printf("\nInserting %d in the Hash Table",val);fflush(stdin);
            //insert the number in the Hash Table;
            insert(val,HashTable);
            printf("\nEntered %d in the Hash Table .....\n",val);fflush(stdin);

            
        }//end of else    
       
    }//end of while
    printf("\nI am here - out of while construct.\n");fflush(stdin);
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

void deleteHT(int key){
	int index = CompHashVal(key);
	if(HashTable[index]==NULL)
	{
		printf("\nNo data with the key ->%d exists in the hash table",key);
		return;
	}	
	else{//search in the chain (linked list) attached to the index and delte the appropriate node
		Node* ptr = HashTable[index];
		Node* prev = NULL;
		while(ptr->next!=NULL){
			if(ptr->key == key){
				Node* del = ptr;
				prev->next = ptr->next;
				free(del);//free the memory for the node with the given key.
			}
			else{
				prev = ptr;
				ptr = ptr->next;
				
			}
		}
		printf("\nNo data with the key ->%d exists in the hash table",key);
		return;
	}
}
}



int searchHT(int key){
	int index = CompHashVal(key);
	if(HashTable[index]==NULL)
	{
		printf("\nNo data with the key ->%d exists in the hash table",key);
		return;
	}	
	else{//search in the chain (linked list) attached to the index
		Node* ptr = HashTable[index];
		while(ptr!=NULL){
			if(ptr->key == key){
				printf("\nData for the key ->%d exists in the hash table");
				return ptr->val;
			}
			else{
				ptr = ptr->next;
			}
		}
		
	}
}

void printHT(Node* HashTable[],int N){
	int i;
	for(i=0;i<N;i++){
		if(HashTable[i]!=NULL){
			//print the chain
			Node* Ptr = HashTable[i];
			printf("\n%d-->",i);fflush(stdin);
			while(Ptr!=NULL){
				printf("->%d",Ptr->val);fflush(stdin);
				Ptr = Ptr->next;
				//getchar();
			}
		}
	}
	//printf("\n");
}

int CompHashVal(int val){
   	int p = 47; // prime number to be used for hashing
   	int target;
   	target = val%p;//hashing by division
   	printf("\nTarget (%d) for the key - > %d computed successfully",target, val);fflush(stdin);
   	printf("\nReturning %d ......",target);
   	return target;
}

void insert(int val, Node* HashTable[]){
 	printf("\n...... Inserting %d in the Hash Table .......\n",val);fflush(stdin);
//using insert we maintain a sorted chain at each target.
	int flag=0;// insertion not complete
	//first -- apply the hash function
	int target;
	target = CompHashVal(val); 
	//int target = val % 37;
	printf("\nTarget (%d) for the key (%d) computed successfully ......",target, val);fflush(stdin);
	//check for collision and chain accordingly.

	if(HashTable[target]==NULL){
		//create a new node and attach it to the target;
		Node* New = (Node*)malloc(sizeof(Node));
		New->key = val;
		New->val = val;
		New->next = NULL;
		HashTable[target] = New;
		flag=1;
	}
	else{
		Node* Chain = HashTable[target];
		Node* New = (Node*)malloc(sizeof(Node));
		New->key = val;
		New->val = val;
		New->next = NULL;
		//insert val in the Chain
		Node* Ptr = Chain;
		Node* Prev = NULL;
		while(Ptr->next!=NULL){
			//if val>Ptr->key move ahead else attach it just before Ptr.
			if(val > Ptr->key){
				Prev = Ptr;
				Ptr = Ptr->next;
			}
			else{//insert the val at the Prev position.
				if(Prev == NULL){
					New->next = Ptr;
					HashTable[target] = New;
					flag=1;//insertion done
					break;
				}
				else{
					Prev->next = New;
					New->next = Ptr;
					flag=1;//insertion done
					break;
				
				}
			
			}	
		}
		//attaching New at the end of the chain.
		if(flag==0){
			 Ptr->next = New;
			 flag = 1;//insertion done
		}	 
	}

}
