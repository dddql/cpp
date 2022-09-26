# **Brief Introduction of C++ Function**

这篇文章是为了帮助你更好地理解C++中函数版块的相关知识。

定义等理论部分参考了Runoob,我再添加一点解释，主要是我打算举很多例子，你主要看举例部分就行。


---

##  **Definition** 

---

##  **Advantages**

可以**使代码条理分明，可读性增强**，也可以提高程序运行的效率。

下面举个例子：

首先这是一个可以把一堆数字按从小到大排序的算法

**先不要管它是什么意思，知道能<i>排序</i>就行！**

```c++
void bubble_sort(int data[], int length)
{
	bool if_swap;
	for (int i = 0; i < length - 1; i++){
		if_swap = false;
		for (int j = 0; j < length - 1 - i; j++){
			if (data[j] > data[j + 1])
				swap(data[j], data[j + 1]);
			if_swap = true;
		}
		if (if_swap == false)
			break;
	}
}
```

如果这些数字会被打乱很多次，需要经常重新排序怎么办？

在不使用函数的情况下，长这样：

```c++
for (int i = 1; i <= 10000; i++) //*让这些数字都随机
   a[i] = rand();

bool if_swap;					//*第一次排序
for (int i = 0; i < length - 1; i++)
{
   if_swap = false;
   for (int j = 0; j < length - 1 - i; j++)
   {
      if (data[j] > data[j + 1])
      {
         swap(data[j], data[j + 1]);
      }
      if_swap = true;
   }
   if (if_swap == false)
      break;
}

for (int i = 1; i <= 10000;i++)		//*再打乱一次
   a[i] -= rand();

bool if_swap;						//第二次排序
for (int i = 0; i < length - 1; i++)
{
   if_swap = false;
   for (int j = 0; j < length - 1 - i; j++)
   {
      if (data[j] > data[j + 1])
      {
         swap(data[j], data[j + 1]);
      }
      if_swap = true;
   }
   if (if_swap == false)
      break;
}

```

可以发现，仅仅一次重复就会让代码看起来很乱（我如果不打注释，不空行，会更乱）

如果使用函数呢？：

```c++
for (int i = 1; i <= 10000; i++)
   a[i] = rand();

bubble_sort(a, 10000);		//看到这句就知道是排序，不用费劲思考

for (int i = 1; i <= 10000;i++)
   a[i] -= rand();

bubble_sort(a, 10000);		//代码也看起来很整洁，一万年后再看也不会觉得懵

```

还是不用管为什么这么写，只要感觉到看起来简洁就行

区别应该还是挺大的吧，其实排序已经算是比较短的算法了

而那些几百行的算法，不该让他们出现在主函数里。

之前我从网站上下载过一个贪吃蛇小游戏的代码

它的主函数长这样
```c++
int main(){
   c.play();
}
```

啊，是的，就一行。

---

##  **Template**

函数的基本结构是这样的

模板代码：

```c++
return_type function_name( parameter list )
{
   //body of the function
}
```

把实际的算法套进去就是

```c++
int add(int a,int b){
   return a+b;
}
```

**返回类型**：一个函数可以返回一个值。```return_type``` 是函数返回的值的数据类型(比如```int```,```bool```,```float```等)。有些函数执行所需的操作而不返回值，在这种情况下，```return_type``` 是关键字 ```void```(*后面有例子*)。

**函数名称**：这是函数的实际名称（基本你随便取）。函数名和参数列表一起构成了函数签名。


**参数**：参数就像是 ***占位符*** 当函数被调用时，您向参数传递一个值，这个值被称为实际参数。参数列表包括函数参数的类型、顺序、数量。参数是可选的，也就是说，**函数可能不包含参数**。


**函数主体**：函数主体包含一组定义函数执行任务的语句。


##  **Examples of Different Types**

## 