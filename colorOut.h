#pragma once
#include <iostream>
#include <string>
#include "RGB.h"

using namespace std;

class colorOut
{

private:
	//��������
	RGB defaultTextColor;//�ı���ɫ
	RGB defaultBackgroundColor;//������ɫ
	bool defaultItalic;//б��
	bool defaultUnderline;//�»���
	bool defaultBlink;//��˸
	bool defaultCrossed_Out;//ɾ����ǣ��м仮��
	bool automaticReset;//�Զ���λ��������Զ��ָ�Ĭ������
	//����
	string outBuffer;//�������


public:
	//����
	colorOut();
	colorOut(RGB defaultTextColor, RGB defaultBackgroundColor);
	colorOut(RGB defaultTextColor, RGB defaultBackgroundColor,
		bool defaultItalic, bool defaultUnderline, bool defaultBlink, bool defaultCrossed_Out, bool automaticReset);
	colorOut(const colorOut& oldColorOut);


	//��ȡ���޸�����
	RGB getDefaultTextColor();
	void setDefaultTextColor(RGB newColor);
	RGB getDefaultBackgroundColor();
	void setDefaultBackgroundColor(RGB newColor);
	bool getDefaultItalic();
	void setDefaultItalic(bool newSet);
	bool getDefaultUnderline();
	void setDefaultUnderline(bool newSet);
	bool getDefaultBlink();
	void setDefaultBlink(bool newSet);
	bool getDefaultCrossed_Out();
	void setDefaultCrossed_Out(bool newSet);
	bool getAutomaticReset();
	void setAutomaticReset(bool newSet);


	//���
	void out(string text);
	void out(string text, RGB textColor);
	void out(string text, RGB textColor, RGB backgroundColor);
	void out(string text, RGB textColor, RGB backgroundColor, 
		bool Italic, bool Underline, bool Blink, bool Crossed_Out);


	//����
	void swapTextColorAndBackgroundColor();//�����ı�ɫ�ͱ���ɫ
	string setOutStyle(RGB textColor, RGB backgroundColor, 
		bool Italic, bool Underline, bool Blink, bool Crossed_Out);//���������ʽ��ֻ���ò����,���Զ���λ,������ʽ���ַ�����ʽ
	void reset();//�ر����������ʽ���������Իָ�Ĭ��



	//����
	colorOut operator<<(string text);//��������������ʽ���
	void operator=(const colorOut& oldColorOut);
};

