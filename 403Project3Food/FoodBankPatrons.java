import java.lang.*;
import java.util.concurrent.Semaphore;
class FoodBank {
    int food;
    public FoodBank() {
        food = 0;
    }
    public void giveFood(int givenFood) {
        food = food + givenFood;
    }
    public void takeFood(int takenFood) {
        food = takenFood;
    }
}
class FoodProducer extends Thread {
    FoodBank bank;
    FoodProducer(FoodBank newBank) {
        bank = newBank;
    }
    @Override
    public void run() {
        while(true) {
            int addFood = (int)(Math.random()*100 + 1);
            bank.food = bank.food + addFood;
            System.out.println("Putting " + addFood + " food into the food bank.");
            System.out.println("Balance is now: " + bank.food + ".");
            try {
                Thread.sleep(100);
            }
            catch (InterruptedException e) {}
        }
    }

}
class FoodConsumer extends Thread {
    FoodBank bank;
    FoodConsumer(FoodBank newBank) {
        bank = newBank;
    }
    @Override
    public void run() {
        while(true) {
            int subFood = (int)(Math.random()*100 + 1);
            if (bank.food - subFood <= 0) {
                System.out.println("Waiting for food.");
                try {
                    Thread.sleep(100);
                }
                catch (InterruptedException e) {}
            }
            else {
                bank.food = bank.food + subFood;
                System.out.println("Taking " + subFood + " food from the food bank.");
                System.out.println("Balance is now: " + bank.food + ".");
                try {
                    Thread.sleep(100);
                }
                catch (InterruptedException e) {}
            }
        }
    }
}
class FoodBankPatrons {
    public static void main(String[] args) {
        FoodBank bank = new FoodBank();
        FoodConsumer consumer = new FoodConsumer(bank);
        FoodProducer producer = new FoodProducer(bank);
        Thread takeThread = new Thread(consumer);
        Thread giveThread = new Thread(producer);

        giveThread.start();
        takeThread.start();
        

    }
}
