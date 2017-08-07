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

int main()
{
    int n, k, m;
    cin >> n >> k >> m;
    if (k > m) return 1;

    vector<int> price(m);
    for (int i = 0; i < m; ++i)
        cin >> price[i];


    llong **dp = new llong *[k + 1];
    for (int i = 0; i <= k; i++)
    {
        dp[i] = new llong[n + 1];
        memset(dp[i], 0, sizeof(llong) * (n + 1));
    }
    dp[0][0] = 1;


    for (int p:price)
    {
        if (p > n) continue;
        for (int i = k - 1; i >= 0; --i)
            for (int j = 0; j <= n - p; ++j)
                dp[i + 1][j + p] += dp[i][j];
    }
    cout << *max_element(dp[k], dp[k] + n + 1);


    for (int i = 0; i <= k; i++)
        delete[] dp[i];
    delete[] dp;
    return 0;
}
