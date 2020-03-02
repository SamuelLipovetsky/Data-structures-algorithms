#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>

using namespace std;

bool subset_sum(int set[], int sum, int set_size)
{
    bool dp[set_size + 1][sum + 1];

    for (int i = 0; i < set_size + 1; i++)
        dp[i][0] = true;

    for (int i = 1; i < sum + 1; i++)
        dp[0][i] = false;

    for (int i = 1; i <= set_size; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < set[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j - set[i - 1]] || dp[i - 1][j];
            }
        }
    }
    for (int i = 0; i <= set_size; i++)
    {
        for (int j = 0; j <= sum; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}
int main(int argc, const char *argv[])
{
    int set[] = {2, 3, 4};
    int sum = 6;
    subset_sum(set, sum, 3);
}
