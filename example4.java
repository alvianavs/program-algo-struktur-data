import java.util.*;

public class example4 {
    
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
        int jumlah, lusin, satuan, hasil;
        int perLusin = 36000;
        int perItem = 3000;

        System.out.print("Masukkan jumlah botol yang ingin dibeli : ");
        jumlah = sc.nextInt();

        lusin = jumlah / 12;
        satuan = jumlah % 12;
        if (lusin > 0) {
            perLusin = perLusin * lusin;
        }
        if (satuan > 0) {
            perItem = perItem * satuan;
        }
        hasil = perLusin + perItem;
        System.out.println("Anda memesan " + jumlah + " Botol");
        System.out.println("Berarti anda memesan " + lusin + " Lusin + " + satuan + " Botol");
        System.out.println(lusin + " Lusin : Rp. " + perLusin);
        System.out.println(satuan + " Botol : Rp. " + perItem);
        System.out.println("Jadi totalnya adalah Rp." + hasil);

    }
    
}