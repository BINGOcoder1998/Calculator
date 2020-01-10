#pragma once
#include <easyx.h>
#include "Option.h"
#include "Standard.h"
#include "Bignumber.h"
#include "Conversion.h"
#include "WindowMessage.h"
#include "Transformation.h"

class SolveSolution
{
private:
	void mem();								                    // ��ʼ������
	void slovesolution();					                    // �ⷽ�̺���
	void updatewithinput2();				                    // �ⷽ�̣��������йصĸ���
	void showscreen2();						                    // �ⷽ�̣���ʾ����

public:
	SolveSolution() {};
	~SolveSolution() {};
	void SolveSolutionFuction(int &);

private:

	MyChar xzfc[10000] = { 0 };								     // �洢������ַ�������
	MyChar Zfc[10000] = { 0 };								     // ��������ʱ���ݴ�
	MyChar s[10000] = { 0 };								     // ��������ʱ���ݴ�
	MyChar name[100] = { 0 };								     // �洢δ֪����������
	MyChar solution[10000] = { 0 };							     // �洢�����ʾ�Ľ��
	long double bsum = 0, zsum = 0, xbsum = 0, fsum = 0;		 // �ֱ�洢�����������ߵ�������
	int n = 0;												     // δ֪���ĳ���
	int E = -1;												     // �������ĳ���
	int blx = 0;										         // ��֤����Ϊһ��
	bool dyy = false;										     // ��֤һ��������ֻ��һ�����ں�
	bool xxs = false;										     // ��֤һ������ֻ��һ��С����
	int String_Move = 0;                             	         // ����ַ����೤�Ϳ��Ի���
	int screenmove = 0;                      	                 // ������ʽ������ȫ��ʾ����ʽ�������ƶ�����
	bool Left_String_move = false, Right_String_move = false;    // �ж��Ƿ���Ի���
};

extern SolveSolution solvesolution;