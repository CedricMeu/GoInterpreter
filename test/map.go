package main

func main() {
	m := make(map[int]int)
	// m map[int]int{}
	m[5]++
	m[7]++
	m[5]++
	m[3]++
	m[3]++
	m[5]++
	m[5]++
	m[2]++
	m[2]++
	print(m[1])
	print(m[7])
	print(m[2])
	print(m[5])
}
