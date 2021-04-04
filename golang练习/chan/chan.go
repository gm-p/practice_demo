package main

import (
	"fmt"
	"time"
)

// 声明不带缓冲区的通道
// ch1 := make(chan string)

// 声明带10个缓冲区的通道
// ch2 := make(chan string, 10)

// 声明只读通道
// ch3 := make(<-chan string)

// 声明只写通道
// ch4 := make(chan<- string)

//不带缓冲的通道，进和出都会阻塞。
//带缓冲的通道，进一次长度 +1，出一次长度 -1，如果长度等于缓冲长度时，再进就会阻塞

// 写入chan
// ch2 <- "a"

// 读取chan
// val, ok := <- ch2

// 关闭chan
// close(ch2)

// close 以后不能再写入，写入会出现 panic
// 重复 close 会出现 panic
// 只读的 chan 不能 close
// close 以后还可以读取数据

func main1() {
	fmt.Println("main start")
	ch := make(chan string, 1)
	ch <- "a"
	go func() {
		val := <-ch
		fmt.Println(val)
	}()
	time.Sleep(time.Second * 1)
	fmt.Println("main end")
}

func main2() {
	fmt.Println("main start")
	ch := make(chan string)
	go func() {
		ch <- "a"
	}()
	go func() {
		val := <-ch
		fmt.Println(val)
	}()
	time.Sleep(time.Second * 1)
	fmt.Println("main end")
}

func main3() {
	fmt.Println("main start")
	ch := make(chan string, 3)
	go producer1(ch)

	time.Sleep(time.Second * 1)
	fmt.Println("main end")
}

func producer1(ch chan string) { // 带缓冲的通道，如果长度等于缓冲长度时，再进就会阻塞
	fmt.Println("producer start")
	ch <- "a"
	ch <- "b"
	ch <- "c"
	ch <- "d"
	fmt.Println("producer end")
}

func main() {
	fmt.Println("main start")
	ch := make(chan string, 3)
	go producer(ch)
	go customer(ch)

	time.Sleep(time.Second * 1)
	fmt.Println("main end")
}

func producer(ch chan string) {
	fmt.Println("producer start")
	ch <- "a"
	ch <- "b"
	ch <- "c"
	ch <- "d"
	fmt.Println("producer end")
}

func customer(ch chan string) {
	for {
		msg := <-ch
		fmt.Println(msg)
	}
}
