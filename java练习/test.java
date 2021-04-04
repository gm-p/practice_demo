public class test {
	public static void main(String[] args) {
		int i = 1, j = 2;
		float f1 = 0.1f;
		float f2 = 123;
		long l1 = 12345678, l2 = 8888888888L;
		double d1 = 2e20, d2 = 124;
		byte b1 = 1, b2 = 2, b3 = 127;
		j = j + 10;
		i = i / 10;
		i = (int) (i * 0.1);
		char c1 = 'a', c2 = 125;
		byte b = (byte) (b1 - b2);
		char c = (char) (c1 + c2 - 1);
		float f3 = f1 + f2;
		float f4 = (float) (f1 + f2 * 0.1);
		double d = d1 * i + j;
		float f = (float) (d1 * 5 + d2);
		
		int result=0;
		int f5=1;
		for(i=1; i<=10; i++)
		{
			f5 *= i;
			result += f5;
		}
		System.out.println("1!+2!+3!+...+10! = "+result);
		
		int sum=0;
		for(int i1=0;i1<=49;i1++)     //for(int i=1; i<=99; i+=2)
			sum += 2*i1 + 1;		  //  result += i;
		System.out.println("1+3+5+7+...+99 = "+sum);
		
		int num=0;
		i=1;
		while(i<=100)
		{
			if(i%3 == 0)
			{
				System.out.print(i+" ");
				num++;
			}
			if(num == 5)
				break;
			i++;
		}
		
		for(i=101; i<=200; i+=2)
		{
			boolean flag = true;
			for(j=2; j<i; j++)
			{
				if(i%j == 0)
				{
					flag=false;
					break;
				}
			}
			if(!flag)
				continue;
			System.out.print(i+" ");
		}
		System.out.println(f(40));
		int fab[] = new int[50];
		fab[1]=fab[2]=1;
		for(i=3; i<=40; i++)
			fab[i] = fab[i-1]+fab[i-2];
		System.out.println(fab[40]);
		
	}
	static int f(int n){
		if(n==1 || n==2)
			return 1;
		else
			return f(n-1)+f(n-2);
	}
	
	public static long f1(int index) {
		if(index < 1){
			System.out.println("Invalid parameter!");
			return -1;
		}
		
		if(index ==1 ||index == 2)
			return 1;
		long f1=1L;
		long f2=1L;
		long f=0;
		for(int i=0; i<index-2; i++){
			f=f1+f2;
			f1=f2;
			f2=f;
		}
		return f;
	}
}