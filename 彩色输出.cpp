#include <iostream>
#include <string>
#include "RGB.h"
#include "colorOut.h"

#include <chrono>//计时

using namespace std;

using namespace std::chrono;//计时

int main()//仅供测试
{
	auto start = steady_clock::now();//计时

	
	colorOut color(RGB(255, 0, 0), RGB(0, 0, 255), true, true, true, true, true);
	for (int i = 0; i < 255; i++)
	{
		color.defaultTextColor = RGB(255, i, 255 - i);
		color.defaultBackgroundColor = RGB(i, i, 255);
		color.out("0123456789");
	}
	color << "asd" << "sdf" << "dfg";


	auto end = steady_clock::now();//计时
	auto last = duration_cast<microseconds>(end - start);
	cout << last.count() << "um";

}