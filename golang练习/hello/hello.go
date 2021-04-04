package main

import "fmt"

func main() {
	fmt.Println("Hello World!")

	// 常量
	const name string = "tom"
	fmt.Println(name)

	const age = 30
	fmt.Println(age)

	const name1, name2 string = "Tom", "Jay"
	fmt.Println(name1, name2)

	const name3, age1 = "Tome", 10
	fmt.Println(name3, age1)

	// 变量
	var age_1 uint8 = 31
	var age_2 = 32
	age_3 := 33
	fmt.Println(age_1, age_2, age_3)

	var age_4, age_5, age_6 int = 31, 32, 33
	fmt.Println(age_4, age_5, age_6)

	var name_1, age_7 = "Tome", 30
	fmt.Println(name_1, age_7)

	name_2, is_boy, height := "Jay", true, 180.66
	fmt.Println(name_2, is_boy, height)

	/* 输出方法
	   fmt.Print：输出到控制台（仅只是输出）

		fmt.Println：输出到控制台并换行

		fmt.Printf：仅输出格式化的字符串和字符串变量（整型和整型变量不可以）

		fmt.Sprintf：格式化并返回一个字符串，不输出。
	*/
	fmt.Print("输出到控制台不换行")
	fmt.Println("-----------")
	fmt.Println("输出到控制台并换行")
	fmt.Printf("name=%s, age=%d\n", "Tom", 30)
	fmt.Printf("name=%s, age=%d, height=%v\n", "Tom", 30, fmt.Sprintf("%.2f", 180.567))

}
