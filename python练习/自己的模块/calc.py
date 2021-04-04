'''import TempratureConversion


print("32摄氏度 = %.2f华氏度" % TempratureConversion.c2f(32))
print("99华氏度 = %.2f摄氏度" % TempratureConversion.f2c(99))'''


'''from TempratureConversion import c2f,f2c

print("32摄氏度 = %.2f华氏度" % c2f(32))
print("99华氏度 = %.2f摄氏度" % f2c(99))'''


import M1.TempratureConversion as tc

print("32摄氏度 = %.2f华氏度" % tc.c2f(32))
print("99华氏度 = %.2f摄氏度" % tc.f2c(99))
