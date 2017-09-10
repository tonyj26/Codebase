/* fibonacci sequence for java
*/

import java.util.Scanner;

public class fibonacci {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.print("How much Fibonacci you want? ");
		int n = input.nextInt();	
	 
		for(int i = 0; i < n; i++) {
			System.out.print(recursive(i) + ", ");
		}
	}

		public static int recursive(int n) {
			if (n == 0) {
				return 0;
			}
			else if (n ==1) {
				return 1;
			}
			else {
				return recursive(n-1) + recursive(n-2);
			}

		}
}


