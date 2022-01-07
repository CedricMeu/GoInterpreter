func main() {
	if (10 % 3 == 1) {
		closure()();
	}

	printRune('\n');

	printHelloWorld();

	printRune('\n');

	var i = 0
	for ;i<15; i = i + 1  {
		printInt(i)
		
	}

	printRune('\n');
}

func closure() func () {
	var test = 1.0
	return func () {
		printFloat32(test)
	}
}

func printHelloWorld() {
	printString("Hello World!");
}
