/* implementation of the Collatz Conjecture Algorithm
*/

import java.util.Scanner;

public class collatz {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.print("Enter a number to collatz: ");
		int n = input.nextInt();

		System.out.println("It took " + alg(n, 0) + " steps to reach 1");
	}
	public static int  alg(int n, int count) {
		if (n == 0 || n == 1) return count;
		else if (n % 2 == 0) return alg(n/2, count+1);
		else return alg(3*n+1, count +1);
	}
}
