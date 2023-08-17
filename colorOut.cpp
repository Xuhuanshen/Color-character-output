#include "colorOut.h"

colorOut::colorOut()//�޲ι��죨�������Ծ�Ĭ��
{
	this->defaultTextColor = RGB(204, 204, 204);//Ĭ����ɫ����PowerShell
	this->defaultBackgroundColor = RGB(12, 12, 12);//Ĭ����ɫ����PowerShell
	this->defaultItalic = false;
	this->defaultUnderline = false;
	this->defaultBlink = false;
	this->defaultCrossed_Out = false;
	this->automaticReset = true;
}

colorOut::colorOut(RGB defaultTextColor, RGB defaultBackgroundColor)//�������죨ֻ��������ɫ�ͱ���ɫ����Ĭ��
{
	this->defaultTextColor = defaultTextColor;
	this->defaultBackgroundColor = defaultBackgroundColor;
	this->defaultItalic = false;
	this->defaultUnderline = false;
	this->defaultBlink = false;
	this->defaultCrossed_Out = false;
	this->automaticReset = true;
}

colorOut::colorOut(RGB defaultTextColor, RGB defaultBackgroundColor, bool defaultItalic, bool defaultUnderline, bool defaultBlink, bool defaultCrossed_Out, bool automaticReset)//��ȫ���죨Ϊ����Ĭ�����Ը�ֵ
{
	this->defaultTextColor = defaultTextColor;
	this->defaultBackgroundColor = defaultBackgroundColor;
	this->defaultItalic = defaultItalic;
	this->defaultUnderline = defaultUnderline;
	this->defaultBlink = defaultBlink;
	this->defaultCrossed_Out = defaultCrossed_Out;
	this->automaticReset = automaticReset;
}

void colorOut::out(string text)//���������ȫ��Ĭ��
{
	out(text, defaultTextColor, defaultBackgroundColor);
}

void colorOut::out(string text, RGB textColor)//�����ı�ɫ
{
	out(text, textColor, defaultBackgroundColor);
}

void colorOut::out(string text, RGB textColor, RGB backgroundColor)//�����ı�ɫ�ͱ���ɫ
{
	out(text, textColor, defaultBackgroundColor, defaultItalic, defaultUnderline, defaultBlink, defaultCrossed_Out);
}

void colorOut::out(string text, RGB textColor, RGB backgroundColor, bool Italic, bool Underline, bool Blink, bool Crossed_Out)//�������в���
{
	//�������ַ�������ʵ��������Ϸ���������


	string outBuffer = "";//�������

	outBuffer += "\033[38;2;";//�����ı�ɫ
	outBuffer += to_string(textColor.red);
	outBuffer += ";";
	outBuffer += to_string(textColor.green);
	outBuffer += ";";
	outBuffer += to_string(textColor.blue);
	outBuffer += ";48;2;";//���ñ���ɫ
	outBuffer += to_string(backgroundColor.red);
	outBuffer += ";";
	outBuffer += to_string(backgroundColor.green);
	outBuffer += ";";
	outBuffer += to_string(backgroundColor.blue);
	outBuffer += (Italic ? ";3" : "");	//б��
	outBuffer += (Underline ? ";4" : "");	//�»���
	outBuffer += (Blink ? ";5" : "");	//��˸
	outBuffer += (Crossed_Out ? ";9" : "");	//ɾ�����
	outBuffer += "m"; //��β
	outBuffer += text;	//Ҫ������ı�����
	outBuffer += (automaticReset ? "\033[0m" : "");	//�ָ�Ĭ�������ʽ

	cout << outBuffer;

	//cout << "\033[38;2;" << textColor.red << ";" << textColor.green << ";" << textColor.blue	//�����ı�ɫ
	//	<< ";48;2;" << backgroundColor.red << ";" << backgroundColor.green << ";" << backgroundColor.blue	//���ñ���ɫ
	//	<< (Italic ? ";3" : "")	//б��
	//	<< (Underline ? ";4" : "")	//�»���
	//	<< (Blink ? ";5" : "")	//��˸
	//	<< (Crossed_Out ? ";9" : "")	//ɾ�����
	//	<< "m" //��β
	//	<< text	//Ҫ������ı�����
	//	<< (automaticReset ? "\033[0m" : "")	//�ָ�Ĭ�������ʽ
	//	<< endl;
}

void colorOut::swapTextColorAndBackgroundColor()
{
	RGB oldTextcolor = defaultTextColor;
	defaultTextColor = defaultBackgroundColor;
	defaultBackgroundColor = oldTextcolor;
}

colorOut colorOut::operator<<(string text)
{	
	out(text, defaultTextColor, defaultBackgroundColor);
	return *this;
}
