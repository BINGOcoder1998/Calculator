#pragma once
#include <Windows.h>
#include "Set.h"
#include "Text.h"
#include "Option.h"
#include "Science.h"
#include "Standard.h"
#include "PassWord.h"
#include "LoadImage.h"
#include "Bignumber.h"
#include "Conversion.h"
#include "TransParent.h"
#include "SolveSolution.h"
#include "Transformation.h"


// ׼��
class ReadyCalculator
{
public:
	enum
	{
		Option =    0,
		Stabdard =  1,
		Science =   2,
		BigNumber = 3,
		Equation =  4,
		Radix =     5,
		Profiles =  18,
		set =       19
	};

public:
	ReadyCalculator() {};
	~ReadyCalculator() {};
	void ReadyCalculatorFuction();
	void ReadyCalculatorPassWord();
};

void ReadyCalculator::ReadyCalculatorFuction()
{
	// ��ȡ�����ļ�
	option.ReadFuction();

	// ���ڴ�С
	HWND hWnd = initgraph(406, 600);

	// ��ȡ���ڱ߿���
	int cx = GetSystemMetrics(SM_CXFIXEDFRAME);
	int cy = GetSystemMetrics(SM_CYFIXEDFRAME) + GetSystemMetrics(SM_CYCAPTION);

	// ���þ�������
	HRGN rgn = CreateRoundRectRgn(5 + cx, 5 + cy, 412 + cx, 606 + cy, 2, 2);
	SetWindowRgn(hWnd, rgn, true);

	//����͸������
	SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	SetLayeredWindowAttributes(hWnd, 0, option.Alpha, LWA_ALPHA);

	//���ô�����λ��
	SetWindowPos(hWnd, HWND_TOPMOST, (GetSystemMetrics(SM_CXSCREEN) - 400) / 2, (GetSystemMetrics(SM_CYSCREEN) - 600) / 2 - 70, 424, 640, SWP_SHOWWINDOW);
}

void ReadyCalculator::ReadyCalculatorPassWord()
{
	if (option.RecordPassWard)
	{
		password.LoadPassWord();                                             // ��������
		while (!password.PassWordRight())                                    // ������ȷ������һ��
		{
			password.FoundPassWord();                                        // �½�����
			password.InputPassWordNumbers();                                 // ���������������
			password.drawscreen();                                           // ��ʾ����
			password.update();                                               // ��������
			password.UpdatePassWordFuction();                                // ��������                           
			Sleep(option.Performance);
		}
	}
}
