#include"Text.h"

Text text;

/***********************************����**************************************/

void Text::loadtext() {
	FILE *p;
	if (!_tfopen_s(&p, _T("help.bat"), _T("rb"))) {//���ļ�
		int i = 0;
		while (!feof(p))SS[i++] = _fgettc(p);//��ȡ
		fclose(p);
	}
	else
		_tcscpy_s(SS, _T("              ���ļ�ʧ�ܣ�\n\n     �������Ŀ¼���Ƿ���help.bat��\n\n      �����help.bat�ļ��������´򿪡�"));
}

void Text::updatewithinput4() {
	MOUSEMSG m;//���������Ϣ
	while (MouseHit()) {//����Ƿ��������Ϣ
		m = GetMouseMsg();

		Window_Message.windowmessage(m);

		if (m.x > 5 && m.x < 40 && m.y > 30 && m.y < 50) {//����
			transformation.help[0] = true;
			if (m.uMsg == WM_LBUTTONUP) transformation.software[0] = -1, transformation.software[2] = 19;
		}
		else transformation.help[0] = false;

		if (m.uMsg == WM_MOUSEWHEEL) {
			if (m.wheel < 0)
				transformation.fly -= 20;
			else
				transformation.fly += 20;
		}	
	}
	int  len = (int)(_tcslen(SS) / 42.0 + 1)*18 - 18;//�ַ�������

	if (transformation.fly > 0)
		transformation.fly -= transformation.fly / 2;
	if (transformation.fly - 450 + (int)round(1.8f*len) < -len)
		transformation.fly += -((transformation.fly - 450 + (int)round(1.8f*len) + len) / 2);
}

void Text::showscreen4() {
	BeginBatchDraw();//��ʼ������ͼ
	setbkmode(TRANSPARENT);
	
	switch (option.WindowStyle)
	{
	case 0:  conversion.Setcolor(0, 406, 100, 550); break;
	case 1:  conversion.Setcolor(0, 406, 100, 550, RGB(180, 180, 180)); break;
	default: conversion.changecolor(0, 406, 100, 550); break;
	}
	
	IMAGE blacks = MyLoadImage.setimage(406, 450, RGB(0, 0, 0));//���û�ͼ
	MyPutimage.my_putimage(0, 100, &blacks, RGB(255, 255, 255), 0, 1, 60, 0);

	settextcolor(WHITE);
	settextstyle(18, 0, _T("����"), 0, 0, 200, false, false, false);
	RECT r = { 10, 100 + transformation.fly, 390, 1500 + transformation.fly };
	
	drawtext(SS, &r, DT_LEFT | DT_WORDBREAK);//д����

	switch (option.WindowStyle)
	{
	case 0:  conversion.Setcolor(0, 406, 0, 100); break;
	case 1:  conversion.Setcolor(0, 406, 0, 100, RGB(180, 180, 180)); break;
	default: conversion.changecolor(0, 406, 0, 100); break;
	}
	                  
	blacks = MyLoadImage.setimage(406, 101, RGB(0, 0, 0));//���û�ͼ
	MyPutimage.my_putimage(0, 0, &blacks, RGB(255, 255, 255), 0, 1, 60, 0);
	settextstyle(40, 0, _T("�����п�"));
	outtextxy(160, 50, _T("���"));

	switch (option.WindowStyle)
	{
	case 0:  conversion.Setcolor(0, 406, 550, 600); break;
	case 1:  conversion.Setcolor(0, 406, 550, 600, RGB(180, 180, 180)); break;
	default: conversion.changecolor(0, 406, 550,  600); break;
	}
	                 
	blacks = MyLoadImage.setimage(406, 50, RGB(0, 0, 0));//���û�ͼ
	MyPutimage.my_putimage(0, 550, &blacks , RGB(255, 255, 255), 0, 1, 60, 0);

	Window_Message.GetFunctionName(_T("����"));

	EndBatchDraw();
}

void Text::TextFuction(int &k)
{		            
	while (true)
	{
		if(!_tcslen(SS))loadtext();	   // ���û�м����ļ�

		updatewithinput4();
		showscreen4();

		if (k != transformation.software[0] + 1) break;
		Sleep(option.Performance);     // ��ʱ
	}
}