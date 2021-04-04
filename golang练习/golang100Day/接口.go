// 接口定义了一组方法，如果某个对象实现了某个接口的所有方法，则此对象就实现了该接口

// 定义接口
// type interface_name interface {
// 	method_name1 [return_type]
// 	method_name2 [return_type]
// 	method_name3 [return_type]
// 	...

// 	method_namen [return_type]
// }

// // 定义结构体
// type struct_name struct {
// 	/*variables*/
// }

// // 实现接口方法
// func (struct_name_variable struct_name) method_name1()[return_type] {
// 	//方法实现
// }
// ...
// func (struct_name_variable struct_name) method_namen() [return_type]{
// 	// 方法实现
// }

package main

import "fmt"

type Phone interface {
	call()
}

type NokiaPhone struct {
}

func (nokiaPhone NokiaPhone) call() {
	fmt.Println("I am Nokia, I can call you!")
}

type IPhone struct {
}

func (iPhone IPhone) call() {
	fmt.Println("I am iPhone, I can call you!")
}

func main1() {
	var phone Phone

	phone = new(NokiaPhone)
	phone.call()

	phone = new(IPhone)
	phone.call()
}

/*
interface可以被任意的对象实现
一个对象可以实现任意多个interface
任意的类型都实现了空interface(我们这样定义：interface{})，也就是包含0个method的interface
*/

// interface 值

type Human struct {
	name  string
	age   int
	phone string
}

type Student struct {
	Human  // 匿名字段
	school string
	loan   float32
}

type Employee struct {
	Human   // 匿名字段
	company string
	money   float32
}

func (h Human) SayHi() {
	fmt.Printf("Hi, I am %s you can call me on %s\n", h.name, h.phone)
}

func (h Human) Sing(lyrics string) {
	fmt.Println("La La La La ...", lyrics)
}

func (e Employee) SayHi() {
	fmt.Printf("Hi, I am %s, I work at %s. Call me on %s\n", e.name, e.company, e.phone)
}

type Men interface {
	SayHi()
	Sing(lyrics string)
}

func main2() {
	mike := Student{Human{"Mike", 25, "222-222-XXX"}, "MIT", 0.00}
	paul := Student{Human{"Paul", 26, "111-222-XXX"}, "Harvard", 100}
	sam := Employee{Human{"Sam", 36, "444-222-XXX"}, "Golang Inc.", 1000}
	tom := Employee{Human{"Tom", 46, "555-222-XXX"}, "Things Ltd.", 5000}

	var i Men
	i = mike
	fmt.Println("This is Mike, a Student:")
	i.SayHi()
	i.Sing("November rain")

	i = tom
	fmt.Println("This is Tom, an Employee")
	i.SayHi()
	i.Sing("Born to be wild")

	fmt.Println("Let's use a slice of Men and see whtat happens")
	x := make([]Men, 3)
	x[0], x[1], x[2] = paul, sam, mike
	for _, value := range x {
		value.SayHi()
	}
}

// interface参数，让函数接受各种类型的参数

// 嵌入interface
type Human1 interface {
	Len()
}

type Student2 interface {
	Human1
}

type Test struct {
}

func (h *Test) Len() {
	fmt.Println("成功")
}

func main3() {
	var s Student2
	s = new(Test)
	s.Len()
}

// 接口断言

// 空接口 interface{}没有定义任何函数，因此 Go 中所有类型都实现了空接口
// 当一个函数的形参是interface{}，那么在函数中，需要对形参进行断言，从而得到它的真实类型

// 安全类型断言
// <目标类型的值>, <布尔参数> := <表达式>.(目标类型)
// 非安全类型断言
// <目标类型的值> := <表达式>.(目标类型)

func main() {
	var i1 interface{} = new(Student3)
	s := i1.(Student3) // 不安全，如果断言失败，会直接panic
	fmt.Println(s)

	var i2 interface{} = new(Student3)
	s, ok := i2.(Student3) // 安全，断言失败，也不会panic，只是ok的值为false
	if ok {
		fmt.Println(s)
	}
}

type Student3 struct {
}

// 断言还可以用switch语句判断
/*
switch ins := s.(type) {
case Triangle:
	fmt.Println("三角形...", ins.a, ins.b, ins.c)
case Circle:
	fmt.Println("圆形...", ins.radius)
case int:
	fmt.Println("整型数据...")
}*/
