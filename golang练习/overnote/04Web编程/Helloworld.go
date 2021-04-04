package main

import (
	"fmt"
	"net/http"
)

func helloworld(w http.ResponseWriter, r *http.Request) {

	// 默认不会解析，需要先解析表单
	// err := r.ParseForm()
	// if err != nil {
	// 	fmt.Println("参数解析出错:", err)
	// 	return
	// }

	// fmt.Println("path", r.URL.Path) // 输出   /
	// fmt.Println(r.Form)             // 输出 map[id:[4] name:[张三]]

	fmt.Fprintf(w, "Hello World!")
}

func main() {
	http.HandleFunc("/hello", helloworld)

	// files := http.FileServer(http.Dir("./public"))
	// http.Handle("/static/", http.StringPrefix("/static/", files))

	server := http.Server{
		Addr: ":8000",
	}
	server.ListenAndServe()
}
