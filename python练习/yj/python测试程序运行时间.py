# �Ƽ�����3 (ֻ�����˳������е�CPUʱ��)
first = time.clock()
time.sleep(2)
second = time.clock();
print(second- first)
  
  
# Ҫʵ�ֿ�ƽ̨�ľ����ԣ�Ҳ����ʹ��timeit ������time.
import timeit
  
starttime2 = timeit.default_timer()
time.sleep(2)
endtime2 = timeit.default_timer()
print(str(endtime2 - starttime2))