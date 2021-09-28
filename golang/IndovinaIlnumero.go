package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {

	s1 := rand.NewSource(time.Now().UnixNano())
	r1 := rand.New(s1)
	casualnumber := r1.Intn(100)

	for i := 0; i != casualnumber; {
		fmt.Println("Inserisci il numero tra 1 e 100")
		fmt.Scanln(&i)
		if i < casualnumber {
			fmt.Println("Numero troppo basso")
		} else if i > casualnumber {
			fmt.Println("Numero troppo alto!")
		}
	}
	fmt.Println("Numero corretto!")
}
