#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
void add(int &a, int b)
{
    a += b;
    if (a >= 100000000)
        a -= 100000000;
}
pair<int, int> pares[100030];
int dp[100030];
int main(int argc, const char *argv[])
{
    int n;
    cin >> n;
    while (n != -1)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> pares[i].first;
            cin >> pares[i].second;
        }
        sort(pares, pares + n, cmp);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1];
            int index = upper_bound(pares, pares + n, make_pair(0, pares[i].first), cmp) - pares - 1;
            add(dp[i], dp[index]);
        }
        add(dp[n], 100000000 - 1);
        cout << setfill('0') << setw(8) << dp[n] - 1 << endl;

        cin >> n;
    }
}
