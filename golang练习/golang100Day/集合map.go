// map是无序的键值对集合，使用hash表实现，是引用类型
/*
map是无序的，每次打印出来的map都会不一样，它不能通过index获取，而必须通过key获取
map的长度是不固定的，也就是和slice一样，也是一种引用类型
内置的len函数同样适用于map，返回map拥有的key的数量
map的key可以是所有可比较的类型，如布尔型、整数型、浮点型、复杂型、字符串型……也可以键
*/

// 使用make（）创建map

//声明变量，默认map是nil
// var map_variable map[key_data_type]value_data_tyep
// 使用make
// map_variable = make(map[key_data_type]value_data_type)

// rating := map[string]float32{"C": 5, "Go": 4.5, "Python": 4.5, "C++": 2}

package main

import "fmt"

func main1() {
	var countryCapitalMap map[string]string
	// 创建集合
	countryCapitalMap = make(map[string]string)

	// map插入key-value对，各个国家对应的首都
	countryCapitalMap["France"] = "Paris"
	countryCapitalMap["Italy"] = "Rome"
	countryCapitalMap["Japan"] = "Tokyo"
	countryCapitalMap["India"] = "New Delhi"

	// 使用key输出map值
	for country := range countryCapitalMap {
		fmt.Println("Capital of ", country, "is ", countryCapitalMap[country])
	}

	// 查看元素在集合中是否存在
	captial, ok := countryCapitalMap["United States"]
	if ok {
		fmt.Println("Capital of United States is ", captial)
	} else {
		fmt.Println("Capital of United States is not present")
	}
}

// delete(map, key) 用于删除集合的元素
func main2() {
	countryCapitalMap := map[string]string{"France": "Paris", "Italy": "Rome", "Japan": "Tokyo", "India": "New Delhi"}
	fmt.Println(countryCapitalMap)

	for country := range countryCapitalMap {
		fmt.Println("Capital of ", country, "is ", countryCapitalMap[country])
	}

	delete(countryCapitalMap, "France")
	fmt.Println("Entry for France is deleted")

	fmt.Println("删除元素后 map")

	for country := range countryCapitalMap {
		fmt.Println("Capital of ", country, "is ", countryCapitalMap[country])
	}
}

// ok-idiom 获取值，可判断 key/value 是否存在
func main3() {
	m := make(map[string]int)
	m["a"] = 1
	x, ok := m["b"]
	fmt.Println(x, ok)
	x, ok = m["a"]
	fmt.Println(x, ok)
}

// len(mao)
// map 是引用类型
func main() {
	personSalary := map[string]int{
		"steve": 12000,
		"jamie": 15000,
	}
	personSalary["mike"] = 10000
	fmt.Println("Original person salary ", personSalary)
	newPersonSalary := personSalary
	newPersonSalary["mike"] = 9000
	fmt.Println("Person salary changed ", personSalary)
}
