// 结构体的定义
// type struct_variable_type struct {
// 	member definition
// 	member definition
// 	...
// 	member definition
// }

// 结构体初始化
// p := Person{"Tom", 25}  // 按照顺序提供初始值
// p := Person{age:24, name:"Tom"} // 通过field:value的方式初始化
// p := new(Peron)  // new方式，未设置初始值的，会赋予类型的默认初始值

package main

import "fmt"

type Books struct {
	title   string
	author  string
	subject string
	book_id int
}

func main() {
	var Book1 Books
	var Book2 Books

	Book1.title = "Go 语言"
	Book1.author = "www.ruoob.com"
	Book1.subject = "Go 语言教程"
	Book1.book_id = 6495407

	Book2.title = "Python 教程"
	Book2.author = "www.runoob.com"
	Book2.subject = "Python 语言教程"
	Book2.book_id = 6495700

	fmt.Printf("Book 1 title: %s\n", Book1.title)
	fmt.Printf("Book 1 author: %s\n", Book1.author)
	fmt.Printf("Book 1 subject: %s\n", Book1.subject)
	fmt.Printf("Book 1 book_id: %d\n", Book1.book_id)

	fmt.Printf("Book 2 title: %s\n", Book2.title)
	fmt.Printf("Book 2 author: %s\n", Book2.author)
	fmt.Printf("Book 2 subject: %s\n", Book2.subject)
	fmt.Printf("Book 2 book_id: %d\n", Book2.book_id)

	printBook(&Book2)

	printBook2(Book1)
}

// 结构体指针
// var struct_pointer *Books
// struct_pointer = &Book1;
// 使用结构体指针访问结构体成员，使用 "." 操作符
func printBook(book *Books) {
	fmt.Printf("Book title: %s\n", book.title)
	fmt.Printf("Book author: %s\n", book.author)
	fmt.Printf("Book subject: %s\n", book.subject)
	fmt.Printf("Book book_id: %d\n", book.book_id)
}

// 结构体实例化也可以是这样
type Book struct {
}

func (s Book) String() string {
	return "data"
}

func main2() {
	fmt.Printf("%s\n", Book{})
}

// 结构体的匿名字段
// 在类型中，使用不写字段名的方式，使用另一个类型
type Human struct {
	name   string
	age    int
	weight int
}

type Student struct {
	Human      // 匿名字段，默认Student就包含了Human的所有字段
	speciality string
}

func main3() {
	mark := Student{Human{"Mark", 25, 120}, "Computer Science"}
	fmt.Println("His name is ", mark.name)
	fmt.Println("His age is ", mark.age)
	fmt.Println("His weight is ", mark.weight)
	fmt.Println("His speciality is ", mark.speciality)

	mark.speciality = "AI"
	fmt.Println("Mark changed his speciality")
	fmt.Println("His speciality is ", mark.speciality)

	fmt.Println("Mark become old")
	mark.age = 46
	fmt.Println("His age is ", mark.age)

	fmt.Println("Mark is not an athlet anymore")
	mark.weight += 60
	fmt.Println("His weight is ", mark.weight)
}

// 结构体嵌套
type Address struct {
	city, state string
}

type Person struct {
	name    string
	age     int
	address Address
}

func main4() {
	var p Person
	p.name = "Naveen"
	p.age = 50
	p.address = Address{
		city:  "Chicago",
		state: "Illinols",
	}
	fmt.Println("Name:", p.name)
	fmt.Println("Age:", p.age)
	fmt.Println("City:", p.address.city)
	fmt.Println("State:", p.address.state)
}

// 提升字段
// 在结构体中属于匿名结构体的字段称为提升字段

type Person1 struct {
	name string
	age  int
	Address
}

func main5() {
	var p Person1
	p.name = "Naveen"
	p.Address = Address{
		city:  "Chicago",
		state: "Illinois",
	}
	fmt.Println("Name:", p.name)
	fmt.Println("Age:", p.age)
	fmt.Println("City:", p.city)   // 提升字段
	fmt.Println("State:", p.state) // 提升字段
}

// 结构体比较
// 结构体是值类型，如果每个字段具有可比较型，则是可比较的
type name struct {
	firstName string
	lastName  string
}

func main6() {
	name1 := name{"Steve", "Jobs"}
	name2 := name{"Steve", "Jobs"}
	if name1 == name2 {
		fmt.Println("name1 and name2 are equal")
	} else {
		fmt.Println("name1 and name2 are not equal")
	}

	name3 := name{firstName: "Steve", lastName: "Jobs"}
	name4 := name{}
	name4.firstName = "Steve"
	if name3 == name4 {
		fmt.Println("name3 and name4 are equal")
	} else {
		fmt.Println("name3 and name4 are not equal")
	}
}

// 如果结构体包含的字段是不可比较的，那么结构体是不可比较的
type image struct {
	data map[int]int
}

// func main() {
// 	image1 := image{data: map[int]int{
// 		0: 155,
// 	}}
// 	image2 := image{data: map[int]int{
// 		0: 155,
// 	}}
// 	if image1 == image2 {  // 编译报错
// 		fmt.Println("image1 and image2 are equal")
// 	}
// }

// 结构体作为函数参数
func printBook2(book Books) {
	fmt.Printf("Book title: %s\n", book.title)
	fmt.Printf("Book author: %s\n", book.author)
	fmt.Printf("Book subject: %s\n", book.subject)
	fmt.Printf("Book book_id: %d\n", book.book_id)
}

// make用于内建类型（map、slice 和channel）的内存分配
// new(T)分配了零值填充的T类型的内存空间，并且返回其地址