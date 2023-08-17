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

colorOut::colorOut(RGB defaultTextColor, RGB defaultBackgroundColor, bool defaultItalic, bool defaultUnderline, bool defaultBlink, bool defaultCrossed_Out, bool automaticReset)//完全构造（为所有默认属性赋值
{
	this->defaultTextColor = defaultTextColor;
	this->defaultBackgroundColor = defaultBackgroundColor;
	this->defaultItalic = defaultItalic;
	this->defaultUnderline = defaultUnderline;
	this->defaultBlink = defaultBlink;
	this->defaultCrossed_Out = defaultCrossed_Out;
	this->automaticReset = automaticReset;
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

void colorOut::out(string text, RGB textColor, RGB backgroundColor, bool Italic, bool Underline, bool Blink, bool Crossed_Out)//设置所有参数
{
	//以下两种方法均可实现输出，上方方法更快


	string outBuffer = "";//输出缓冲

	outBuffer += "\033[38;2;";//设置文本色
	outBuffer += to_string(textColor.red);
	outBuffer += ";";
	outBuffer += to_string(textColor.green);
	outBuffer += ";";
	outBuffer += to_string(textColor.blue);
	outBuffer += ";48;2;";//设置背景色
	outBuffer += to_string(backgroundColor.red);
	outBuffer += ";";
	outBuffer += to_string(backgroundColor.green);
	outBuffer += ";";
	outBuffer += to_string(backgroundColor.blue);
	outBuffer += (Italic ? ";3" : "");	//斜体
	outBuffer += (Underline ? ";4" : "");	//下划线
	outBuffer += (Blink ? ";5" : "");	//闪烁
	outBuffer += (Crossed_Out ? ";9" : "");	//删除标记
	outBuffer += "m"; //结尾
	outBuffer += text;	//要输出的文本内容
	outBuffer += (automaticReset ? "\033[0m" : "");	//恢复默认输出样式

	cout << outBuffer << endl;

	//cout << "\033[38;2;" << textColor.red << ";" << textColor.green << ";" << textColor.blue	//设置文本色
	//	<< ";48;2;" << backgroundColor.red << ";" << backgroundColor.green << ";" << backgroundColor.blue	//设置背景色
	//	<< (Italic ? ";3" : "")	//斜体
	//	<< (Underline ? ";4" : "")	//下划线
	//	<< (Blink ? ";5" : "")	//闪烁
	//	<< (Crossed_Out ? ";9" : "")	//删除标记
	//	<< "m" //结尾
	//	<< text	//要输出的文本内容
	//	<< (automaticReset ? "\033[0m" : "")	//恢复默认输出样式
	//	<< endl;
}
