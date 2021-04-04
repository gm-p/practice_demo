package main

import (
	"fmt"
	"net"
)

func main() {
	conn, err := net.Dial("tcp", "127.0.0.1:3000")
	if err != nil {
		fmt.Println("Dial err:", err)
		return
	}
	defer conn.Close()

	// 主动向服务器发送数据
	conn.Write([]byte("hello"))

	// 接收服务器返回数据
	buf := make([]byte, 4096)
	n, err := conn.Read(buf)
	if err != nil {
		fmt.Println("client read err:", err)
		return
	}
	fmt.Println("client receive:", string(buf[:n]))
}
