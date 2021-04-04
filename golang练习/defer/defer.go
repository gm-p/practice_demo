package main

import (
	"fmt"
	"os"
)

func calc(index string, a, b int) int {
	ret := a + b
	fmt.Println(index, a, b, ret)
	return ret
}

func main1() {
	x := 1
	y := 2
	defer calc("A", x, calc("B", x, y))
	x = 3
	defer calc("C", x, calc("D", x, y))
	y = 4
}

// 结论：defer 函数定义的顺序 与 实际执的行顺序是相反的，也就是最先声明的最后才执行
func main2() {
	defer fmt.Println("1")
	defer fmt.Println("2")
	defer fmt.Println("3")

	fmt.Println("main")
}

func main3() {
	var a = 1
	var b = 2
	defer fmt.Println(a + b) // 3

	a = 2
	fmt.Println("main")
}

// 闭包
func main4() {
	var a = 1
	var b = 2

	defer func() {
		fmt.Println(a + b) // 4   // 结论：闭包获取变量相当于引用传递，而非值传递
	}()

	a = 2
	fmt.Println("main")
}

func main5() {
	var a = 1
	var b = 2

	defer func(a int, b int) {
		fmt.Println(a + b)
	}(a, b)

	a = 2

	fmt.Println("main")
}

//  return
func t1() int {
	a := 1
	defer func() {
		a++
	}()
	return a
} // 输出 1

func t2() (a int) {
	defer func() {
		a++
	}()
	return 1
} // 输出 2

func t3() (b int) {
	a := 1
	defer func() {
		a++
	}()
	return 1
} // 输出 1

func t4() (a int) {
	defer func(a int) {
		a++
	}(a)
	return 1
} // 输出 1
// return不是原子操作

// func main() {
// 	fmt.Println(t1())
// 	fmt.Println(t2())
// 	fmt.Println(t3())
// 	fmt.Println(t4())
// }

func main6() {
	defer fmt.Println("1")
	fmt.Println("main")
	os.Exit(0)
}

// 输出：main
// 结论：当os.Exit()方法退出时，defer不会被执行

// 不同协程
// func main() {
// 	GoA()
// 	time.Sleep(time.Second * 1)
// 	fmt.Println("main")
// }

// func GoA() {
// 	defer (func() {
// 		if err := recover(); err != nil {
// 			fmt.Println("panic:" + fmt.Sprintf("%s", err))
// 		}
// 	})()

// 	go GoB()
// }

// func GoB() {
// 	panic("error")
// }
