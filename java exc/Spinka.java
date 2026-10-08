public class Spinka{
    public static void main(String[] args){
        Person kris = new Person("Krisi", 9);
        kris.getName();
        kris.getWake();
        kris.doJob(3.6f, 2.3f);
    }
}

class Person extends StayAwake{
    private String name;
    
    Person(
        String name,
        int sleepDuration
    ){
        super(sleepDuration);
        this.name = name;
    }

    public void getName(){
        System.out.println(this.name);
    }

    public void setName(String name){
        this.name = name;
    }
}


class StayAwake{
    protected final float wakeCoefficient = 100.0f;
    protected final float coffeeCoefficient = 10.0f;

    protected float currentWake;

    StayAwake(
            int sleepDuration
    ){
        this.currentWake = calculateRegen(sleepDuration);
    }

    protected final float calculateRegen(float sleepDuration){
        return wakeCoefficient + 100.0f*(9.0f-sleepDuration);
    }

    protected final float calculateExhaust(float job){
        return (wakeCoefficient/((1.0f-job)*-1.0f));
    }

    public void doJob(float hours, float jobCoefficient){
        for(;hours>0.0f;hours--){
            this.setWake(this.currentWake - hours*jobCoefficient);
        }
        this.getWake();
    }

    public void drinkCoffee(){
        this.setWake(this.currentWake + coffeeCoefficient);
        this.getWake();
    }

    public void sleep(boolean intentional, float hours){
        this.setWake(calculateRegen(hours));
        if(intentional){
            System.out.println("You are tight and warm in bed...");
        } else{
            System.out.println("You fell asleep on job...");
        }
        this.getWake();
    }

    public void getWake(){
        System.out.printf("%.2f\n", this.currentWake);
    }

    public void setWake(float value){
        this.currentWake = (value<wakeCoefficient) ? value : 100.0f;
    }

}