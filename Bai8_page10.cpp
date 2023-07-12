#include <stdio.h>
#include <stdlib.h>
int count = 0 ;
struct node
{
	int data ;
	node *next;
};
node *head, *newn, *trav ;
void create_list(){
	int value ;
	struct node *temp;
	temp=head ;
	newn =(struct node*)malloc(sizeof(struct node));
	printf("\n Nhap gia tri phan tu: ");
	scanf("%d", &value);
	newn -> data=value ;
	if(head == NULL){
		head = newn;
		head -> next = NULL ;
		count ++ ;
	}
	else {
		while(temp -> next !=NULL)
		{
			temp= temp-> next ;
		}
		temp -> next = newn ;
		newn -> next = NULL;
		count ++ ;
	}
}
void add_FList(int value){
	newn =(struct node*)malloc(sizeof(struct node));
	newn -> data =value ;
	if(head == NULL)
	{
		head = newn ;
		head -> next = NULL;
		count ++;
	}
	else {
		newn -> next = head ;
		head = newn ;
		count ++;
	}
}
void add_LList(int value){
	newn =(struct node*)malloc(sizeof(struct node));
	struct node* temp;
	temp = head ;
	newn -> data = value ;
	if(head == NULL){
		head = newn ;
		head -> next = NULL ;
		count ++ ;
	}
	else {
		while (temp -> next != NULL)
		{
			temp = temp -> next ;
		}
		temp -> next = newn ;
		newn -> next = NULL ;
		count ++ ;
	}
}
int SumOfNode(){
	node* temp = head ;
	int s= 0;
	while(temp != NULL){
		s += temp -> data ;
		temp = temp -> next ;
	}
	return s ;
}
int display(){
	trav = head ;
	if(trav == NULL)
	{
		printf("\n list is empty \n");
		return 0;
	}
	else
	{
		printf("\n So phan tu cua danh sach la %d: \n", count);
		while(trav!= NULL){
			printf(" ->%d", trav -> data);
			trav = trav -> next ;
		}
			printf("\n");
	}
}
int main()
{
	int ch=0;
	char ch1;
	
	head=NULL;
	while(1)
	{
		printf("\n1.Tao danh sach");
		printf("\n2.ADD First");
		printf("\n3.ADD Last");
		printf("\n4.Them giua");
		printf("\n5.");
		printf("\n6. ");
		printf("\n7.");
		printf("\n8.Xuat danh dach");
		printf("\n9.exit\n");
		printf("\nLua chon:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				do{
					create_list();
					display();
					printf("Tiep tuc tao danh sach? ,y / n ");
					getchar();
					scanf("%c",&ch1);
				}while(ch1=='y');
				
				break;
			}
			case 2:
			{
				int value;
				printf("\nNhap gia tri muon them vao dau DS:");
				scanf("%d",&value);
				add_FList(value);
				display();
				break;
			}
			case 3:
				{
					int value ;
					printf("\nNhap gia tri muon them vao cuoi DS:");
					scanf("%d", &value);
					add_LList(value);
					display();
					break;
				}
			case 4:
				{
					printf("Tong cua cac node la: %d\n", SumOfNode());
	                break;
				}
			case 9:
			{
				exit(1);
			}
			default:printf("\n****Chon sai****\n");
		}
	}
	getchar();
}
