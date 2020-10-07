package array;

import java.util.Scanner;

// Diagonal traversal of a 2D matrix entered by user

public class DiagonalTraversal2D {

	public static void main(String[] args) {
		
		Scanner scn = new Scanner(System.in);
// input of array
		int row = scn.nextInt();
		int col = scn.nextInt();
		
		int arr[][]= new int [row][col];
		for(int i=0;i<row;i++) {
			for(int j=0;j<col;j++) {
				arr[i][j] = scn.nextInt();
			}
		}
// traversal of array
		for(int k=0;k<= row -1;k++){
			int i =k;
			int j =0;
			while(i>=0){
				System.out.print(arr[i][j] + " ");
				i =i-1;
				j=j+1;
				
			}
			System.out.println();
		}
		
		for(int k=1;k<=col-1;k++){
			int i = row -1;
			int j =k;
			
			while(j <= col-1){
				System.out.print(arr[i][j] + " ");
				i =i-1;
				j= j+1;
				
			}
			System.out.println();
		}
	}

}
