#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include "Search_A.h"

using namespace std;

int main()
{
	SSTable ST;
	int key, m = 0;

	ST.R = (ElemType*)malloc(20 * sizeof(ElemType));	//分配存储空间

	cout << "输入序列长度：";
	cin >> ST.length;						//先输入该序列的长度
	for (int i = 0; i <= ST.length; i++)	//初始化ST里的值
	{
		ST.R[i].key = 0;
		ST.R[i].otherinfo = 0;
	}	
	cout << "输入序列元素：";
	for (int i = 0; i < ST.length; i++)
		cin >> ST.R[i].key;					//输入序列元素	
	cout << "输入要查找的元素：";
	cin >> key;								//输入要查找的元素

	if (!Search_Seq(ST, key))
		cout << "顺序查找-查无该元素。" << endl << endl;
	else
		cout << "顺序查找-查找成功，该元素在序列中的序号为" << Search_Seq(ST, key) << endl << endl;

	cout << "顺序查找-每次比较的元素：";
	while (ST.R[m].otherinfo)
	{
		cout << ST.R[m].otherinfo << "\t";	//依次输出比较的值
		m += 1;
	}
	cout << endl << endl;
	
	for (int i = 0; i <= ST.length; i++)	//重置ST里依次比较的值
	{
		ST.R[i].otherinfo = 0;
	}

	if (!Search_Bin(ST, key))
		cout << "折半查找-查无该元素。" << endl << endl;			//输出位置
	else
		cout << "折半查找-查找成功，该元素在序列中的序号为" << Search_Bin(ST, key) << endl << endl;			//输出位置	

	cout << "折半查找-每次比较的元素：";
	m = 0;
	while (ST.R[m].otherinfo)
	{
		cout << ST.R[m].otherinfo << "\t";	//依次输出比较的值
		m += 1;
	}

	cout << endl << endl;
	return 0;
}
