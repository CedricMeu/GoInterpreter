package main

func main() {
	freezingF := 32
	boilingF := 212
	print(fToC(freezingF))
	print(fToC(boilingF))
}

func fToC(f int) int {
	return (f - 32) * 5 / 9
}
