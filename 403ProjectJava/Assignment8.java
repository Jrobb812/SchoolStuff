class FoodBank {
    private int food;

    void FoodBank() {
        food = 0;
    }

    void giveFood(int goodFood) {
        food = food + goodFood;
    }

    void takeFood(int badFood) {
        food = food - badFood;
    }
}

class FoodProducer extends Thread {
    FoodBank bank = new FoodBank();

    void FoodProducer(FoodBank theBank) {
        bank = theBank;
    }
    // @Override
    // void run() {
    //     bank.run();
    // }



}

class FoodConsumer {

}

class FoodBankPatrons {
    static void main(String[] args) {
        FoodBank bank = new FoodBank();
        FoodProducer producer = new FoodProducer();
        FoodConsumer consumer = new FoodConsumer();
    }
}