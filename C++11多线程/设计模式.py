# https://blog.csdn.net/burgess_zheng/article/details/86762248
# https://www.cnblogs.com/Liqiongyu/p/5916710.html

# 6大原则：
# 1.开闭原则：对扩展开放，对修改关闭
# 2.里氏替换原则
# 3.依赖倒置原则：对接口编程，依赖于抽象而不依赖于具体
# 4.接口隔离原则
# 5.迪米特法则(最少知道原则)
# 6.合成服用原则

# 23 GoF
# 一、创建型模式
# 简单工厂模式、工厂方法模式、抽象工厂模式、创建者模式、原型模式、单例模式
# 二、结构型模式
# 适配器模式、代理模式、装饰器模式、桥接模式、组合模式、外观模式、享元模式
# 三、行为型模式
# 观察者模式、状态模式、策略模式、责任链模式、命令模式、访问者模式、调停者模式、备忘录模式、迭代器模式、解释器模式、模板方法

# 0. 简单工厂
class Shape(object):
    def draw(self):
        raise NotImplmentedError

class Circle(Shape):
    def draw(self):
        print('draw circle')

class Rectangle(Shape):
    def draw(self):
        print('draw Rectangle')

class ShapeFactor(object):
    def create(self, shape):
        if shape == 'Circle':
            return Circle()
        elif shape == 'Rectangle':
            return Rectangle()
        else:
            return None 

fac = ShapeFactor()
obj = fac.create('Circle')
obj.draw()
# 优点：客户端不需要修改代码
# 缺点：当要增加新的运算类的时候，不仅要新增加运算类，还需要修改工厂类，违反了开闭原则

# 1.工厂方法模式
class ShapeFactor(object):
    def getShape(self):
        return self.shape_name

class Circle(ShapeFactor):
    def __init__(self):
        self.shape_name = 'Circle'
    def draw(self):
        print('draw circle')

class Rectangle(ShapeFactor):
    def __init__(self):
        self.shape_name = 'Rectangle'
    def draw(self):
        print('draw rectangle')

class ShapeInterfaceFactory(object):
    def create(self):
        raise NotImplmentedError

class ShapeCircle(ShapeInterfaceFactory):
    def create(self):
        return Circle()

class ShapeRectangle(ShapeInterfaceFactory):
    def create(self):
        return Rectangle()

shape_interface = ShapeCircle()
obj = shape_interface.create()
obj.getShape()
obj.draw()

shape_interface2 = ShapeRectangle()
obj2 = shape_interface2.create()
obj2.draw()
# 优点：增加一个运算类，只需要增加运算类和相对应的工厂，两个类，不需要修改工厂类
# 缺点：增加运算类，会修改客户端代码，工厂方法只是把简单工厂的内部逻辑判断移到了客户端进行

# 2.抽象工厂
class AbstractCpu(object):
    series_name = ''
    instructions = ''
    arch = ''

class IntelCpu(AbstractCpu):
    def __init__(self, series):
        self.series_name = series
    
class AmdCpu(AbstractCpu):
    def __init__(self, series):
        self.series_name = series

class AbstractMainboard(object):
    series_name = ''

class IntelMainBoard(AbstractMainboard):
    def __init__(self, series):
        self.series_name = series

class AmdMainBoard(AbstractMainboard):
    def __init__(self, series):
        self.series_name = series

class AbstractFactory(object):
    computer_name = ''   # 静态成员
    def createCpu(self):
        pass
    def createMainboard(self):
        pass

class InterlFactory(AbstractFactory):
    computer_name = 'Interl I7-series computer'
    def createCpu(self):
        return IntelCpu('I7-6500')
    def createMainboard(self):
        return IntelMainBoard('Intel-6000')

class AmdFactory(AbstractFactory):
    computer_name = 'Amd 4 computer'
    def createCpu(self):
        return AmdCpu('Amd 444')
    def createMainboard(self):
        return AmdMainBoard('Amd-4000')

class ComputerEngineer(object):
    def prepareHardWares(self, factory_obj):
        self.cpu = factory_obj.createCpu()
        self.mainboard = factory_obj.createMainboard()
        info = '''---------computer [%s] info:
                  cpu: %s
                  mainboard: %s
                  ---------End''' % (factory_obj.computer_name, self.cpu.series_name, self.mainboard.series_name)
        print(info)
    def makeComputer(self, factory_obj):
        self.prepareHardWares(factory_obj)

engineer = ComputerEngineer()
intel_factory = InterlFactory()
engineer.makeComputer(intel_factory)
amd_factory = AmdFactory()
engineer.makeComputer(amd_factory)
# 优点：分离接口和实现；使切换产品族变得容易
# 缺点：不太容易扩展新的产品

# 3.创建者模式:  将一个复杂对象的构建与他的表示分离，使得同样的构建过程可以创建不同的表示
class PersonBuilder(object):
    def BuildHead(self):
        pass
    def BuildBody(self):
        pass
    def BuildArm(self):
        pass
    def BuildLeg(self):
        pass

class PersonFatBuilder(PersonBuilder):
    type = '胖子'
    def BuildHead(self):
        print('构建%s的头' % self.type)
    def BuildBody(self):
        print('构建%s的身体' % self.type)
    def BuildArm(self):
        print('构建%s的手' % PersonFatBuilder.type)
    def BuildLeg(self):
        print('构建%s的脚' % self.type)

class PersonThinBuilder(PersonBuilder):
    type = '瘦子'
    def BuildHead(self):
        print('构建%s的头' % self.type)
    def BuildBody(self):
        print('构建%s的身体' % self.type)
    def BuildArm(self):
        print('构建%s的手' % PersonFatBuilder.type)
    def BuildLeg(self):
        print('构建%s的脚' % self.type)

class PersonDirector(object):  # 指挥者
    pb = None
    def __init__(self, pb):
        self.pb = pb
    def CreatePerson(self):
        self.pb.BuildHead()
        self.pb.BuildBody()
        self.pb.BuildArm()
        self.pb.BuildLeg()

pb = PersonThinBuilder()
pd = PersonDirector(pb)
pd.CreatePerson()

pb2 = PersonFatBuilder()
pd.pb = pb2
pd.CreatePerson()

# 4. 原型模式
import copy

class Prototype(object):
    def __init__(self):
        self._objects = {}
    def register_object(self, name, obj):
        self._objects[name] = obj
    def unregister_object(self, name):
        del self._objects[name]
    def clone(self, name, **attr):
        obj = copy.deepcopy(self._objects.get(name))
        obj.__dict__.update(attr)
        return obj

def main():
    class A(object):
        def __str__(self):
            return 'I am A'
    a = A()
    prototype = Prototype()
    prototype.register_object('a', a)
    b = prototype.clone('a', a=1, b=2, c=3)

    print(a)
    print(b.__dict__)
    print(b.a, b.b, b.c)

main()

# 5. 单例模式


https://design-patterns.readthedocs.io/zh_CN/latest/creational_patterns/builder.html
创建者模式：建造者模式将复杂对象的构建与对象的表现分离开来，这样使得同样的构建过程可以创建出不同的表现
