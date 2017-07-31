#include <limits>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//testDijkstraGraph(0, 19);
	//testYenAlg(0, 17, 3);
	//testYenAlg(17, 19, 3);

	std::vector<int> vecNum(100000000);
	for (size_t i = 0; i < vecNum.size(); i++)
	{
		vecNum[i] = rand();
	}
	int sum = 0;
	time_t start;

	// 第一种用法：最原始的语法(用下标)
	start = clock();
	for (size_t i = 0; i < vecNum.size(); ++i)
			sum += vecNum[i];
	cout << clock() - start << "ms\n";

	// 第二种用法：最原始的语法(用迭代器)
	start = clock();
	for (auto it = vecNum.begin(); it != vecNum.end(); ++it)
		sum += *it;
	cout << clock() - start << "ms\n";

	// 第三种用法：简化数组遍历语法(从vs2008开始支持)
	start = clock();
	for each(auto item in vecNum)
		sum += item;
	cout << clock() - start << "ms\n";

	// 第四种用法：STL函数
	start = clock();
	std::for_each(vecNum.begin(), vecNum.end(), [&](const int &item) {
		sum += item;
	});
	cout << clock() - start << "ms\n";

	// 第五种用法：C++11新增加的(VS2012支持)
	start = clock();
	for (auto item : vecNum)
		sum += item;
	cout << clock() - start << "ms\n";
	
	cout << sum << endl;
	getchar();

	return 0;
}

// environment: win7 64bit, 16G RAM, VS2017

// reslut:
// 74ms
// 73ms
// 73ms
// 72ms
// 72ms

// reference:
// https://www.zhihu.com/question/28127777
// http://blog.csdn.net/zzq060143/article/details/54409730
