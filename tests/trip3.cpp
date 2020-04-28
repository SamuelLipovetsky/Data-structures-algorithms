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
    for (char i = 'a'; char <= 'z'; i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] == i)
            {
                for (int k = 0; k < b.size(); k++)
                {
                    if (a[k] == i)
                    {
                        if ()
                    }
                }
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