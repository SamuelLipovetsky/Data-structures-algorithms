#include <iostream>
using namespace std;
int mem[100] = {};
int problem(int n, int soma, int *array)
{

    if (soma < 0)
    {
        return 0;
    }
    else if (soma == 0)
    {
        return 1;
    }
    else if (n < 0)
    {
        return 0;
    }
    else if (array[n] > soma)
    {
        return problem(n - 1, soma, array);
    }
    else
    {
        return problem(n - 1, soma, array) + problem(n - 1, soma - array[n], array);
    }
}
int main()
{
    int array[100] = {};
    for (int i = 0; i < 100; i++)
    {
        array[i] = i;
    }

    int teste = problem(100, 400, array);
    cout << teste;
}
