package main

import (
	"fmt"
)

// Creare una calcolatrice

func main() {
	var operazione string
	var numero1, numero2 int

	fmt.Println("Inserisci il primo numero con cui effettuare il calcolo")

	fmt.Scanln(&numero1)
	fmt.Println("Inserisci l'operazione che vuoi effettuare: + per la somma, - per la differenza, * per la moltiplicazione, : per la divisione")

	fmt.Scanln(&operazione)
	fmt.Println("Inserisci il secondo numero")

	fmt.Scanln(&numero2)
	switch operazione {
	case "+":
		{
			fmt.Println("Il risultato è", numero1+numero2)
		}
	case "-":
		{
			fmt.Println("Il risultato è", numero1-numero2)
		}
	case ":":
		{
			fmt.Println("Il risultato è", numero1/numero2)
		}
	case "x":
		{
			fmt.Println("Il risultato è", numero1*numero2)
		}
	}

	if operazione != "+" || operazione != "-" || operazione != "x" || operazione != ":" {
		fmt.Println("L'operazione che hai inserito non è valida")
	}

}
