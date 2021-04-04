package main

import (
	"encoding/json"
	"fmt"
)

type Person struct {
	Name string
	Age  int
}

func main1() {
	var p1 Person
	p1.Name = "Tom"
	p1.Age = 30
	fmt.Println("p1 = ", p1)

	var p2 = Person{Name: "Burke", Age: 31}
	fmt.Println("p2 = ", p2)

	p3 := Person{Name: "Aaron", Age: 32}
	fmt.Println("p3 = ", p3)

	// 匿名结构体
	p4 := struct {
		Name string
		Age  int
	}{Name: "匿名", Age: 33}
	fmt.Println("p4 = ", p4)
}

// 生成json
type Result struct {
	Code    int    `json:"code"`
	Message string `json:"msg"`
}

func main2() {
	var res Result
	res.Code = 200
	res.Message = "success"

	// 序列化
	jsons, errs := json.Marshal(res)
	if errs != nil {
		fmt.Println("json marshal error: ", errs)
	}
	fmt.Println("json data: ", string(jsons))

	// 反序列化
	var res2 Result
	errs = json.Unmarshal(jsons, &res2)
	if errs != nil {
		fmt.Println("json unmarshal error: ", errs)
	}
	fmt.Println("res2: ", res2)
}

// 改变数据
func main() {
	var res Result
	res.Code = 200
	res.Message = "success"
	toJson(&res)

	setData(&res)
	toJson(&res)
}

func setData(res *Result) {
	res.Code = 500
	res.Message = "fail"
}

func toJson(res *Result) {
	jsons, errs := json.Marshal(res)
	if errs != nil {
		fmt.Println("json marshal error: ", errs)
	}
	fmt.Println("json data: ", string(jsons))
}
