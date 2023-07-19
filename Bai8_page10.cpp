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
void OutputEven() {
	trav = head;
	if (trav == NULL) {
		printf("\nDanh sach rong.\n");
	} else {
		printf("\nCac gia tri chan trong danh sach:\n");
		while (trav != NULL) {
			if (trav->data % 2 == 0) {
				printf("-> %d", trav->data);
			}
			trav = trav->next;
		}
		printf("\n");
	}
}
int sumEven(){
    trav = head ;
    int sum = 0 ;
    while (trav != NULL){
        if (trav -> data % 2 == 0){
            sum += trav -> data ;
        }
        trav = trav -> next;
    }
    return sum ;
}
int timMax(){
    int max = head->data;
    node *trav = head;
    while(trav != NULL){
        if(trav->data > max){
            max = trav->data;
        }
        trav = trav->next;
    }
    return max;
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
		printf("\n4.Tong node");
		printf("\n5.Xuat cac so chan");
		printf("\n6.Tong cac so chan ");
		printf("\n7.Tim max");
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
			case 5:
				{
					OutputEven() ;
					break ;
				}
			case 6:
				{
					printf("\nTong cac so chan la: %d", sumEven());
					break ;
				}
			case 7:
				{
					printf("\nMax la: %d", timMax());
					break ;
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
