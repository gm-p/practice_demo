package main

import "fmt"

// if语句及if变体

func main1() {
	var a int = 10
	// var a = 10
	// a := 10

	if a < 20 {
		fmt.Printf("a 小于20 \n")
	}
	fmt.Printf("a的值为: %d\n", a)

	if num := 10; num%2 == 0 {
		fmt.Println(num, "is even")
	} else {
		fmt.Println(num, "is odd")
	}
}

// switch
/*
Go里面switch默认相当于每个case最后带有break，匹配成功后不会自动向下执行其他case，而是跳出整个switch, 但是可以使用fallthrough强制执行后面的case代码
switch没有表达式，它会匹配true
变量 var1 可以是任何类型，而 val1 和 val2 则可以是同类型的任意值。类型不被局限于常量或整数，但必须是相同的类型；或者最终结果为相同类型的表达式。 您可以同时测试多个可能符合条件的值，使用逗号分割它们，例如：case val1, val2, val3
*/

func main2() {
	var grade string = "B"
	var marks int = 90

	switch marks {
	case 90:
		grade = "A"
	case 80:
		grade = "B"
	case 50, 60, 70:
		grade = "C"
	default:
		grade = "D"
	}

	switch {
	case grade == "A":
		fmt.Printf("优秀\n")
	case grade == "B", grade == "C":
		fmt.Printf("良好\n")
	case grade == "D":
		fmt.Printf("及格\n")
	case grade == "F":
		fmt.Printf("不及格\n")
	default:
		fmt.Printf("差\n")
	}
	fmt.Printf("您的等级是 %s\n", grade)
}

// fallthrough 贯通后续（下一个）的case

func main3() {
	switch x := 5; x {
	default:
		fmt.Println(x)
	case 5:
		x += 10
		fmt.Println(x)
		fallthrough
	case 6:
		x += 20
		fmt.Println(x)
	}
}

func main4() {
	num := 75
	switch {
	case num >= 0 && num <= 50:
		fmt.Println("num is greater than 0 and less than 50")
	case num >= 51 && num <= 100:
		fmt.Println("num is greater than 51 and less than 100")
	case num >= 101:
		fmt.Println("num is greater than 100")
	}
}

// type-switch 用于判断某个interface变量实际存储的变量类型
func main() {
	var x interface{}

	switch i := x.(type) {
	case nil:
		fmt.Println(" x 的类型：%T", i)
	case int:
		fmt.Printf("x 是int型")
	case float64:
		fmt.Printf("x 是 float64型")
	case func(int) float64:
		fmt.Printf("x 是 func(int) 型")
	case bool, string:
		fmt.Printf("x 是 bool 或 string型")
	default:
		fmt.Printf("未知型")
	}
}
