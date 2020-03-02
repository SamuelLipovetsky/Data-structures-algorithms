#include <iostream>
#include <cstdio>

using namespace std;
int dp[1000010] = {};
int main()
{

    int k, l, m;
    cin >> k;
    cin >> l;
    cin >> m;

    int n[m];

    int max = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> n[i];
        if (n[i] > max)
        {
            max = n[i];
        }
    }

    dp[0] = -1;
    for (int i = 1; i <= l; i++)
    {
        dp[i] = 1;
    }

    for (int i = l + 1; i <= max; i++)
    {

        if (dp[i - l] == 0 || dp[i - 1] == 0 || dp[i - k] == 0)
        {
            dp[i] = 1;
        }
        else
        {
            dp[i] = 0;
        }
    }
    int p = 0;

    for (int i = 0; i < m; i++)
    {

        if (dp[n[i]])
        {
            printf("A");
        }
        else
        {
            printf("B");
        }
    }
    printf("\n");
}
