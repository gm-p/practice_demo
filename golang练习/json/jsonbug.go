package main

import (
	"bytes"
	"encoding/json"
	"fmt"
	"reflect"
)

func main() {
	jsonStr := `{"number": 1234567}`
	result := make(map[string]interface{})
	err := json.Unmarshal([]byte(jsonStr), &result)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println(result) // 输出map[number:1.234567e+06]

	// 方法一：强制类型转换
	fmt.Println(int(result["number"].(float64))) //1234567

	// 方法二：尽量避免使用interface，对 json 字符串结构定义结构体，快捷方法可使用在线工具：https://mholt.github.io/json-to-go/
	type Num struct {
		Number int `json:"number"`
	}

	var result2 Num
	err = json.Unmarshal([]byte(jsonStr), &result2)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println(result2) //{1234567}

	// 方法三 使用 UseNumber() 方法
	result3 := make(map[string]interface{})
	d := json.NewDecoder(bytes.NewReader([]byte(jsonStr)))
	d.UseNumber()
	err = d.Decode(&result3)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println(result3)                                                    //map[number:1234567]
	fmt.Println(fmt.Sprintf("type: %v", reflect.TypeOf(result3["number"]))) // type: json.Number
	// json.Number 其实就是字符串类型
	// 转成 int64
	numInt, _ := result3["number"].(json.Number).Int64()
	fmt.Println(fmt.Sprintf("value: %v, type: %v", numInt, reflect.TypeOf(numInt))) //value: 1234567, type: int64

	// 转成 string
	numStr := result3["number"].(json.Number).String()
	fmt.Println(fmt.Sprintf("value: %v, type: %v", numStr, reflect.TypeOf(numStr))) // value: 1234567, type: string
}
