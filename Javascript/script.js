//FizzBuzz Challenge

var num = 1;

while (num <=100) {
	switch (num){
		case(num % 3 == 0):
			console.log('Fizz');
			break;
		case(num % 5 == 0 && num % 3 != 0):
			console.log('Buzz');
			break;
		default:
			console.log(num);
			break;
	}
	num++;
}
			
