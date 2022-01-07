package main

func echo(arr [5]int) {
	for i := 0; i < 5; i++ {
		print(arr[i])
	}
}

func main() {
	lijst := [5]int{60, 70, 33, 22, 101}
	// lijst[0] = 60
	// lijst[1] = 70
	// lijst[2] = 33
	// lijst[3] = 22
	// lijst[4] = 101
	echo(lijst)
}
