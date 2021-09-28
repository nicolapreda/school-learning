package main

import "fmt"

func start() {
	// Dichiarazione veriabile x
	var x int

	fmt.Println("Inserisci il numero di righe:")
	fmt.Scanln(&x)
	//x = numero di righe da inserire nel progetto
	
	for j := 0; j <= x; j++ {
		// j = numero ipotetico, la varabile permette di capire al for quando eseguire le istruzioni
		var spaces string
		spaces = " "
		var spaces1 = spaces * j
		fmt.Print(spaces1 * j)
		fmt.Println("X")

		if j >= i {
			fmt.Print("X ")
		}
	}
	fmt.Println()
}
