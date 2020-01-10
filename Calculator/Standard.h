#pragma once
#pragma comment(lib,"Comctl32.lib")
#include <stack>
#include <easyx.h>
#include "Option.h"
#include "LoadImage.h"
#include "TransParent.h"
#include "WindowMessage.h"
#include "Transformation.h"

class Standard
{
private:
	void change();								                 // ��׺���ʽת��Ϊ��׺���ʽ
	void calculate();							                 // �����׺���ʽ��ֵ
	void updatewithinput_();					                 // ��ͨ���㣺�������йصĸ���
	void showscreen_();							                 // ��ͨ���㣺��ʾ����
	void OperationFuction(int, int);                             // ��������
	void operation(MyChar C);
	
private:
	long double A = 10000000000;
	MyChar ZFC[10000] = { 0 };                 	                 // ��¼�����ÿһ������
	MyChar ZFC1[10000] = { 0 };                	                 // ��¼�������ʽ
	MyChar ZFC2[10000] = { 0 };               	                 // �洢��׺���ʽת��Ϊ��׺�Ľ��
	MyChar ZFC3[10000] = { 0 };                                  // ��¼������
	int Number_Length = -1;                              	     // �������ֵĳ���
	int String_Length = 0;                              	     // �������ʽ�ĳ���
	int Left_Brackets = 0;                              	     // ���������ŵ�����
	int String_Move = 0;                             	         // ����ַ����೤�Ϳ��Ի���
	bool Decimal_Point = false;                       	         // �ж��Ƿ���԰�С����
	bool FIRSTSHOW = false;                                      // ��һ����ʾ
	bool CLEARN = false;

public:
	Standard();
	void screenmovehd();						                 // �ַ�����������
	void ConMove(MOUSEMSG);                                      // ���ƻ���
	void StandardFuction(int &);

public:
	int fx = 0, fy = 0;                       	                 // �ж��Ƿ������������ƶ���ʽ
	int color = 0, color1 = 0;                                 	 // ���������ҿ����ƶ�����ɫ�仯
	int screenmove = 0;                      	                 // ������ʽ������ȫ��ʾ����ʽ�������ƶ�����
	bool Left_String_move = false, Right_String_move = false;    // �ж��Ƿ���Ի���
	
};

extern Standard standard;

class My_Stack
{
private:
	typedef struct node                   		// ջ�Ľṹ��
	{
		MyChar data;
		struct node *next;
	}Stack;
	Stack *t = NULL;
public:
	// ��ջ
	void push(MyChar c)	
	{
		Stack *s;
		s = (Stack*)malloc(sizeof(Stack));
		s->data = c;
		s->next = t;
		t = s;
	}
    // �ж�ջ�Ƿ�Ϊ��
	bool empty()	
	{
		if (!t)return true;
		return false;
	}
    // ��ջ
	void pop()		
	{
		Stack *s;
		if (!empty())
		{
			s = t->next;
			free(t);
			t = s;
		}
	}
    // ȡջ��Ԫ��
	MyChar top()	
	{
		MyChar s;
		s = '#';
		if (!empty()) s = t->data;
		return s;
	}
	// ���ջ
	void clearstack()	
	{
		Stack *s;
		while (!empty()) 
		{
			s = t->next;
			free(t);
			t = s;
		}
	}
};