#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <functional>
#include <ctime>

using namespace std;

int main()
{
	int len = 1000000;
	vector<int> vec(len);
	for (int i = 0; i < len; i++)
	{
		vec[i] = i;
	}
	random_shuffle(vec.begin(), vec.end());

	//priority_queue
	priority_queue<int, vector<int>, greater<int> > pq;
	time_t start;

	start = clock();
	for (int i = 0; i < len; i++)	pq.push(vec[i]);
	cout << "priority_queue push: " << clock() - start << "ms\n";

	start = clock();
	for (int i = 0; i < len; i++)	pq.pop();
	cout << "priority_queue pop: " << clock() - start << "ms\n";

	// set
	set<int> s;
	start = clock();
	for (int i = 0; i < len; i++)	s.insert(vec[i]);
	cout << "set insert: " << clock() - start << "ms\n";

	start = clock();
	for (int i = 0; i < len; i++)	s.erase(s.begin());
	cout << "set pop: " << clock() - start << "ms\n";

	return 0;
}

// environment: win7 64bit, 16G RAM, VS2017
//
// reslut:
// priority_queue push: 36ms
// priority_queue pop: 183ms
// set insert: 737ms
// set pop: 153ms
