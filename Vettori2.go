package main

import "fmt"

func main() {
	const N = 3
	var x [N]int

	for i := 0; i < N; i++ {

		fmt.Println("Inserisci i valori")
		fmt.Scanln(&x[i])

	}
	var somma int
	for i := 0; i < N; i++ {
		somma = somma + x[i]

	}
	media := float64(somma) / float64(N)
	for i := 0; i < N; i++ {
		if float64(x[i]) > media {
			fmt.Println(x[i])
		}
	}
}
