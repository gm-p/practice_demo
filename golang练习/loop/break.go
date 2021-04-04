package main

import "fmt"

func main() {
	// break 跳出当前循环，可⽤于 for、switch、select
	for i := 1; i <= 10; i++ {
		if i == 6 {
			break
		}
		fmt.Println("i = ", i)
	}
	fmt.Println("")

	// continue 跳过本次循环，只能用于 for
	for i := 1; i < 10; i++ {
		if i == 6 {
			continue
		}
		fmt.Println("i = ", i)
	}
	fmt.Println("")

	// goto 改变函数内代码执行顺序，不能跨函数使用
	fmt.Println("Begin.......")
	for i := 1; i <= 10; i++ {
		if i == 6 {
			goto END
		}
		fmt.Println("i = ", i)
	}
END:
	fmt.Println("END......")
}
