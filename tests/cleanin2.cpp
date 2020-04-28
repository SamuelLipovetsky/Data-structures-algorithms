#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
#define infinito 9999999
char tabela[21][21];
int usados[21][21];
int dp[12][2060];
int dists[21][21][12];
int limit, len, row, col;
vector<pair<int, int>> sujos;
void init()
{

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < limit; j++)
        {
            dp[i][j] = -1;
        }
    }
    for (int k = 0; k < len; k++)
    {
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                dists[i][j][k] = infinito;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true)
    {
        cin >> row >> col;
        if (row == 0 || col == 0)
        {
            break;
        }
        pair<int, int> c;
        sujos.clear();
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                cin >> tabela[i][j];

                if (tabela[i][j] == '*')
                    sujos.push_back(make_pair(i, j));
                else if (tabela[i][j] == 'o')
                {
                    c = make_pair(i, j);
                }
            }
        }
        sujos.insert(sujos.begin(), c);
        len = sujos.size();
        limit = (1 << sujos.size()) - 1;
        init();
    }
}