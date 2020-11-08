import java.util.*;
import java.lang.*;
public class cmsc401 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("input num cities");
        int numCities = scan.nextInt(); //number of verticies
        int numHighways = scan.nextInt(); //number of edges
        List<City> visitedNodes = new List<City>();
        List<City> unvisitedNodes = new List<City>();

        City zeroCity = new City(0, 0);
        visitedNodes.add(zeroCity);
        unvisitedNodes.add(zeroCity);

        int cityNum[] = new int [numCities];
        cityNum[0] = 0;
        cityNum[1] = 1;
        cityNum[2] = 2;

        int motelCost[] = new int[numCities];
        motelCost[0] = 0;
        motelCost[1] = 0;
        motelCost[2] = 0;

        //loop to recieve inputs of motel costs in cities
        for (int i = 3; i < numCities + 1; i++) {
            cityNum[i] = scan.nextInt();
            motelCost[i] = scan.nextInt();
        }

        for (int i = 1; i < numCities + 1; i++) { //for loop to add cities coordinating with motel costs
            City tempCity = new City(cityNum[i], motelCost[i]);
            unvisitedNodes.add(tempCity);
        }

        int cost[][] = new int[numCities + 1][numCities + 1];
        for (int[] row : cost) {
            Arrays.fill(row, 0); //new array completely filled with 0
        }

        //creates three variables for the next part of the input
        int firstNode;
        int secondNode;
        int gasPrice;

        //for loop to get node 1, node 2, gas prices
        for (int i = 1; i < numHighways + 1; i++) {
            firstNode = scan.nextInt();
            secondNode = scan.nextInt();
            gasPrice = scan.nextInt();

            //sets up 2d array for reading in undirected values
            cost[firstNode][secondNode] = gasPrice;
            cost[secondNode][firstNode] = gasPrice;
        }

        int[][] totalCost = new int[numCities + 1][numCities + 1]; //total cost matrix
        
        //now creates the 2d matrix containing all costs between cities (and includes the motel cost)
        for (int i = 1; i < numCities + 1; i++) {
            for (int j = 1; j < numCities + 1; j++){
                totalCost[i][j] = cost[i][j] + motelCost[j];
            }
        }
        
    }
    


}
public class City {
    int motelCost;
    int cityNumber;
    City visitedCity;
    
    //default constructor
    public City(int cityNum) {
        this.cityNumber = cityNum;
        this.visitedCity = null;
    }

    //constructor including motel cost (still default)
    public City(int cityNum, int motelCost) {
        this.cityNumber = cityNum;
        this.motelCost = motelCost;
        this.visitedCity = null;
    }

    public void setCityNumber(int cityNum) {
        this.cityNumber = cityNum;
    }

    public int getCityNum() {
        return cityNumber;
    }

    public void setMotelCost(int motelCost) {
        this.motelCost = motelCost;
    }

    public int getMotelCost() {
        return motelCost;
    }

    public void setVisited(City city) {
        this.visitedCity = city;
    }

    public City getVisited() {
        return visitedCity;
    }
}