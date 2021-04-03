#include <stdio.h>
#include <string.h>
int main()
{
	int a,b;
	char str[40];
	while(scanf("%d%s%d",&a,str,&b)!=EOF)
	{
		int tmp=0,length=strlen(str),c=1;//tmp为我们将要计算的a进制对应的十进制数，length为字符串长度方便我们从低位到高位遍历
										//每个数位上的数，c为各个数位的权重初始化为1，表示低位数位权重为1，之后每位权重都是前一位权重的a倍
		 for(int i=length-1;i>=0;i--)//从低位到高位遍历每个数位上的数
		 {
		 	int x;//计算该位上数字
			if(str[i]>='0'&&str[i]<='9')
				x=str[i]-'0';//当字符在0到9之间，计算其代表的数字
			else if(str[i]>='a'&&str[i]<='z') 
				x=str[i]-'a'+10;//当字符为小写字母时，计算其代表的数字
			else
				x=str[i]-'A'+10;//当字符为大写字母时，计算其代表的数字
			tmp+=x*c;//累加该位数字与该数位权重的积
			c*=a;//计算下一位数位权重 
		 } 
		 char ans[40],size=0;//用ans保存转换到b进制的各个数位数字
		 do
		 {
		 	int x=tmp%b;//计算该位数字
			ans[size++]=(x<10)?x+'0':x-10+'A';//将数字转换为字符
			tmp/=b; 
		 } while(tmp);
		 for(int i=size-1;i>=0;i--)
		 	printf("%c",ans[i]);
		printf("\n");//输出 
	}
	return 0;
}
