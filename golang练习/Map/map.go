package main

import (
	"encoding/json"
	"fmt"
)

/*
Map 集合是无序的 key-value 数据结构。

Map 集合中的 key / value 可以是任意类型，但所有的 key 必须属于同一数据类型，所有的 value 必须属于同一数据类型，key 和 value 的数据类型可以不相同。
*/
func main1() { // map声明
	var p1 map[int]string
	p1 = make(map[int]string)
	p1[1] = "Tom"
	fmt.Println("p1: ", p1)

	var p2 map[int]string = map[int]string{}
	p2[1] = "Tom"
	fmt.Println("p2: ", p2)

	var p3 map[int]string = make(map[int]string)
	p3[1] = "Tom"
	fmt.Println("p3: ", p3)

	p4 := map[int]string{}
	p4[1] = "Tom"
	fmt.Println("p4: ", p4)

	p5 := make(map[int]string)
	p5[1] = "Tom"
	fmt.Println("p5: ", p5)

	p6 := map[int]string{
		1: "Tom",
	}
	fmt.Println("p6: ", p6)

}

// 生成json
func main2() {
	res := make(map[string]interface{})
	res["code"] = 200
	res["msg"] = "success"
	res["data"] = map[string]interface{}{
		"username": "Tom",
		"age":      30,
		"hobby":    []string{"读书", "爬山"},
	}
	fmt.Println("map data: ", res)

	// 序列化
	jsons, errs := json.Marshal(res)
	if errs != nil {
		fmt.Println("json marshal error: ", errs)
	}
	fmt.Println("")
	fmt.Println("-----map to json ----")
	fmt.Println("json data :", string(jsons))

	// 反序列化
	res2 := make(map[string]interface{})
	errs = json.Unmarshal([]byte(jsons), &res2)
	if errs != nil {
		fmt.Println("json marshal error: ", errs)
	}
	fmt.Println("")
	fmt.Println("--- json to map ---")
	fmt.Println("map data: ", res2)
}

// 编辑和删除
func main() {
	person := map[int]string{
		1: "Tom",
		2: "Aaron",
		3: "John",
	}
	fmt.Println("data: ", person)

	delete(person, 2)
	fmt.Println("data: ", person)

	person[2] = "jack"
	person[3] = "Kevin"
	fmt.Println("data: ", person)
}
