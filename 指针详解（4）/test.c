#include <stdio.h>
//  函数指针



// 例一：

//    (*(void(*)())0)();    void(*)() - 函数指针类型
//    将0强制类型转换成:void(*)()函数指针类型-0就是一个函数的地址
//    调用0地址处的该函数
// 解释：将0强制转换成一个函数指针类型，该函数指针指向的一个类型是无参函数void，
//       把0变成一个函数地址时，把它解引用操作，去调用以0为地址的该函数


// 例二：

//      void(*	signal(int,void(*)(int)) )(int)   void(*)(int)  - 函数指针类型
//      signal - 函数命名，函数类型有 int型，void(*)(int)函数指针型，
//      剩下的void(*)(int)又是一个函数指针类型
//    
// 简易：
//     用typedef    - typedef unsigned int uint;可以将int类型重新定义类型为uint ；
//     函数指针重新定义类型：typedef void(* )(int) pfun_t;	这样是错误的
//					应该为：typedef void(* pfun_t)(int);     这样是正确的
// 简易步骤：
//			typedef void(*pfun_t)(int);
//			pfun_t signal(int,pfun_t);
// 解释：signal是一个函数声明
//	signal函数的参数有两个：一个是int,一个是函数指针，该函数指针指向的函数的参数是int,返回类型是void
//  signal函数的返回类型也是一个函数指针，该函数指针指向的函数的参数是int,返回类型是void

 

//int Add(int x, int y)
//{
//	int sum = 0;
//	sum = x + y;
//	return sum;
//}
//int main()
//{
//	int a = 10;
//	int b = 30;
//	int (*pa)(int, int) = Add;
//	printf("%d\n", (*pa)(2, 3));    //函数可以不必解引用后再引用，可直接引用
//	printf("%d\n", (**pa)(2, 3));	// *可有可无，有和无的效果都一样
//	printf("%d\n", (***pa)(2, 3));
//	printf("%d\n", Add(2, 3));
//	printf("%d\n", pa(2, 3));       // 调用Add函数和pa函数都一样的效果，不加括号也行
//	// printf("%d\n", *pa(2, 3));	error
//	return 0;
//}


//// 函数指针数组
//
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//
//int Sub(int x, int y)
//{
//	int z = 0;
//	z = x - y;
//	return z;
//}
//
//int Mul(int x, int y)
//{
//	int z = 0;
//	z = x * y;
//	return z;
//}
//
//int Div(int x, int y)
//{
//	int z = 0;
//	z = x / y;
//	return z;
//}
//
//int main()
//{
//	// 指针数组
//	// int* arr[5];
//	// 现建一个数组，这个数组可以存放4个函数的地址 - 函数指针的数组
//	int(*pa)(int, int) = Add;
//	int (*ppa[4])(int, int) = { Add,Sub,Mul,Div };   // 函数指针的数组
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d\n", ppa[i](6, 3));
//	}
//	return 0;
//}

//// 例题：
//char* my_strcpy(char* dest, const char* src);
//
////1.写一个函数指针pf，能够指向my_strcpy
//char* (*pf)(char*,const char*);
////2.写一个函数指针数组 pfArr，能够存放4个my_strcpy函数的地址
//char* (*pfArr[4])(char*,const char*)


//// 函数指针数组的用途：转移表
//
//// 计算器
//
//void menu()
//{
//	printf("***********************************\n");
//	printf("*****	1.add           2.sub  ****\n");
//	printf("*****	3.mul		4.div  ****\n");
//	printf("*****	5.xor		0.exit ****\n");
//	printf("***********************************\n");
//}
//
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//
//int Sub(int x, int y)
//{
//	int z = 0;
//	z = x - y;
//	return z;
//}
//
//int Mul(int x, int y)
//{
//	int z = 0;
//	z = x * y;
//	return z;
//}
//
//int Div(int x, int y)
//{
//	int z = 0;
//	z = x / y;
//	return z;
//}
//
//int Xor(int x, int y)
//{
//	return x ^ y;
//}
//
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	//  法二：
//	//// parr是一个函数指针数组 - 转移表
//	//int (*parr[6])(int, int) = { 0,Add,Sub,Mul,Div,Xor };
//	//do
//	//{
//	//	menu();
//	//	printf("请选择：>");
//	//	scanf("%d", &input);
//	//	if (input >= 1 & input <= 5)
//	//	{
//	//		printf("请输入两个数: >");
//	//		scanf("%d%d", &x, &y);
//	//		printf("%d\n", parr[input](x, y));
//	//	}
//	//	else if (input == 0)
//	//	{
//	//		printf("退出\n");
//	//	}
//	//	else
//	//	{
//	//		printf("选择错误,请重新输入：\n");
//	//	}
//	//} while (input);
//
//	/*  法一：
//	do
//	{
//		menu();
//		printf("请选择：>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个数: >");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Add(x, y));
//			break;
//		case 2:
//			printf("请输入两个数: >");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Sub(x, y));
//			break;
//		case 3:
//			printf("请输入两个数: >");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Mul(x, y));
//			break;
//		case 4:
//			printf("请输入两个数: >");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Div(x, y));
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default:
//			printf("选择错误，再来一次：>\n");
//			break;
//		}
//	} while (input);
//	*/
//
//	return 0;
//}

//// 指向函数指针数组的指针
//int main()
//{
//	int arr[10] = { 0 };
//	int(*p)[10] = &arr;    // 取出数组的地址
//	int(*pf)(int, int);    // 函数指针
//	int(*pfarr[4])(int, int); // pfArr是一个数组 - 函数指针的数组
//	int(*(*ppfArr)[4])(int, int);  // ppfArr是一个指向[函数指针数组]的指针
//	// ppfArr是一个数组指针，指针指向的数组有4个元素
//	// 指向的数组的每个元素的类型是一个函数指针 int(*)(int,int)
//	return 0;
//}


//// 回调函数 - 通过函数指针调用的函数，把函数的指针（地址）作为参数传递给
//   另一个函数，当这个指针被用来调用其所指向的函数是，就是回调函数,
//   只有在特定的事件或条件发生时由另外的一方调用

// 例一：

//void menu()
//{
//	printf("***********************************\n");
//	printf("*****	1.add           2.sub  ****\n");
//	printf("*****	3.mul		4.div  ****\n");
//	printf("*****	5.xor		0.exit ****\n");
//	printf("***********************************\n");
//}
//
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//
//int Sub(int x, int y)
//{
//	int z = 0;
//	z = x - y;
//	return z;
//}
//
//int Mul(int x, int y)
//{
//	int z = 0;
//	z = x * y;
//	return z;
//}
//
//int Div(int x, int y)
//{
//	int z = 0;
//	z = x / y;
//	return z;
//}
//
//int Xor(int x, int y)
//{
//	return x ^ y;
//}
//
//void Calc(int (*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入两个数: >");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", pf(x, y));
//
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择：>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Calc(Add);      //这里的Add函数就是回调函数
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//		case 5:
//			Calc(Xor);
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default:
//			printf("选择错误，再来一次：>\n");
//			break;
//		}
//	} while (input);
//	
//
//	return 0;
//}

//// 例二：
//
//void print(char* str)
//{
//	printf("hehe:%s\n", str);    // print是回调函数
//}
//
//void test(void(*p)(char*))
//{
//	printf("test\n");
//	p("bit");
//}
//int main()
//{
//	test(print); 
//	return 0;
//}
