package main

func fac(n int) int {
	if n == 0 {
		return 1
	} else {
		return n * fac(n-1)
	}
}

func main() {
	print(fac(5))
}
