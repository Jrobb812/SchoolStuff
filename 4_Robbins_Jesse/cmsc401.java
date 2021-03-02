import java.io.*;
import java.lang.*;
import java.util.Scanner;
public class cmsc401 {
    public static void main (String[] args) {
        
        Scanner scan  = new Scanner(System.in);
        System.out.println("Enter rod size: ");
        int n = scan.nextInt();
        System.out.println("Enter number of cutting points: ");
        int m = scan.nextInt();
        int[] cp = new int[m];
        System.out.println("Enter cutting points: ");
        for (int i = 0; i < m; i++) {
            cp[i] = scan.nextInt();
        }
        cmsc401 rodObj = new cmsc401();
        System.out.print("Min rod cutting cost is: " + rodObj.cutRod(0, n, cp));
    }
    public int cutRod(int start, int end, int[] cp) {
        final int MIN_VAL = 99999; 
        if (end == 0 || cp.length == 0) return 0;
        else if (cp.length == 1) return end - start;
        //rod cutting alg
        else {
            int cut = MIN_VAL;
            for (int i = 0; i < cp.length; i++) {
                int[] leftCut = new int[i];
                int[] rightCut = new int[cp.length - i - 1];
                int rodLength = end - start;
                for (int j = 0; j < i; j++) 
                    leftCut[j] = cp[j];
                for (int j = 1; j < cp.length - i; j++) 
                    rightCut[j - 1] = cp[i + j];
                cut = Math.min(cut, rodLength + (cutRod(start, cp[i], leftCut) + cutRod(cp[i], end, rightCut)));
            }
            return cut;
        }
    }



}