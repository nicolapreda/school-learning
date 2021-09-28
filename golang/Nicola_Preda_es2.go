package main

import "fmt"

func main() {
	var n int
	fmt.Scanln(&n)

	for j := 0; j < n; j++ {
		for i := 0; i < n; i++ {
			fmt.Print("X ")
		}
		fmt.Println()
	}
}
