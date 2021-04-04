# 推荐方法3 (只计算了程序运行的CPU时间)
first = time.clock()
time.sleep(2)
second = time.clock();
print(second- first)
  
  
# 要实现跨平台的精度性，也可以使用timeit 来代替time.
import timeit
  
starttime2 = timeit.default_timer()
time.sleep(2)
endtime2 = timeit.default_timer()
print(str(endtime2 - starttime2))