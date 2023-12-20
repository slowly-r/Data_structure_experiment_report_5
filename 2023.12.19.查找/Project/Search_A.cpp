#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include "Search_A.h"

using namespace std;

//��˳���ST��˳�������ؼ��ֵ���key������Ԫ�ء����ҵ�������ֵΪ��Ԫ���ڱ��е�λ�ã�����Ϊ0
int Search_Seq(SSTable& ST, KeyType key)			//˳�����
{
	for (int i = 0; i < ST.length; i ++)
	{
		ST.R[i].otherinfo = ST.R[i].key;			//���Ƚϵ�ֵ����otherinfo
		if (ST.R[i].key == key)		return i + 1;	//�Ӻ���ǰ����
	}
	return 0;
}

//�������ST���۰������ؼ��ֵ���key������Ԫ�ء����ҵ�������ֵΪ��Ԫ���ڱ��е�λ�ã�����Ϊ0
int Search_Bin(SSTable& ST, KeyType key)			//�۰����
{
	int low = 1;
	int mid;
	int high = ST.length;							//�ò��������ֵ
	int i = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		ST.R[i].otherinfo = ST.R[mid].key;			//���Ƚϵ�ֵ����otherinfo
		i += 1;
		if (key == ST.R[mid].key)		return mid + 1;		//�ҵ�����Ԫ��
		else if (key < ST.R[mid].key)	high = mid - 1;		//������ǰһ�ӱ���в���
		else							low = mid + 1;		//�����ں�һ�ӱ���в���
	}
	return 0;										//���в����ڴ���Ԫ��
}
