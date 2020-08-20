#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<conio.h>
typedef struct {
	char hoTen[50];
	char maNV[10];
	int luong;
}nhanVien;

struct node{
	nhanVien data;
	struct node *next;
};
typedef struct node NODE;

typedef struct{
	NODE *pHead;
	NODE *pTail;
}list;

void createEmptyList(list &l){
	l.pHead=l.pTail=NULL;
}

NODE *getNode(){
	NODE *pNode;
	pNode=(NODE*)malloc(sizeof(NODE));
	if(pNode==NULL){
		printf("Loi cap phat bo nho!");
		return NULL;
	}
	printf("\nNhap ho ten nhan vien: ");
	fflush(stdin);
	gets(pNode->data.hoTen);
	printf("\nMa nhan vien: ");
	fflush(stdin);
	gets(pNode->data.maNV);
	printf("\nLuong: ");
	fflush(stdin);
	scanf("%d",&pNode->data.luong);
	return pNode;
}
void addNode(list &l){
	if(l.pHead==NULL){
		l.pHead=getNode();
		l.pTail=l.pHead;
		l.pTail->next=NULL;
	}else{
		l.pTail->next=getNode();
		l.pTail=l.pTail->next;
		l.pTail->next=NULL;
	}
}
void printList(list l){
	NODE *pNode;
	if(l.pHead==NULL){
		printf("\nDanh sach rong!");
		return ;
	}
	pNode=l.pHead;
	while(pNode!=NULL){
		printf("\nMaNV: %s, Hoten: %s, Luong: %d",pNode->data.maNV,pNode->data.hoTen,pNode->data.luong);
		pNode=pNode->next;
	}
}
void sortByID(list &l){
	if(l.pHead==NULL){
		printf("\nDanh sach rong!");
		return ;
	}
	NODE *pNode;
	NODE *qNode;
	pNode=l.pHead;
	while(pNode->next!=NULL){
		qNode=pNode->next;
		while(qNode!=NULL){
			if(strcmp(qNode->data.maNV,pNode->data.maNV)!=1){
				nhanVien tmp;
				tmp=pNode->data;
				pNode->data=qNode->data;
				qNode->data=tmp;
			}
			qNode=qNode->next;
		}
		pNode=pNode->next;
	}
}
void menu(){
	printf("\nChon 1 de Nhap danh sach nhan vien!");
	printf("\nChon 2 de Hien thi danh sach nhan vien!");
	printf("\nChon 3 de Sap xem danh sach nhan vien theo ma nhan vien!");
	printf("\nChon 4 de ket thuc!\n");
}
int main(){
	char selection;
	list nhanVien;
	createEmptyList(nhanVien);
	while(1){
		menu();
		fflush(stdin);
		selection=getche();
		switch(selection){
			case '1':
				while(1){
					int choice;
					addNode(nhanVien);
					printf("\nBan co muon nhap tiep khong(y/n)?");
					choice=getche();
					if(choice=='n')
						break;
				}
				break;
			case '2':
				printList(nhanVien);
				break;
			case '3':
				sortByID(nhanVien);
				printf("\nDanh sach sau khi sap xep la:\n");
				printList(nhanVien);
				break;
		}
		if(selection=='4')
			break;
	}
	return 1;
}
