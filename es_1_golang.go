// presi in input i numeri reali a, b risolvere l'equazione
// ax+b=0
// 2x+0=0
// 2x=0
// x=0

// x=-b/a
// dati di input: a, b reali
// dati di output: x reale
// vincoli: a==0 e b==0 --> indeterminato
//          a==0 e b!=0 --> impossibile

// prendere a in input
// prendere b in input
// se a!=0 allora x=-b/a; comunicare x
// altrimenti 
//   se b==0  allora comunica indeterminato
//   altrimenti comunica impossibile
package main

import "fmt"

func main() {
  var a, b, x float64
  fmt.Println("Inserisci a")
  fmt.Scanln(&a)
  fmt.Println("Inserisci b")
  fmt.Scanln(&b)
  if a!=0 {
    x=-b/a
    fmt.Println("Il risultato è",x)
  } else {
    if b==0 {
      fmt.Println("indeterminato")
    }else{
      fmt.Println("Impossibile")
    }
  }
}