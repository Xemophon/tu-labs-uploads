public class Spinka{
    public static void main(String[] args){
        Person kris = new Person("Krisi", 9.0f);
        kris.getName();
        kris.getWake();
        kris.doJob(3.6f);
    }
}

class Person extends StayAwake{
    private String name;
    
    Person(
        String name,
        float sleepDuration
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
            float sleepDuration
    ){
        this.currentWake = calculateRegen(sleepDuration);
    }

    protected float calculateRegen(float sleepDuration){
        return 9*wakeCoefficient/((1.0f-sleepDuration)*-1.0f);
    }

    protected float calculateExhaust(float job){
        return (wakeCoefficient/((1.0f-job)*-1.0f));
    }

    public void doJob(float hours){
        for(;hours>0.0f;hours--){
            this.currentWake -= hours;
        }
        this.getWake();
    }

    public void drinkCoffee(){
        this.currentWake += coffeeCoefficient;
        this.getWake();
    }

    public void sleep(boolean intentional, float hours){
        this.currentWake = wakeCoefficient/((1.0f-hours)*-1.0f);
        if(intentional){
            System.out.println("You are tight and warm in bed...");
        } else{
            System.out.println("You fell asleep on job...");
        }
        this.getWake();
    }

    public void getWake(){
        System.out.println(this.currentWake);
    }

}