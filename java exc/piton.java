import java.util.Scanner;


public class piton{
    public void status_info(FoodDelivery[] order_list, int num){
        boolean found = false;
        for( FoodDelivery obj : order_list){
            if(obj.order_number == num){
                found = true;
                break;
            }
        }
        switch (found) {
            case true:
                System.out.println("Found");
                break;
            case false:
                System.out.println("Found");
                break;
        }
    }
    public FoodDelivery[] add_order(FoodDelivery[] order_list, FoodDelivery obj){
        FoodDelivery[] temp = new FoodDelivery[order_list.length + 1];
        temp[order_list.length] = obj;
        return temp;
    }
    public static void main(String[] args){

        //zad1
        int[] first_list = new int[20];
        Scanner reader = new Scanner(System.in);
        for (int i = 0; i < 20; i++) {
            String input = reader.nextLine();
            first_list[i] = Integer.parseInt(input);
        }
        reader.close();
        int min = first_list[0];
        int max = first_list[0];
        int odd = 0;
        int second_list_count = 0;
        for (int num : first_list) {
            if(min > num){
                min = num;
            }
            if(max < num){
                max = num;
            }
            if(num%2!=0){
                odd++;
            }
            if(num%5==0){
                second_list_count++;
            }
        }
        System.out.println(max+min);      
        int[] second_list = new int[second_list_count];
        int j = 0;
        for(int num : first_list){
            if(num%5==0){
                j++;
                second_list[j] = num;
            }
        }
        int max2 = second_list[0];
        int sum2 = 0;
        for(int num : second_list){
            sum2 += num;
            if(max2<num){
                max2 = num;
            }
        }
        float avg = sum2/second_list.length;
        float example = max2 - avg;
        int[] temp = new int[second_list_count+1];
        j = 0;
        for(int num : second_list){
            temp[j] = num;
            j++;
        }
        temp[j] = second_list[0] + second_list[second_list.length-1];
        //zad2

    }
}

class FoodDelivery{
    int order_number;
    String destination;
    float price;
    String delivery_term;
    String order_status;

    public FoodDelivery(
        int order_num,
        String dest,
        float cost,
        String delivery,
        int status
    ){
        String[] order_status_list = {
        "delivered",
        "delayed",
        "cancelled"
        };
        order_number = order_num;
        destination = dest;
        price = cost;
        delivery_term = delivery;
        if(status < 0 || status > 2){
            order_status = order_status_list[2];
        } else{
            order_status = order_status_list[status];
        }
    }

    public void order_info(){
        System.out.println(this.order_number+" "+this.destination+" "+this.price+" "+this.delivery_term+" "+this.order_status);
    }
    public void change_term(String new_time){
        this.delivery_term = new_time;
    }
}