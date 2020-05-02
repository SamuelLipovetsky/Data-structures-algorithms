#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <complex>
#include <iostream>
#include <valarray>
#include <cstring>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <sstream>
#include <ctime>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cmath>

using namespace std;

#define PB push_back
#define i64 long long
#define FOR(i, a, b) for (i = (a); i < (b); ++i)
#define FORE(i, a, b) for (i = (a); i <= (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define REPE(i, n) FORE(i, 0, n)
#define SZ(v) ((v).size())
#define LD long double
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VLD vector<LD>
#define MSET(x, y) memset((x), (y), sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI vector<VI>
#define PII pair<int, int>
#define VPII vector<PII>
#define MP make_pair
#define PIPII pair<int, PII>
#define PIPIPII pair<int, PIPII>
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>

#define MAXN 1001
#define MAXM 10002
#define INF 0x7f7f7f7f

int n, m, src, dest, k;

int arr[MAXN][MAXN];
int bst[MAXN][MAXN];
int ben[MAXN][MAXN];

int g;
int garr[MAXN];
int ans;
int distt[MAXN];

void solve()
{
    MSET(distt, 0x7f);
    priority_queue<PII> pq;

    pq.push(MP(-k, src));
    int x, d;
    int ti;

    while (!pq.empty())
    {

        x = pq.top().second;
        d = -pq.top().first;
        pq.pop();

        //printf("%d\t%d\n",x,d);

        if (distt[x] <= d)
        {
            continue;
        }

        distt[x] = d;
        if (x == dest)
        {
            ans = d;
            return;
        }

        for (int i = 1; i <= n; ++i)
        {
            if (arr[x][i] == -1)
            {
                continue;
            }

            ti = 0;

            if (bst[x][i] != -1 && bst[i][x] != -1)
            {
                if (bst[x][i] < bst[i][x])
                {
                    if (ben[x][i] == bst[i][x])
                    {
                        if (!(d < bst[x][i] || d >= ben[i][x]))
                        {
                            ti += ben[i][x] - d;
                        }
                    }
                    else
                    {
                        if (!(d < bst[x][i] || d >= ben[x][i] || (d >= ben[x][i] && d < bst[i][x])))
                        {
                            if (d < ben[x][i])
                            {
                                ti += ben[x][i] - d;
                            }
                            else
                            {
                                ti += ben[i][x] - d;
                            }
                        }
                    }
                }
                else
                {
                    if (ben[i][x] == bst[x][i])
                    {
                        if (!(d < bst[i][x] || d >= ben[x][i]))
                        {
                            ti += ben[x][i] - d;
                        }
                    }
                    else
                    {
                        if (!(d < bst[i][x] || d >= ben[i][x] || (d >= ben[i][x] && d < bst[x][i])))
                        {
                            if (d < ben[i][x])
                            {
                                ti += ben[i][x] - d;
                            }
                            else
                            {
                                ti += ben[x][i] - d;
                            }
                        }
                    }
                }
            }
            else if (bst[x][i] != -1)
            {
                if (!(d < bst[x][i] || d >= ben[x][i]))
                {
                    ti += ben[x][i] - d;
                }
            }
            else if (bst[i][x] != -1)
            {
                if (!(d < bst[i][x] || d >= ben[i][x]))
                {
                    ti += ben[i][x] - d;
                }
            }

            ti += arr[x][i];
            ti += d;

            pq.push(MP(-ti, i));
        }
    }
}

int main()
{
    // freopen("Text/GEORGE.txt", "r", stdin);

    int x, y, z;
    ans = INF;
    MSET(bst, -1);
    MSET(ben, -1);
    MSET(arr, -1);

    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &src, &dest, &k, &g);

    for (int i = 0; i < g; ++i)
    {
        scanf("%d", garr + i);
    }

    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d %d", &x, &y, &z);
        arr[x][y] = z;
        arr[y][x] = z;
    }

    int ti = 0;
    for (int i = 0; i < g - 1; ++i)
    {
        bst[garr[i]][garr[i + 1]] = ti;
        ti += arr[garr[i]][garr[i + 1]];
        ben[garr[i]][garr[i + 1]] = ti;
    }

    solve();

    ans -= k;
    printf("%d\n", ans);

    return 0;
}