package main

import "fmt"

func main() {
	// Dichiarazione delle variabili a,b,c
	var a, b, c int
	// Assegnazione variabile a
	fmt.Println("Inserisci il primo numero:")
	fmt.Scanln(&a)
	// Assegnazione variabile b
	fmt.Println("Inserisci il secondo numero:")
	fmt.Scanln(&b)
	// Assegnazione variabile c
	fmt.Println("Inserisci il terzo numero:")
	fmt.Scanln(&c)
	if a > b && a > c {
		println(a, "è il numero maggiore")
	} else if b > a && b > c {
		println(b, "è il numero maggiore")
	} else if c > a && c > b {
		println(c, "è il numero maggiore")
	}
}
