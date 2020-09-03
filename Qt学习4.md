文本基本上对照《Qt 5.9 C++ 开发指南》(人民邮电出版社)章节安排来总结。

60% 搬运 40%原创总结吧.

开头总写这两行，没啥意义，就是单纯的提醒自己注重版权问题吧，以前不注意吃了亏，也提醒自己尽快可以自己原创出自己的总结，别老就是搬，就是cv，就是对着抄。

第四章开始讲解具体的模块，具体的类，具体的方法。第四章后每一章都是一个大块，一共12块左右吧。这一章节是常用界面设计组件，就基本上还是UI上用的比较多的东西

<!-- more -->

## 第四章 常用界面设计组件

### 4.1 字符串与输入输出

#### 4.1.1 字符串与数值之间的转换

​	Qt中很常见的字符串处理的类就是QString了。和C++中String类差不多吧，因为觉得感觉的不准确，所以就去百度了，也没百度到什么，只查到一句“和Java中的String类似，可以重载运算符...” 所以到底类不类似也不做过多讨论了，但从名字上来讲是类似的，具体一些功能方法上想必也有相似的地方，毕竟两个类的目的都是处理字符串嘛。

1.普通数值与字符串之间的转换

​	QString类从字符串转换为整数的函数 可转换为Int Long Short uInt uLong 。例：toInt();

​	若不设置参数即为转换为十进制，也可将二进制，十六进制字符串转换为整数。



---

​	在打印数值时有四种方法，分别是QString中的静态函数number() 和 asprintf() 以及公共函数setNum()和sprintf(). QString的sprintf()和C语言里的sprintf()格式是一样的，而setNum()和number()函数使用另外一种格式定义，而setNum()和Number()有多个重载函数定义，可以处理各种类型的整数和浮点数，在处理整数时还可以制定进制，例如将一个整数直接转换十六进制或者二进制。

​	eg.

```c
str  = QString::number(total,'f',2);
str  = QString::asprintf("%.2f",total);
str  = QString::setNum(total,'f',2);
str  = QString::sprintf("%.2f",total);
```

2.进制转换

​	还是利用 setNum() 和 number() 

​	函数原型：**QString &setNum (int val ,int base = 10);**

​						**QString number (int val ,int base = 10);** 



#### 4.1.2 QString的常用功能

​	在这一块的样例就是介绍了若干方法。(感觉和String真的差不多，但是有些方法我也不知道String里面有没有)

​	我在这里就直接罗列方法，并解释一下作用和用法好了。

- append()和prepend()  

  append()字符串后添加字符串；prepend()字符串前添加字符串

- toUpper()和toLower() 

  分别为全部转换大写和全部转换为小写

- conut(),size()和length() 

  返回字符串字符个数，(汉字算一个字符)

- trimmed()和simplified()

   分别为去掉首位空格和去掉首尾空格且将连续空格替换成单空格

- indexOf() 和lastIndexOf()

  indexOf 函数原型：**int indexOf(const QString &str,int from = 0 ,Qt::CaseSensitivity cs = Qt::CaseSensitive) const** 功能时在自身字符串中查找参数字符串的文职，from查找起始位置，cs指定是否区分大小写

  lastindexOf 查找某个字符串最后出现的位置。

- isNull() 和 isEmpty() 

  都判断字符串是否为空，区别isNull只有判断未赋值的字符串时返回true,其余为false；故判空一般用isEmpty.

- contains() 

  判断字符串是否包含某个字符串，可传Qt::CaseInsensitive 和Qt::CaseSensitive 来指定是否区分大小写。

- endsWith() 和 startsWith() 

  判断是否以某个字符 开头/结尾

- left() 和 right() 

  表示从字符串中取 左/ 右 多少个字符，

- section()

  函数原型：**QString section(const QString &sep,int start ,int end = -1,SectionFlags flags = SectionDefault) const **

  函数功能：从字符串中提取以sep作为分隔符，从start到end的字符串



### 4.2 SpinBox的使用

​	QSpinBox用于整数的显示和输入，QDoubleSpinBox用于浮点数的显示和输入。

​	这俩组件的设置基本在UI设计器里就可以实现属性配置

​	这里只介绍几种常用属性，在UI设计器里就可以直接修改属性

​	prefix/suffix: 数字显示的前缀后缀 如"$",“kg”

​	minimum/maximum : 数值范围的最小值/最大值

​	singlestep: 单击右侧上下调整按钮的单步改变值

​	value: 当前显示值

​	displayInterBase: QSpinBox特有，设置显示整数时的进制

​	decimals: QDoubleSpinBox特有，显示数值的小数点位数

**注: 上述属性就奔都有一个同名方法获取值，也有一个set方法设置值，也可通过代码方式改变**

 

### 4.3 其他数值输入和显示组件

#### 4.3.1 实例功能

​	这一部分主要是通过一个实例来介绍除去LineEdit 和 SpinBox 以外还有一些其他用于数值输入和显示的组件，如下：

- QSlider: 滑动条。通过滑动来设置数值，可用于数值输入
- QScorllBar: 卷滚条，与滑动条类似，还可以用于卷滚区域
- Qprogress: 进度条，一般用于显示任务进度，可以用于数值的百分比显示。
- QDial: 表盘式数值输入组件，通过转动表针获得输入值
- QLCDNumber: 模仿LCD数字的显示组件，可以显示整数或者浮点数，显示整数时可以同进制显示。

#### 4.3.2 各组件的主要功能和属性

​	这一部分主要就是介绍了上面几个组件的主要功能和主要属性，感觉搬运上来的作用不大，因为就算是搬上来我也记不住，该百度还是会百度，而且退一步来讲，也不常用，真不常用。

#### 4.3.3 实例功能的代码实现

​	都在git上了. 有自己打的也有随书资料，不废话了。

​	提一嘴，合成颜色自己打的代码是有问题的，具体出在哪里也不知道，也忘了怎么改了改就又行了。



### 4.4 时间日期与定时器

#### 4.4.1 时间日期相关的类

​	时间类型的类：

​		QTime：时间数据类型，只表示时间 

​		QDate：日期数据类型，只表示日期

​		QDateTime：日期时间数据类型，表示日期和时间

​	编辑/显示时间类型的界面组件：

​		QTimeEdit：编辑和显示时间的组件

​		QDateEdit：编辑和显示日期的组件

​		QDateTimeEdit：编辑和显示日期时间的组件

​		QCalenderWidget：一个用日历形式选择日期的组件

​	定时器类：QTimer ，直接从QObject继承，并不是界面组件类。

这一章节，主要也是通过一个实例，来介绍上述几个类的功能和方法。

#### 4.4.2 日期时间数据与字符串之间的转换

1.时间，日期编辑器属性设置

​	QTime和QDate都继承与QDateTime,也没有什么特殊属性，QDateTime的属性也不是很难，不进行记录了。

2.日期时间数据的获取与转换为字符串

​	代码略了，

​	首先是QDateTime的静态函数currentDateTime()获取当前日期时间，获取值可用time()和 date()分别提取时间和日期，再将数据用toString转换为字符串(这里传参可以设置字符串的格式)。具体操作其实看代码要更快理解的。

3.字符串转换为日期时间

​	用QDateTime::fromString()

​	函数原型 **`QDateTime QDateTime::fromString(const QString &string ,const QString &format)`** 

​	第一个String是日期时间字符串，第二个参数format是字符串表示的格式，

​	代码略。

#### 4.4.3 QCalendarWidget 日历组件

​	用就完事了。	

```c
void Dialog::on_calendarWidget_selectionChanged()
{ //在日历上选择日期
    QDate dt=ui->calendarWidget->selectedDate(); //读取选择的日期时间
    QString str=dt.toString("yyyy年M月d日");//转换为字符串
    ui->editCalendar->setText(str); //字符串显示日期
}
```



#### 4.4.4 定时器的使用

​	首先定时器QTimer不是一个可见的界面组件，所以UI设计器里找不到它。

​	实例程序里是实现了一个计时器的功能，就是计算定时器开始到停止持续的时间长度。

​	主要介绍一个属性：**interval** 就是定时中断的周期，单位为毫秒。然后就是各种定义...  用start()启动定时器，同时计时器也启动，再stop()停止定时器，计时器同时关闭记录显示定时器的持续时间

​	(嗯嗯 我知道很敷衍了这一块，但是就是看代码可能要更容易理解，本来也就是如何应用的东西。)



-----

下面几个大致看了，感觉基本上就是对着书操作就好，也没啥要详细记录的.... (~~其实就是我懒了，不想做了，感觉没有意义了~~ 莫名其妙有点烦躁。在质疑自己之后就会觉得后悔，烦躁。勉强传了。以后看心情想不想搬运完吧。)



### 4.5 QComboBox和QPlainTextEdit

#### 4.5.1 实例功能概述

​	QComboBox: 下拉列表组件框

​	QPlainTextEdit: 多行文本编辑器。

#### 4.5.2 QComboBox的使用

#### 4.5.3 QPlainTextEdit的使用



### 4.6 QListWidget和QToolButton

#### 4.6.1 实例功能简介

#### 4.6.2 界面设计

#### 4.6.3 QListWidget的操作

#### 4.6.4 QToolButton与下拉式菜单

#### 4.6.5 创建右键快捷菜单



### 4.7 QTreeWidget和QDockWidget

#### 4.7.1 实例功能概述

#### 4.7.2 界面设计

#### 4.7.3 QTreeWidget的操作

#### 4.7.4 QLabel和Qpixmap显示图片

#### 4.7.5 QDockWidget的操作



### 4.8 QTableWidget的使用

#### 4.8.1 QTableWidget概述

#### 4.8.2 界面设计与初始化

#### 4.8.3 QTableWidget的操作





