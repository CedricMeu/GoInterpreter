func main() {
	var board = createBoard()

	// blinker
	// board[2][1] = true
	// board[2][2] = true
	// board[2][3] = true

	// beacon
	board[0][0] = true
	board[1][0] = true
	board[0][1] = true
	board[3][3] = true
	board[3][2] = true
	board[2][3] = true

	var itterations, i = 5, 0

	for ; i < itterations; i=i+1 {
		board = next(board)
		printBoard(board)
		printString("=====\n")
	}
}

func printBoard(board [][]bool) {
	var y = 0
	for ; y < 5; y = y + 1 {

		var x = 0
		for ; x < 5; x = x + 1 {
			if board[y][x] {
				printRune('#')
			} else {
				printRune('.')
			}
		}
		printRune('\n')
	}
}

// Create a 5x5 board
func createBoard() [][]bool {
	return [][]bool{
		[]bool{false, false, false, false, false},
		[]bool{false, false, false, false, false},
		[]bool{false, false, false, false, false},
		[]bool{false, false, false, false, false},
		[]bool{false, false, false, false, false}}
}

// Calculate nest fase
func next(board [][]bool) [][]bool {
	var newBoard = createBoard()

	var y = 0
	for ; y < 5; y = y + 1 {

		var x = 0
		for ; x < 5; x = x + 1 {
			var count = 0

			if x > 0 { 
				if y > 0 {
					if board[y-1][x-1] {
						count = count + 1
					}
				}

				if y < 4 {
					if board[y+1][x-1] {
						count = count + 1
					}
				}
			}

			if x < 4 { 
				if y > 0 {
					if board[y-1][x+1] {
						count = count + 1
					}
				}

				if y < 4 {
					if board[y+1][x+1] {
						count = count + 1
					}
				}
			}

			if y > 0 {
				if board[y-1][x] {
					count = count + 1
				}
			}

			if y < 4 {
				if board[y+1][x] {
					count = count + 1
				}
			}

			if x > 0 {
				if board[y][x-1] {
					count = count + 1
				}
			}

			if x < 4 {
				if board[y][x+1] {
					count = count + 1
				}
			}
			
			if count == 2 {
				newBoard[y][x] = board[y][x]
			} else if count == 3 {
				newBoard[y][x] = true
			}
		}
	}

	return newBoard
}
