package main

import (
	"errors"
	"fmt"
)

func main() {
	d, err := divisione(8.0, 2.0)
	if err != nil { // nil = null, vuoto
		fmt.Println(err)
	} else {
		fmt.Println(d)
	}

}

func divisione(x float64, y float64) (float64, error) {
	if y == 0.0 {
		return 0.0, errors.New("Impossibile")
	} else {
		return x / y, nil
	}
}
