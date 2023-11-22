import java.io.*;
import java.util.Scanner;

public class q1 {
    public static void main(String[] args) throws IOException{
        Scanner a = new Scanner(System.in);
        String f = a.next();
        File f1 = new File(f);

        FileInputStream b = new FileInputStream(f);

        FileOutputStream j = new FileOutputStream("b.txt");

        System.out.println("name of the file : "+f1.getName());
        System.out.println("path : "+f1.getAbsolutePath());
        System.out.println("path : "+f1.getParent());

        int alpha = 0;
        int nums=0;
        int other=0;

        while(true){
            int k = b.read();

            if(k==-1){
                break;
            }

            else if((k>=97 && k<=122)||(k>=65 && k<=90)){
                alpha++;
            }
            else if(k>=48 && k<=57){
                nums++;
            }
            else{
                other++;
            }
        }
        String li="alphabets"+alpha+"\n"+"numbers"+nums+"\n"+"other"+other;
        byte s[] = li.getBytes();
        j.write(s);
        j.close();
        b.close();
    }
}
