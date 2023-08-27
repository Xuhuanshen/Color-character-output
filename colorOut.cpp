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

colorOut::colorOut(RGB defaultTextColor, RGB defaultBackgroundColor, 
	bool defaultItalic, bool defaultUnderline, bool defaultBlink, bool defaultCrossed_Out, bool automaticReset)
	//��ȫ���죨Ϊ����Ĭ�����Ը�ֵ
{
	this->defaultTextColor = defaultTextColor;
	this->defaultBackgroundColor = defaultBackgroundColor;
	this->defaultItalic = defaultItalic;
	this->defaultUnderline = defaultUnderline;
	this->defaultBlink = defaultBlink;
	this->defaultCrossed_Out = defaultCrossed_Out;
	this->automaticReset = automaticReset;
}

colorOut::colorOut(const colorOut& oldColorOut)
{
	this->defaultTextColor = oldColorOut.defaultTextColor;
	this->defaultBackgroundColor = oldColorOut.defaultBackgroundColor;
	this->defaultItalic = oldColorOut.defaultItalic;
	this->defaultUnderline = oldColorOut.defaultUnderline;
	this->defaultBlink = oldColorOut.defaultBlink;
	this->defaultCrossed_Out = oldColorOut.defaultCrossed_Out;
	this->automaticReset = oldColorOut.automaticReset;
}






RGB colorOut::getDefaultTextColor()
{
	return this->defaultTextColor;
}

void colorOut::setDefaultTextColor(RGB newColor)
{
	this->defaultTextColor = newColor;
	return;
}

RGB colorOut::getDefaultBackgroundColor()
{
	return this->defaultBackgroundColor;
}

void colorOut::setDefaultBackgroundColor(RGB newColor)
{
	this->defaultBackgroundColor = newColor;
	return;
}

bool colorOut::getDefaultItalic()
{
	return this->defaultItalic;
}

void colorOut::setDefaultItalic(bool newSet)
{
	this->defaultItalic = newSet;
	return;
}

bool colorOut::getDefaultUnderline()
{
	return this->defaultUnderline;
}

void colorOut::setDefaultUnderline(bool newSet)
{
	this->defaultUnderline = newSet;
}

bool colorOut::getDefaultBlink()
{
	return this->defaultBlink;
}

void colorOut::setDefaultBlink(bool newSet)
{
	this->defaultBlink = newSet;
}

bool colorOut::getDefaultCrossed_Out()
{
	return this->defaultCrossed_Out;
}

void colorOut::setDefaultCrossed_Out(bool newSet)
{
	this->defaultCrossed_Out = newSet;
}

bool colorOut::getAutomaticReset()
{
	return this->automaticReset;
}

void colorOut::setAutomaticReset(bool newSet)
{
	this->automaticReset = newSet;
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

void colorOut::out(string text, RGB textColor, RGB backgroundColor,
	bool Italic, bool Underline, bool Blink, bool Crossed_Out)//�������в���
{
	outBuffer.clear();//��ջ�����

	outBuffer += setOutStyle(textColor, backgroundColor, Italic, Underline, Blink, Crossed_Out);
	outBuffer += text;	//Ҫ������ı�����
	outBuffer += (automaticReset ? "\033[0m" : "");	//�ָ�Ĭ�������ʽ

	cout << outBuffer;//���
}

void colorOut::swapTextColorAndBackgroundColor()
{
	RGB oldTextColor = defaultTextColor;
	defaultTextColor = defaultBackgroundColor;
	defaultBackgroundColor = oldTextColor;
}

string colorOut::setOutStyle(RGB textColor = RGB(204, 204, 204), RGB backgroundColor = RGB(12, 12, 12),
	bool Italic = false, bool Underline = false, bool Blink = false, bool Crossed_Out = false)
{
	string buffer;

	buffer += "\033[38;2;";//�����ı�ɫ
	buffer += to_string(textColor.red);
	buffer += ";";
	buffer += to_string(textColor.green);
	buffer += ";";
	buffer += to_string(textColor.blue);
	buffer += ";48;2;";//���ñ���ɫ
	buffer += to_string(backgroundColor.red);
	buffer += ";";
	buffer += to_string(backgroundColor.green);
	buffer += ";";
	buffer += to_string(backgroundColor.blue);
	buffer += (Italic ? ";3" : "");	//б��
	buffer += (Underline ? ";4" : "");	//�»���
	buffer += (Blink ? ";5" : "");	//��˸
	buffer += (Crossed_Out ? ";9" : "");	//ɾ�����
	buffer += "m"; //��β

	return buffer;
}

void colorOut::reset()
{
	cout << "\033[0m";//�ָ�Ĭ����ʽ
	this->defaultTextColor = RGB(204, 204, 204);//Ĭ����ɫ����PowerShell
	this->defaultBackgroundColor = RGB(12, 12, 12);//Ĭ����ɫ����PowerShell
	this->defaultItalic = false;
	this->defaultUnderline = false;
	this->defaultBlink = false;
	this->defaultCrossed_Out = false;
	this->automaticReset = true;
}

colorOut colorOut::operator<<(string text)
{
	out(text, defaultTextColor, defaultBackgroundColor);
	return *this;
}

void colorOut::operator=(const colorOut& oldColorOut)
{
	this->defaultTextColor = oldColorOut.defaultTextColor;
	this->defaultBackgroundColor = oldColorOut.defaultBackgroundColor;
	this->defaultItalic = oldColorOut.defaultItalic;
	this->defaultUnderline = oldColorOut.defaultUnderline;
	this->defaultBlink = oldColorOut.defaultBlink;
	this->defaultCrossed_Out = oldColorOut.defaultCrossed_Out;
	this->automaticReset = oldColorOut.automaticReset;
}
