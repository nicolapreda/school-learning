// Prendere in input 5 valori e stamparli al contrario
package main

import "fmt"

// Vettore: Variabile che contiene tante variabili, tutte dello stesso tipo
func main() {
	var v [5]int

	for i := 0; i < 5; i++ {
		fmt.Scanln(&v[i])
	}
	fmt.Println("----------------------------")

	for i := 5 - 1; i >= 0; i-- {
		fmt.Println(v[i])
	}
}
