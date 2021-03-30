import java.util.*;

public class example2{
    public final static char kode = 'R';
    public final static double rupiah = 13000;

	private char darike;
    private String pesan;
    private double nilai;
    private double nilaihasil;

    public void setDari(char uang){
        darike = uang;
    }

    public void setNilai(double nilaikonversi){
        nilai = nilaikonversi;
    }

    public double getNilai(){
        return nilai;
    }

    public String getPesan(){
        if(darike == kode){
            return pesan = "Konversi dari Rupiah ke Dollar";
        }
        else{
            return pesan = "konversi dari Dollar ke Rupiah";
        }
    }

    public double getNilaiKonversi(){
        if(darike == kode || darike == 'r'){
            nilaihasil= nilai / rupiah;
        }
        else if(darike == 'D' || darike == 'd'){
            nilaihasil= nilai * rupiah;
        }
        return nilaihasil;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        example2 konv = new example2();

        System.out.println("R untuk conversi Rupiah ke Dollar, D untuk Conversi Dollar ke Rupiah");
        char inputkode = sc.next().charAt(0);
        konv.setDari(inputkode);
        System.out.print("Masukkan nilai yang akan di konversi : ");
        double inputnilai = sc.nextDouble();

        konv.setNilai(inputnilai);

        System.out.println();
        System.out.println(konv.getPesan());
        System.out.println("Nilai yang akan dikonversi : " + konv.getNilai());
        System.out.println("Hasil Konversi : " + konv.getNilaiKonversi());

        System.out.println("Press enter to exit...");
        sc.next();
        System.exit(1);
        

    }
}