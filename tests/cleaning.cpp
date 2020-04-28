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
#define max 9999999
#define mrow 12
#define mcol 12
#define mnos 21
//mostra as celulas limpas sujas etc;
char tabela[21][21];
int distancias[21][21][mnos];
int dp[mnos][2060];
int usados[21][21];
int limit, len, row, col;
vector<pair<int, int>> sujos;

bool safe(int x, int y)
{
    if (x < col && y < row && x >= 0 && y >= 0 && tabela[x][y] != 'x')
    {
        return true;
    }
    else
        return false;
}
int posx[4] = {1, -1, 0, 0};
int posy[4] = {0, 0, 1, -1};
void init()
{

    for (int i = 0; i < len + 1; i++)
    {
        for (int j = 0; j < limit; j++)
        {
            dp[i][j] = -1;
        }
    }
}
void bfs(pair<int, int> c, int no)
{
    queue<pair<int, int>> fila;

    distancias[c.first][c.second][no] = 0;
    fila.emplace(c);

    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            usados[i][j] = 0;
        }
    }

    while (!fila.empty())
    {

        int x = fila.front().first;
        int y = fila.front().second;
        fila.pop();

        for (int i = 0; i < 4; i++)
        {

            if (!usados[x + posx[i]][y + posy[i]] && safe(x + posx[i], y + posy[i]))
            {

                fila.push(make_pair(x + posx[i], y + posy[i]));
                usados[x + posx[i]][y + posy[i]] = 1;
                if (distancias[x + posx[i]][y + posy[i]][no] > distancias[x][y][no] + 1)
                {
                    distancias[x + posx[i]][y + posy[i]][no] = distancias[x][y][no] + 1;
                }
            }
        }
    }
}
int solve(int idx, int mask)
{
    if (mask == limit)
    {
        return 0;
    }

    if (dp[idx][mask] != -1)
    {

        return dp[idx][mask];
    }

    int ret = max;

    for (int i = 0; i < len; i++)
    {
        if ((mask & (1 << i)) == 0)
        {
            int newMask = mask | (1 << i);

            ret = min(ret, solve(i, newMask) + distancias[sujos[i].first][sujos[i].second][idx]);
        }
    }

    return dp[idx][mask] = ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true)
    {

        cin >> row >> col;
        sujos.clear();
        if (row == 0 || col == 0)
        {
            break;
        }
        pair<int, int> c;
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
        for (int k = 0; k < len; k++)
        {
            for (int i = 0; i < col; i++)
            {
                for (int j = 0; j < row; j++)
                {
                    distancias[i][j][k] = max;
                }
            }
        }

        for (int i = 0; i < sujos.size(); i++)
        {
            bfs(sujos[i], i);
        }

        int ans = solve(0, 1);

        if (ans != max)
            cout << ans << endl;
        else
        {
            cout << -1 << endl;
        }
    }
}