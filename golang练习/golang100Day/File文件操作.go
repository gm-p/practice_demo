package main

import (
	"bufio"
	"fmt"
	"io"
	"io/ioutil"
	"log"
	"os"
	"path"
	"path/filepath"
	"strconv"
	"strings"
)

func main1() {
	/*
		FileInfo：文件信息
			interface
				Name()，文件名
				Size()，文件大小，字节为单位
				IsDir()，是否是目录
				ModTime()，修改时间
				Mode()，权限

	*/
	fileInfo, err := os.Stat("string.go")
	if err != nil {
		fmt.Println("err:", err)
		return
	}
	fmt.Printf("%T\n", fileInfo)
	fmt.Println(fileInfo.Name())    // 文件名
	fmt.Println(fileInfo.Size())    // 文件大小
	fmt.Println(fileInfo.IsDir())   // 是否是目录
	fmt.Println(fileInfo.ModTime()) // 修改时间
	fmt.Println(fileInfo.Mode())    // 权限
}

func main2() {
	/*
		文件操作：
		1.路径：
			相对路径：relative
				ab.txt
				相对于当前工程
			绝对路径：absolute
				/Users/ruby/Documents/pro/a/aa.txt

			.当前目录
			..上一层
		2.创建文件夹，如果文件夹存在，创建失败
			os.MkDir()，创建一层
			os.MkDirAll()，可以创建多层

		3.创建文件，Create采用模式0666（任何人都可读写，不可执行）创建一个名为name的文件，如果文件已存在会截断它（为空文件）
			os.Create()，创建文件

		4.打开文件：让当前的程序，和指定的文件之间建立一个连接
			os.Open(filename)
			os.OpenFile(filename,mode,perm)

		5.关闭文件：程序和文件之间的链接断开。
			file.Close()

		5.删除文件或目录：慎用，慎用，再慎用
			os.Remove()，删除文件和空目录
			os.RemoveAll()，删除所有
	*/
	// 1. 路径
	fileName1 := "C:/Users/guangming.pan/Desktop/byte.txt"
	fileName2 := "string.go"
	fmt.Println(filepath.IsAbs(fileName1))
	fmt.Println(filepath.IsAbs(fileName2))
	fmt.Println(filepath.Abs(fileName1))
	fmt.Println(filepath.Abs(fileName2))

	fmt.Println("获取父目录：", path.Join(fileName1, ".."))

	// 2. 创建目录
	err := os.Mkdir("C:/Users/guangming.pan/Desktop/88", os.ModePerm)
	if err != nil {
		fmt.Println("err:", err)
		return
	}
	fmt.Println("文件夹创建成功。。")

	err = os.MkdirAll("C:/Users/guangming.pan/Desktop/88/99/10", os.ModePerm)
	if err != nil {
		fmt.Println("err:", err)
		return
	}
	fmt.Println("多层文件夹创建成功")

	// 3.创建文件:Create采用模式0666（任何人都可读写，不可执行）创建一个名为name的文件，如果文件已存在会截断它（为空文件）
	file1, err := os.Create("C:/Users/guangming.pan/Desktop/88/ab.txt")
	if err != nil {
		fmt.Println("err:", err)
		return
	}
	fmt.Println(file1)

	file2, err := os.Create("haha.txt") // 创建相对路径的文件
	if err != nil {
		fmt.Println("err:", err)
		return
	}
	fmt.Println(file2)

	// 4. 打开文件
	file3, err := os.Open(fileName1) // 只读的
	if err != nil {
		fmt.Println("err:", err)
		return
	}
	fmt.Println(file3)

	file4, err := os.OpenFile(fileName1, os.O_RDONLY|os.O_WRONLY, os.ModePerm)
	if err != nil {
		fmt.Println("err:", err)
		return
	}
	fmt.Println(file4)

	// 5. 关闭文件
	file4.Close()

	// 6.删除文件或文件夹
	// 删除文件
	err = os.Remove("C:/Users/guangming.pan/Desktop/1.txt")
	if err != nil {
		fmt.Println("err:", err)
		return
	}
	fmt.Println("删除文件成功。。")
	// 删除目录
	err = os.RemoveAll("C:/Users/guangming.pan/Desktop/88")
	if err != nil {
		fmt.Println("err:", err)
		return
	}
	fmt.Println("删除目录成功。。")
}

// 文件读写
func main3() {
	/*
		读取数据：
			Reader接口：
				Read(p []byte)(n int, error)
	*/
	//读取本地aa.txt文件中的数据
	//step1：打开文件
	fileName := "C:/Users/guangming.pan/Desktop/byte.txt"
	file, err := os.Open(fileName)
	if err != nil {
		fmt.Println("err: ", err)
		return
	}
	//step3：关闭文件
	defer file.Close()

	// step2: 读取数据
	bs := make([]byte, 4, 4)
	n := -1
	for {
		n, err = file.Read(bs)
		if n == 0 || err == io.EOF {
			fmt.Println("\n读取到了文件的末尾, 结束读取操作...")
			return
		}
		fmt.Printf(string(bs[:n]))
	}
}

// 写文件
func main4() {
	fileName := "C:/Users/guangming.pan/Desktop/write.txt"
	file, err := os.OpenFile(fileName, os.O_CREATE|os.O_WRONLY|os.O_APPEND, os.ModePerm)
	if err != nil {
		fmt.Println(err)
		return
	}
	defer file.Close()

	// 写出数据
	bs := []byte{97, 98, 99, 100} // a, b, c, d

	n, err := file.Write(bs[:2])
	fmt.Println(n)
	HandleErr(err)
	file.WriteString("\n")

	//直接写出字符串
	n, err = file.WriteString("Hello World")
	fmt.Println(n)
	HandleErr(err)

	file.WriteString("\n")
	n, err = file.Write([]byte("today"))
	fmt.Println(n)
	HandleErr(err)
}

func HandleErr(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

// 文件赋值
// 方法一：IO包下的 Read() 和 Write() 方法实现
func copyFile1(srcFile, destFile string) (int, error) {
	file1, err := os.Open(srcFile)
	if err != nil {
		return 0, err
	}
	file2, err := os.OpenFile(destFile, os.O_WRONLY|os.O_CREATE, os.ModePerm)
	if err != nil {
		return 0, err
	}
	defer file1.Close()
	defer file2.Close()

	// 拷贝数据
	bs := make([]byte, 1024, 1024)
	n := -1 // 读取的数据量
	total := 0
	for {
		n, err = file1.Read(bs)
		if err == io.EOF || n == 0 {
			fmt.Println("拷贝完成...")
			break
		} else if err != nil {
			fmt.Println("报错了...")
			return total, err
		}
		total += n
		file2.Write(bs[:n])
	}
	return total, nil
}

// 方法二：io包下的Copy()方法
// Copy（dst,src） 为复制src 全部到 dst 中。

// CopyN(dst,src,n) 为复制src 中 n 个字节到 dst。

// CopyBuffer（dst,src,buf）为指定一个buf缓存区，以这个大小完全复制。
func copyFile2(srcFile, destFile string) (int64, error) {
	file1, err := os.Open(srcFile)
	if err != nil {
		return 0, err
	}
	file2, err := os.OpenFile(destFile, os.O_WRONLY|os.O_CREATE, os.ModePerm)
	if err != nil {
		return 0, err
	}
	defer file1.Close()
	defer file2.Close()

	return io.Copy(file2, file1)
}

// 方法三：ioutil包
// ioutil.WriteFile()和 ioutil.ReadFile()使用一次性读取文件，再一次性写入文件的方式，所以该方法不适用于大文件，容易内存溢出
func copyFile3(srcFile, destFile string) (int, error) {
	input, err := ioutil.ReadFile(srcFile)
	if err != nil {
		fmt.Println(err)
		return 0, err
	}

	err = ioutil.WriteFile(destFile, input, 0644)
	if err != nil {
		fmt.Println("操作失败：", destFile)
		fmt.Println(err)
		return 0, err
	}
	return len(input), nil
}

func main5() {
	srcFile := "C:/Users/guangming.pan/Desktop/byte.txt"
	destFile := "tiktop.txt"
	total, err := copyFile1(srcFile, destFile)
	fmt.Println(err)
	fmt.Println(total)
}

// seek随机读写文件
func main6() {
	/*
			seek(offset,whence),设置指针光标的位置
			第一个参数：偏移量
			第二个参数：如何设置
				0：seekStart表示相对于文件开始，
				1：seekCurrent表示相对于当前偏移量，
				2：seek end表示相对于结束。


			const (
			SeekStart   = 0 // seek relative to the origin of the file
			SeekCurrent = 1 // seek relative to the current offset
			SeekEnd     = 2 // seek relative to the end
		)

			随机读取文件：
				可以设置指针光标的位置
	*/

	file, _ := os.OpenFile("C:/Users/guangming.pan/Desktop/byte.txt", os.O_RDWR, 0)
	defer file.Close()
	bs := []byte{0}

	file.Read(bs)
	fmt.Println(string(bs))

	file.Seek(4, io.SeekStart)
	file.Read(bs)
	fmt.Println(string(bs))

	file.Seek(2, 0) // 也是SeekStart
	file.Read(bs)
	fmt.Println(string(bs))

	file.Seek(3, io.SeekCurrent)
	file.Read(bs)
	fmt.Println(string(bs))

	file.Seek(0, io.SeekEnd)
	file.WriteString("ABC")
}

// 断电续传
func main7() {
	/*
		断点续传：
			文件传递：文件复制
				/Users/ruby/Documents/pro/a/guliang.jpeg

			复制到
				guliang4.jpeg

		思路：
			边复制，边记录复制的总量
	*/
	srcFile := "C:/Users/guangming.pan/Downloads/aa.jpg"
	destFile := "ly.jpg"
	tempFile := destFile + "temp.txt"
	file1, _ := os.Open(srcFile)
	file2, _ := os.OpenFile(destFile, os.O_CREATE|os.O_WRONLY, os.ModePerm)
	file3, _ := os.OpenFile(tempFile, os.O_CREATE|os.O_RDWR, os.ModePerm)

	defer file1.Close()
	defer file2.Close()

	// 1.读取临时文件中的数据，根据seek
	file3.Seek(0, io.SeekStart)
	bs := make([]byte, 100, 100)
	n1, err := file3.Read(bs)
	fmt.Println(n1)
	countStr := string(bs[:n1])
	fmt.Println(countStr)

	count, _ := strconv.ParseInt(countStr, 10, 64)
	fmt.Println(count)

	// 2.设置读、写的偏移量
	file1.Seek(count, 0)
	file2.Seek(count, 0)
	data := make([]byte, 1024, 1024)
	n2 := -1            // 读取的数据量
	n3 := -1            // 写出的数据量
	total := int(count) // 读取的总量

	for {
		// 3.读取数据
		n2, err = file1.Read(data)
		if err == io.EOF {
			fmt.Println("文件复制完毕...")
			file3.Close()
			os.RemoveAll(tempFile)
			break
		}
		// 将数据写入到目标文件
		n3, _ = file2.Write(data[:n2])
		total += n3
		// 将复制总量，存储到临时文件中
		file3.Seek(0, io.SeekStart)
		file3.WriteString(strconv.Itoa(total))

		// 假装断电
		// 	if total > 800 {
		// 		panic("假装断电了。。。")
		// 	}
	}
}

//buffio
// 读取数据
func main8() {
	/*
		bufio:高效io读写
			buffer缓存
			io：input/output

		将io包下的Reader，Write对象进行包装，带缓存的包装，提高读写的效率

			ReadBytes()
			ReadString()
			ReadLine()

	*/
	fileName := "C:/Users/guangming.pan/Desktop/byte.txt"
	file, err := os.Open(fileName)
	if err != nil {
		fmt.Println(err)
		return
	}
	defer file.Close()

	// 创建Reader对象
	b1 := bufio.NewReader(file)
	// Read() 高效读取
	p := make([]byte, 1024)
	n1, err := b1.Read(p)
	fmt.Println(n1)
	fmt.Println(string(p[:n1]))

	// ReadLine()
	data, flag, err := b1.ReadLine()
	fmt.Println(flag)
	fmt.Println(err)
	fmt.Println(data)
	fmt.Println(string(data))

	// ReadString()
	for {
		s1, err := b1.ReadString('\n')
		if err == io.EOF {
			fmt.Println("读取完毕...")
			break
		}
		fmt.Println(s1)
	}

	// ReadBytes()
	data, err := b1.ReadBytes('\n')
	fmt.Println(err)
	fmt.Println(string(data))

	// Scanner
	// s2 := ""
	// fmt.Scanln(&s2)
	// fmt.Println(s2)

	b2 := bufio.NewReader(os.Stdin)
	s2, _ := b2.ReadString('\n')
	fmt.Println(s2)
}

// bufio写文件
func main9() {
	/*
		bufio:高效io读写
			buffer缓存
			io：input/output

		将io包下的Reader，Write对象进行包装，带缓存的包装，提高读写的效率

			func (b *Writer) Write(p []byte) (nn int, err error)
			func (b *Writer) WriteByte(c byte) error
			func (b *Writer) WriteRune(r rune) (size int, err error)
			func (b *Writer) WriteString(s string) (int, error)
	*/
	fileName := "C:/Users/guangming.pan/Desktop/bufio.txt"
	file, err := os.OpenFile(fileName, os.O_CREATE|os.O_WRONLY, os.ModePerm)
	if err != nil {
		fmt.Println(err)
		return
	}
	defer file.Close()

	w1 := bufio.NewWriter(file)
	//  n, err := w1.WriteString("helloWorld")
	//  fmt.Println(err)
	//  fmt.Println(n)
	//  w1.Flush()  // 刷新缓冲区
	for i := 1; i <= 1000; i++ {
		w1.WriteString(fmt.Sprintf("%d:hello", i))
	}
	w1.Flush()
}

// ioutil
func main10() {
	/*
		ioutil包：
			ReadFile()
			WriteFile()
			ReadDir()
			..
	*/
	// 1.读取文件中的所有的数据
	fileName1 := "string.go"
	data, err := ioutil.ReadFile(fileName1)
	fmt.Println(err)
	fmt.Println(string(data))

	// 2. 写出数据
	fileName2 := "bb.txt"
	s1 := "helloworld面朝大海春暖花开"
	err := ioutil.WriteFile(fileName2, []byte(s1), 0777)
	fmt.Println(err)

	s2 := "qwertadoapfd"
	r1 := strings.NewReader(s2)
	data, _ := ioutil.ReadAll(r1)
	fmt.Println(data)

	// 4.ReadDir() 读取一个目录下的子内容：子文件和子目录，但是仅有一层
	dirName := "C:/Users/guangming.pan/Desktop"
	fileInfos, _ := ioutil.ReadDir(dirName)
	fmt.Println(len(fileInfos))
	for i := 0; i < len(fileInfos); i++ {
		fmt.Printf("%T\n", fileInfos[i])
		fmt.Println(i, fileInfos[i].Name(), fileInfos[i].IsDir())
	}

	// 5. 创建临时目录
	dir, err := ioutil.TempDir("C:/Users/guangming.pan/Desktop", "goTemp")
	if err != nil {
		fmt.Println(err)
	}
	defer os.Remove(dir) // 用完删除
	fmt.Println("%s\n", dir)

	// 创建临时文件
	f, err := ioutil.TempFile(dir, "gotest")
	if err != nil {
		fmt.Println(err)
	}
	defer os.Remove(f.Name()) // 用完删除
	fmt.Printf("%s\n", f.Name())
}

// 遍历文件夹
func main() {
	dirname := "C:/Users/guangming.pan/Desktop/test"
	listFiles(dirname, 0)
}

func listFiles(dirname string, level int) {
	// level 用来记录当前递归的层次
	// 生成有层次感的空格
	s := "|=--"
	for i := 0; i < level; i++ {
		s = "|   " + s
	}

	fileInfos, err := ioutil.ReadDir(dirname)
	if err != nil {
		log.Fatal(err)
	}
	for _, fi := range fileInfos {
		filename := dirname + "/" + fi.Name()
		fmt.Printf("%s%s\n", s, filename)
		if fi.IsDir() {
			// 继续遍历fi这个目录
			listFiles(filename, level+1)
		}
	}
}
