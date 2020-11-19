import java.lang.*;
public class FoodBank {
    int food;
    public void FoodBank(int food) {
        this.food = food;
    }
    public void giveFood(int givenFood) {
        food = food + givenFood;
    }
    public void takeFood(int takenFood) {
        food = takenFood;
    }
}
public class FoodProducer extends Thread{
    FoodBank bank = new FoodBank();
    public void FoodProducer(FoodBank newBank) {
        bank = newBank;
    }
    @Override
    public void run() {
        while(true) {
            bank.food =+ 100 * Math.random();
        }
    }

}
public class FoodConsumer {
    FoodBank bank = new FoodBank();
    public void FoodProducer(FoodBank newBank) {
        bank = newBank;
    }
    @Override
    public void run() {
        while(true) {
            bank.food =- 100 * Math.random();
        }
    }
}
public class FoodBankPatrons {
    public static void main(String[] args) {
        FoodBank bank = new FoodBank();
        FoodProducer producer = new FoodProducer(bank);
        FoodConsumer consumer = new FoodConsumer(bank);

        Thread t;
        String threadName = "thread";
    }
}
