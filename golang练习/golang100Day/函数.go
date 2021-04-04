package main

import (
	"fmt"
	"math"
)

func main1() {
	var a int = 100
	var b int = 200
	var ret int

	ret = max(a, b)
	fmt.Printf("最大值是: %d\n", ret)
}

func max(num1, num2 int) int {
	var result int
	if num1 > num2 {
		result = num1
	} else {
		result = num2
	}
	return result
}

// 值传递
func main2() {
	// 声明函数变量
	getSquareRoot := func(x float64) float64 {
		return math.Sqrt(x)
	}

	// 使用函数
	fmt.Println(getSquareRoot(9))
}

// 引用传递
func add(a *int) int {
	*a = *a + 1
	return *a
}

func main3() {
	x := 3
	fmt.Println("x = ", x)
	x1 := add(&x)
	fmt.Println("x + 1 = ", x1)
	fmt.Println("x = ", x)
}

// 返回值
func swap(x, y string) (string, string) {
	return y, x
}

func main4() {
	a, b := swap("Mahesh", "Kumar")
	fmt.Println(a, b)
	fmt.Println(SumAndProduct(1, 2))
}

func SumAndProduct(A, B int) (add int, Multiplied int) {
	add = A + B
	Multiplied = A * B
	return
}

// 空白标志符
func rectProps(length, width float64) (float64, float64) {
	var area = length * width
	var perimeter = (length + width) * 2
	return area, perimeter
}

func main5() {
	area, _ := rectProps(10.8, 5.6)
	fmt.Printf("Area %f", area)
}

// defer 延迟(后进先出模式) 在离开方法的时候执行(报错也会执行)
func main6() {
	a := 1
	b := 2
	defer fmt.Println(b)
	fmt.Println(a)
}

func main7() {
	nums := []int{78, 109, 2, 563, 300}
	largest(nums)
}

func finished() {
	fmt.Println("Finished finding largest")
}

func largest(nums []int) {
	defer finished()
	max := nums[0]
	for _, v := range nums {
		if v > max {
			max = v
		}
	}
	fmt.Println("Largest number in ", nums, " is ", max)
}

// 延迟方法
type person struct {
	firstName string
	lastName  string
}

func (p person) fullName() {
	fmt.Printf("%s %s", p.firstName, p.lastName)
}

func main8() {
	p := person{
		firstName: "John",
		lastName:  "Smith",
	}
	defer p.fullName()
	fmt.Printf("Welcome ")
}

// 延迟参数
// 延迟函数的参数在执行延迟语句时被执行，而不是在执行实际的函数调用时执行
func printA(a int) {
	fmt.Println("value of a in deferred function ", a)
}

func main9() {
	a := 5
	defer printA(a)
	a = 10
	fmt.Println("value of a before deferred function call ", a)
}

// 堆栈的延迟
// 当一个函数有多个延迟调用时，它们被添加到一个堆栈中，并在Last In First Out（LIFO）后进先出的顺序中执行
func main() {
	name := "Abcdef"
	fmt.Printf("Original String: %s\n", string(name))
	fmt.Printf("Reversed String: ")
	for _, v := range []rune(name) {
		defer fmt.Printf("%c", v)
	}
}

/*
当外围函数中的语句正常执行完毕时，只有其中所有的延迟函数都执行完毕，外围函数才会真正的结束执行。
当执行外围函数中的return语句时，只有其中所有的延迟函数都执行完毕后，外围函数才会真正返回。
当外围函数中的代码引发运行恐慌时，只有其中所有的延迟函数都执行完毕后，该运行时恐慌才会真正被扩展至调用函数
*/
