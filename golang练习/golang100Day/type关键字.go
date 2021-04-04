// 1.1 定义结构体
// type person struct {
// 	name string
// 	age  int
// }

// 1.2 定义接口
// typer USB interface {
// 	start()
// 	end()
// }

// 1.3 定义其他新类型
// type 类型名 Type

package main

import (
	"fmt"
	"strconv"
)

type myint int
type mystr string

func main1() {
	var i1 myint
	var i2 = 100
	i1 = 100
	fmt.Println(i1)
	fmt.Println(i1, i2)

	var name mystr
	name = "王二狗"
	var s1 string
	s1 = "李小花"
	fmt.Println(name, s1)
	//name = s1  //cannot use s1 (type string) as type mystr in assignment

	res1 := fun1()
	fmt.Println(res1(10, 20))
}

// 1.4 定义函数类型
type my_fun func(int, int) string

func fun1() my_fun {
	fun := func(a, b int) string {
		s := strconv.Itoa(a) + strconv.Itoa(b)
		return s
	}
	return fun
}

// 2. 类型别名
func main2() {
	var i1 myint1
	var i2 = 180
	i1 = 180
	fmt.Println(i1)
	fmt.Println(i1, i2)

	var i3 myint2 // int的别名
	i3 = i2
	fmt.Println(i1, i2, i3)
}

type myint1 int
type myint2 = int // 不是重新定义类型，只是给int起别名

//3. 非本地类型不能定义方法
// 解决办法：
// 将类型别名改为类型定义： type MyDuration time.Duration，也就是将 MyDuration 从别名改为类型。
// 将 MyDuration 的别名定义放在 time 包中

// 4. 在结构体成员嵌入时使用别名
type Person struct {
	name string
}

func (p Person) Show() {
	fmt.Println("Person-->", p.name)
}

type People = Person // 类型别名

type Student struct {
	Person
	People
}

func (p People) Show2() {
	fmt.Println("People---------->", p.name)
}

func main() {
	var s Student

	s.People.name = "李小花"
	s.Person.name = "王二狗"

	s.Person.Show()
	s.People.Show2()
	fmt.Printf("%T, %T\n", s.Person, s.People)
}
