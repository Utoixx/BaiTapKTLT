import java.util.Scanner;
import java.util.ArrayList;
class Nhan_vien{
    String manv;
    String hoTen;

    public String getManv() {
        return manv;
    }

    public void setManv(String manv) {
        this.manv = manv;
    }

    public String getHoTen() {
        return hoTen;
    }

    public void setHoTen(String hoTen) {
        this.hoTen = hoTen;
    }

    public int getThamNien() {
        return thamNien;
    }

    public void setThamNien(int thamNien) {
        this.thamNien = thamNien;
    }
    int thamNien;

    void show(){
        System.out.println("Ma nhan vien: "+manv+", Ten nhan vien: "+hoTen+", Tham nien: "+thamNien);
    }
    void setNhanVien(){
        Scanner sc= new Scanner(System.in);
        System.out.println("\nNhap ma nhan vien: ");
        manv=sc.nextLine();
        System.out.println("Ten nhan vien: ");
        hoTen=sc.nextLine();
        System.out.println("Tham nien: ");
        thamNien=sc.nextInt();
    }
}
public class BaiKT{
    public BaiKT(){
     }
    ArrayList<Nhan_vien> list= new ArrayList<Nhan_vien>();
    //Hien thi danh sach nhan vien
    public void showList(){
        for(int i=0; i<list.size(); i++){
            list.get(i).show();
        }
    }
    public void addToList(){
        String selection;
        Scanner sc= new Scanner(System.in);
        while(true){
            Nhan_vien nv= new Nhan_vien();
            nv.setNhanVien();
            list.add(nv);
            System.out.println("Ban co muon nhap tiep khong?(y/n)");
            selection=sc.nextLine();
            if(selection.equals("n"))
                break;
        }
    }
    public void showThamNien(){
        for(int i=0; i<list.size(); i++){
            if(list.get(i).getThamNien()>10)
                list.get(i).show();
        }
    }
    public void menu(){
        System.out.println("Chon chuc nang:");
        System.out.println("Chon 1 de nhap danh sach nhan vien!");
        System.out.println("Chon 2 de hien thi danh sach nhan vien!");
        System.out.println("Chon 3 de hien thi danh sach nhan vien tham nien 10 nam!");
        System.out.println("Chon 4 de ket thuc!");
    }
    public static void main(String[] args){
        Scanner scan= new Scanner(System.in);
        BaiKT nv= new BaiKT();
        int selection;
        while(true){
            nv.menu();
            selection=scan.nextInt();
            switch(selection){
                case 1:
                    nv.addToList();
                    break;
                case 2:
                    nv.showList();
                    break;
                case 3:
                    nv.showThamNien();
                    break;
            }
            if(selection==4)
                break;
        }
    }
}