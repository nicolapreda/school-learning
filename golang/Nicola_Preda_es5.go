package main

import "fmt"

func main() {
	var a, b float64
	b = 0
	for c := 0; c < 7; c++ {
		fmt.Scanln(&a)
		b = b + a

	}
	b = b / 7
	fmt.Println("La media è", b)
}
