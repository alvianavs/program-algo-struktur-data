import java.util.*;

public class example {
    
    public static void main(String[]args){
        String[] provinsi = new String[2];
        Scanner sc = new Scanner(System.in);
        
        for(int i=0; i<provinsi.length;i++){
            System.out.print("Masukkan Nama Provinsi : ");
            provinsi[i] = sc.nextLine();
        }
        System.out.println("Hasil : ");
        for (int j = 0; j < provinsi.length; j++)
        {
            System.out.println("Posisi ke " + j + " adalah : " + provinsi[j]);
        }
    }
    
}