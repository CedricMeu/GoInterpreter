type node struct {
	val         int
	left, right *node
}

func lookup(x int, p *node) bool {
	for p != nil {
		if p.val == x {
			return true
		} else if p.val < x {
			p = p.right
		} else {
			p = p.left
		}
	}
	return false
}

func insert(x int, p *node) {
	for {
		if p.val == x {
			return
		} else if p.val < x {
			if p.right == nil {
				p.right = &node{x, nil, nil}
				return
			} else {
				p = p.right
			}
		} else {
			if p.left == nil {
				p.left = &node{x, nil, nil}
				return
			} else {
				p = p.left
			}
		}
	}
}

func main() {
	t := &node{0, nil, nil}
	insert(-4, t)
	insert(5, t)
	insert(100, t)
	insert(60, t)
	insert(-77, t)
	insert(-1, t)
	print(lookup(-2, t))
}
