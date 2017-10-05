/* Coin Flip simulator
*/

import java.util.Scanner;

public class coinflip {
	public static void main (String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("How many times do you want to flip the coin?");
		int n = input.nextInt();
		int heads = 0;
		int tails = 0;
		for(int i = 0; i < n; i++) {
			String	str = flip();
			System.out.print(str + " ");
			if (str == "T"){
				heads++;
			}
			else {
				tails++;
			}
		}
		System.out.println("\n" + heads + " heads, " + tails + " tails.");
	}
	public static String flip() {
		double coin = Math.round(Math.random());
		if( coin == 0){
			return "T";
		}
		else {
			return "H";
		}
	}

}
