// Go中的错误也是一种类型。错误用内置的error 类型表示
package main

import (
	"fmt"
	"math"
	"net"
	"os"
)

func main1() {
	f, err := os.Open("test.txt")
	// if err != nil {
	// 	fmt.Println(err)
	// 	return
	// }
	if err, ok := err.(*os.PathError); ok {
		fmt.Println("File at path", err.Path, "failed to open")
		return
	}

	// 根据f进行文件的读或写
	fmt.Println(f.Name(), "opened successfully")
}

func main2() {
	addr, err := net.LookupHost("golanghost123.com")
	if err, ok := err.(*net.DNSError); ok {
		if err.Timeout() {
			fmt.Println("operation timed out")
		} else if err.Temporary() {
			fmt.Println("temporary error")
		} else {
			fmt.Println("generic error:", err)
		}
		return
	}
	fmt.Println(addr)
}

// var ErrBadPattern = errors.New("syntax error in pattern")

// func main() {
// 	files, error := Glob("[")
// 	if error != nil && error == ErrBadPattern {
// 		fmt.Println(error)
// 		return
// 	}
// 	fmt.Println("matched files", files)
// }

// 自定义错误
// 创建自定义错误可以使用errors包下的New()函数，以及fmt包下的：Errorf()函数

//errors包：
// func New(text string) error {}

//fmt包：
// func Errorf(format string, a ...interface{}) error {}

func circleArea(radius float64) (float64, error) {
	if radius < 0 {
		// return 0, errors.New("Area calculation failed, radius is less than zero")
		return 0, fmt.Errorf("Area calculation failed, radius %0.2f is less than zero", radius)
	}
	return math.Pi * radius * radius, nil
}

func main3() {
	radius := -20.0
	area, err := circleArea(radius)
	if err != nil {
		fmt.Println(err)
		return
	}
	fmt.Println("Area of circle %0.2f", area)
}

type areaError struct {
	err    string
	radius float64
}

func (e *areaError) Error() string {
	return fmt.Sprintf("radius %0.2f: %s", e.radius, e.err)
}

func circleArea2(radius float64) (float64, error) {
	if radius < 0 {
		return 0, &areaError{"radius is negative", radius}
	}
	return math.Pi * radius * radius, nil
}

func main4() {
	radius := -20.0
	area, err := circleArea2(radius)
	if err != nil {
		if err, ok := err.(*areaError); ok {
			fmt.Printf("Radius %0.2f is less than zero", err.radius)
			return
		}
		fmt.Println(err)
		return
	}
	fmt.Printf("Area of circle %0.2f", area)
}

type areaError2 struct {
	err    string
	length float64
	width  float64
}

func (e *areaError2) Error() string {
	return e.err
}

func (e *areaError2) lengthNegative() bool {
	return e.length < 0
}

func (e *areaError2) widthNegative() bool {
	return e.width < 0
}

func reactArea(length, width float64) (float64, error) {
	err := ""
	if length < 0 {
		err += "length is less than zero"
	}
	if width < 0 {
		if err == "" {
			err += "width is less than zero"
		} else {
			err += ", width is less than zero"
		}
	}
	if err != "" {
		return 0, &areaError2{err, length, width}
	}
	return length * width, nil
}

func main() {
	length, width := -5.0, -9.0
	area, err := reactArea(length, width)
	if err != nil {
		if err, ok := err.(*areaError2); ok {
			if err.lengthNegative(){
				fmt.Printf("error: length %0.2f is less than zero\n", err.length)
			}
			if err.widthNegative() {
				fmt.Printf("error: width %0.2f is less than zero\n", err.width)
			}
		}
		fmt.Println(err)
		return 
	}
	fmt.Println("area of rect ", area)
}


// panic() 和 recover()
// go中可以抛出一个panic的异常，然后在defer中通过recover捕获这个异常，然后正常处理
// https://github.com/rubyhan1314/Golang-100-Days/blob/master/Day01-15(Go%E8%AF%AD%E8%A8%80%E5%9F%BA%E7%A1%80)/day15_%E9%94%99%E8%AF%AF%E5%A4%84%E7%90%86.md
