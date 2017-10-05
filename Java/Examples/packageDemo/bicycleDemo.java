/* Main class of Bicycle 
 * simple test for using multiple java
 * files for one program.
 */

public class bicycleDemo {
	public static void main(String[] args) {
		bicycle bike1 = new bicycle();

		bicycle bike2 = new bicycle(6, 500, "trike");

		System.out.println(bike1.wheels());
		System.out.println(bike2.wheels());
		System.out.println(bike1.type());
		System.out.println(bike2.type());
	}
}
