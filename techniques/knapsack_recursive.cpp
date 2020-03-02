#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <set>
#include <time.h>
using namespace std;

pair<int, int> cartas[2000] = {};
int soma1 = 0;
int dp[2002][2002] = {};
int teste = 1;
int control = 0;

int naive(int restante, int index)
{
    int result;
    if (dp[restante][index] != -1)
        return dp[restante][index];
    if (restante == 0 || index == 0)
    {
        result = 0;
    }
    else if (cartas[index].first > restante)
    {
        result = naive(restante, index - 1);
    }
    else
    {
        int temp1 = naive(restante, index - 1);
        int temp2 = cartas[index].second + naive(restante - cartas[index].first, index - 1);
        result = max(temp2, temp1);
    }

    dp[restante][index] = result;
    return result;
}
int main(int argc, const char *argv[])

{

    int tamanho, q_cartas, max, atual;
    cin >> tamanho;
    cin >> q_cartas;

    cartas[0].first = -1;
    cartas[0].second = -1;
    for (int i = 1; i <= q_cartas; i++)
    {
        cin >> cartas[i].first;
        cin >> cartas[i].second;
    }
    for (int i = 0; i <= tamanho; i++)
    {
        for (int j = 0; j <= q_cartas; j++)
        {
            dp[i][j] = -1;
        }
    }
    int q = naive(tamanho, q_cartas);

    cout << q;
}
