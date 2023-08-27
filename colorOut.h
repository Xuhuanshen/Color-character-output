#pragma once
#include <iostream>
#include <string>
#include "RGB.h"

using namespace std;

class colorOut
{

private:
	//功能属性
	RGB defaultTextColor;//文本颜色
	RGB defaultBackgroundColor;//背景颜色
	bool defaultItalic;//斜体
	bool defaultUnderline;//下划线
	bool defaultBlink;//闪烁
	bool defaultCrossed_Out;//删除标记（中间划线
	bool automaticReset;//自动复位（输出后自动恢复默认设置
	//属性
	string outBuffer;//输出缓冲


public:
	//构造
	colorOut();
	colorOut(RGB defaultTextColor, RGB defaultBackgroundColor);
	colorOut(RGB defaultTextColor, RGB defaultBackgroundColor,
		bool defaultItalic, bool defaultUnderline, bool defaultBlink, bool defaultCrossed_Out, bool automaticReset);
	colorOut(const colorOut& oldColorOut);


	//获取与修改属性
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


	//输出
	void out(string text);
	void out(string text, RGB textColor);
	void out(string text, RGB textColor, RGB backgroundColor);
	void out(string text, RGB textColor, RGB backgroundColor, 
		bool Italic, bool Underline, bool Blink, bool Crossed_Out);


	//功能
	void swapTextColorAndBackgroundColor();//交换文本色和背景色
	string setOutStyle(RGB textColor, RGB backgroundColor, 
		bool Italic, bool Underline, bool Blink, bool Crossed_Out);//设置输出样式（只设置不输出,不自动复位,返回样式的字符串形式
	void reset();//关闭所有输出样式（所有属性恢复默认



	//重载
	colorOut operator<<(string text);//返回自身，方便链式输出
	void operator=(const colorOut& oldColorOut);
};

