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
using namespace std;
#define max 9999999

double cord[1000][2];
double g[1000][1000];
set<int> setu;
vector<int> u;
int n;
void prim()
{
    cout.precision(4);
    cout << fixed;
    setu.clear();
    u.clear();
    setu.insert(0);
    u.push_back(0);
    double min = 0;
    int to_add;
    int atual;
    double m = 0;
    while (true)
    {
        min = max;
        to_add = 0;
        int aa;
        if (u.size() == n)
        {
            break;
        }
        for (int i = 0; i < u.size(); i++)
        {
            atual = u[i];
            for (int j = 0; j < n; j++)
            {
                double custo = g[atual][j];
                int prox = j;
                if (custo < min && setu.count(prox) == 0)
                {
                    min = custo;
                    to_add = j;
                    aa = atual;
                }
            }
        }

        u.push_back(to_add);
        setu.insert(to_add);
        if (g[aa][to_add] > m)
        {
            m = g[aa][to_add];
        }
    }

    cout << m << "\n";
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double x, y;
    while (true)
    {

        cin >> n;
        if (n == 0)
            break;
        else
        {

            for (size_t i = 0; i < n; i++)
            {
                cin >> x >> y;
                cord[i][0] = x;
                cord[i][1] = y;
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = i; j < n; j++)
                {
                    if (i != j)
                    {
                        double temp = sqrt(pow((cord[i][0] - cord[j][0]), 2) + pow((cord[i][1] - cord[j][1]), 2));
                        g[i][j] = temp;
                        g[j][i] = temp;
                    }
                }
            }
            prim();
        }
    }
}
