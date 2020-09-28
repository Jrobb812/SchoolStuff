import java.util.*;
public class cmsc401 {
    final int unitPrice = 1;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int numGarden = scan.nextInt();
        while (numGarden >= 1000000000 | numGarden < 2) {
            System.out.println("Error number of gardens must be between 1,000,000,000 and 2.");
            numGarden = scan.nextInt();
        }
    }
    public int computeCost(int size, int distance) {
        return size * distance * unitPrice;
    }
}