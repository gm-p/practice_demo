package main

import (
	"fmt"

	"github.com/gin-gonic/gin"
)

func main() {

	r := gin.Default() // Default返回一个默认路由引擎

	r.GET("/", func(c *gin.Context) {
		username := c.Query("username")
		fmt.Println(username)
		c.JSON(200, gin.H{
			"msg": "Hello World!",
		})
	})

	r.Run() // 默认位于0.0.0.0:8000，可以传入参数":3030""
}
