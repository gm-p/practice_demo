package main

import "fmt"

func main1() {
	var a int = 10

	// 获取变量地址
	fmt.Printf("变量的地址：%x\n", &a)

	var ip *int // 声明指针
	ip = &a
	fmt.Printf("a 变量的地址是：%x\n", &a)
	fmt.Printf("ip 变量的存储地址：%x\n", ip)
	fmt.Printf("*ip变量的值：%d\n", *ip)
}

type name int8
type first struct {
	a int
	b bool
	name
}

func main2() {
	a := new(first)
	a.a = 1
	a.name = 11
	fmt.Println(a.a, a.b, a.name) // 未初始化的变量自动赋上默认值

	var b = first{1, true, 2}
	var c *first = &b
	fmt.Println(b.a, b.b, b.name, &b, c.a, &c, (*c).a)
}

func main3() {
	a := 255
	b := &a
	fmt.Println("address of a is ", b)
	fmt.Println("vlaue of a is ", *b) // 获取指针的值

	*b++
	fmt.Println("new value of a is ", a) // 指针操作改变变量的值
}

// 使用指针传递函数的参数
func change(val *int) {
	*val = 55
}

func main4() {
	a := 58
	fmt.Println("value of a before function call is ", a)
	b := &a
	change(b)
	fmt.Println("value of a afer function call is ", a)
}

// 不要将一个指向数组的指针传递给函数。使用切片
func modify(arr *[3]int) {
	(*arr)[0] = 90 // 或者 arr[0] = 90
}

func main5() {
	a := [3]int{89, 90, 91}
	modify(&a)
	fmt.Println(a)
}

func modifySlice(sls []int) { // 切片
	sls[0] = 90
}

func main6() {
	a := [3]int{89, 90, 91}
	modifySlice(a[:])
	fmt.Println(a)
}

// 指针数组
const MAX int = 3

func main7() {
	a := []int{10, 100, 200}
	var i int
	var ptr [MAX]*int

	for i = 0; i < MAX; i++ {
		ptr[i] = &a[i]
	}

	for i = 0; i < MAX; i++ {
		fmt.Printf("a[%d] = %d\n", i, *ptr[i])
	}
}

// 指针的指针
func main8() {
	var a int
	var ptr *int
	var pptr **int

	a = 300
	ptr = &a
	pptr = &ptr

	fmt.Printf("变量 a = %d\n", a)
	fmt.Printf("指针变量 *ptr = %d\n", *ptr)
	fmt.Printf("指向指针的指针变量 **pptr = %d\n", **pptr)
}

// 指针作为函数参数
func main() {
	var a int = 100
	var b int = 200

	fmt.Printf("交换前 a 的值: %d\n", a)
	fmt.Printf("交换前 b 的值: %d\n", b)

	swap(&a, &b)

	fmt.Printf("交换后 a 的值: %d\n", a)
	fmt.Printf("交换后 b 的值：%d\n", b)
}

func swap(x *int, y *int) {
	*y, *x = *x, *y
}
