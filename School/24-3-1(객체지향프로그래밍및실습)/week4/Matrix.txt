import java.util.Scanner;

public class Matrix {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int m1 = sc.nextInt();
		int n1 = sc.nextInt();
		int m2 = sc.nextInt();
		int n2 = sc.nextInt();
		int[][] A = new int[m1][n1];
		int[][] B = new int[m2][n2];
		int[][] C = new int[m1][n2];
		
		for(int i = 0; i < m1; i++) {
			for(int j = 0; j < n1; j++) {
				A[i][j] = sc.nextInt();
			}
		}

		for(int i = 0; i < m2; i++) {
			for(int j = 0; j < n2; j++) {
				B[i][j] = sc.nextInt();
			}
		}

		if (n1 != m2) {
			System.out.println("the multiplication can not proceed");
		} else {
			for (int i = 0; i < m1; i++) {
				for(int j = 0; j < n2; j++){
					C[i][j] = 0;
					for (int k = 0; k < n1; k++) {
						C[i][j] += A[i][k]*B[k][j];
					}
				}
			}
			
			System.out.println();
			for (int i = 0; i < m1; i++) {
				for(int j = 0; j < n2; j++){
					System.out.print(C[i][j]);
					System.out.print(" ");
				}
				System.out.println();
			}
		}

		sc.close();
	}
}