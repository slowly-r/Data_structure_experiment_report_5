#pragma once

#ifndef Search_A_H
#define Search_A_H

#define KeyType int		//�궨������ķ�������Ϊint
#define InfoType int

typedef struct {
	KeyType key;		//�ؼ�����
	InfoType otherinfo;	//������
}ElemType;

typedef struct {
	ElemType* R;		//�洢�ռ����ַ
	int length;			//��ǰ����
}SSTable;

int Search_Seq(SSTable& ST, KeyType key);		//˳�����
int Search_Bin(SSTable& ST, KeyType key);		//�۰����

#endif
