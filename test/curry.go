func curry(f func(x, y int) int) func(x int) func(y int) int {
	return func(x int) func(y int) int { 
		return func(y int) int { 
			return f(x, y) 
		} 
	}
}
func kokko(x, y int) int { 
	return x + y
}

func main() {
	var g = curry(kokko)
	var h = g(5)
	printInt(h(7))
}

