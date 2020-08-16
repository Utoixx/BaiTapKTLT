#include<stdio.h>

int luyThua(int a, int n){
    //Neu n=0 thi gia tri cua a^n=1
    if(n==0)
        return 1;
    else
        //Neu n=1 thi gia tri cua a^n=a
        //mat khac gia tri cua a^n=a^(n-1)*a;
        if(n==1)
            return a;
        else
            return a*luyThua(a,n-1);
        
}
int main(){
    //Khai bao bien a va b kieu nguyen
    int a;
    int b;
    //Nhap gia tri cho bien a va b
    printf("\nNhap a va b: ");
    scanf("%d %d", &a, &b);
    //Tinh gia tri cua a mu b
    printf("\nGia tri cua %d mu %d la %d", a, b, luyThua(a,b));
    return 0;
}