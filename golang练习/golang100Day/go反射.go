// Go 语言提供了一种机制在运行时更新变量和检查它们的值、调用它们的方法，但是在编译时并不知道这些变量的具体类型，这称为反射机制
package main

import (
	"fmt"
	"reflect"
)

func main1() {
	// 反射操作：通过反射，可以获取一个接口类型变量的 类型和数值
	var x float64 = 3.4
	fmt.Println("type: ", reflect.TypeOf(x))   // type: float64
	fmt.Println("value: ", reflect.ValueOf(x)) // value: 3.4

	fmt.Println("-----------")

	// 根据反射的值，来获取对应的类型和数值
	v := reflect.ValueOf(x)
	fmt.Println("kind is float64: ", v.Kind() == reflect.Float64)
	fmt.Println("tyep: ", v.Type())
	fmt.Println("value:", v.Float())
}

// 反射可以将“接口类型变量”转换为“反射类型对象”，反射类型指的是reflect.Type和reflect.Value这两种

// 反射三大定律
// 1. 反射可以从接口值得到反射对象
// 反射是一种检测存储在 interface中的类型和值机制。这可以通过 TypeOf函数和 ValueOf函数得到
// 2. 反射可以从反射对象获得接口值
// 它将 ValueOf的返回值通过 Interface()函数反向转变成 interface变量
// 3. 如果需要操作一个反射变量，则其值必须可以修改
// 反射变量可设置的本质是它存储了原变量本身，这样对反射变量的操作，就会反映到原变量本身

// 从reflect.Value中获取接口interface的信息
// 已知原有类型
// realValue := value.Interface().(已知的类型)

func main2() {
	var num float64 = 1.2345

	pointer := reflect.ValueOf(&num)
	value := reflect.ValueOf(num)

	// 可以理解为“强制转换”，但是需要注意的时候，转换的时候，如果转换的类型不完全符合，则直接panic
	// Golang 对类型要求非常严格，类型一定要完全符合
	// 如下两个，一个是*float64，一个是float64，如果弄混，则会panic
	convertPointer := pointer.Interface().(*float64)
	convertValue := value.Interface().(float64)

	fmt.Println(convertPointer)
	fmt.Println(convertValue)
}

// 未知原有类型
type Person struct {
	Name string
	Age  int
	Sex  string
}

func (p Person) Say(msg string) {
	fmt.Println("hello, ", msg)
}

func (p Person) PrintInfo() {
	fmt.Printf("姓名： %s, 年龄: %d, 性别：%s\n", p.Name, p.Age, p.Sex)
}

func main3() {
	p1 := Person{"王二狗", 30, "男"}

	DoFileAndMethod(p1)
}

// 通过接口来获取任意参数
func DoFileAndMethod(input interface{}) {

	getType := reflect.TypeOf(input)            // 先获取input的类型
	fmt.Println("get Type is:", getType.Name()) // Person
	fmt.Println("get Kind is:", getType.Kind()) // struuct

	getValue := reflect.ValueOf(input)
	fmt.Println("get all fields is :", getValue) // {王二狗 30 男}

	// 获取方法字段
	// 1. 先获取interface的reflect.Type，然后通过NumField进行遍历
	// 2. 再通过reflect.Type的Field获取其Field
	// 3. 最后通过Field的Interface()得到对应的value
	for i := 0; i < getType.NumField(); i++ {
		field := getType.Field(i)
		value := getValue.Field(i).Interface() // 获取第i个值
		fmt.Printf("字段名称：%s, 字段类型：%s, 字段数值：%v\n", field.Name, field.Type, value)
	}

	// 通过反射，操作方法
	// 1. 先获取interface的reflect.Type，然后通过.NumMethod进行遍历
	// 2. 再公国reflect.Type的Method获取其Method
	for i := 0; i < getType.NumMethod(); i++ {
		method := getType.Method(i)
		fmt.Printf("方法名称：%s,方法类型：%v\n", method.Name, method.Type)
	}
}

func main4() {
	var num float64 = 1.2345
	fmt.Println("old value of pointer:", num)

	// 通过reflect.VAlueOf后去num中的reflect.Value 。注意：参数必须是指针才能修改其值
	pointer := reflect.ValueOf(&num)
	newValue := pointer.Elem()

	fmt.Println("type of pointer:", newValue.Type())
	fmt.Println("settability of pointer:", newValue.CanSet())

	// 重新赋值
	newValue.SetFloat(77)
	fmt.Println("new value of pointer:", num)

	// 如果reflect.ValueOf的参数不是指针，会panic
}

func (p Person) Test(i, j int, s string) {
	fmt.Println(i, j, s)
}

func main5() {
	p2 := Person{"Ruby", 30, "男"}
	// 1.要通过反射来调用起对应的方法，必须要先通过reflect.ValueOf(interface)来获取到reflect.Value,得到反射类型对象后才能做下一步处理
	getValue := reflect.ValueOf(p2)

	// 2. 一定要指定参数为正确的方法名
	// 先看看有没有参数的调用方法
	methodValue1 := getValue.MethodByName("PrintInfo")
	fmt.Printf("Kind: %s, Type: %s\n", methodValue1.Kind(), methodValue1.Type())
	methodValue1.Call(nil) // 没有参数，直接写nil

	args1 := make([]reflect.Value, 0) // 或者创建一个空切片也可以
	methodValue1.Call(args1)

	// 有参数的方法调用
	methodValue2 := getValue.MethodByName("Say")
	fmt.Printf("Kind: %s, Type: %s\n", methodValue2.Kind(), methodValue2.Type())
	args2 := []reflect.Value{reflect.ValueOf("反射机制")}
	methodValue2.Call(args2)

	methodValue3 := getValue.MethodByName("Test")
	fmt.Println("Kind: %s, Type: %s\n", methodValue3.Kind(), methodValue3.Type())
	args3 := []reflect.Value{reflect.ValueOf(100), reflect.ValueOf(200), reflect.ValueOf("Hello")}
	methodValue3.Call(args3)
}

func main() {
	// 函数反射
	f1 := fun1
	value := reflect.ValueOf(f1)
	fmt.Printf("Kind: %s, Type: %s\n", value.Kind(), value.Type()) // Kind: func, Type: func()

	value2 := reflect.ValueOf(fun2)
	fmt.Printf("Kind: %s, Type: %s\n", value2.Kind(), value2.Type()) // Kind: func, Type: func(int, string)

	// 通过反射调用函数
	value.Call(nil)

	value2.Call([]reflect.Value{reflect.ValueOf(100), reflect.ValueOf("hello")})
}

func fun1() {
	fmt.Println("我是函数func1(), 无参数...")
}

func fun2(i int, s string) {
	fmt.Println("我是函数fun2(), 有参数。。", i, s)
}
