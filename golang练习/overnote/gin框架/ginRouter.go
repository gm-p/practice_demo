package main

import (
	"github.com/gin-gonic/gin"
)

func login(c *gin.Context) {
	c.JSON(300, gin.H{
		"msg": "login",
	})
}

func logout(c *gin.Context) {
	c.JSON(300, gin.H{
		"msg": "logout",
	})
}

func main() {

	router := gin.Default()

	user := router.Group("/user")
	{
		user.GET("/login", login)
		user.GET("/logout", logout)
	}

	router.Run(":8080")
}
