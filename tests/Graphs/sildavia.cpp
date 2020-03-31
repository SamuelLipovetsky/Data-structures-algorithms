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

typedef vector<vector<double>> graph;

double dist(double x1, double y1, double x2, double y2)
{
    double a = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));

    return a;
}
vector<double> all;

int c = 0;
// é necessario remover os gravos para o bfs ser mais rapido;
void bfs(graph g, int inicio, int fim)
{
    graph n = g;
    c++;
    cout.precision(4);
    cout << fixed;
    double limite = all[inicio + ceil((fim - inicio) / 2)];
    int point = ceil((fim - inicio) / 2);
    if (point == 1)
    {
        cout << limite << endl;
    }
    else
    {
        vector<int> usados;
        queue<int> fila;
        usados.clear();
        usados.resize(g.size(), 0);
        fila.emplace(0);
        int count = 0;

        while (fila.size() > 0)
        {
            int atual = fila.front();
            if (usados[atual] == 0)
                count++;
            usados[atual] = 1;

            for (int j = 0; j < g[atual].size(); j++)
            {
                if (g[atual][j] < limite)
                {
                    if (usados[j] == 0)
                    {

                        fila.emplace(j);
                    }
                }
                else
                {
                    g[atual].erase(g[atual].begin() + j);
                }
            }
            fila.pop();
        }

        if (count == g.size())
        {
            bfs(g, inicio, fim - point);
        }
        else
        {
            bfs(n, inicio + point, fim);
        }
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    double x, y;

    while (true)
    {

        cin >> n;
        if (n == 0)
            break;
        else
        {
            graph g;
            all.clear();
            g.clear();
            g.resize(n);
            for (int i = 0; i < n; i++)
            {
                g[i].resize(n);
            }
            double cord[n][2];

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
                        double temp = dist(cord[i][0], cord[i][1], cord[j][0], cord[j][1]);
                        g[i][j] = temp;
                        g[j][i] = temp;
                        all.push_back(temp);
                        all.push_back(temp);
                    }
                }
            }
            sort(all.begin(), all.end());
            if (n == 1)
                cout << g[0][0] << endl;
            else if (n == 2)
                cout << g[1][0] << endl;
            else
                bfs(g, 0, all.size() - 1);
            cout << c << endl;
        }
    }
}