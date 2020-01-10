#pragma once
#include <cmath>
#include <string>
#include <stack>
#include <easyx.h>
#include "Option.h"
#include "Standard.h"
#include "LoadImage.h"
#include "TransParent.h"
#include "WindowMessage.h"
#include "Transformation.h"

using std::stack;
using std::wstring;
using std::to_wstring;

class Science
{
private:
	constexpr static auto  Radian = 0.01745329251994329576923690768489;
	enum
	{
		Sqrt = 1,
		Square = 2,
		Log = 3,
		Ten_X = 4,
		Power_X_Y = 5,
		Sin = 6,
		Cos = 7,
		Tan = 8,

		E_X = 9,
		Cube = 10,
		Ln = 11,
		Mod = 12,
		Square_X_Y = 13,
		ArcSin = 14,
		ArcCos = 15,
		ArcTan = 16
	};
private:
	void updatewithinput();								   // ��ѧ���������йصĸ���
	void showscreen();									   // ��ѧ����ʾ����
	void RecordInput(int, int, bool PageTurn = false);     // ��¼����
	void ScienceCalculator(LPCTSTR, LPCTSTR);              // ��ʽ��ʾ
	void MiddleEquationToLast();                           // ��׺���ʽת��׺
	void CalculatorLastEquation();                         // �����׺���ʽ
	void Calculator_Function(short);                       // ���㺯��
	void StorageEquation_Show_Move();					   // ��ʽ����
	void ConMove(MOUSEMSG);                                // ���ƻ���

public:
	Science() {};
	~Science() {};
	void ScienceFuction(int &);
	void ShowLeftBrackets();                               // ��ʾ��������Ŀ

private:
	wstring StorageEquation_Show;                          // ��¼��ʽ��ʾ
	wstring StorageEquation_Calculator;                    // ��¼��ʽ����
	wstring StorageEquation_Calculator_Last;               // ��׺���ʽ
	wstring StorageNumber;                                 // ��¼����
	wstring Number[3] = { _T("123"),_T("456"),_T("789") }; // ����
	wstring Operator = _T("�¡�-+");                       // �����
	long double PreNumber = 0;                             // ��ǰ������1
	long double PreNumber_Two = 1;                         // ���׵�����2
	int Calculator_TwoNumber = 0;                          // ��Ǽ���������
	int Left_Brackets = 0;                                 // ���������ŵ�����
	bool Push = false;                                     // �Ƿ���мӼ�
	bool PageTurn = false;                                 // ��ҳ����������������
	bool FinshCalculate = false;                           // �����Ƿ����
	bool DecimalPoint = false;                             // �Ƿ������С����
	bool Judge_Left_Can_Move = 0;                          // �ж��Ƿ�������ƶ���ʽ
	bool Judge_Right_Can_Move = 0;                         // �ж��Ƿ�������ƶ���ʽ
	bool Left_Clolor = 0;                                  // ����Ƶ�λ����ɫ�仯
	bool Right_Color = 0;
	bool Left_String_move = false;                         // �ж��Ƿ���Ի���
    bool Right_String_move = false;                     
	int Move_Number = 0;                                   // �Ƶ�����
	int String_Move = 0;                             	   // ����ַ����೤�Ϳ��Ի���

};

extern Science science;

