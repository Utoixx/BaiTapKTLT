#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<conio.h>

//Tao struct sach
typedef struct{
    int maSach;
    char tenSach[100];
    char tacGia[100];
    int nhaXB;
}sach;

//Tao struct node
struct node{
    sach data;
    node *next;
};
typedef struct node NODE;

//Tao struc list dung de luu danh sach sinh vien
typedef struct{
    NODE *pHead;
    NODE *pTail;
}list;

//Ham khoi tao danh sach
void createEmptyList(list &l){
    l.pHead=l.pTail=NULL;
}

//Ham lay du lieu cho 1 node
NODE *getNode(){
    NODE *pNode;
    pNode=(NODE*)malloc(sizeof(NODE));
    printf("\nNhap ma sach:");
    scanf("%d",&pNode->data.maSach);
    printf("\nTen sach: ");
    fflush(stdin);
    gets(pNode->data.tenSach);
    printf("\nTac gia: ");
    fflush(stdin);
    gets(pNode->data.tacGia);
    printf("\nNha xuat ban: ");
    scanf("%d",&pNode->data.nhaXB);
    return pNode;
}
//Ham kiem tra ma sach da ton tai trong danh sach chua
int checkID(list l, int id){
    int check=1;
    NODE *pNode;
    pNode=l.pHead;
    while(pNode!=NULL){
        if(pNode->data.maSach==id){
            check=0;
            break;
        }
        pNode=pNode->next;
    }
    return check;
}
//Them sach vao trong danh sach
void addToList(list &l){
    NODE *pNode;
    pNode=getNode();
    //Neu ma sach da ton tai thi khong them vao danh sach
    while(checkID(l,pNode->data.maSach)!=1){
        printf("Ma sach bi trung, vui long nhap lai!");
        pNode=getNode();
    }
    //Neu danh sach rong thi them vao dau danh sach, nguoc lai them vao cuoi danh sach
    if(l.pHead==NULL){
        l.pHead=pNode;
        l.pTail=l.pHead;
        l.pTail->next=NULL;
    }else{
        l.pTail->next=pNode;
        l.pTail=l.pTail->next;
        l.pTail->next=NULL;
    }

}
//Hien thi danh sach
void showList(list l){
    NODE *pNode;
    pNode=l.pHead;
    if(pNode==NULL){
        printf("\nDanh sach rong!");
        return ;
    }
    printf("\nDanh sach dach:");
    while(pNode!=NULL){
         printf("\nMa sach: %-10d Ten sach: %-30s Tac gia: %-30s Nha XB: %-30d",pNode->data.maSach,pNode->data.tenSach,pNode->data.tacGia,pNode->data.nhaXB);
        pNode=pNode->next;
    }
    printf("\n---------------------------------------------");
}
//Ham hien thi sach cua 1 nha xuat ban
void hienThiSachNXB(list l){
    //Ten nha xuat ban
    int name_nhaXB;
    //So luong sach nha xuat ban
    int countBook=0;
    printf("\nHien thi sach cua nha xuat ban: ");
    scanf("%d",&name_nhaXB);
    NODE *pNode;
    pNode=l.pHead;
    printf("Cac dau sach cua nha xuat ban %d",name_nhaXB);
    while(pNode!=NULL){
        if(pNode->data.nhaXB==name_nhaXB){
            countBook+=1;
            printf("\nMa sach: %-10d Ten sach: %-30s Tac gia: %-30s Nha XB: %-30d",pNode->data.maSach,pNode->data.tenSach,pNode->data.tacGia,pNode->data.nhaXB);
        }
        pNode=pNode->next;
    }
    printf("\nTong so sach cua nha xuat ban %d la %d",name_nhaXB,countBook);
    printf("\n---------------------------------------------");
}
//Menu
void menu(){
    printf("\nChon chuc nang:");
    printf("\nChon 1 de tao danh muc sach!");
    printf("\nChon 2 de hien thi danh sach!");
    printf("\nChon 4 de hien thi ds sach theo NXB!");
    printf("\nChon 3 de ket thuc!\n");
}
int main(){
    char selection;
    list bookList;
    createEmptyList(bookList);
    while(1){
        menu();
        selection=getche();
        switch(selection){
            case '1':
                while(1){
                    addToList(bookList);
                    char choice;
                    printf("\nBan co muon nhap tiep khong?(y/n)");
                    fflush(stdin);
                    choice=getche();
                    if(choice=='n')
                        break;
                }
                break;
            case '2':
                showList(bookList);
                break;
            case '4':
                hienThiSachNXB(bookList);
                break;
        }
        if(selection=='3')
            break;
    }
    return 0;
}
