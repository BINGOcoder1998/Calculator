#pragma once
#include <ctime>
#include <easyx.h>
#include "LoadImage.h"
#include "Transformation.h"
#pragma warning(disable:4996)

#define address "calculator.dat"

//������
class PassWord
{
private:
	//�����ṹ��
	struct buttons
	{
		// �������Ƿ��ڵ���
		bool button;
		// ����Ƿ���ĳ������
		bool mouse_down;
		// ѡ�еĵ�ı��
		int pointnumber;
	}buttons[3][3];
	// ������ṹ��
	struct point
	{
		int X, Y;
	}point[9];

	// H:ɫ�౥ 
	// S:�Ͷ� 
	// L:����
	float H, S, L;
	// ����
	int number;
	// �����ƶ�
	int move;
	// ��������
	int  m_X, m_Y;
	// ����������
	int X, Y;
	// ����Ƿ���
	bool mouse_isdown;
	// ��ʱ����
	clock_t start, end;  
	// ��׼����
	MyChar StandardPassWord[50];
	// �����Ƿ���ȷ
	bool passwordcorrect;
	bool control;
	bool control_1;
	// ��������Ĵ���
	int DrawPassWordNumber;  
	// ���Ʊ�����ɫ
	void drawcolor();
	
public:
	 
	// ���캯��
	PassWord();
	PassWord(float, float, float);
	// ��������
	~PassWord(void) {};
	// ����
	void update(int k = 0);;
	// ���ƽ���
	void drawscreen(int k = 0);
	// ��������
	void LoadPassWord();
	// �������
	void CheckPassWord();

private:
	// ������ʾ
	MyChar inputprompt[50];
	// �ݴ��������
	MyChar initpassword1[50], initpassword2[50];

	// ������ڰ�����
	bool on_button[6];
	bool down_button[6];
	
	// ��ʼ������
	void initfunction(int);
	// �ݴ�����
	void initpassword();
	// ��������
	void SavePassWord();
	// ����Ĵ���
	int inputnumber;
	// ����Ƿ�������
	bool Check();
	// ���½�������
	void update_establish_password();
	// ��ʾ��������
	void show_establish_password();
	// ��������
	bool UpdatePassWord;
	// ȡ����������
	bool No_UpdatePassWord;

public:
	// �½�����
	void FoundPassWord();
	// �������뺯��
	void UpdatePassWordFuction();
	// ����������ȷ
	bool PassWordRight();
	// ���������������
	void InputPassWordNumbers();
};

extern PassWord password;