#pragma once
#include <stack>
#include <easyx.h>
#include <iostream>
#include "Option.h"
#include "Bignumber.h"
#include "WindowMessage.h"
#include "Transformation.h"

class Conversion
{
private:
	void conversion(MyChar *sss, long long x, int n);      //����ջ���н���ת��
	void memse();                                          //��ʼ��
	bool input(int n);
	void everone(int n = 2);                               //�ֱ�����������
	void updatewithinput3();                               //����ת�����������йصĸ���
	void showscreen3();                                    //����ת������ʾ����

public:
	void ConversionFuction(int &);
	void changecolor(
		int Left, int Right, int Top, int Bottom,
		float l = 0.0008f, float k = 1.0f,
		bool t = false
	);                                  //�ı���ɫ
	void Setcolor(
		int Left, int Right, int Top, int Bottom,
		COLORREF rgb = RGB(50, 50, 50)
	);

private:

	MyChar S[65][100];                                    //��¼���������
	MyChar s0[19] = { _T("������滵�ˣ�����") };         //������
	int ZH = -1;                                          //�������ֵĳ���
	bool button3[10] = { true };                          //���ѡ������ĸ�����
	bool button2[10] = { false };                         //���ѡ������ĸ�����

};

extern Conversion conversion;