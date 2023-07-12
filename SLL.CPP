
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int count=0;
struct node
{
	int data;
	struct node *next;
}*head,*newn,*trav;
//----------------------------------------------------------
void create_list()
{
	int value;
	struct node *temp;
	temp=head;
	newn=(struct node *)malloc(sizeof (struct node));
	printf("\Nhap gia tri:");
	scanf("%d",&value);
	newn->data=value;
	if(head==NULL)
	{
		head=newn;
		head->next=NULL;
		count++;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
		newn->next=NULL;
		count++;
	}
}
//----------------------------------------------------
void insert_at_begning(int value)
{
	newn=(struct node *)malloc(sizeof (struct node));
	newn->data=value;
	if(head==NULL)
	{
		head=newn;
		head->next=NULL;
		count++;
	}
	else
	{
		newn->next=head;
		head=newn;
		count++;
	}
}
//----------------------------------------------------------
void insert_at_end(int value)
{
	struct node *temp;
	temp=head;
	newn=(struct node *)malloc(sizeof (struct node));
	newn->data=value;
	if(head==NULL)
	{
		head=newn;
		head->next=NULL;
		count++;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
		newn->next=NULL;
		count++;
	}
}
//------------------------------------------------------
int insert_at_middle()
{
	if(count>=2)
	{
		struct node *var1,*temp;
		int loc,value;
		printf("\n Gia tri muon tim (k): ");
		scanf("%d",&loc);
		printf("\nNhap gia tri muon them vao sau k:");
		scanf("%d",&value);
		newn=(struct node *)malloc(sizeof (struct node));
		newn->data=value;
		temp=head;
		while(temp->data!=loc)
		{
			temp=temp->next;
			if(temp==NULL)
			{
				printf("\nSORRY...khong tim thay %d",loc);
				return 0;
			}
		}
		newn->next=temp->next;//var1;
		temp->next=newn;
		
		count++;

	}
	else
	{
		printf("\nSo node phai >=2");
	}
}
//------------------------------------------------------
int display()
{
	trav=head;
	if(trav==NULL)
	{
		printf("\nDanh sach rong\n");
		return 0;
	}
	else
	{
		printf("\n\nSo phan tu cua danh sach la %d:\n",count);
		while(trav!=NULL)
		{
			printf(" -> %d ",trav->data);
			trav=trav->next;
		}
		printf("\n");
	}
}
//---------------------------------------------------------------
int main()
{
	int ch=0;
	char ch1;
	
	head=NULL;
	while(1)
	{
		printf("\n1.Tao danh sach");
		printf("\n2.Them dau");
		printf("\n3.Them cuoi");
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
				printf("\nNhap gia tri muon chen them vao dau danh sach:");
				scanf("%d",&value);
				insert_at_begning(value);
				display();
				break;
			}
			case 3:
			{
				int value;
				printf("\nNhap gia tri muon chen them vao cuoi danh sach:");
				scanf("%d",&value);
				insert_at_end(value);
				display();
				break;
			}
			case 4:
			{
				insert_at_middle();
				display();
				break;
			}
			case 5:	
			case 6:
			case 7:
			case 8:
			{
				display();
				break;
			}
			case 9:
			{
				exit(1);
			}
			default:printf("\n****Chon sai****\n");
		}
	}
	getch();
}
