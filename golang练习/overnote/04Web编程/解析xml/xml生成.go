package main

import (
	"encoding/xml"
	"fmt"
	"os"
)

type BookStore struct {
	XMLName xml.Name `xml:"books"`
	Version string   `xml:"version,attr"`
	Store   []book   `xml:"book"`
}

type book struct {
	BookName  string `xml:"bookName"`
	BookPrice string `xml:"bookPrice"`
}

func main() {

	bs := &BookStore{Version: "1"}
	bs.Store = append(bs.Store, book{"离散数学", "120"})
	bs.Store = append(bs.Store, book{"人月神话", "75"})

	output, err := xml.MarshalIndent(bs, "  ", "    ")
	if err != nil {
		fmt.Printf("error: %v\n", err)
	}

	// 生成正确的xml头
	os.Stdout.Write([]byte(xml.Header))
	os.Stdout.Write(output)
}
