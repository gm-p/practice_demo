package main

import "fmt"

// for init; condition; post {}
func main1() {
	for i := 1; i <= 10; i++ {
		fmt.Printf(" %d", i)
	}

	var b int = 15
	var a int

	numbers := [6]int{1, 2, 3, 5}

	for a := 0; a < 10; a++ {
		fmt.Printf("a1 的值为：%d\n", a)
	}

	for a < b {
		a++
		fmt.Printf("a2 的值为：%d\n", a)
	}

	for i, x := range numbers {
		fmt.Printf("第 %d 位 x 的值 = %d\n", i, x)
	}
}

// break

func main2() {
	for i := 1; i <= 10; i++ {
		if i > 5 {
			break
		}
		fmt.Printf("%d ", i)
	}
	fmt.Printf("\nline after for loop")
}

// continue
func main3() {
	for i := 1; i <= 10; i++ {
		if i%2 == 0 {
			continue
		}
		fmt.Printf("%d ", i)
	}
}

// goto 无条件地转移到过程中的指定的行
// goto label;
// ...
// ...
// label: statement;
func main() {
	var a int = 10

LOOP:
	for a < 20 {
		if a == 15 {
			a = a + 1
			goto LOOP
		}
		fmt.Printf("a的值为：%d\n", a)
		a++
	}
}

// goto 统一多错误处理
// 	err := firstCheckError()
// 	if err != nil {
// 		goto onExit
// 	}
// 	err = secondCheckError()
// 	if err != nil {
// 		goto onExit
// 	}
// 	fmt.Println("Done")
// 	return
// onExit:
// 	fmt.Println(err)
// 	exitProcess()
