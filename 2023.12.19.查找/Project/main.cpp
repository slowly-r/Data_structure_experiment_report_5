#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include "Search_A.h"

using namespace std;

int main()
{
	SSTable ST;
	int key, m = 0;

	ST.R = (ElemType*)malloc(20 * sizeof(ElemType));	//����洢�ռ�

	cout << "�������г��ȣ�";
	cin >> ST.length;						//����������еĳ���
	for (int i = 0; i <= ST.length; i++)	//��ʼ��ST���ֵ
	{
		ST.R[i].key = 0;
		ST.R[i].otherinfo = 0;
	}	
	cout << "��������Ԫ�أ�";
	for (int i = 0; i < ST.length; i++)
		cin >> ST.R[i].key;					//��������Ԫ��	
	cout << "����Ҫ���ҵ�Ԫ�أ�";
	cin >> key;								//����Ҫ���ҵ�Ԫ��

	if (!Search_Seq(ST, key))
		cout << "˳�����-���޸�Ԫ�ء�" << endl << endl;
	else
		cout << "˳�����-���ҳɹ�����Ԫ���������е����Ϊ" << Search_Seq(ST, key) << endl << endl;

	cout << "˳�����-ÿ�αȽϵ�Ԫ�أ�";
	while (ST.R[m].otherinfo)
	{
		cout << ST.R[m].otherinfo << "\t";	//��������Ƚϵ�ֵ
		m += 1;
	}
	cout << endl << endl;
	
	for (int i = 0; i <= ST.length; i++)	//����ST�����αȽϵ�ֵ
	{
		ST.R[i].otherinfo = 0;
	}

	if (!Search_Bin(ST, key))
		cout << "�۰����-���޸�Ԫ�ء�" << endl << endl;			//���λ��
	else
		cout << "�۰����-���ҳɹ�����Ԫ���������е����Ϊ" << Search_Bin(ST, key) << endl << endl;			//���λ��	

	cout << "�۰����-ÿ�αȽϵ�Ԫ�أ�";
	m = 0;
	while (ST.R[m].otherinfo)
	{
		cout << ST.R[m].otherinfo << "\t";	//��������Ƚϵ�ֵ
		m += 1;
	}

	cout << endl << endl;
	return 0;
}
