package main

import (
	"fmt"
	"io"
	"net"
)

func main() {
	/**
	Unix网络编程步骤：Server -> bind -> listen -> accept
	Go语言简化为：listen -> accept
	*/

	// 此处创建第一个套接字：设置了通信协议，Ip地址，port
	listener, err := net.Listen("tcp", "127.0.0.1:3000")
	defer listener.Close()
	if err != nil {
		fmt.Println("net listen err:", err)
		return
	}

	// 此处创建了第二个套接字：用于阻塞监听客户端连接请求（listen并未监听，accept实现了监听）
	// conn, err := listener.Accept()
	// defer conn.Close() // 套接字也是文件，需要关闭
	// if err != nil {
	// 	fmt.Println("listenr accetp err:", err)
	// 	return
	// }

	// // 读取客户端数据
	// buf := make([]byte, 4096)
	// n, err := conn.Read(buf)
	// if err != nil {
	// 	fmt.Println("conn.Read err:", err)
	// 	return
	// }

	// // 业务逻辑
	// fmt.Println("Read msg:", string(buf[:n]))
	// conn.Write([]byte("word"))

	// 监听客户端连接请求
	for {
		conn, err := listener.Accept()
		if err != nil {
			fmt.Println("listener accept err:", err)
			return
		}

		// 业务逻辑
		go handler(conn)
	}
}

func handler(conn net.Conn) {
	if conn == nil {
		panic("conn is nil")
	}
	defer conn.Close()

	// 循环读取客户端数据
	buf := make([]byte, 4096)
	for {
		n, err := conn.Read(buf)
		if err == io.EOF { // 此时 n = 0
			fmt.Println("read EOF")
			break
		}
		if err != nil {
			fmt.Println("conn.Read err:", err)
			break
		}

		fmt.Println("Server receive msg:", string(buf[:n]))
		conn.Write([]byte("word"))
	}
}
