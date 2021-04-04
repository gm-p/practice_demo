package main

import "fmt"

func main() {
	// 声明切片
	var sli1 []int // nil 切片
	fmt.Printf("len = %d cap = %d slice = %v\n", len(sli1), cap(sli1), sli1)

	var sli2 = []int{} // 空切片
	fmt.Printf("len = %d cap = %d slice = %v\n", len(sli2), cap(sli2), sli2)

	var sli3 = []int{1, 2, 3, 4, 5}
	fmt.Printf("len = %d cap = %d slice = %v\n", len(sli3), cap(sli3), sli3)

	sli4 := []int{1, 2, 3, 4, 5}
	fmt.Printf("len = %d cap = %d slice = %v\n", len(sli4), cap(sli4), sli4)

	var sli5 []int = make([]int, 5, 8)
	fmt.Printf("len = %d cap = %d slice = %v\n", len(sli5), cap(sli5), sli5)

	sli6 := make([]int, 5, 9)
	fmt.Printf("len = %d cap = %d slice = %v\n", len(sli6), cap(sli6), sli6)

	// 截取切片
	sli7 := []int{1, 2, 3, 4, 5, 6}
	fmt.Printf("len = %d cap = %d slice = %v type = %T\n", len(sli7), cap(sli7), sli7, sli7)

	fmt.Println("sli7[1] = ", sli7[1])
	fmt.Println("sli7[:] = ", sli7[:])
	fmt.Println("sli7[1:] = ", sli7[1:])
	fmt.Println("sli7[:4] = ", sli7[:4])

	fmt.Println("sli7[0:3] = ", sli7[0:3])
	fmt.Printf("len = %d cap = %d slice = %v\n", len(sli7[0:3]), cap(sli7[0:3]), sli7[0:3])

	fmt.Println("sli7[0:3:4] = ", sli7[0:3:4])
	fmt.Printf("len = %d cap = %d slice = %v\n", len(sli7[0:3:4]), cap(sli7[0:3:4]), sli7[0:3:4])

	// 追加切片
	sli8 := []int{4, 5, 6}
	fmt.Printf("len = %d cap = %d slice = %v\n", len(sli8), cap(sli8), sli8)

	sli8 = append(sli8, 7)
	fmt.Printf("len = %d cap = %d slice = %v\n", len(sli8), cap(sli8), sli8)

	sli8 = append(sli8, 9)
	fmt.Printf("len = %d cap = %d slice = %v\n", len(sli8), cap(sli8), sli8)

	sli8 = append(sli8, 10)
	fmt.Printf("len = %d cap = %d slice = %v\n", len(sli8), cap(sli8), sli8)

	// 删除切片
	sli9 := []int{1, 2, 3, 4, 5, 6, 7, 8}
	fmt.Printf("len = %d cap = %d slice = %v\n", len(sli9), cap(sli9), sli9)

	// 删除尾部2个元素
	fmt.Printf("len = %d cap = %d slice = %v\n", len(sli9[:len(sli9)-2]), cap(sli9[:len(sli9)-2]), sli9[:len(sli9)-2])

	// 删除开头2个元素
	fmt.Printf("len = %d cap = %d slice = %v\n", len(sli9[2:]), cap(sli9[2:]), sli9[2:])

	// 删除中间2个元素
	sli9 = append(sli9[:3], sli9[3+2:]...)
	fmt.Printf("len = %d cap = %d slice = %v\n", len(sli9), cap(sli9), sli9)
}
