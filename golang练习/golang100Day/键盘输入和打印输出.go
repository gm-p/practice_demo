// 格式化打印占位符：
// 			%v,原样输出
// 			%T，打印类型
// 			%t,bool类型
// 			%s，字符串
// 			%f，浮点
// 			%d，10进制的整数
// 			%b，2进制的整数
// 			%o，8进制
// 			%x，%X，16进制
// 				%x：0-9，a-f
// 				%X：0-9，A-F
// 			%c，打印字符
// 			%p，打印地址

package main

import (
	"bufio"
	"fmt"
	"os"
)

func main1() {
	a := 100
	b := 3.14
	c := true
	d := "Hello World"
	e := `Ruby`
	f := 'A'
	fmt.Printf("%T, %b\n", a, a)
	fmt.Printf("%T, %f\n", b, b)
	fmt.Printf("%T, %t\n", c, c)
	fmt.Printf("%T, %s\n", d, d)
	fmt.Printf("%T, %s\n", e, e)
	fmt.Printf("%T, %d, %c\n", f, f, f)
	fmt.Println("--------------------")
	fmt.Printf("%v\n", a)
	fmt.Printf("%v\n", b)
	fmt.Printf("%v\n", c)
	fmt.Printf("%v\n", d)
	fmt.Printf("%v\n", e)
	fmt.Printf("%v\n", f)
}

// fmt包读取键盘输入
func main2() {
	var x int
	var y float64
	fmt.Println("请输入一个整数，一个浮点数:")
	fmt.Scanln(&x, &y)
	fmt.Printf("x的数值：%d, y的数值:%f\n", x, y)

	fmt.Scanf("%d,%f", &x, &y) // 输入时x与y必须用逗号分隔
	fmt.Printf("x: %d, y: %f\n", x, y)
}

// bufio包读取

func main() {
	fmt.Println("请输入一个字符串：")
	reader := bufio.NewReader(os.Stdin)
	s1, _ := reader.ReadString('\n')
	fmt.Println("读到的数据：", s1)
}
