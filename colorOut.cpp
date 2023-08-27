#include "colorOut.h"

colorOut::colorOut()//无参构造（所有属性均默认
{
	this->defaultTextColor = RGB(204, 204, 204);//默认颜色来自PowerShell
	this->defaultBackgroundColor = RGB(12, 12, 12);//默认颜色来自PowerShell
	this->defaultItalic = false;
	this->defaultUnderline = false;
	this->defaultBlink = false;
	this->defaultCrossed_Out = false;
	this->automaticReset = true;
}

colorOut::colorOut(RGB defaultTextColor, RGB defaultBackgroundColor)//基本构造（只设置字体色和背景色其他默认
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
	//完全构造（为所有默认属性赋值
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





void colorOut::out(string text)//基本输出（全部默认
{
	out(text, defaultTextColor, defaultBackgroundColor);
}

void colorOut::out(string text, RGB textColor)//设置文本色
{
	out(text, textColor, defaultBackgroundColor);
}

void colorOut::out(string text, RGB textColor, RGB backgroundColor)//设置文本色和背景色
{
	out(text, textColor, defaultBackgroundColor, defaultItalic, defaultUnderline, defaultBlink, defaultCrossed_Out);
}

void colorOut::out(string text, RGB textColor, RGB backgroundColor,
	bool Italic, bool Underline, bool Blink, bool Crossed_Out)//设置所有参数
{
	outBuffer.clear();//清空缓冲区

	outBuffer += setOutStyle(textColor, backgroundColor, Italic, Underline, Blink, Crossed_Out);
	outBuffer += text;	//要输出的文本内容
	outBuffer += (automaticReset ? "\033[0m" : "");	//恢复默认输出样式

	cout << outBuffer;//输出
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

	buffer += "\033[38;2;";//设置文本色
	buffer += to_string(textColor.red);
	buffer += ";";
	buffer += to_string(textColor.green);
	buffer += ";";
	buffer += to_string(textColor.blue);
	buffer += ";48;2;";//设置背景色
	buffer += to_string(backgroundColor.red);
	buffer += ";";
	buffer += to_string(backgroundColor.green);
	buffer += ";";
	buffer += to_string(backgroundColor.blue);
	buffer += (Italic ? ";3" : "");	//斜体
	buffer += (Underline ? ";4" : "");	//下划线
	buffer += (Blink ? ";5" : "");	//闪烁
	buffer += (Crossed_Out ? ";9" : "");	//删除标记
	buffer += "m"; //结尾

	return buffer;
}

void colorOut::reset()
{
	cout << "\033[0m";//恢复默认样式
	this->defaultTextColor = RGB(204, 204, 204);//默认颜色来自PowerShell
	this->defaultBackgroundColor = RGB(12, 12, 12);//默认颜色来自PowerShell
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
