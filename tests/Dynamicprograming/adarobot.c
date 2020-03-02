#include <stdio.h>

long long int dp[100000010];
long long int arr[1000010];
int ipow(long long int base, long long int exp)
{
    long long int result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}
int func(int n)
{

    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
            dp[i] = pow(__builtin_ctz(i * (i - 1)) + 1, 3) + dp[i - 2];
        else
            dp[i] = dp[i - 1];
    }
    return 0;
}
int main()
{

    long long int n;
    scanf("%lld", &n);

    long long int max = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    func(max);
    for (int i = 0; i < n; i++)
    {
        printf("%lld \n", dp[arr[i]]);
    }
}