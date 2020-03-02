#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <set>
#include <vector>
using namespace std;

pair<int, int> cartas[2000] = {};
int soma1 = 0;
int dp[2002][2002] = {};
int teste = 1;
int control = 0;

int knap(int peso[], int valor[], int tamanho, int soma)
{
    int dp[tamanho + 1][soma + 1] = {};
    for (int i = 0; i <= tamanho; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= soma; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= tamanho; i++)
    {
        for (int j = 1; j <= soma; j++)
        {
            if (peso[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], valor[i - 1] + dp[i - 1][j - peso[i - 1]]);
            }
        }
    }
    return dp[tamanho][soma];
}
bool by_final(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}
int main(int argc, const char *argv[])
{
    int cap, n;
    cin >> cap;
    cin >> n;
    int a, b;
    vector<pair<int, int>> sla;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        cin >> b;
        sla.push_back(make_pair(a, b));
    }
    sort(sla.begin(), sla.end(), by_final);
    int peso[n];
    int value[n];
    for (int i = 0; i < n; i++)
    {
        peso[i] = sla[i].first;
        value[i] = sla[i].second;
    }
    int l = knap(peso, value, n, cap);
    cout << l;
}
