import java.io.*;
import java.util.*;
import java.util.ArrayList;
/*
 c) Write a program that reads a text file containing some technical content and identify the
technical terms and sort them alphabetically.
Note: use a file containing stop words (general English and Grammar terms as many as
possible) 

 */
public class q3 {
    static Boolean check(String a,String b){
        int l;
        if(a.length()<b.length()){
            l=a.length();
        }
        else{
            l=b.length();
        }
        for(int i=0;i<l;i++){
            if(a.charAt(i)<b.charAt(i)){
                return true;
            }
            else if(a.charAt(i)>b.charAt(i)){
                return false;
            }
            else{
                continue;
            }
        }
        return true;
    }
    public static void main(String[] args) throws IOException{
        FileReader a =new FileReader("text.txt");
        BufferedReader br = new BufferedReader(a);
        FileReader b =new FileReader("words.txt");
        BufferedReader br1 = new BufferedReader(b);
        ArrayList<String> al = new ArrayList<>();
        ArrayList<String> ret = new ArrayList<>();
        while(true){
            String k= br1.readLine();
            if(k!=null){
                for(String s : k.split(" ")){
                    al.add(s);
                }
            }
            else{
                break;
            }
        }
        br1.close();
        b.close();
        while(true){
            String k= br.readLine();
            if(k!=null){
                for(String s : k.split(" ")){
                    if(al.contains(s)){
                        ret.add(s);
                    }
                }
            }
            else{
                break;
            }
        }
        for(int i=0;i<ret.size();i++){
            for(int j=i;j<ret.size();j++){
                if(!check(ret.get(i), ret.get(j))){
                    String temp = ret.get(i);
                    ret.set(i,ret.get(j));
                    ret.set(j,temp);
                }
            }
        }
        System.out.println(ret);
        a.close();
        br.close();
    }
}
