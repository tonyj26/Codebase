/* bicycle object class
*/

public class bicycle implements myInterface {
	// test constructor
	int wheels = 2;
	int price = 0;
	String type = "bike";
	public bicycle (int wheels, int price, String type) {
		this.wheels = wheels;
		this.price = price;
		this.type = type;
	}

	public bicycle () {
	}

	public int wheels() {
		return this.wheels;
	}

	public int price() {
		return this.price;
	}

	public String type() {
		return this.type;
	}

}
