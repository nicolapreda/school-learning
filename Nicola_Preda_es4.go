package main

import "fmt"

func main() {
	var n int // Valori maggiori di 0
	var insert int

	for i := 1; i != 0; {
		fmt.Scanln(&n)

		if n > 0 || n < 0 {
			insert++
		}
		if n == 0 {
			i = 0
		}
	}
	print("Hai inserito ", insert, " valori diversi da 0")

}
