package main

import (
	"encoding/xml"
	"fmt"
	"io/ioutil"
	"os"
)

type BookStore struct {
	XMLName     xml.Name `xml:"books"`
	Version     string   `xml:"version,attr"`
	Store       []book   `xml:"book"`
	Description string   `xml:",interxml"`
}

type book struct {
	XMLName   xml.Name `xml:"book"`
	BookName  string   `xml:"bookName"`
	BookPrice string   `xml:"bookPrice"`
}

func main() {

	file, err := os.Open("books.xml")
	if err != nil {
		fmt.Printf("error: %v", err)
		return
	}
	defer file.Close()
	data, err := ioutil.ReadAll(file)
	if err != nil {
		fmt.Printf("error: %v", err)
		return
	}

	v := BookStore{}
	err = xml.Unmarshal(data, &v)
	if err != nil {
		fmt.Printf("error: %v", err)
		return
	}
	fmt.Println(v)
}
