#include<stdio.h>
#include<malloc.h>
#include<conio.h>

//Dinh nghia 1 struct
struct so_nguyen{
    //Du lieu cua struct
    int a;
    int b;
};
typedef struct so_nguyen soNguyen;

//Dinh nghia 1 node
struct node{
    soNguyen data;
    struct node *next;
};
typedef struct node NODE;

//Dinh nghia 1 danh sach
typedef struct{
    NODE *pHead;
    NODE *pTail;
}list;

//Tao mot danh sach lien ket rong
void createEmptyList(list &l){
    l.pHead=l.pTail=NULL;
}

//Tao 1 node
NODE *getNode(){
    NODE *pNode;
    pNode=(NODE*)malloc(sizeof(NODE));
    if(pNode==NULL){
        printf("\nLoi cap phat bo nho!");
        return NULL;
    }
    printf("\nNhap so a: ");
    scanf("%d",&pNode->data.a);
    printf("\nNhap so b: ");
    scanf("%d",&pNode->data.b);

    return pNode; 
}
//Them 1 node vao trong danh sach
void addNode(list &l){
    //Neu danh sach rong thi them vao dau
    if(l.pHead==NULL){
        l.pHead=getNode();
        l.pTail=l.pHead;
        l.pTail->next=NULL;
    }else{//Neu danh sach khong rong thi them vao cuoi
        l.pTail->next=getNode();
        l.pTail=l.pTail->next;
        l.pTail->next=NULL;
    }
}
//Hien thi danh sach lien ket
void show(list l){
    NODE *pNode;
    if(l.pHead==NULL){
        printf("\nDanh sach lien ket rong!");
        return;
    }
    pNode=l.pHead;
    while(pNode!=NULL){
        printf("\n a= %d, b= %d", pNode->data.a, pNode->data.b);
        pNode=pNode->next;
    }
}
//Tim kiem trong danh sach
void search(list l){
    int a;
    if(l.pHead==NULL){
        printf("\nDanh sach lien ket rong!");
        return;
    }else{
        printf("\nNhap gia tri cua a: ");
        fflush(stdin);
        scanf("%d",&a);
        NODE *pNode;
        pNode=l.pHead;
        while(pNode!=NULL){
            if(pNode->data.a==a)
                printf("\nGia tri tim duoc a=%d, b=%d",pNode->data.a,pNode->data.b);
            pNode=pNode->next;
        }
    }
}
int main(){
    char selection;
    //Tao mot danh sach
    list ds;
    createEmptyList(ds);
    //Them du lieu vao trong danh sach
    while(1){
        addNode(ds);
        printf("\nBan co muon nhap tiep khong?(y/n)");
        fflush(stdin);
        selection=getche();
        if(selection=='n')
        break;
    }
    //Hien thi danh sach
    show(ds);
    //Tim kiem trong danh sach theo a
    search(ds);

    return 0;
}
