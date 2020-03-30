#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
string a;
string b;
int l = 0;
int lcs[81][81];

void set_zero()
{

    for (int i = 0; i <= a.size(); i++)
    {
        for (int j = 0; j <= b.size(); j++)
        {
            lcs[i][j] = 0;
        }
    }
}

void Common()
{
    set_zero();

    for (int i = 0; i <= a.size(); i++)
    {
        for (int j = 0; j <= b.size(); j++)
        {
            if (j > 0 && i > 0)
            {
                if (a[i - 1] == b[j - 1])
                {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                }
                else
                {
                    lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
                }
            }
        }
    }
    l = lcs[a.size()][b.size()];
}
set<vector<char>> all_lcs;
void printall(int x, int y, vector<char> t)
{

    if (t.size() == l)
    {
        reverse(t.begin(), t.end());
        all_lcs.insert(t);
    }
    else if (x >= 0 && y >= 0)
    {
        if (a[x] == b[y])
        {
            t.push_back(a[x]);
            printall(x - 1, y - 1, t);
        }
        else
        {

            if (lcs[x][y + 1] >= lcs[x + 1][y])
            {
                printall(x - 1, y, t);
            }
            if (lcs[x + 1][y] >= lcs[x][y + 1])
            {
                printall(x, y - 1, t);
            }
        }
    }
}
int main()
{
    int m;
    cin >> m;
    cin.ignore();
    for (int i = 0; i < m; i++)
    {
        string aa, bb;
        getline(cin, a);
        getline(cin, b);
        Common();
        vector<char> t;
        printall(a.size() - 1, b.size() - 1, t);
        for (auto i : all_lcs)
        {
            for (auto x : i)
            {
                cout << x;
            }
            cout << endl;
        }
    }
}