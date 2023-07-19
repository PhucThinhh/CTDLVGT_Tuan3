#include <stdio.h>
#include <stdlib.h>
int count = 0 ;
struct node
{
	int data ;
	node *next;
};
node *head, *newn, *trav ;
//tao danh sach !!!
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
//them phan tu vao dau ds !!!
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
//them phan tu vao cuoi ds !!!
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
//Tong phan tu!!!
int SumOfNode(){
	node* temp = head ;
	int s= 0;
	while(temp != NULL){
		s += temp -> data ;
		temp = temp -> next ;
	}
	return s ;
}
//Xuat so chan!!!
void OutputEven() {
	trav = head;
	if (trav == NULL) {
		printf("\nDanh sach rong.\n");
	} else {
		printf("\nCac gia tri chan trong danh sach:\n");
		while (trav != NULL) {
			if (trav->data % 2 == 0) {
				printf("->%d ", trav->data);
			}
			trav = trav->next;
		}
		printf("\n");
	}
}
//Tong chan!!!
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
//xuat so le!!!
void OutputOdd() {
    node *temp = head;
    bool foundOdd = false;

    while (temp != NULL) {
        if (temp->data % 2 != 0) {
            printf("->%d ", temp->data);
            foundOdd = true;
        }
        temp = temp->next;
    }

    if (!foundOdd) {
        printf("Khong tim thay so le trong danh sach.");
    }

    printf("\n");
}
//Tong le!!!
int sumOdd() {
    int sum = 0;
    node *temp = head;

    while (temp != NULL) {
        if (temp->data % 2 != 0) {
            sum += temp->data;
        }
        temp = temp->next;
    }

    return sum;
}
//Tim Max
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
//timMin
int timMin() {
    if (head == NULL) {
        printf("Danh sach rong.\n");
        return 0;
    }

    int min = head->data;
    node *temp = head->next;

    while (temp != NULL) {
        if (temp->data < min) {
            min = temp->data;
        }
        temp = temp->next;
    }

    return min;
}
//Xoa phan tu nho nhat !!!
void deleteSmallest() {
    if (head == NULL) {
        printf("Danh sach rong, khong the xoa.\n");
        return;
    }

    node *minNode = head;
    node *prevMinNode = NULL;
    node *temp = head->next;
    while (temp != NULL) {
        if (temp->data < minNode->data) {
            minNode = temp;
            prevMinNode = prevMinNode == NULL ? head : prevMinNode->next;
        }
        temp = temp->next;
    }

    if (prevMinNode == NULL) {
        // N?u ph?n t? nh? nh?t l� ph?n t? d?u ti�n
        head = head->next;
        free(minNode);
    } else {
        prevMinNode->next = minNode->next;
        free(minNode);
    }

    count--;
    printf("Da xoa phan tu nho nhat trong danh sach.\n");
}

//Xoa phan tu lon nhat !!!
void deleteLargest() {
    if (head == NULL) {
        printf("Danh sach rong, khong the xoa.\n");
        return;
    }
    node *maxNode = head;
    node *prevMaxNode = NULL;
    node *temp = head->next;
    while (temp != NULL) {
        if (temp->data > maxNode->data) {
            maxNode = temp;
            prevMaxNode = head;
        } else if (temp->data == maxNode->data) {
            prevMaxNode = temp;
        }
        temp = temp->next;
    }
    if (prevMaxNode == NULL) {
        // N?u ph?n t? l?n nh?t l� ph?n t? d?u ti�n
        head = head->next;
        free(maxNode);
    } else {
        prevMaxNode->next = maxNode->next;
        free(maxNode);
    }
    count--;
    printf("Da xoa phan tu lon nhat trong danh sach.\n");
}
// Tim so nguyen to!!!
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
//Dem so luong so nguyen to !!!
int countPrimes() {
    int count = 0;
    node *temp = head;

    while (temp != NULL) {
        if (isPrime(temp->data)) {
            count++;
        }
        temp = temp->next;
    }

    return count;
}
//Xoa phan tu dau tien !!!
void deleteFirst() {
    if (head == NULL) {
        printf("Danh sach rong, khong the xoa.\n");
        return;
    }

    node *temp = head;
    head = head->next;
    free(temp);
    count--;

    printf("Da xoa phan tu dau tien trong danh sach.\n");
}
void deleteLast() {
    if (head == NULL) {
        printf("Danh sach rong, khong the xoa.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        count--;
        printf("Da xoa phan tu cuoi cung trong danh sach.\n");
        return;
    }

    node *prev = NULL;
    node *temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    count--;

    printf("Da xoa phan tu cuoi cung trong danh sach.\n");
}
//Xoa phan tu X !!!
void deleteElement(int value) {
    if (head == NULL) {
        printf("Danh sach rong, khong the xoa.\n");
        return;
    }

    if (head->data == value) {
        node *temp = head;
        head = head->next;
        free(temp);
        count--;
        printf("Da xoa phan tu dau tien trong danh sach.\n");
        return;
    }

    node *prev = NULL;
    node *temp = head;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Khong tim thay phan tu co gia tri can xoa trong danh sach.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    count--;

    printf("Da xoa phan tu co gia tri %d trong danh sach.\n", value);
}
//Xoa phan tu dung sau X !!!
void deleteAfterX(int value) {
    if (head == NULL || head->next == NULL) {
        printf("Khong co phan tu de xoa sau phan tu X.\n");
        return;
    }

    node *temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Khong tim thay phan tu co gia tri X trong danh sach hoac khong co phan tu sau phan tu X.\n");
        return;
    }

    node *toBeDeleted = temp->next;
    temp->next = toBeDeleted->next;
    free(toBeDeleted);
    count--;

    printf("Da xoa phan tu sau phan tu co gia tri X trong danh sach.\n");
}
//Xoa phan tu truoc X !!!
void deleteBeforeX(int value) {
    if (head == NULL || head->next == NULL) {
        printf("Khong co phan tu de xoa truoc phan tu X.\n");
        return;
    }

    if (head->data == value) {
        printf("Khong co phan tu dung truoc phan tu X.\n");
        return;
    }

    node *temp = head->next;
    node *prev = head;
    node *prevPrev = NULL;

    while (temp != NULL && temp->data != value) {
        prevPrev = prev;
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Khong tim thay phan tu co gia tri X trong danh sach.\n");
        return;
    }

    if (prev == head) {
        head = temp;
    } else {
        prevPrev->next = temp;
    }
    free(prev);
    count--;

    printf("Da xoa phan tu dung truoc phan tu co gia tri X trong danh sach.\n");
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
		printf("\n4.Tong phan tu trong danh sach");
		printf("\n5.Xuat cac so chan");
		printf("\n6.Tong cac so chan ");
		printf("\n7.Xuat cac so le");
		printf("\n8.Tong cac so le");
		printf("\n9.Tim max");
		printf("\n10.Tim min");
		printf("\n11.Xoa phan tu nho nhat");
		printf("\n12.Xoa phan tu lon nhat");
		printf("\n13.Tim so nguyen to");
		printf("\n14.Dem so nguyen to");
		printf("\n15.Xoa phan tu dau tien");
		printf("\n16.Xoa phan tu cuoi cung");
		printf("\n17.Xoa phan tu X");
		printf("\n18.Xoa phan tu sau X");
		printf("\n18.Xoa phan tu truoc X");


//		printf("\n15.Xuat danh dach");
//		printf("\n16.exit\n");
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
					printf("Tong cua cac phan tu la: %d\n", SumOfNode());
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
                	OutputOdd();
					break;
			}
			case 8: 
			{
                    int sum = sumOdd();
                    printf("Tong cac so le trong danh sach: %d\n", sum);
                    break;
            }
			case 9:
			{
					printf("\nMax la: %d", timMax());
					break ;
			}
			case 10: 
			{
                    int min = timMin();
                    printf("Phan tu nho nhat trong danh sach: %d\n", min);
                    break;
            }
            case 11: 
			{
                    deleteSmallest();
                    display(); // Hi?n th? l?i danh s�ch sau khi x�a ph?n t? nh? nh?t
                    break;
            }
            case 12: 
			{
                    deleteLargest();
                    display(); // Hi?n th? l?i danh s�ch sau khi x�a ph?n t? l?n nh?t
                    break;
            }
            case 13:
			{
					node *temp = head;
                    printf("\nCac so nguyen to trong danh sach:\n");
                    bool foundPrime = false;

                    while (temp != NULL) {
                    if (isPrime(temp->data)) {
                    printf("->%d ", temp->data);
                    foundPrime = true;
                      }
                    temp = temp->next;
                     }

                    if (!foundPrime) {
                    printf("Khong tim thay so nguyen to trong danh sach.");
                     }
                    printf("\n");
                    break;
			}
			case 14: 
			{
                    int count = countPrimes();
                    printf("So luong so nguyen to trong danh sach: %d\n", count);
                    break;
            }
           case 15: 
		    {
                    deleteFirst();
                    display(); // Hi?n th? l?i danh s�ch sau khi x�a ph?n t? d?u ti�n
                    break;
            }
            case 16: 
			{
                    deleteLast();
                    display(); // Hi?n th? l?i danh s�ch sau khi x�a ph?n t? cu?i c�ng
                    break;
            }
            case 17: 
			{
                    int value;
                    printf("Nhap gia tri phan tu muon xoa: ");
                    scanf("%d", &value);
                    deleteElement(value);
                    display(); // Hi?n th? l?i danh s�ch sau khi x�a ph?n t? du?c ch?n
                    break;
            }
            case 18: 
			{
                int value;
                printf("Nhap gia tri cua phan tu X: ");
                scanf("%d", &value);
                deleteAfterX(value);
                display(); // Hi?n th? l?i danh s�ch sau khi x�a ph?n t? d?ng sau X
                break;    
            }
            case 19: 
			{
                int value;
                printf("Nhap gia tri cua phan tu X: ");
                scanf("%d", &value);
                deleteBeforeX(value);
                display(); // Hi?n th? l?i danh s�ch sau khi x�a ph?n t? d?ng tru?c X
                break;
            }

//			case 15:{
//				    display();
//				    break;
//			}
//			
//			case 16:
//			{
//				    exit(1);
//			}
			default:printf("\n****Chon sai****\n");
		}
	}
	getchar();
}
