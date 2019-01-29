**1、python类的实例方法（instance method）、类方法（class method）和静态方法（static method）**[1]

实例方法：

```python
class Kls(object):
    def __init__(self, data):
        self.data = data

    def printd(self):  # 实例方法，第一个参数为self
        print(self.data)
ik1 = Kls('leo')
ik2 = Kls('lee')
ik1.printd()  # 实例ik1会传给self参数。
ik2.printd()
```

类方法：


```python
class Kls(object):
    num_inst = 0  # 这是一个类变量，用于统计类Kls实例的个数。创建一个实例+1
    def __init__(self):
        Kls.num_inst = Kls.num_inst + 1  # 注意这里替换成self的区别。

    @classmethod  # 只在类中运行而不在实例中运行。
    def get_no_of_instance(cls):  # 调用类方法时，python会将类(Kls)传递给cls，这样就可以在类函数										内引用类变量num_inst
        return cls.num_inst

ik1 = Kls()
ik2 = Kls()
print ik1.get_no_of_instance()  # 既可以通过类也可以通过实例来调用类方法。
print Kls.get_no_of_instance()
```

静态方法

```python
IND = 'ON'

class Kls(object):
    def __init__(self, data):
        self.data = data

    @staticmethod
    def checkind():  # 只需检查IND的值，而不需要引用类或者实例，
        return IND == 'ON'

    def do_reset(self):
        if self.checkind():
            print('Reset done for: %s' % self.data)

    def set_db(self):
        if self.checkind():
            print('DB connection made for: %s' % self.data)

ik1 = Kls(24)
ik1.do_reset()
ik1.set_db()
```



**2、闭包**[2]

在一个内部函数中，对外部作用域的变量进行引用，(并且一般外部函数的返回值为内部函数)，那么内部函数就被认为是**闭包**。

闭包避免了使用全局变量，此外，闭包允许将函数与其所操作的某些数据（环境）关连起来。



**参考资料：**

[1]、https://blog.csdn.net/lihao21/article/details/79762681

[2]、https://zhuanlan.zhihu.com/p/22229197



