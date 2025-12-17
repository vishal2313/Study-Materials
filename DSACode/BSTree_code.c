#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node{
	int key;
	struct node* left;
	struct node* right;
}Node;

int ComputeSize(Node*);

int ComputeMax(int, int);

Node* insert(Node*, int);

int ComputeHeight(Node*);

void printBST(Node*);

int main() {
   
    int val;
    char c[5];
    Node* BST = NULL;//initially the BST is empty
/*----------------------------------------------------------------------------------   
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
            printf("\nI am here - else-if construct\n");
            printf("\nEnter another number ->");
            scanf("%d",&val);
            printf("\n..... inserting %d in the BST .....\n",val);
            //we have to insert the new value in the BST
            if(BST == NULL){
			//the BST is empty
			//simply put the val as root - after creating a new node
			BST = (Node*)malloc(sizeof(Node));
			BST->key = val;
			BST->left = NULL;
			BST->right = NULL;

			printf("\n..... insertion complete ......\n");

   			}
   			else{
            	BST = insert(BST,val);
            	printf("\nPrinting the BST after insertion ....... \n");
            	printBST(BST);
            }
            continue;
        }
       
    }//end of while
    printf("\nI am here - out of while construct.\n");
------------------------------------------------------------------------*/   
	int List1[] = {30,40,20,25,15,35,45};//height 2
	int List2[] = {15,20,25,30,35,40,45};//height 6
	int i;
	for(i=0;i<7;i++){
		val = List1[i];
		printf("\n..... inserting %d in the BST .....\n",val);
        //we have to insert the new value in the BST
        if(BST == NULL){
			//the BST is empty
			//simply put the val as root - after creating a new node
			BST = (Node*)malloc(sizeof(Node));
			BST->key = val;
			BST->left = NULL;
			BST->right = NULL;

			printf("\n..... insertion complete ......\n");

   		}
 		else{
            	BST = insert(BST,val);
            	printf("\nPrinting the BST after insertion ....... \n");
            	printBST(BST);
        }
		
	}
    //let us traverse the BST
    printf("\nPrinting the BST ......... \n");
    printBST(BST);
    printf("\nPrinting Done .........\n");

    //Let us compute the height of the tree
    int height = ComputeHeight(BST);
    printf("\nHeight of the BST is %d\n",height -1);

   //Let us compute the size of the tree
    int size = ComputeSize(BST);
    printf("\nSize of the BST is %d\n",size);    
    
    return 0;    
}//end of main

int ComputeHeight(Node* BST){
	if(BST == NULL){
		return 0;
	}
	else{
		return  (1 + ComputeMax(ComputeHeight(BST->left),ComputeHeight(BST->right)));
	}

}

int ComputeSize(Node* BST){
	if(BST == NULL){
		return 0;
	}
	else{
		return  1 + (ComputeSize(BST->left)+ ComputeSize(BST->right));
	}

}


int ComputeMax(int val1, int val2){
	if(val1 >= val2)
		return val1;
	else
		return val2;				
}

Node* insert(Node* BST,int val){
	//base case
	if(BST==NULL){
		//val has to be inserted at this point
		Node* New;

		New = (Node*)malloc(sizeof(Node));
		New->key = val;
		New->left = NULL;
		New->right = NULL;

		printf("\n..... insertion complete ......\n");

		return New;
	}
	//inductive case
	else{
		if(BST->key == val){
			printf("\nThe value to be inserted,  %d, already exists in the tree.",val);
			return BST;

		}
		else if(BST->key > val){
			//insert in the left subtree
			BST->left = insert(BST->left,val);

		}
		else if(BST->key < val){
			//insert in the right subtree
			BST->right = insert(BST->right,val);

		}
		else{
			printf("\nThere is an error...... exiting......\n");
			exit(0);
		}
	}
	return BST;

}//end of insert function


void printBST(Node* BST){
	if(BST==NULL)
		return;
	else{
		printBST(BST->left);
				
		printf("%d\n",BST->key);

		printBST(BST->right);
	}
}
