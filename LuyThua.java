import java.util.Scanner;

class LuyThua{
    //Class gom 2 thuoc tinh la So nguyen a va So nguyen b
    private int a;
    private int b;

    public LuyThua(int a, int b){
        this.a=a;
        this.b=b;
    }
    public LuyThua(){

    }
    //Phuong thuc tinh gia tri cua a mu b
    public int luy_thua() {
        int value=1;
        for(int i=0; i<b; i++){
            value*=a;
        }
        return value;
    }
    //Phuong thuc nhap gia tri cho a va b
    public void nhapGiaTri(){
        Scanner sc= new Scanner(System.in);
        System.out.println("Nhap gia tri cua a: ");
        a=sc.nextInt();
        System.out.println("Nhap gia tri cua b: ");
        b=sc.nextInt();
        sc.close();
    }
    public static void main(String[] args){
        LuyThua lt= new LuyThua();
        lt.nhapGiaTri();
        System.out.println("Gia tri cua a mu b = "+lt.luy_thua());
    }
}