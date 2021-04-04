// 数组的语法
// 声明和初始化数组
// var variable_name [SIZE]variable_type

// var balance [10]float32
// var balance = [5]float32{1000.0, 2.0, 3.4, 7.0, 50.0}
// var balance = []float32{100.0, 2.0, 3.4, 7.0, 50.0}

// var a [4]float32 // 等价于 var arr2 = [4]float32{}
// fmt.Println(a)  // [0 0 0 0]

// var b = [5]string{"ruby", "王二狗", "rose"}
// fmt.Println(b)  // [ruby 王二狗 rose]

// var c = [5]int{'A', 'B', 'C', 'D', 'E'}  // byte
// fmt.Println(c) // [65 66 67 68 69]

// d := [...]int{1, 2, 3, 4, 5} // 根据元素个数，设置数组的大小
// fmt.Println(d)  // [1 2 3 4 5]

// e := [5]int{4: 100}
// fmt.Println(e)   // [0 0 0 0 100]

// f := [...]int{0: 1, 4: 1, 9: 1}
// fmt.Println(f)  // [1 0 0 0 1 0 0 0 0 1]

package main

import "fmt"

func main1() {
	var n [10]int
	var i, j int

	for i = 0; i < 10; i++ {
		n[i] = i + 100
	}

	for j = 0; j < 10; j++ {
		fmt.Printf("Element[%d] = %d\n", j, n[j])
	}

	a := [...]float64{67.7, 99.8, 21, 78}
	fmt.Println("length of a is", len(a))
	fmt.Println("cap of a is", cap(a))
	fmt.Println(a)

	for i = 0; i < len(a); i++ { // 遍历
		fmt.Printf("%d th element of a is %.2f\n", i, a[i])
	}

	// range 遍历
	sum := float64(0)
	for i, v := range a { // for _, v := range a    忽略索引
		fmt.Printf("%d the element of a is %.2f\n", i, v)
		sum += v
	}
	fmt.Println("\nsum of all elements of a", sum)
}

// 多维数组
// var variable_name [SIZE1][SIZE2]...[SIZEN]variable_type
// var threedim [5][10][4]int
func main2() {
	a := [3][4]int{
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11},
	}
	for _, a1 := range a {
		fmt.Println(a1)
		for _, a2 := range a1 {
			fmt.Println(a2)
		}
		fmt.Println("*********")
	}
}

// 数组是值类型
func main() {
	a := [...]string{"USA", "China", "India", "Germany", "France"}
	b := a             // 复制
	b[0] = "Singapore" // 修改是副本不影响a
	fmt.Println("a is ", a)
	fmt.Println("b is ", b)
}
