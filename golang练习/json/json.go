package main

import (
	"encoding/json"
	"fmt"
)

/*
{
    "resultcode": "200",
    "reason": "Return Successd!",
    "result": {
        "province": "浙江",
        "city": "杭州",
        "areacode": "0571",
        "zip": "310000",
        "company": "中国移动",
        "card": ""
    }
}
*/

type MobileInfo struct {
	Resultcode string `json:"resultcode"`
	Reason     string `json:"reason"`
	Result     struct {
		Province string `json:"province"`
		City     string `json:"city"`
		Areacode string `json:"areacode"`
		Zip      string `json:"zip"`
		Company  string `json:"company"`
		Card     string `json:"card"`
	} `json:"result"`
}

func main() {
	jsonStr := `
		{
			"resultcode": "200",
			"reason": "Return Successd!",
			"result": {
				"province": "浙江",
				"city": "杭州",
				"areacode": "0571",
				"zip": "310000",
				"company": "中国移动",
				"card": ""
			}
		}
	`

	var mobile MobileInfo
	err := json.Unmarshal([]byte(jsonStr), &mobile)
	if err != nil {
		fmt.Println(err.Error())
	}
	fmt.Println(mobile.Resultcode)
	fmt.Println(mobile.Reason)
	fmt.Println(mobile.Result.City)
}

// 类型不确定
// 弱类型解析方法 WeakDecode()
// type MobileInfo struct {
// 	Resultcode string `json:"resultcode"`
// }

// func main() {
// 	jsonStr := `
// 		{
// 			"resultcode": 200
// 		}
// 	`

// 	var result map[string]interface{}
// 	err := json.Unmarshal([]byte(jsonStr), &result)
// 	if err != nil {
// 		fmt.Println(err.Error())
// 	}

// 	var mobile MobileInfo
// 	err = mapstructure.WeakDecode(result, &mobile) // 这是一个包 https://github.com/mitchellh/mapstructure
// 	if err != nil {
// 		fmt.Println(err.Error())
// 	}

// 	fmt.Println(mobile.Resultcode)
// }

// 参数不固定
// type Family struct {
// 	LastName string
// }

// type Location struct {
// 	City string
// }

// type Person struct {
// 	Family    `mapstructure:",squash"`
// 	Location  `mapstructure:",squash"`
// 	FirstName string
// }

// func main() {
// 	input := map[string]interface{}{
// 		"FirstName": "Mitchell",
// 		"LastName":  "Hashimoto",
// 		"City":      "San Francisco",
// 	}

// 	var result Person
// 	err := mapstructure.Decode(input, &result)
// 	if err != nil {
// 		panic(err)
// 	}

// 	fmt.Println(result.FirstName)
// 	fmt.Println(result.LastName)
// 	fmt.Println(result.City)
// }
