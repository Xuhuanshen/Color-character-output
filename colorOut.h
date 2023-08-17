#pragma once
#include <iostream>
#include <string>
#include "RGB.h"

using namespace std;

class colorOut
{
public:
	//属性
	RGB defaultTextColor;//文本颜色
	RGB defaultBackgroundColor;//背景颜色
	bool defaultItalic;//斜体
	bool defaultUnderline;//下划线
	bool defaultBlink;//闪烁
	bool defaultCrossed_Out;//删除标记	（中间划线
	bool automaticReset;//自动复位	（输出后自动恢复默认设置


	//构造
	colorOut();
	colorOut(RGB defaultTextColor, RGB defaultBackgroundColor);
	colorOut(RGB defaultTextColor, RGB defaultBackgroundColor, bool defaultItalic, bool defaultUnderline, bool defaultBlink, bool defaultCrossed_Out, bool automaticReset);


	//输出
	void out(string text);
	void out(string text, RGB textColor);
	void out(string text, RGB textColor, RGB backgroundColor);
	void out(string text, RGB textColor, RGB backgroundColor, bool Italic, bool Underline, bool Blink, bool Crossed_Out);
};

