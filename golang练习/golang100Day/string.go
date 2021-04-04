// Go中的字符串是一个字节的切片。可以通过将其内容封装在“”中来创建字符串。Go中的字符串是Unicode兼容的，并且是UTF-8编码的
package main

import "fmt"

func main() {
	name := "Hello World"
	fmt.Println(name)

	// 访问单个字节
	for i := 0; i < len(name); i++ {
		fmt.Printf("%d ", name[i])
	}
	fmt.Println("")

	for i := 0; i < len(name); i++ {
		fmt.Printf("%c ", name[i])
	}
	fmt.Println("")

	s := "中国，Hello"
	for _, ch := range []rune(s) {
		fmt.Printf("%c  ", ch)
	}
}
