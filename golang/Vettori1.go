package main

import "fmt"

const N = 5

func main() {
	var x [N]int // Dichiarato un vettore con 5 variabili, chiamate tutte x
	for i := 0; i < N; i++ {
		fmt.Println("Inserisci un numero")
		fmt.Scanln(&x[i]) //
	}
	fmt.Println()

	for i := N - 1; i >= 0; i-- {
		fmt.Println(x[i])
	}

}
