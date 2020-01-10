#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <easyx.h>
#include "Option.h"
#include "Standard.h"
#include "LoadImage.h"
#include "Conversion.h"
#include "TransParent.h"
#include "WindowMessage.h"
#include "Transformation.h"

class Bignumber
{
private:
	void bignumberadd();						                    // �������ӷ�
	void bignumbersubtract();					                    // ����������
	void bignumbermuit();						                    // �������˷�
	void bignumberdiv();						                    // ����������
	void updatewithinput1();				                      	// ���������������йصĸ���
	void showscreen1();							                    // ����������ʾ����
	void memsenumber();
	void LsJJ(MyChar *s4, bool t);                                  // �������ּӼ�һ
	MyChar *numberaddx(MyChar *ss, MyChar *ss1);
	MyChar *numberadd(MyChar *ss, MyChar *ss1);
	MyChar *numbersub(MyChar *ss, MyChar *ss1);
	MyChar *numbersubx(MyChar *ss, MyChar *ss1);

public:
	void BignumberFuction(int &);

private:
	
	MyChar s6[100000];												// �洢������ַ�����ʾ��
	MyChar s4[100000] = { 0 }, s5[100000] = { 0 };					// �洢����������ַ���
	int a[100000] = { 0 }, b[100000] = { 0 };						// �洢�ַ���ת��Ϊ����
	int c[100000] = { 0 };											// �洢������

public:
	bool button1[10] = { false };									// �жϼ��������

};

extern Bignumber bignumber;