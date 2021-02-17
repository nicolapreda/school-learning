package main

import "fmt"

func main() {

	// Dichiarazione delle variabili a,b,c
	var a, b, c int
	// Assegnazione del valore in input alla variabile int a
	fmt.Println("Inserisci il primo numero:")
	fmt.Scanln(&a)
	// Assegnazione del valore in input alla variabile int b
	fmt.Println("Inserisci il secondo numero:")
	fmt.Scanln(&b)
	// Assegnazione del valore in input alla variabile int c
	fmt.Println("Inserisci il terzo numero:")
	fmt.Scanln(&c)

	if a >= b && a >= c { // Se "a" è maggiore-uguale di "b" e di "c", stampa la variabile "a"
		println(a, "è il numero maggiore")
	} else if b >= a && b >= c { // Se "b" è maggiore-uguale di "a" e di "c", stampa la variabile "b"
		println(b, "è il numero maggiore")
	} else if c >= a && c >= b { // Se "c" è maggiore-uguale di "a" e di "b", stampa la variabile "b"
		println(c, "è il numero maggiore")
	} else if c == a && c == b { // Se tutte le variabili int sono uguali, stampa "I tre numeri sono uguali"
		println("I tre numeri sono uguali")
	}

}
