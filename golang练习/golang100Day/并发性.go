// 协程与多线程相比，其优势体现在：协程的执行效率极高。因为子程序切换不是线程切换，而是由程序自身控制，因此，没有线程切换的开销，和多线程比，线程数量越多，协程的性能优势就越明
package main

import (
	"fmt"
	"sync"
	"time"
)

var ticket = 10

var wg sync.WaitGroup
var mutex sync.Mutex

func main1() {
	wg.Add(4)
	go saleTickets("售票口1")
	go saleTickets("售票口2")
	go saleTickets("售票口3")
	go saleTickets("售票口4")

	wg.Wait()
	//time.Sleep(5 * time.Second)
}

func saleTickets(name string) {
	rand.Seed(time.Now().UnixNano())
	defer wg.Done()
	for {
		mutex.Lock()
		if ticket > 0 {
			time.Sleep(time.Duration(rand.Intn(1000)) * time.Millisecond)
			fmt.Println(name, "售出:", ticket)
			ticket--
		} else {
			mutex.Unlock()
			fmt.Println(name, "售罄，没有票了...")
			break
		}
		mutex.Unlock()
	}
}

// 不要以共享内存的方式去通信，而要以通信的方式去共享内存

func main2() {
	/*
		WaitGroup：同步等待组
			可以使用Add(),设置等待组中要 执行的子goroutine的数量，

			在main 函数中，使用wait(),让主程序处于等待状态。直到等待组中子程序执行完毕。解除阻塞

			子gorotuine对应的函数中。wg.Done()，用于让等待组中的子程序的数量减1
	*/
	wg.Add(2)
	go fun1()
	go fun2()
	fmt.Println("main进入阻塞状态。。。等待wg中的子goroutine结束。。")
	wg.Wait() // 表示main groutine进入等待，意味着阻塞
	fmt.Println("main,解除阻塞。。")
}

func fun1() {
	for i := 1; i <= 10; i++ {
		fmt.Println("fun1...  i: ", i)
	}
	wg.Done()
}

func fun2() {
	defer wg.Done()
	for j := 1; j <= 10; j++ {
		fmt.Println("\tfun2...j,", j)
	}
}

// RWMutex 读写锁
var rwMutex *sync.RWMutex

var wg *sync.WaitGroup

func main() {
	rwMutex = new(sync.RWMutex)
	wg = new(sync.WaitGroup)
	wg.Add(3)
	go writeData(1)
	go readData(2)
	go writeData(3)

	wg.Wait()
	fmt.Println("main...over...")
}

func writeData(i int) {
	defer wg.Done()
	fmt.Println(i, "开始写：write star...")
	rwMutex.Lock() // 写操作上锁
	fmt.Println(i, "正在写：writing...")
	time.Sleep(3 * time.Second)
	rwMutex.Unlock()
	fmt.Println(i, "写结束：write over...")
}

func readData(i int) {
	defer wg.Done()

	fmt.Println(i, "开始读：read start...")

	rwMutex.RLock() // 读操作上锁
	fmt.Println(i, "正在读取数据：reading...")
	time.Sleep(3 * time.Second)
	rwMutex.RUnlock() // 读操作解锁
	fmt.Println(i, "读结束：read over...")
}
