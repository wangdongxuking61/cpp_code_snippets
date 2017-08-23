#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <cmath>
using namespace std;

// 替换
#define umap unordered_map
#define uset unordered_set
#define p_queue priority_queue
typedef long long llong;
typedef unsigned int uint;

// 打印
#define ss(var)                     #var" = %2d   "
#define PRINT_1VAR(v0)              printf(ss(v0)"\n",v0)
#define PRINT_2VAR(v0, v1)          printf(ss(v0)"\t" ss(v1)"\n",v0,v1)
#define PRINT_3VAR(v0, v1, v2)      printf(ss(v0)"\t" ss(v1)"\t" ss(v2)"\n",v0,v1,v2)
#define PRINT_4VAR(v0, v1, v2, v3)  printf(ss(v0)"\t" ss(v1)"\t" ss(v2)"\t" ss(v3)"\n",v0,v1,v2,v3)
#define PRINT_VECTOR(v0)            print_vector(#v0, v0)
#define PRINT_ARRAY(v0, n)          print_array(#v0, v0, n)
template<class T>
void print_vector(const string &name, vector<T> &vec)
{
    cout << name << ": ";
    for (int i = 0; i < vec.size(); ++i)
        cout << i << "(" << vec[i] << ")\t";
    cout << endl;
}
template<class T>
void print_array(const string &name, T arr[], int n)
{
    cout << name << ": ";
    for (int i = 0; i < n; ++i)
        cout << i << "(" << arr[i] << ")\t";
    cout << endl;
}

// 比大小与heap
template<class T>
struct cmp_less
{
    bool operator()(T &a, T &b)
    { return a < b; }
};
template<class T>
struct cmp_more
{
    bool operator()(T &a, T &b)
    { return a > b; }
};
//p_queue<int, vector<int>, cmp_less<int> > max_heap;//top()是最大
//p_queue<int, vector<int>, cmp_more<int> > min_heap;//top()是最小

// new出来的变量 debug: (int(*)[10])a
// new出来的变量访问时，下标一定不要越界!!!
// new出来的一定要delete!!!
// 整形容易正负溢出!!!
// cin和cout速度不如scanf和printf
///////////////////////////////////////////////////////////////////////////////////////


int main()
{
    //freopen("/Users/xuxu/Desktop/input.in", "r", stdin);
    //freopen("/Users/xuxu/Desktop/output.out", "w", stdout);
    int n;
    scanf("%d", &n);
    printf("%d\n", n)
    return 0;
}
