package main

import (
	"fmt"
	"net/http"
)

func before(handle http.HandlerFunc) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		fmt.Println("执行前置处理")
		handle(w, r)
	}
}

func test(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "test1")
}

func main() {
	http.HandleFunc("/", before(test))

	server := http.Server{
		Addr: "127.0.0.1:8080",
	}
	server.ListenAndServe()
}
