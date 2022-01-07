func main() {
	printInt(fib(77))
}

func fib(n int) int {
	var x, y = 0, 1
	var i = 0
	for ; i < n; i = i + 1 {
		x, y = y, x+y
	}
	return x
}
