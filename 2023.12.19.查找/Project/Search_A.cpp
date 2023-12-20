#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include "Search_A.h"

using namespace std;

//在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，则函数值为该元素在表中的位置，否则为0
int Search_Seq(SSTable& ST, KeyType key)			//顺序查找
{
	for (int i = 0; i < ST.length; i ++)
	{
		ST.R[i].otherinfo = ST.R[i].key;			//将比较的值存入otherinfo
		if (ST.R[i].key == key)		return i + 1;	//从后往前查找
	}
	return 0;
}

//在有序表ST中折半查找其关键字等于key的数据元素。若找到，则函数值为该元素在表中的位置，否则为0
int Search_Bin(SSTable& ST, KeyType key)			//折半查找
{
	int low = 1;
	int mid;
	int high = ST.length;							//置查找区间初值
	int i = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		ST.R[i].otherinfo = ST.R[mid].key;			//将比较的值存入otherinfo
		i += 1;
		if (key == ST.R[mid].key)		return mid + 1;		//找到待查元素
		else if (key < ST.R[mid].key)	high = mid - 1;		//继续在前一子表进行查找
		else							low = mid + 1;		//继续在后一子表进行查找
	}
	return 0;										//表中不存在待查元素
}
