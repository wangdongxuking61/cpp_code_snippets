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

typedef long long llong;
using namespace std;

// 说明
// 使用算法：动态规划
// 时间复杂度：O(m*k*n),其中内部两个循环优化了一点点
// 空间复杂度：O(k*n)
// 2017.8.14 fix bug: 打印错误，应该打印和，不应打印最大值

int main()
{
    // 读入数据
    int n, k, m;
    cin >> n >> k >> m;
    if (k > m) return 1;

    vector<int> price(m);
    for (int i = 0; i < m; ++i)
        cin >> price[i];

    // dp[][]：代表状态的二维数组
    // dp[i][j]代表：k个数的和恰好为j，这样的k个数的组合数量
    llong **dp = new llong *[k + 1];
    for (int i = 0; i <= k; i++)
    {
        dp[i] = new llong[n + 1];
        memset(dp[i], 0, sizeof(llong) * (n + 1));
    }

    // 每次增加一个菜品
    int price_sum = 0;
    for (int loop = 0; loop < m; ++loop)
    {
        int p = price[loop];
        if (p > n) continue;

        for (int i = min(loop, k - 1); i > 0; --i)
            for (int j = min(price_sum, n - p); j >= 0; --j)
                dp[i + 1][j + p] += dp[i][j];

        ++dp[1][p];
        price_sum += p;
    }

    // ****************** fis bug ******************
    int ans = 0;
    for (int i = 0; i <= n; ++i)
        ans += dp[k][i];
    cout << ans << endl;
    // ****************** fis bug ******************

    for (int i = 0; i <= k; i++)
        delete[] dp[i];
    delete[] dp;
    return 0;
}
