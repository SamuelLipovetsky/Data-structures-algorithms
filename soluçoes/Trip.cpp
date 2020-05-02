#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
using namespace std;
int lcs[82][82];
string a;
string b;
int size_a;
int size_b;
//set first line and first collum to 0
void setZero()
{
    for (int i = 0; i <= size_a; i++)
    {
        lcs[0][i] = 0;
    }
    for (int i = 0; i <= size_b; i++)
    {
        lcs[i][0] = 0;
    }
}
// make the lcs table for a b;
void make_lcs()
{
    int size_a = a.size();
    int size_b = b.size();
    setZero();
    for (int i = 1; i <= size_a; i++)
    {
        for (int j = 1; j <= size_b; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else
            {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }
}
//x and y are pointer to the index of strings  a and b
void print(string sufix, int x, int y)
{
    if (sufix.size() == lcs[size_a][size_b])
    {
        cout << sufix << endl;
        return;
    }
    else
    {
        for (char i = 'a'; i <= 'z'; i++)
        {
            int flag = 0;

            for (int j = x; j < size_a; j++)
            {

                if (i == a[j])
                {
                    for (int k = y; k < size_b; k++)
                    {
                        if (a[j] == b[k])
                        {

                            if (sufix.size() + 1 == lcs[j + 1][k + 1])
                            {
                                print(sufix + a[j], j + 1, k + 1);
                                flag = 1;
                                break;
                            }
                        }
                    }
                }
                if (flag)
                {
                    break;
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        cin >> b;
        size_a = a.size();
        size_b = b.size();
        make_lcs();
        print("", 0, 0);
        cout << endl;
    }
}