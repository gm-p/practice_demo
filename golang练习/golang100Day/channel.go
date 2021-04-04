package main

import (
	"fmt"
	"strconv"
	"time"
)

// “不要通过共享内存来通信，而应该通过通信来共享内存”
//声明通道
// var 通道名 chan 数据类型
// 创建通道：如果通道为nil，就需要先创建通道
// 通道名 = make(chan 数据类型)

func main1() {
	var a chan int
	if a == nil {
		fmt.Println("channel 是 nil 的，不能使用，需要先创建通道...")
		a = make(chan int)
		fmt.Printf("数据类型是：%T", a)
	}
}

// channel的数据类型
// channel是引用类型的数据，在作为参数传递的时候，传递的是内存地址
func main2() {
	ch1 := make(chan int)
	fmt.Printf("%T, %p\n", ch1, ch1)

	test1(ch1)
}

func test1(ch chan int) {
	fmt.Printf("%T, %p\n", ch, ch)
}

/*
1.用于goroutine，传递消息的。

2.通道，每个都有相关联的数据类型, nil chan，不能使用，类似于nil map，不能直接存储键值对

3.使用通道传递数据： chan <- data,发送数据到通道。向通道中写数据 data <- chan,从通道中获取数据。从通道中读数据

4.阻塞： 发送数据：chan <- data,阻塞的，直到另一条goroutine，读取数据来解除阻塞 读取数据：data <- chan,也是阻塞的。直到另一条goroutine，写出数据解除阻塞。

5.本身channel就是同步的，意味着同一时间，只能有一条goroutine来操作。

最后：通道是goroutine之间的连接，所以通道的发送和接收必须处在不同的goroutine中
*/
// data := <- a  // read from channel a
// a <- data     // write tochannel a
// v, ok := <- a   // 从一个channel中读数

// 发送和接收默认是阻塞的
func main3() {
	var ch1 chan bool       // 声明，没有创建
	fmt.Println(ch1)        // <nil>
	fmt.Printf("%T\n", ch1) // chan bool

	ch1 = make(chan bool)
	fmt.Println(ch1)

	go func() {
		for i := 0; i < 10; i++ {
			fmt.Println("子goroutine中，i: ", i)
		}
		ch1 <- true

		fmt.Println("结束...")
	}()

	data := <-ch1 // 从ch1通道中读取数据
	fmt.Println("data -- >", data)
	fmt.Println("main .. over ...")
}

func main4() {
	ch1 := make(chan int)
	done := make(chan bool)
	go func() {
		fmt.Println("子goroutine执行...")
		time.Sleep(3 * time.Second)
		data := <-ch1
		fmt.Println("data: ", data)
		done <- true
	}()
	time.Sleep(5 * time.Second)
	ch1 <- 100

	<-done
	fmt.Println("main ... over...")
}

func calcSquares(number int, squareop chan int) {
	sum := 0
	for number != 0 {
		digit := number % 10
		sum += digit * digit
		number /= 10
	}
	squareop <- sum
}

func calcCubes(number int, cubeop chan int) {
	sum := 0
	for number != 0 {
		digit := number % 10
		sum += digit * digit * digit
		number /= 10
	}
	cubeop <- sum
}

func main5() {
	number := 589
	sqrch := make(chan int)
	cubech := make(chan int)
	go calcSquares(number, sqrch)
	go calcCubes(number, cubech)
	squares, cubes := <-sqrch, <-cubech
	fmt.Println("Final output ", squares+cubes)

	// ch := make(chan int)
	// ch <- 5 // 死锁
}

// 关闭通道
func main6() {
	ch1 := make(chan int)
	go sendData(ch1)
	/*
		子goroutine，写出数据10个
				每写一个，阻塞一次，主程序读取一次，解除阻塞

		主goroutine：循环读
				每次读取一个，堵塞一次，子程序，写出一个，解除阻塞

		发送方，关闭通道的--->接收方，接收到的数据是该类型的零值，以及false
	*/
	//主程序中获取通道的数据
	for {
		time.Sleep(1 * time.Second)
		v, ok := <-ch1
		if !ok {
			fmt.Println("已经读取了所有的数据,", ok)
			break
		}
		fmt.Println("取出数据：", v, ok)
	}
	fmt.Println("main ... over ...")
}

func sendData(ch1 chan int) {
	// 发送方：10条数据
	for i := 0; i < 10; i++ {
		ch1 <- i
	}
	close(ch1) // 关闭ch1通道
}

// 通道上的范围循环
func main7() {
	ch1 := make(chan int)
	go sendData(ch1)
	// for循环的for range 形式可用于从通道接收值，直到它关闭为止
	for v := range ch1 {
		fmt.Println("读取数据：", v)
	}
	fmt.Println("main...over...")
}

// 缓冲通道
// ch := make(chan type, capacity)
func main8() {
	/*
		非缓存通道：make(chan T)
		缓存通道：make(chan T ,size)
			缓存通道，理解为是队列：

		非缓存，发送还是接受，都是阻塞的
		缓存通道,缓存区的数据满了，才会阻塞状态。。

	*/
	ch1 := make(chan int) // 非缓存的通道
	fmt.Println(len(ch1), cap(ch1))

	ch2 := make(chan int, 5)
	fmt.Println(len(ch2), cap(ch2))
	ch2 <- 100
	fmt.Println(len(ch2), cap(ch2))

	fmt.Println("-----------")
	ch3 := make(chan string, 4)
	go sendData3(ch3)
	for {
		time.Sleep(1 * time.Second)
		v, ok := <-ch3
		if !ok {
			fmt.Println("读完了...", ok)
			break
		}
		fmt.Println("\t读取的数据是:", v)
	}
	fmt.Println("main...over...")
}

func sendData3(ch3 chan string) {
	for i := 0; i < 10; i++ {
		ch3 <- "数据" + strconv.Itoa(i)
		fmt.Println("子goroutine，写出第", i, "个数据")
	}
	close(ch3)
}

// 双向通道
// data := <- a
// a <- data
func main9() {
	/*
		双向：
			chan T -->
				chan <- data,写出数据，写
				data <- chan,获取数据，读
		单向：定向
			chan <- T,
				只支持写，
			<- chan T,
				只读
	*/
	ch1 := make(chan string) // 双向，可读、可写
	done := make(chan bool)
	go sendData4(ch1, done)
	data := <-ch1 // 阻塞
	fmt.Println("子goroutine传来:", data)
	ch1 <- "我是main.." // 阻塞

	<-done
	fmt.Println("main...over...")
}

// 子goroutine 写数据到ch1通道中
// main groutine 从ch1通道中读取
func sendData4(ch1 chan string, done chan bool) {
	ch1 <- "我是小明" // 阻塞
	data := <-ch1 // 阻塞
	fmt.Println("main goroutine传来:", data)

	done <- true
}

// 单向通道
// 只能发送 或 接收
func main10() {
	/*
		单向：定向
		chan <- T,
			只支持写，
		<- chan T,
			只读


		用于参数传递：
	*/
	ch1 := make(chan int)
	//  ch2 := make(chan <- int) // 单向，只写
	//  ch3 := make(<- chan int) // 单向，只读
	//  ch1 <- 100
	//  data := ch1
	//  ch2 <- 1000
	go fun1(ch1)
	data := <-ch1
	fmt.Println("fun1中写出的数据是：", data)

	go fun2(ch1)
	ch1 <- 200
	fmt.Println("main...over...")
}

// 该函数接收，只写的通道
func fun1(ch chan<- int) {
	ch <- 100
	fmt.Println("fun1函数结束..")
}

func fun2(ch <-chan int) { // 只读
	data := <-ch
	fmt.Println("fun2函数，从ch中读取的数据是:", data)
}

func main11() {
	/*
		1.func NewTimer(d Duration) *Timer
			创建一个计时器：d时间以后触发，go触发计时器的方法比较特别，就是在计时器的channel中发送值
	*/
	//新建一个计时器：timer
	timer := time.NewTimer(3 * time.Second)
	fmt.Printf("%T\n", timer)
	fmt.Println(time.Now())

	// 此处等待channel中的信号，执行此段代码时会阻塞3秒
	ch2 := timer.C // <-chan time.Time
	fmt.Println(<-ch2)
}

func main12() {
	timer2 := time.NewTimer(5 * time.Second)
	go func() {
		// 等触发时的信号
		<-timer2.C
		fmt.Println("Timer2 结束。。")
	}()

	// 由于上面的等待信号是在新线程中，所以代码会继续往下执行，停掉计时器
	time.Sleep(3 * time.Second)
	stop := timer2.Stop()

	if stop {
		fmt.Println("Timer 2 停止..")
	}
}

func main13() {
	/*
		func After(d Duration) <-chan Time
			返回一个通道：chan，存储的是d时间间隔后的当前时间。
	*/
	ch1 := time.After(3 * time.Second) // 3s后
	fmt.Printf("%T\n", ch1)            // <- chan time.Time
	fmt.Println(time.Now())
	time2 := <-ch1
	fmt.Println(time2)
}

// select 随机执行一个可运行的case。如果没有case可运行，它将阻塞，直到有case可运行
/*
每个case都必须是一个通信

所有channel表达式都会被求值

所有被发送的表达式都会被求值

如果有多个case都可以运行，select会随机公平地选出一个执行。其他不会执行。

否则：

如果有default子句，则执行该语句。

如果没有default字句，select将阻塞，直到某个通信可以运行；Go不会重新对channel或值进行求值
*/

func main14() {
	ch1 := make(chan int)
	ch2 := make(chan int)

	go func() {
		time.Sleep(2 * time.Second)
		ch2 <- 200
	}()

	go func() {
		time.Sleep(2 * time.Second)
		ch1 <- 100
	}()

	select {
	case num1 := <-ch1:
		fmt.Println("ch1中取数据..", num1)
	case num2, ok := <-ch2:
		if ok {
			fmt.Println("ch2中取数据..", num2)
		} else {
			fmt.Println("ch2通道已经关闭..")
		}

	}
}

func main() {
	ch1 := make(chan int)
	ch2 := make(chan int)

	select {
	case <-ch1:
		fmt.Println("case1可以执行..")
	case <-ch2:
		fmt.Println("case2可以执行..")
	case <-time.After(3 * time.Second):
		fmt.Println("case执行。。。timeout..")
		// default:
		// 	fmt.Println("执行default。。")
	}
}
