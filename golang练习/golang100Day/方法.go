// 方法就是一个包含了接受者的函数
// 方法与函数的区别：方法有一个接收者
// 接收者可以是值接收者，也可以是指针接收者

package main

import (
	"fmt"
	"math"
)

type Employee struct {
	name     string
	salary   int
	currency string
}

func (e Employee) displaySalary() {
	fmt.Printf("Salary of %s is %s%d", e.name, e.currency, e.salary)
}

func main1() {
	emp1 := Employee{
		name:     "Sam Adolf",
		salary:   5000,
		currency: "$",
	}
	emp1.displaySalary()
}

// 可以定义相同的方法名
type Rectangle struct {
	width, height float64
}

type Circle struct {
	radius float64
}

func (r Rectangle) area() float64 {
	return r.width * r.height
}

func (c Circle) area() float64 {
	return c.radius * c.radius * math.Pi
}

func main2() {
	r1 := Rectangle{12, 2}
	r2 := Rectangle{9, 4}
	c1 := Circle{10}
	c2 := Circle{25}
	fmt.Println("Area of r1 is:", r1.area())
	fmt.Println("Area of r2 is:", r2.area())
	fmt.Println("area of c1 is:", c1.area())
	fmt.Println("area of c2 is:", c2.area())
}

// 指针作为接收者
func (r *Rectangle) setVal() {
	r.height = 20
}

func main4() {
	p := Rectangle{1, 2}
	s := p
	p.setVal()
	fmt.Println(p.height, s.height)
}

// 方法继承
type Human struct {
	name  string
	age   int
	phone string
}

type Student struct {
	Human  // 匿名字段
	school string
}

type Employee2 struct {
	Human
	company string
}

func (h *Human) SayHi() {
	fmt.Printf("Hi, I am %s you can call me on %s\n", h.name, h.phone)
}

func main5() {
	mark := Student{Human{"Mark", 25, "222-2222-YYYY"}, "MIT"}
	sam := Employee2{Human{"Sam", 45, "111-888-xxxx"}, "Golang Inc"}
	mark.SayHi()
	sam.SayHi()
}

// 方法重写
func (e *Employee2) SayHi() {
	fmt.Printf("Hi, I am %s, I work at %s. Call me on %s\n", e.name, e.company, e.phone)
}

func main() {
	mark := Student{Human{"Mark", 25, "222-222-YYYY"}, "MIT"}
	sam := Employee2{Human{"Sam", 45, "111-888-XXXX"}, "Golang Inc"}
	mark.SayHi()
	sam.SayHi()
}
