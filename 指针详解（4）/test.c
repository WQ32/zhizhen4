#include <stdio.h>
//  ����ָ��



// ��һ��

//    (*(void(*)())0)();    void(*)() - ����ָ������
//    ��0ǿ������ת����:void(*)()����ָ������-0����һ�������ĵ�ַ
//    ����0��ַ���ĸú���
// ���ͣ���0ǿ��ת����һ������ָ�����ͣ��ú���ָ��ָ���һ���������޲κ���void��
//       ��0���һ��������ַʱ�����������ò�����ȥ������0Ϊ��ַ�ĸú���


// ������

//      void(*	signal(int,void(*)(int)) )(int)   void(*)(int)  - ����ָ������
//      signal - �������������������� int�ͣ�void(*)(int)����ָ���ͣ�
//      ʣ�µ�void(*)(int)����һ������ָ������
//    
// ���ף�
//     ��typedef    - typedef unsigned int uint;���Խ�int�������¶�������Ϊuint ��
//     ����ָ�����¶������ͣ�typedef void(* )(int) pfun_t;	�����Ǵ����
//					Ӧ��Ϊ��typedef void(* pfun_t)(int);     ��������ȷ��
// ���ײ��裺
//			typedef void(*pfun_t)(int);
//			pfun_t signal(int,pfun_t);
// ���ͣ�signal��һ����������
//	signal�����Ĳ�����������һ����int,һ���Ǻ���ָ�룬�ú���ָ��ָ��ĺ����Ĳ�����int,����������void
//  signal�����ķ�������Ҳ��һ������ָ�룬�ú���ָ��ָ��ĺ����Ĳ�����int,����������void

 

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
//	printf("%d\n", (*pa)(2, 3));    //�������Բ��ؽ����ú������ã���ֱ������
//	printf("%d\n", (**pa)(2, 3));	// *���п��ޣ��к��޵�Ч����һ��
//	printf("%d\n", (***pa)(2, 3));
//	printf("%d\n", Add(2, 3));
//	printf("%d\n", pa(2, 3));       // ����Add������pa������һ����Ч������������Ҳ��
//	// printf("%d\n", *pa(2, 3));	error
//	return 0;
//}


//// ����ָ������
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
//	// ָ������
//	// int* arr[5];
//	// �ֽ�һ�����飬���������Դ��4�������ĵ�ַ - ����ָ�������
//	int(*pa)(int, int) = Add;
//	int (*ppa[4])(int, int) = { Add,Sub,Mul,Div };   // ����ָ�������
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d\n", ppa[i](6, 3));
//	}
//	return 0;
//}

//// ���⣺
//char* my_strcpy(char* dest, const char* src);
//
////1.дһ������ָ��pf���ܹ�ָ��my_strcpy
//char* (*pf)(char*,const char*);
////2.дһ������ָ������ pfArr���ܹ����4��my_strcpy�����ĵ�ַ
//char* (*pfArr[4])(char*,const char*)


//// ����ָ���������;��ת�Ʊ�
//
//// ������
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
//	//  ������
//	//// parr��һ������ָ������ - ת�Ʊ�
//	//int (*parr[6])(int, int) = { 0,Add,Sub,Mul,Div,Xor };
//	//do
//	//{
//	//	menu();
//	//	printf("��ѡ��>");
//	//	scanf("%d", &input);
//	//	if (input >= 1 & input <= 5)
//	//	{
//	//		printf("������������: >");
//	//		scanf("%d%d", &x, &y);
//	//		printf("%d\n", parr[input](x, y));
//	//	}
//	//	else if (input == 0)
//	//	{
//	//		printf("�˳�\n");
//	//	}
//	//	else
//	//	{
//	//		printf("ѡ�����,���������룺\n");
//	//	}
//	//} while (input);
//
//	/*  ��һ��
//	do
//	{
//		menu();
//		printf("��ѡ��>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("������������: >");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Add(x, y));
//			break;
//		case 2:
//			printf("������������: >");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Sub(x, y));
//			break;
//		case 3:
//			printf("������������: >");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Mul(x, y));
//			break;
//		case 4:
//			printf("������������: >");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Div(x, y));
//			break;
//		case 0:
//			printf("�˳�\n");
//			break;
//		default:
//			printf("ѡ���������һ�Σ�>\n");
//			break;
//		}
//	} while (input);
//	*/
//
//	return 0;
//}

//// ָ����ָ�������ָ��
//int main()
//{
//	int arr[10] = { 0 };
//	int(*p)[10] = &arr;    // ȡ������ĵ�ַ
//	int(*pf)(int, int);    // ����ָ��
//	int(*pfarr[4])(int, int); // pfArr��һ������ - ����ָ�������
//	int(*(*ppfArr)[4])(int, int);  // ppfArr��һ��ָ��[����ָ������]��ָ��
//	// ppfArr��һ������ָ�룬ָ��ָ���������4��Ԫ��
//	// ָ��������ÿ��Ԫ�ص�������һ������ָ�� int(*)(int,int)
//	return 0;
//}


//// �ص����� - ͨ������ָ����õĺ������Ѻ�����ָ�루��ַ����Ϊ�������ݸ�
//   ��һ�������������ָ�뱻������������ָ��ĺ����ǣ����ǻص�����,
//   ֻ�����ض����¼�����������ʱ�������һ������

// ��һ��

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
//	printf("������������: >");
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
//		printf("��ѡ��>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Calc(Add);      //�����Add�������ǻص�����
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
//			printf("�˳�\n");
//			break;
//		default:
//			printf("ѡ���������һ�Σ�>\n");
//			break;
//		}
//	} while (input);
//	
//
//	return 0;
//}

//// ������
//
//void print(char* str)
//{
//	printf("hehe:%s\n", str);    // print�ǻص�����
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
