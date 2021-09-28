package main

import (
	"fmt"
	"log"
	"net/http"
)

// func handler gestisce le richieste al server (r) e si occupa di restituire le relative risposte (w).
func handler(w http.ResponseWriter, r *http.Request) {
	// Scrive in w la stringa "Ciao" seguita dalla parte di testo successiva alla "/" nell'URL passato dopo il dominio.
	fmt.Fprintf(w, "Ciao %s!\n", r.URL.Path[1:])
}

func main() {
	// http.HandleFunc gestisce le richieste http.
	// Ogni richiesta http effettuata viene gestita dalla funzione "handler".
	http.HandleFunc("/", handler)
	// Attenzione! handler è usato come parametro, ma è una funzione e non una variabile!
	// In Go questo è possibile perché è un linguaggio "First Class" (per tale motivo, "handler" è una "first-class citizen". Ulteriori info nella seconda parte dell'anno).

	// http.ListenAndServe si occupa di mettere il processo in ascolto sulla porta specificata (8080).
	// Per ogni richiesta http ricevuta, viene generata una goroutine che si occupa di gestirla.
	log.Fatal(http.ListenAndServe(":8080", nil))
	// In caso di problemi log.Fatal termina l'esecuzione del programma (terminazione di tutte le goroutine).

	// test su browser: http://127.0.0.1:8080/Sani
	// test da console: printf "GET /Marco HTTP/1.0\r\n\r\n"|nc 116.203.33.65 8080

	// Cosa succede se si lanciano due istanze del programma nello stesso momento?
}
