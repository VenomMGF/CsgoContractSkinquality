// CSGOcontract.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


std::vector <double> skinData;
double max, min;
double sum = 0;

void readTxt()
{
	std::ifstream ifs;
	ifs.open("皮肤磨损.txt", std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "打开文件失败" << std::endl;
		return;
	}
	
	double d;
	while (ifs >> d)
		skinData.push_back(d);//将数据压入堆栈。//
	std::vector <double>:: iterator it;

	for (it = skinData.begin(); it != skinData.end(); it++)

	{
		std::cout << *it << std::endl;
		sum += *it;
	}
	std::sort(skinData.begin(), skinData.end());
	min = skinData[0];
	max = skinData[9];
	
	

	//第一种方式打开
	/*char buf[10] = { 0 };
	while (ifs >> buf)
	{
	std::cout << buf << std::endl;
	}*/

	/*
	//第二种
	string buf;
	while (getline(ifs, buf))
	{
	cout << buf << endl;
	}
	*/
	//第三种 
	//char c;
	//while ((c = ifs.get()) != EOF)
	//{
	//	std::cout << c;
	//}
	ifs.close();
}

int main()
{
	
	double val,x, aver;
	double tempMin = 0;
	double tempMax = 0;
	readTxt();
	/*std::cout << "请依次输入10把武器的磨损值" << std::endl;
	std::cin >> val;
	tempMin = val;
	tempMin = val;
	for (int i = 1; i < 10; i++)
	{
		std::cin >> val;
		sum += val;
		if (tempMin > val) tempMin = val;
		if (tempMax < val) tempMax = val;
	}
	min = tempMin;
	max = tempMax;*/
	aver = sum / 10;
	x = (max - min) * aver + min;
	if (x < 0) std::cout << "武器磨损值出现负数，请检查输入" << std::endl;
	if (x >=0 && x <= 0.0699999) std::cout << "预测武器品质：崭新出厂" << std::endl;
	if (x >= 0.07 && x <= 0.14999) std::cout << "预测武器品质：略有磨损" << std::endl;
	if (x >= 0.15 && x <= 0.37999) std::cout << "预测武器品质：久经沙场" << std::endl;
	if (x >= 0.38 && x <= 0.44999) std::cout << "预测武器品质：破损不堪" << std::endl;
	if (x >= 0.45 && x <= 0.99999) std::cout << "预测武器品质：战痕累累" << std::endl;
	std::cout << "10把武器磨损值之和：" << sum << std::endl;
	std::cout << "10把武器磨损值平均值：" << aver << std::endl;
	std::cout << "10把武器磨损值最大为：" << max << std::endl;
	std::cout << "10把武器磨损值最小为：" << min << std::endl;
	std::cout << "预测武器磨损值：" << x << std::endl;
    return 0;
}

