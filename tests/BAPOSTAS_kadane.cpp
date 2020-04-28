#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <ctime>
#include <stdio.h>
#include <array>
using namespace std;
//kadane?
int main(int argc, const char *argv[])
{
    int tamanho;
    cin >> tamanho;
    int dp[10000] = {};
    while (tamanho)
    {
        for (int i = 0; i < tamanho; i++)
        {
            cin >> dp[i];
        }
        int local_max = 0;
        int global_max = 0;
        for (int i = 0; i < tamanho; i++)
        {
            local_max += dp[i];
            if (dp[i] > local_max)
            {
                local_max = dp[i];
            }
            if (local_max > global_max)
            {
                global_max = local_max;
            }
        }
        if (global_max > 0)
        {
            cout << "The maximum winning streak is " << global_max << "." << endl;
        }
        else
        {
            cout << "Losing streak." << endl;
        }

        cin >> tamanho;
    }
}
