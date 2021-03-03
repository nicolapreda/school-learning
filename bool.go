// Variabili booleane
// Hanno soltanto valori => Vero / Falso
package main

import "fmt"

func main() {
	var x bool = false

	x = 9 > 5
	if x == true {
		fmt.Println("x è vera!")
	} else {
		fmt.Println("x è falsa!")
	}

}
