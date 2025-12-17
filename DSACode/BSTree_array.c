#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Declarations for BST using Tabular data structure
void insertA(int[],int,int);
void printA(int[],int);
void printB(int[],int);
int CompHeight(int[], int);
int CompLeaves(int[], int);
int CompMax(int, int);


int main() {	   
	int val;
	int BST[350];
	int flag=0;//initially the BST is empty
	int i;
	//initially the BST is empty
	for(i=0;i<350;i++){
		BST[i] = -1;
	}
	int List1[] = {35,45,40,50,20,15,30};
	int List2[] = {15,20,30,35,40,45,50};
	//insertion into BST
	for(i=0;i<7;i++){
		val = List2[i];
		if(flag==0){//BST is NULL - Base case
			printf("\nBase case of insert ......");
			BST[i] = val;
			flag=1;
		}
		else{ //induction case
			printf("\nInduction case of insert .....");
			insertA(BST,val,0);
		}
	}  
//let us traverse the BST
	printf("\nPrinting the final BST ......... \n");fflush(stdin);
	printA(BST,0);
	printf("\nPrinting Done .........\n");fflush(stdin);
	
//let us compute the height of the BST
	printf("\nHeight of the BST is %d\n",CompHeight(BST,0));	
//let us compute the no. of leaves in the BST
	printf("\nNo. of leaves in the BST is %d\n",CompLeaves(BST,0));		
	return 0;
	    
	    
}//end of main

int CompHeight(int BST[], int ptr){
	if(BST[ptr]==-1){//Base case
		return -1;	
	}
	else{//Induction case
		int L1 = CompHeight(BST, 2*ptr+1);//the left subtree
		int L2 = CompHeight(BST, 2*ptr+2);//the right subtree	
		return 1+CompMax(L1,L2);
	}

}

int CompMax(int V1, int V2){
	if(V1>=V2)
		return V1;
	else
		return V2;	
}

int CompLeaves(int BST[], int ptr){
	if(BST[2*ptr+1]==-1 && BST[2*ptr+2]==-1)
		return 1;
	else if(BST[2*ptr+1]==-1 && BST[2*ptr+2]!=-1)	
		return CompLeaves(BST, 2*ptr+2);
	else if(BST[2*ptr+1]!=-1 && BST[2*ptr+2]==-1)	
		return CompLeaves(BST, 2*ptr+1);
	else
		return CompLeaves(BST, 2*ptr+1) + CompLeaves(BST, 2*ptr+2);			
}


//insert routine with BST implemented as array

void insertA(int BST[],int val,int ptr){
	if(BST[ptr]==-1){//Base case
		//val has to be inserted at this point
		BST[ptr] = val;
		printf("\nInserted %d at the index %d ......",BST[ptr],ptr);fflush(stdin);
		return;	
	}
	else{//Induction case
		if(BST[ptr] == val){
			printf("\nThe value to be inserted,  %d, already exists in the tree.",val);
			return;

		}
		else if(BST[ptr] > val){
			//insert in the left subtree
			insertA(BST,val,2*ptr+1);

		}
		else if(BST[ptr] < val){
			//insert in the right subtree
			insertA(BST,val,2*ptr+2);

		}
		else{
			printf("\nThere is an error...... exiting......\n");
			exit(0);
		}		
	}
	return;
}

//insert routine with BST implemented as array

void printA(int BST[],int ptr){
	if(BST[ptr]==-1){//Base case
		return;	
	}
	else{//Induction case
		printA(BST, 2*ptr+1);//move to the left subtree
		printf("%d --- index value -> %d\n",BST[ptr],ptr);fflush(stdin);
		printA(BST, 2*ptr+2);//move to the right subtree	
	}
	return;
}

