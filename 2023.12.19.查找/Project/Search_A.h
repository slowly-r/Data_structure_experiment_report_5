#pragma once

#ifndef Search_A_H
#define Search_A_H

#define KeyType int		//宏定义特殊的返回类型为int
#define InfoType int

typedef struct {
	KeyType key;		//关键字域
	InfoType otherinfo;	//其他域
}ElemType;

typedef struct {
	ElemType* R;		//存储空间基地址
	int length;			//当前长度
}SSTable;

int Search_Seq(SSTable& ST, KeyType key);		//顺序查找
int Search_Bin(SSTable& ST, KeyType key);		//折半查找

#endif
