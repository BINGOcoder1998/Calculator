#include "Option.h"

Option option;

Option::Option()
{
	Down_Button[0] = 0;
	Down_Button[1] = 1;
	Down_Button[2] = 0;
	Down_Button[3] = 2; 
	Down_Button[4] = 0;
	Down_Button[5] = 5;
}

Option::~Option() {}

void Option::updatewithinput17()
{
	MOUSEMSG m;	// ���������Ϣ
	while (MouseHit())	// ����Ƿ��������Ϣ
	{
		m = GetMouseMsg();

		Window_Message.windowmessage(m, -1); //�ƶ�����

		for (int i = 0; i < 2; i++) // ���뿪��
		{
			if (m.x > 100 + 50 * i&&m.x < 150 + 50 * i&&m.y>100 && m.y < 125)
			{
				if (m.uMsg == WM_LBUTTONUP) 
				{
					Down_Button[0] = i;
					if (i) RecordPassWard = true;
					else RecordPassWard = false;
				}
			}
		}
		for (int i = 0; i < 4; i++) // ���ƴ���
		{
			if (m.x > 100 + 50 * i&&m.x < 150 + 50 * i&&m.y>150 && m.y < 175)
			{
				if (m.uMsg == WM_LBUTTONUP)
				{
					Down_Button[1] = i;
					if (i == 0)      DrawPasswordNumbers = 3;
					else if (i == 1) DrawPasswordNumbers = 5;
					else if (i == 2) DrawPasswordNumbers = 10;
					else if (i == 3) DrawPasswordNumbers = 900000;
				}
			}
		}
		for (int i = 0; i < 2; i++) // fps
		{
			if (m.x > 100 + 50 * i&&m.x < 300 + 50 * i&&m.y>300 && m.y < 325)
			{
				if (m.uMsg == WM_LBUTTONUP)
				{
					Down_Button[2] = i;
					if (i == 0)      Window_Message.showFPS = false;
					else if (i == 1) Window_Message.showFPS = true;
				}
			}
		}
		for (int i = 0; i < 4; i++) // ����
		{
			if (m.x > 100 + 50 * i&&m.x < 150 + 50 * i&&m.y>350 && m.y < 375)
			{
				if (m.uMsg == WM_LBUTTONUP)
				{
					Down_Button[3] = i;
					if (i == 0)      Performance = 60;
					else if (i == 1) Performance = 35;
					else if (i == 2) Performance = 10;
					else if (i == 3) Performance = 0;
				}
			}
		}
		for (int i = 0; i < 5; i++) // С��λ��
		{
			if (m.x > 100 + 50 * i&&m.x < 150 + 50 * i&&m.y>400 && m.y < 425)
			{
				if (m.uMsg == WM_LBUTTONUP)
				{
					Down_Button[5] = i;
					if (!i)          DecimalDigit = 2;
					else if (i == 1) DecimalDigit = 5;
					else if (i == 2) DecimalDigit = 8;
					else if (i == 3) DecimalDigit = 10;
					else if (i == 4) DecimalDigit = 15;
				}
			}
		}
		if (m.x >= 110 && m.x <= 315 && m.y>502 && m.y < 522)// alpha
		{
			if (m.mkLButton)
			{
				M_X = m.x - 8;
				Alpha = m.x - 60;
			}
		}
		for (int i = 0; i < 3; i++) // ���
		{
			if (m.x > 100 + 50 * i&&m.x < 150 + 50 * i&&m.y>550 && m.y < 575)
			{
				if (m.uMsg == WM_LBUTTONUP)
				{
					Down_Button[4] = i;
					if (!i)          WindowStyle = 0;
					else if (i == 1) WindowStyle = 1;
					else             WindowStyle = 2;
				}
			}
		}

		if (m.x > 310 && m.x <395  && m.y>570 && m.y < 590) // ��������
		{
			Down_Button[6] = 1;
			if (m.uMsg == WM_LBUTTONUP)
			{
				CaveFuction();
				transformation.software[0] = Window_Message.Recorde;
			}
		}
		else
			Down_Button[6] = 0;
	}
}

void Option::showscreen17()
{
	BeginBatchDraw();

	setbkmode(TRANSPARENT);

	if (!WindowStyle)          conversion.Setcolor(0, 406, 0, 600);
	else if (WindowStyle == 1) conversion.Setcolor(0, 406, 0, 600, RGB(180, 180, 180));
	else                       conversion.changecolor(0, 406, 0, 600);

	IMAGE black = MyLoadImage.setimage(406, 600, RGB(0, 0, 0));	// ���û�ͼ
	MyPutimage.my_putimage(0, 0, &black, RGB(255, 255, 255), 0, 1, 30, 0);

	Window_Message.GetFunctionName(_T(""), -1);

	black = MyLoadImage.setimage(406, 20, RGB(0, 0, 0));	   // ���û�ͼ
	MyPutimage.my_putimage(0, 50, &black, RGB(255, 255, 255), 0, 1, 50, 0);

	settextstyle(19, 0, _T("΢���ź�"), 0, 0, 100, 0, 0, 0);
	settextcolor(RGB(150, 150, 150));
	outtextxy(20, 50, _T("��ȫ����"));

	// ���� ����ѡ��
	settextcolor(RGB(255, 255, 255));
	settextstyle(23, 0, _T("΢���ź�"), 0, 0, 100, 0, 0, 0);
	outtextxy(10, 100, _T("����"));
    black = MyLoadImage.setimage(103, 25, RGB(0, 0, 0));	   // ���û�ͼ
	MyPutimage.my_putimage(100, 100, &black, RGB(255, 255, 255), 0, 1, 50, 0);
	setfillcolor(HSLtoRGB(195, 1, 0.5f));
	solidroundrect(102 + 50 * Down_Button[0], 102, 150 + 50 * Down_Button[0], 122, 3, 3);
	MyChar Name1[][5] = { {_T("��")},{_T("��")}};
	for (int i = 0; i < 2; i++) outtextxy(118 + 50 * i, 100, Name1[i]);
	settextstyle(17, 0, _T("΢���ź�"), 0, 0, 10, 0, 0, 0);
	outtextxy(320, 105, _T("����������Ч"));

	// �����������ѡ��
	settextcolor(RGB(255, 255, 255));
	settextstyle(23, 0, _T("΢���ź�"), 0, 0, 100, 0, 0, 0);
	outtextxy(10, 150, _T("��������"));
	black = MyLoadImage.setimage(203, 25, RGB(0, 0, 0));	   // ���û�ͼ
	MyPutimage.my_putimage(100, 150, &black, RGB(255, 255, 255), 0, 1, 50, 0);
	setfillcolor(HSLtoRGB(195, 1, 0.5f));
	solidroundrect(102 + 50 * Down_Button[1], 152, 150 + 50 * Down_Button[1], 172, 3, 3);
	MyChar Name2[][10] = { {_T("����")},{_T("���")},{_T("ʮ��")},{_T("����")} };
	for (int i = 0; i < 4; i++) outtextxy(110 + 50 * i, 150, Name2[i]);
	settextstyle(17, 0, _T("΢���ź�"), 0, 0, 10, 0, 0, 0);
	outtextxy(320, 155, _T("����������Ч"));
    
	// ��ʾfpsѡ��
	black = MyLoadImage.setimage(406, 20, RGB(0, 0, 0));	// ���û�ͼ
	MyPutimage.my_putimage(0, 250, &black, RGB(255, 255, 255), 0, 1, 50, 0);
	settextstyle(19, 0, _T("΢���ź�"), 0, 0, 100, 0, 0, 0);
	settextcolor(RGB(150, 150, 150));
	outtextxy(20, 250, _T("��������"));

	settextcolor(RGB(255, 255, 255));
	settextstyle(23, 0, _T("΢���ź�"), 0, 0, 100, 0, 0, 0);
	outtextxy(10, 300, _T("��ʾFPS"));
	black = MyLoadImage.setimage(103, 25, RGB(0, 0, 0));	   // ���û�ͼ
	MyPutimage.my_putimage(100, 300, &black, RGB(255, 255, 255), 0, 1, 50, 0);
	setfillcolor(HSLtoRGB(195, 1, 0.5f));
	solidroundrect(102 + 50 * Down_Button[2], 302, 150 + 50 * Down_Button[2], 322, 3, 3);
	MyChar Name3[][5] = { {_T("��")},{_T("��")}};
	for (int i = 0; i < 2; i++) outtextxy(118 + 50 * i, 300, Name3[i]);

	// ����ѡ��
	settextcolor(RGB(255, 255, 255));
	settextstyle(23, 0, _T("΢���ź�"), 0, 0, 100, 0, 0, 0);
	outtextxy(10, 350, _T("����"));
	black = MyLoadImage.setimage(203, 25, RGB(0, 0, 0));	   // ���û�ͼ
	MyPutimage.my_putimage(100, 350, &black, RGB(255, 255, 255), 0, 1, 50, 0);
	setfillcolor(HSLtoRGB(195, 1, 0.5f));
	solidroundrect(102 + 50 * Down_Button[3], 352, 150 + 50 * Down_Button[3], 372, 3, 3);
	MyChar Name4[][10] = { {_T("�ϵ�")},{_T("�е�")},{_T("�ϸ�")},{_T("����")} };
	for (int i = 0; i < 4; i++) outtextxy(110 + 50 * i, 350, Name4[i]);

	// С������λ��
	settextcolor(RGB(255, 255, 255));
	settextstyle(17, 0, _T("΢���ź�"), 0, 0, 100, 0, 0, 0);
	outtextxy(100, 430, _T("����������λ�������õ�λ����ʱ����Ч"));
	settextstyle(23, 0, _T("΢���ź�"), 0, 0, 100, 0, 0, 0);
	outtextxy(10, 400, _T("����λ��"));
	black = MyLoadImage.setimage(253, 25, RGB(0, 0, 0));	   // ���û�ͼ
	MyPutimage.my_putimage(100, 400, &black, RGB(255, 255, 255), 0, 1, 50, 0);
	setfillcolor(HSLtoRGB(195, 1, 0.5f));
	solidroundrect(102 + 50 * Down_Button[5], 402, 150 + 50 * Down_Button[5], 422, 3, 3);
	MyChar Name6[][10] = { {_T("2 λ")},{_T("5 λ")},{_T("8 λ")},{_T("10λ")},{_T("15λ")} };
	for (int i = 0; i < 5; i++)
	{
		if (i == 3 || i == 4) outtextxy(110 + 50 * i - 5, 400, Name6[i]);
		else outtextxy(110 + 50 * i, 400, Name6[i]);
	}

	// ����ѡ��
	black = MyLoadImage.setimage(406, 20, RGB(0, 0, 0));	// ���û�ͼ
	MyPutimage.my_putimage(0, 450, &black, RGB(255, 255, 255), 0, 1, 50, 0);
	settextstyle(19, 0, _T("΢���ź�"), 0, 0, 100, 0, 0, 0);
	settextcolor(RGB(150, 150, 150));
	outtextxy(20, 450, _T("��������"));
	settextcolor(RGB(255, 255, 255));
	settextstyle(23, 0, _T("΢���ź�"), 0, 0, 100, 0, 0, 0);
	outtextxy(10, 500, _T("����͸����"));
	setlinestyle(PS_SOLID| PS_ENDCAP_ROUND, 5);
	setlinecolor(RGB(20,20,20));
	line(110, 512, 315, 512);
	setlinecolor(HSLtoRGB(250, 1, 0.5f));
	line(110, 512, M_X + 8, 512);
	setfillcolor(HSLtoRGB(195, 1, 0.5f));
	POINT pts[] = {  {M_X, 512},{10 + M_X, 502}, {20 + M_X, 512},{10 + M_X ,522} };
	solidpolygon(pts, 4);
	settextstyle(18, 0, _T("΢���ź�"), 0, 0, 100, 0, 0, 0);
	MyChar s[15];
	_stprintf_s(s, _T("Alpha: %d"), Alpha);
	outtextxy(335, 503, s);

	settextcolor(RGB(255, 255, 255));
	settextstyle(23, 0, _T("΢���ź�"), 0, 0, 100, 0, 0, 0);
	outtextxy(10, 550, _T("�������"));
	black = MyLoadImage.setimage(153, 25, RGB(0, 0, 0));	   // ���û�ͼ
	MyPutimage.my_putimage(100, 550, &black, RGB(255, 255, 255), 0, 1, 50, 0);
	setfillcolor(HSLtoRGB(195, 1, 0.5f));
	solidroundrect(102 + 50 * Down_Button[4], 552, 150 + 50 * Down_Button[4], 572, 3, 3);
	MyChar Name5[][10] = { {_T("�ڻ�")},{_T("����")},{_T("�ò�")} };
	for (int i = 0; i < 3; i++)
		outtextxy(110 + 50 * i, 550, Name5[i]);

	// ȷ��
	if (Down_Button[6]) settextcolor(HSLtoRGB(195, 1, 0.5f));
	else                settextcolor(WHITE);
	settextstyle(20, 0, _T("΢���ź�"), 0, 0, 100, 0, 0, 0);
	outtextxy(310, 570, _T("����ȫ������"));

	EndBatchDraw();
}

void Option::OptionFuction(int &k)
{
	while (true)
	{
		//����͸������
		SetWindowLong(GetHWnd(), GWL_EXSTYLE, GetWindowLong(GetHWnd(), GWL_EXSTYLE) | WS_EX_LAYERED);
		SetLayeredWindowAttributes(GetHWnd(), 0, Alpha, LWA_ALPHA);

		showscreen17();
		updatewithinput17();

		if (k != transformation.software[0] + 1) 
			break;
		Sleep(Performance);						       // ��ʱ
	}
}

void Option::ReadFuction()
{
	// ��ȡ��һ�ε�����
	// ����Ŀ���
	RecordPassWard = GetPrivateProfileInt(_T("PassWard"), _T("RecordPassWard"), 0, _T(".\\important.ini"));
	// ���ƵĴ���
	DrawPasswordNumbers = GetPrivateProfileInt(_T("Draw"), _T("DrawPasswordNumbers"), 3, _T(".\\important.ini"));
	// �Ƿ���ʾfps
	Window_Message.showFPS = GetPrivateProfileInt(_T("FPS"), _T("ShowFPS"), false, _T(".\\important.ini"));
	// ����
	Performance = GetPrivateProfileInt(_T("Performance"), _T("performance"), 35, _T(".\\important.ini"));
	// ����͸����
	Alpha = GetPrivateProfileInt(_T("Alpha"), _T("alpha"), 255, _T(".\\important.ini"));
	// ������ɫ
	WindowStyle = GetPrivateProfileInt(_T("WindowStyle"), _T("windowstyle"), 0, _T(".\\important.ini"));
	// С��λ��
	DecimalDigit = GetPrivateProfileInt(_T("DecimalDigit"), _T("decimaldigit"), 15, _T(".\\important.ini"));

	InitFuction();
}

void Option::CaveFuction()
{
	// �������굽�����ļ�
	MyChar s[20];
	// ����Ŀ���
	_stprintf_s(s, _T("%d"), RecordPassWard);
	::WritePrivateProfileString(_T("PassWard"), _T("RecordPassWard"), s, _T(".\\important.ini"));
	// ���ƵĴ���
	_stprintf_s(s, _T("%d"), DrawPasswordNumbers);
	::WritePrivateProfileString(_T("Draw"), _T("DrawPasswordNumbers"), s, _T(".\\important.ini"));
	// �Ƿ���ʾfps
	_stprintf_s(s, _T("%d"), Window_Message.showFPS);
	::WritePrivateProfileString(_T("FPS"), _T("ShowFPS"), s, _T(".\\important.ini"));
	// ����
	_stprintf_s(s, _T("%d"), Performance);
	::WritePrivateProfileString(_T("Performance"), _T("performance"), s, _T(".\\important.ini"));
	// ����͸����
	_stprintf_s(s, _T("%d"), Alpha);
	::WritePrivateProfileString(_T("Alpha"), _T("alpha"), s, _T(".\\important.ini"));
	// ������ɫ
	_stprintf_s(s, _T("%d"), WindowStyle);
	::WritePrivateProfileString(_T("WindowStyle"), _T("windowstyle"), s, _T(".\\important.ini"));
	// ������ɫ
	_stprintf_s(s, _T("%d"), DecimalDigit);
	::WritePrivateProfileString(_T("DecimalDigit"), _T("decimaldigit"), s, _T(".\\important.ini"));
}

void Option::InitFuction()
{
	Down_Button[0] = RecordPassWard;                             // �Ƿ�������

	if      (DrawPasswordNumbers == 3)      Down_Button[1] = 0;  // ���ƻ��ƴ���
	else if (DrawPasswordNumbers == 5)      Down_Button[1] = 1;  // ���ƻ��ƴ���
	else if (DrawPasswordNumbers == 10)     Down_Button[1] = 2;  // ���ƻ��ƴ���
	else if (DrawPasswordNumbers == 900000) Down_Button[1] = 3;  // ���ƻ��ƴ���
	
	Down_Button[2] = Window_Message.showFPS;                     // �Ƿ���ʾfps

	if      (Performance == 60)  Down_Button[3] = 0;             // ����
	else if (Performance == 35)  Down_Button[3] = 1;
	else if (Performance == 10)  Down_Button[3] = 2;
	else if (Performance == 0)   Down_Button[3] = 3;

	M_X = Alpha + 60 - 8;                                        // ����͸����

	Down_Button[4] = WindowStyle;                                // ������ɫ

	if      (DecimalDigit == 2)  Down_Button[5] = 0;             // С��λ��
	else if (DecimalDigit == 5)  Down_Button[5] = 1;
	else if (DecimalDigit == 8)  Down_Button[5] = 2;
	else if (DecimalDigit == 10) Down_Button[5] = 3;
	else if (DecimalDigit == 15) Down_Button[5] = 4;
}