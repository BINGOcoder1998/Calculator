#pragma once
#include <easyx.h>
#include "Standard.h"
#include "LoadImage.h"
#include "WindowMessage.h"
#include "Transformation.h"


// ѡ����
class Option
{
private:
	int Down_Button[10];
	// �������
	int M_X = 307;

private:
	// �������޹صĸ���
	void updatewithinput17();
	// ��ͼ
	void showscreen17();
	// ��ʼ��
	void InitFuction();
public:
	// ���캯��
	Option();
	// ��������
	~Option();

	// ѡ���
	void OptionFuction(int &);
	// ���������ļ�
	void CaveFuction();
	// ��ȡ�����ļ�
	void ReadFuction();

public:
	// ��¼�Ƿ�������
	bool RecordPassWard = 0;
	// ���ƻ��ƴ���
	int DrawPasswordNumbers = 3;
	// ͸����
	int Alpha = 255;
	// ����
	int Performance = 0;
	// ���ڷ��
	int WindowStyle = 0;
	// С������λ��
	int DecimalDigit = 15;
};

extern Option option;