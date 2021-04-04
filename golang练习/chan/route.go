package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println("main Begin......")
	go func() {
		fmt.Println("goroutine.....")
	}()

	time.Sleep(1 * time.Second)

	fmt.Println("main End.....")
}
