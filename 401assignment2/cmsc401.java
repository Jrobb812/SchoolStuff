import java.util.*;
public class cmsc401 {
    final int unitPrice = 1;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int numGarden = scan.nextInt();
        while (numGarden >= 1000000000 | numGarden < 2) {
            System.out.println("Error number of gardens must be between 2 and 1,000,000,000.");
            numGarden = scan.nextInt();
        }

        int[] coords = new int[numGarden];
        int[] size = new int[numGarden];


        for (int i = 0; i < numGarden; i++) {
            //System.out.println("Enter coordinate for garden " + i + ".");
            coords[i] = scan.nextInt();
            //size[i] = scan.nextInt();
        }

        cmsc401 tester = new cmsc401();

        tester.quicksort(coords, coords[0], coords[coords.length - 1]);
    }

    public int computeCost(int size, int distance) {
        return size * distance * unitPrice;
    }

    public int[] swap (int[] arr, int a, int b) {  //where a and b are getting swapped in the array
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
        return arr;
    }

    public int partitionFunction(int[] arr, int p, int r) {
        int pivot = arr[r]; //takes last element of array and makes it the randomized pivot
        int i = p - 1; //takes p so we can keep track of p while also changing it
        int j = p; //j = p this is our tracker

        for (j = p; j < r - 1; j++) {
            if (arr[j] <= pivot) { // if the arrray at position j is less than the pivot we will increment i and then swap the array at position i and position j
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i, j);  // finally, we swap the last element (aka the pivot) with the current arr[i]

        return i + 1; //we return the index + 1, giving us the index for the pivot value
    }

    public void quicksort(int[] arr, int p, int r) {
        if (p < r) { //checks for size 1 array, if not size 1, array needs to be sorted
            int q = partitionFunction(arr, p, r); //q = pivot's location 
            quicksort(arr, p, q - 1); //does the left/smaller side of the array
            quicksort(arr, q + 1, r); //does the right/larger side of the array
            System.out.println("This is " + q);
        }
    }

}