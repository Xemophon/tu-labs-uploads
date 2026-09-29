import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;

public class ceto{

    private ArrayList<Medicine> expired(ArrayList<Medicine> list, String expiry){
        int exp_month, exp_year;
        var temp = new ArrayList<Medicine>();
        exp_month = Integer.parseInt(expiry.substring(0,2));
        exp_year = Integer.parseInt(expiry.substring(2,7));
        for(Medicine obj : list){
            int year,month;
            month = Integer.parseInt(obj.date.substring(0,2));
            year = Integer.parseInt(obj.date.substring(2,7));
            if(year<exp_year || year == exp_year && month<exp_month){
                temp.add(obj);
            }
        }
        if(temp.isEmpty()){
            return null;
        } else{
            return temp;
        }
    }

    private void remove_obj(ArrayList<Medicine> list, String sdate,String sname){
        boolean found = false;
        for(Medicine obj : list){
            if(obj.date.equals(sdate)&&obj.name.equals(sname)){
                found = true;
                list.remove(obj);
                break;
            }
        }
        if(!found){
            System.out.print("Not found");
        }
    }

    private int write_txt(ArrayList<Medicine> list,float min, float max){
        int count = 0;
        try (PrintWriter writer = new PrintWriter(new FileWriter("filename.txt", true))) {
            for(Medicine obj : list){
                if(obj.price > min && obj.price < max){
                    count++;
                    writer.println("ID: " + obj.id + 
                               " | Name: " + obj.name + 
                               " | Date: " + obj.date + 
                               " | Price: " + obj.price + 
                               " | Count: " + obj.count);
                }
            }
            System.out.println("Successfully appended to file.");
        }catch (IOException e) {
            System.out.println("Error writing file.");
        }
        return count;
    }

    public static void main(String[] args) {
        try (ObjectInputStream file = new ObjectInputStream(new FileInputStream("medicines.bin"))){
            @SuppressWarnings("unchecked")
            ArrayList<Medicine> med_list = (ArrayList<Medicine>) file.readObject();
        } catch (IOException e) {
            System.out.println("Error reading file.");
        } catch (ClassNotFoundException e){
            System.out.println("Error reading class.");
        }
    }

}

class Medicine{
    private static final long serialVersionUID = 1L;

    String name;
    String date;
    String id;
    float price;
    int count;

    Medicine(
        String new_name,
        String new_date,
        String new_id,
        float cost,
        int quantity
    ){
        name = new_name.substring(0,30);
        date = new_date.substring(0,7);
        id = new_id.substring(0,13);
        price = cost;
        count = quantity;
    }
}