package main

import "fmt"

func main() {
	risposta := "<"

	valoreMinimo := 1
	valoreMassimo := 100

	numero := (valoreMassimo + valoreMinimo) / 2
	fmt.Println("Pensa ad un numero compreso tra 1 e 100, proverò a indovinarlo.\n(I valori consentiti sono <, > o =)")

	for risposta != "=" {
		fmt.Println("Il numero che hai pensato è maggiore, minore o uguale a", int(numero), "?")
		fmt.Scanln(&risposta)
		if risposta == "<" {
			valoreMassimo = numero
			numero = (valoreMassimo + valoreMinimo) / 2
		} else if risposta == ">" {
			valoreMinimo = numero
			numero = (valoreMassimo + valoreMinimo) / 2
		}

	}
	fmt.Println("Il numero che hai pensato è:", int(numero), "! :D")

}
