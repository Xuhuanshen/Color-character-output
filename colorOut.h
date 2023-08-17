#pragma once
#include <iostream>
#include <string>
#include "RGB.h"

using namespace std;

class colorOut
{
public:
	//����
	RGB defaultTextColor;//�ı���ɫ
	RGB defaultBackgroundColor;//������ɫ
	bool defaultItalic;//б��
	bool defaultUnderline;//�»���
	bool defaultBlink;//��˸
	bool defaultCrossed_Out;//ɾ�����	���м仮��
	bool automaticReset;//�Զ���λ	��������Զ��ָ�Ĭ������


	//����
	colorOut();
	colorOut(RGB defaultTextColor, RGB defaultBackgroundColor);
	colorOut(RGB defaultTextColor, RGB defaultBackgroundColor, bool defaultItalic, bool defaultUnderline, bool defaultBlink, bool defaultCrossed_Out, bool automaticReset);


	//���
	void out(string text);
	void out(string text, RGB textColor);
	void out(string text, RGB textColor, RGB backgroundColor);
	void out(string text, RGB textColor, RGB backgroundColor, bool Italic, bool Underline, bool Blink, bool Crossed_Out);


	//����
	void swapTextColorAndBackgroundColor();//�����ı�ɫ�ͱ���ɫ


	//����
	colorOut operator<<(string text);
};

