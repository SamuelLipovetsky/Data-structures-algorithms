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
using namespace std;
#define max 9999999

typedef vector<vector<double>> graph;
struct gre
{
    template <class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};
double dist(double x1, double y1, double x2, double y2)
{
    double a = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));

    return a;
}
void bfs(graph g, vector<double> all)
{
    cout.precision(4);
    cout << fixed;
    double limite;
    for (int i = 0; i < all.size(); i++)
    {
        vector<int> usados;
        queue<int> fila;
        usados.resize(g.size(), 0);
        fila.emplace(0);
        int count = 0;

        while (fila.size() > 0)
        {
            int atual = fila.front();
            if (usados[atual] == 0)
                count++;
            usados[atual] = 1;

            for (int j = 0; j < g.size(); j++)
            {
                if (g[atual][j] <= all[i])
                {
                    if (usados[j] == 0)
                    {

                        fila.emplace(j);
                    }
                }
            }
            fila.pop();
        }

        if (count == g.size())
            limite = all[i];
    }
    cout << limite << endl;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    double x, y;
    set<double> u;
    vector<double> all;
    while (true)
    {

        cin >> n;
        if (n == 0)
            break;

        else
        {
            graph g;
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
                        if (u.count(temp) == 0)
                        {
                            u.insert(temp);
                            all.push_back(temp);
                        }
                    }
                }
            }
            sort(all.begin(), all.end(), gre());

            bfs(g, all);
        }
    }
}