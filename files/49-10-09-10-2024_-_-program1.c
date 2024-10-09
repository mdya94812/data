#include<stdio.h>
#include<stdlib.h>
int a[10],n;

void create(){
	system("clear");
	printf("\n---create---\n");
	printf("enter the no. of elements : ");
	scanf("%d",&n);

	for (int i=1;i<=n;i++){
		printf("enter the %d element : ",i);
		scanf("%d",&a[i-1]);
	}
	return;
}

void display(){
	system("clear");
	printf("\n---display---\n");
	for(int i=1;i<=n;i++){
		printf("the %d element is : %d \n",i,a[i-1]);
	}
	printf("Total elements in the arry is : %d \n",n);
	return;
}

void insert(){
	system("clear");
	display();
	printf("\n---insert---\n");
	int newElement,positionIndex;
	printf("enter the new element and it's position : ");
	scanf("%d%d",&newElement,&positionIndex);
	positionIndex=positionIndex-1;
	for(int i=(n-1);i>=positionIndex;i--){
		a[i+1]=a[i];
		}
	a[positionIndex]=newElement;
	n=n+1;
	display();
	return;
}

void delete(){
	system("clear");
	display();
	printf("\n---delete---\n");
	int deleteIndex;
	printf("enter the position of element to delete : ");
	scanf("%d",&deleteIndex);
	deleteIndex=deleteIndex-1;
	
	for (int i=deleteIndex;i<n;i++){
		a[i]=a[i+1];
	}
	n=n-1;
	display();
	return;
}

int main(){
int op;
printf("\n---start---\n");

while(1){
	printf("\n---menu---\n");
	printf("1 for create\n2 for display\n3 for insert\n4 for delete\nenter :");
	scanf("%d",&op);
switch(op){
	case 1:create();
		break;
	case 2:display();
		break;
	case 3:insert();
		break;
	case 4:delete();
		break;
	default :exit(0);
	}
	
}
return 0;
}
