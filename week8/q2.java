import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

class data{
    String id;
    String name;
    String Cost;
    String quantity;
    data(String id,String name,String Cost,String quantity){
        this.id=id;
        this.name=name;
        this.Cost=Cost;
        this.quantity=quantity;
    }
    int sale(){
        return Integer.parseInt(Cost)*Integer.parseInt(quantity);
    }
    int demand(){
        return Integer.parseInt(quantity);
    }
    String re(){
        return id+","+name+","+Cost+","+quantity+"\n";
    }
}
public class q2 {
    public static void main(String[] args) throws IOException{
        FileReader a = new FileReader("a.csv");
        BufferedReader br = new BufferedReader(a);
        data[] d = new data[6];
        int i=0;
        while(true){
            String sr = br.readLine();
            if(sr==null){
                break;
            }
            String[] k=sr.split(",");
            d[i++] = new data(k[0],k[1],k[2],k[3]);
        }
        int total=0;
        for(int j=0;j<i;j++){
            total+=d[j].sale();
        }
        System.out.println(total);
        for(int j=0;j<i;j++){
            for(int u=j;u<i;u++){
                if(d[u].demand()>d[j].demand()){
                    data temp;
                    temp=d[u];
                    d[u]=d[j];
                    d[j]=temp;
                }
            }
        }
        a.close();
        br.close();
        FileWriter ret = new FileWriter("a.csv");
        for(int j=0;j<i;j++){
            ret.write(d[j].re());
        }
        ret.close();
        
    }
}
