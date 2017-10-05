/* Factorial Finder
*/
import java.util.Scanner;

public class factorial {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter Factorial");
		int n = input.nextInt();
		System.out.println("Factorial of " + n + " is: " + factorialize(n));
	}

	public static int factorialize(int x) {
		if (x==0) {
			return 1;
		}
		else if (x==1) {
			return 1;
		}
		else {
			return factorialize(x-1) * x;
		}
	}
}
