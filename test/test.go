func main() {
	// Hello world message
	printHelloWorld()
	printRune('\n')

	// Test if statement
	if (10 % 3 == 1) {
		printString("\nIf passed\n")
	}

	// Test closure
	var closedFunc = closure()
	printString("Closure created")
	closedFunc();

	// Test for loop
	printString("\nFor loop:\n")
	var i = 0
	for ;i<15; i = i + 1  {
		printInt(i)
		printRune(',')
		
	}
	printRune('\n')

	// Test return statement in for loop
	printInt(returnInFor())
	printRune('\n')

	// Test return in switch case
	printFloat32(returnInSwitch())
	printRune('\n')

	// Test composite literal array
	arrays()

	// Test composite literal struct (also type definitions)
	structs()

	// Test slices
	slices()
}

func closure() func () {
	printString("\nCreating closure\n")
	var test = 1.0
	return func () {
		printString("\nClosure\n")
		printFloat32(test)
		printRune('\n')
	}
}

func printHelloWorld() {
	printString("Hello World!")
}

func returnInFor() int {
	printString("\nReturn in for:\n")
	var i = 0;
	for ;i < 10 ; i = i + 1 {
		if i == 3 {
			return i
		}
	}
	return 11
}

func returnInSwitch() float32 {
	printString("\nReturn in switch:\n")
	var i = 3.14;
	switch (i) {
	case 2.0:
		return i * 1.0
	case 3.0:
		return i * 2.0
	case 4.0:
		return i * 3.0
	default:
		return i
	}
}

func arrays() {
	printString("\nArray:\n")
	var array = [3]int{1, 2, 3}
	printInt(array[0])
	printRune(',')
	printInt(array[1])
	printRune(',')
	printInt(array[2])
	printRune('\n')

	array[1] = 2564
	printInt(array[0])
	printRune(',')
	printInt(array[1])
	printRune(',')
	printInt(array[2])
	printRune('\n')
}

func structs() {
	printString("\nStructs:\n")

	type Point struct {
		x float32
		y float32
	}

	var test = Point{x: 1.0, y: 2.0}

	printFloat32(test.x)
	printRune(',')
	printFloat32(test.y)
	printRune('\n')

	test.y = 3.14

	printFloat32(test.x)
	printRune(',')
	printFloat32(test.y)
	printRune('\n')
}

func slices() {
	printString("\nSlices:\n")
	var array = []int{1, 2, 3, 4, 5}
	var slice = array[1:3]
	
	printInt(slice[0])
	printRune(',')
	printInt(slice[1])
	printRune('\n')
}
