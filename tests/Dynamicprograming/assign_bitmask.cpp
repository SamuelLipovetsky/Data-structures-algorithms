#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;
int adjmat[21][21];
int sze;
long long memo[1 << 20];

int main()
{
    memset(adjmat, 0, sizeof(adjmat));
    ios_base::sync_with_stdio(false);
    int nT;
    cin >> nT;
    while (nT-- && cin >> sze)
    {
        memset(adjmat, 0, sizeof(adjmat));
        memset(memo, 0, sizeof(memo));
        for (int i = 0; i < sze; i++)
        {
            for (int j = 0; j < sze; j++)
            {
                int val;
                cin >> val;
                adjmat[i][j] = val;
            }
        }
        memo[(1 << sze) - 1] = 1;
        for (int j = (1 << sze) - 1; j >= 0; j--)
        {
            int idx = __builtin_popcount(j);
            for (int k = 0; k < sze; k++)
            {
                if (adjmat[idx][k] == 0 || (j & (1 << k)))
                    continue;
                memo[j] += memo[j + (1 << k)];
              
              
            }
        }

        cout << memo[0] << "\n";
    }
    return 0;
}
