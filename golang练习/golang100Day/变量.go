// 声明变量
// 第一种：指定变量类型，声明后若不赋值，使用默认值
// var name type
// name = value

// 第二种：根据值自行判断变量类型
// var name = value

// 第三种：省略var
// name := value

// var a int = 10
// var b = 10
// c := 10

package main

import "fmt"

var a = "Hello"
var b string = "World"
var c bool

func main1() {
	d := 100
	fmt.Println(a, b, c, d)
}

// 多变量声明
// 第一种：以逗号分隔，声明与赋值分开，若不赋值，存在默认值
// var name1, name2, name3 type
// name1, name2, name3 = v1, v2, v3

// 第二种：直接赋值，下面的变量类型可以是不同的类型
// var name1, name2, name3 = v1, v2, v3

// 第三种：集合类型
// var (
// 	name1 type1
// 	name2 tyep2
// )

func main2() {
	x := 100
	fmt.Println(&x)
	x, y := 200, "abc"
	fmt.Println(&x, x)
	fmt.Println(y)
}

// 常量
// 常量的声明
// const idnetifier [type] = value
// 显式类型定义：const b string = "abc"
// 隐式类型定义：const b = "abc"

func main3() {
	const LENGTH int = 10
	const WIDTH int = 5
	var area int
	const a, b, c = 1, false, "str" // 多重赋值

	area = LENGTH * WIDTH
	fmt.Printf("面积为：%d", area)
	fmt.Println("")
	fmt.Println(a, b, c)
}

// 常量可以作为枚举，常量组
// constt (
// 	Unknown = 0
// 	Female = 1
// 	Male = 2
// )
// 常量组中如不指定类型和初始化值，则与上一行非空常量右值相同

func main4() {
	const (
		x uint16 = 16
		y
		s = "abc"
		z
	)
	fmt.Printf("%T, %v\n", y, y)
	fmt.Printf("%T, %v\n", z, z)
}

/*
常量的注意事项：

常量中的数据类型只可以是布尔型、数字型（整数型、浮点型和复数）和字符串型

不曾使用的常量，在编译的时候，是不会报错的

显示指定类型的时候，必须确保常量左右值类型一致，需要时可做显示类型转换。这与变量就不一样了，变量是可以是不同的类型值
*/

// iota,特殊常量，可以认为是一个可以被编译器修改的常量
// iota可以被用作枚举值
// const (
// 	a = iota // 0
// 	b = iota // 1
// 	c = iota // 2
// )

// 第一个 iota 等于 0，每当 iota 在新的一行被使用时，它的值都会自动加 1
// 可以简写为
// const (
// 	a = iota
// 	b
// 	c
// )

func main() {
	const (
		a = iota // 0
		b        // 1
		c        // 2
		d = "ha" // 独立值，iota += 1
		e        // "ha"  iota += 1
		f = 100  // 100 iota += 1
		g        // 100 iota +=1
		h = iota // 7  恢复计数
		i        // 8
	)
	fmt.Println(a, b, c, d, e, f, g, h, i)
}
