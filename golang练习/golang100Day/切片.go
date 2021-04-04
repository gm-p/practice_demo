// 切片（动态数组）概念上像结构体包含三个元素
// 1.指针，指向数组中slice指定的开始位置
// 2.长度，即slice的长度
// 3.最大长度，也就是slice开始位置到数组的最后位置的长度

// 定义切片
// var identifier []type

// var slice1 []type = make([]type, len)
// 也可以简写为
// slice1 := make([]type, len)
// make([]T, length, capacity)

// 初始化
// s[0] = 1
// s[1] = 2
// s[2] = 3

// s := []int{1, 2, 3}

// s := arr[startIndex: endIndex]  // 前闭后开

package main

import "fmt"

func main1() {
	a := [5]int{76, 77, 78, 79, 80}
	var b []int = a[1:4]
	fmt.Println(b)
	fmt.Printf("cap: %d, len: %d", cap(b), len(b))
}

// 修改切片
// slice没有自己的任何数据。它只是底层数组的一个表示。对slice所做的任何修改都将反映在底层数组中
func main2() {
	darr := [...]int{57, 89, 90, 82, 100, 78, 67, 69, 59}
	dslice := darr[2:5]
	fmt.Println("array before ", darr)
	for i := range dslice {
		dslice[i]++
	}
	fmt.Println("array after ", darr)

	numa := [3]int{78, 79, 80}
	nums1 := numa[:]
	nums2 := numa[:]
	fmt.Println("array before change 1:", numa)
	nums1[0] = 100
	fmt.Println("array after modification to slice nums1:", numa)
	nums2[1] = 101
	fmt.Println("array after modification to slice nums2:", numa)
}

// len() 和 cap()
func main3() {
	var numbers = make([]int, 3, 5)

	printSlice(numbers)

	var num2 []int // 空切片未初始化之前默认为nil，长度为0
	printSlice(num2)
	if num2 == nil {
		fmt.Printf("切片是空的")
	}
}

func printSlice(x []int) {
	fmt.Printf("len = %d cap = %d slice = %v\n", len(x), cap(x), x)
}

func main4() {
	// 创建切片
	numbers := []int{0, 1, 2, 3, 4, 5, 6, 7, 8}
	printSlice(numbers)

	// 打印原始切片
	fmt.Println("numbers == ", numbers)

	// 打印子切片从索引1（包含）到索引4（不包含）
	fmt.Println("numbers[1:4] == ", numbers[1:4])

	fmt.Println("numbers[:3] == ", numbers[:3])

	fmt.Println("numbers[4:] == ", numbers[4:])

	numbers1 := make([]int, 0, 5)
	printSlice(numbers1)

	numbers2 := numbers[:2]
	printSlice(numbers2)

	numbers3 := numbers[2:5]
	printSlice(numbers3)
}

// append() 和 copy()
func main() {
	var numbers []int
	printSlice(numbers)

	// 允许追加空切片
	numbers = append(numbers, 0)
	printSlice(numbers)

	numbers = append(numbers, 1)
	printSlice(numbers)

	// 同时添加多个元素
	numbers = append(numbers, 2, 3, 4)
	printSlice(numbers)

	// 创建切片 numbers1 是之前切片的两倍容量
	numbers1 := make([]int, len(numbers), (cap(numbers))*2)

	// 拷贝numbers的内容到numbers1
	copy(numbers1, numbers)
	printSlice(numbers1)
}
