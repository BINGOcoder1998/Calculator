#pragma once
#include <easyx.h>
#include "Option.h"
#include "LoadImage.h"
#include "Conversion.h"
#include "TransParent.h"
#include "WindowMessage.h"
#include "Transformation.h"

class Text
{
private:
	// �����ļ�
	MyChar SS[100000] = { 0 };
	// �������������йصĸ���
	void updatewithinput4();
	// ��������ʾ����                         
	void showscreen4(); 
	// �����ļ�                                   
	void loadtext();  
public:
	Text() {};
	~Text() {};
	void TextFuction(int &);
};

extern Text text;
