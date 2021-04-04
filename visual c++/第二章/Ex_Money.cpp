#include <iostream>
#include <cstring>
using namespace std;
typedef char* USTR;
class CMoney
{
	double amount;
public:
	CMoney(double a=0.0)
	{
		amount=a;
	}
	operator USTR();
};
CMoney::operator USTR()
{
	USTR basestr[15]={"��","��","Ԫ","ʰ","��","Ǫ","��",
					"ʰ","��","Ǫ","��","ʰ","��","Ǫ","��"};
	USTR datastr[10]={"��","Ҽ","��","��","��","��","½","��","��","��"};
	static char strResult[80];
	double temp,base=1.0;
	int n=0;
	temp=amount*100.0;
	strcpy(strResult,"���Ϊ:");
	if(temp<1.0)
		strcpy(strResult,"���Ϊ����Ԫ������");
	else
	{
		while(temp>=10.0)//����λ��
		{
			base=base*10.0;
			temp=temp/10.0;
			n++;
		}
		if(n>=15)
			strcpy(strResult,"������Χ��");
		else
		{
			temp=amount*100.0;
			for(int m=n;m>=0;m--)
			{
				int d=(int)(temp/base);
				temp=temp-base*(double)d;
				base=base/10;
				strcat(strResult,datastr[d]);
				strcat(strResult,basestr[m]);
			}
		}

	}
	return strResult;
}
int main()
{
	CMoney money(1234123456789.123);
	cout<<(USTR)money<<endl;
	return 0;
}