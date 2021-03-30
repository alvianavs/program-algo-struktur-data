import java.util.ArrayList;
import java.util.List;
import java.util.*;

public class example3 {
    
    public static void main(String[]args){
        int no, benar = 0, salah = 5;
        List<String> asean = new ArrayList<>();
        List<String> jawab = new ArrayList<>();
        asean.add("Indonesia");
        asean.add("Singapura");
        asean.add("Malaysia");
        asean.add("Brunei");
        asean.add("Kamboja");
        asean.add("Vietnam");
        asean.add("Thailand");
        asean.add("Laos");
        asean.add("Myanmar");
        asean.add("Filipina");

        Scanner sc = new Scanner(System.in);
        
        System.out.println("Tebak Negara - Negara ASEAN");
        for (int i = 0; i < 5; i++){
            no = i + 1;
            System.out.print("Masukkan Nama Negara ke-[" + no + "] : ");
            jawab.add(sc.nextLine());
        }
        for (int j = 0; j < jawab.size(); j++)
        {
            for(int k = 0; k < asean.size(); k++) {
                if (jawab.get(j).equals(asean.get(k))){
                    benar++;
                }
            }
        }
        salah = salah - benar;
        System.out.println("Hasil : ");
        System.out.println("Benar " + benar + " negara");
        System.out.println("Salah " + salah + " negara");

    }
    
}