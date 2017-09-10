/* Pi Demo count digits of Pi up to N
 */
import java.util.Scanner;
import java.math.BigDecimal;

public class piDemo {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Please enter the decimal places to which you'd like PI printed: ");
		int n = input.nextInt();
		BigDecimal b1 = new BigDecimal(7.0);
		BigDecimal b2 = new BigDecimal(22.0);
		BigDecimal pi = b2.divide(b1, n, BigDecimal.ROUND_UP);
		if (n > 100 || n < 0) {
			System.out.println("Decimal place out of bounds!");
		}
		else {
			System.out.println(pi);
		}
	}
}

