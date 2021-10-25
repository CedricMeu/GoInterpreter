{
	type (
		structAlias = struct {
			x, y int
			z float32
		}
		arrayDefinition map[int]string
		sliceAlias *[]func (x, y int) (int, int)
	)

	var test test
	var test, test2 = 0.3
	var test, test2 int = 3.14, 3.15
}