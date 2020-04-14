import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class DA3 {
    public static void main(String[] args) throws Exception{
        String currLine;
        String[] clear;
        int size, start, end, h;
        File inFile = new File("data.txt");
        Scanner in = new Scanner(inFile);

        //Reads first line to get the size of the array
        currLine = in.nextLine();
        size = Character.getNumericValue(currLine.charAt(0));
        System.out.println(size);
        //Reads second line to get start point
        currLine = in.nextLine();
        start = Character.getNumericValue(currLine.charAt(0));
        System.out.println(start);
        //Reads third line to get end point
        currLine = in.nextLine();
        end = Character.getNumericValue(currLine.charAt(0));
        System.out.println(end);

        int[][] matrix = new int[size][size];

        for(int i = 0; i <size; i++){
            currLine = in.nextLine();
            clear = currLine.split(",");
            h=0;
            for(String hold : clear){
                matrix[i][h] = Character.getNumericValue(hold.charAt(0));
                h++;
            }
        }
        for(int i=0;i<size;i++) {
            for (int j = 0; j < size; j++) {
                System.out.print(matrix[i][j]);

            }
            System.out.println("");
        }


        BFS(matrix, start, end);
    }

    public static void BFS(int [][] matrix, int start, int end){

        if(start==end){
            System.out.println(start);
            return;
        }
        myQueue bfsQueue = new myQueue();
        int size = matrix.length;
        int[] visited = new int[size];
        int i, element;

        visited[start]=1;
        bfsQueue.enqueue(start);

        while(!bfsQueue.isEmpty()) {
            element = bfsQueue.remove();
            i = element;
            int j = 0;
            System.out.println(i);
            while(i<size){

                if(matrix[element][j] == 1 && visited[j] == 0){
                    bfsQueue.enqueue(j);
                    visited[j] = 1;
                }
                i++;
                j++;

            }
        }
    }
   /* public static int[][] create2DMatrix(String fileName) throws Exception{

        String currLine;
        String[] clear;
        int size, start, end, h;
        File inFile = new File(fileName);
        Scanner in = new Scanner(inFile);

        //Reads first line to get the size of the array
        currLine = in.nextLine();
        size = Character.getNumericValue(currLine.charAt(0));
        System.out.println(size);
        //Reads second line to get start point
        currLine = in.nextLine();
        start = Character.getNumericValue(currLine.charAt(0));
        System.out.println(start);
        //Reads third line to get end point
        currLine = in.nextLine();
        end = Character.getNumericValue(currLine.charAt(0));
        System.out.println(end);

        int[][] matrix = new int[size][size];

        for(int i = 0; i <size; i++){
            currLine = in.nextLine();
            clear = currLine.split(",");
            h=0;
            for(String hold : clear){

                //System.out.println("" + in);//these are checks for the file reading
                matrix[i][h] = Character.getNumericValue(hold.charAt(0));
                h++;
            }
        }
        return matrix;
    }*/

}
