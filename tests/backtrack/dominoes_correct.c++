#include <iostream>
#include <set>
#include <array>
#include <map>
using namespace std;
int geral = 0;
map<array<int, 2>, int> pecas = {
    {{0, 0}, 1},
    {{0, 1}, 2},
    {{0, 2}, 3},
    {{0, 3}, 4},
    {{0, 4}, 5},
    {{0, 5}, 6},
    {{0, 6}, 7},
    {{1, 1}, 8},
    {{1, 2}, 9},
    {{1, 3}, 10},
    {{1, 4}, 11},
    {{1, 5}, 12},
    {{1, 6}, 13},
    {{2, 2}, 14},
    {{2, 3}, 15},
    {{2, 4}, 16},
    {{2, 5}, 17},
    {{2, 6}, 18},
    {{3, 3}, 19},
    {{3, 4}, 20},
    {{3, 5}, 21},
    {{3, 6}, 22},
    {{4, 4}, 23},
    {{4, 5}, 24},
    {{4, 6}, 25},
    {{5, 5}, 26},
    {{5, 6}, 27},
    {{6, 6}, 28}};
int matriz[8][9] = {};
int arr[8][9] = {};

int problem(set<array<int, 2>> usados, int x, int y)
{
    int candidatos[16];
    int cnt = 0;
    if (usados.size() == 28)
    {
        geral++;
    }
    if (y == 9 and x < 9)
    {
        y = 1;
        x++;
    }
    if (arr[x][y] == 0 && usados.size() < 28)
    {

        if (arr[x + 1][y] == 0 && matriz[x + 1][y] != -1)
        {
            int menor = min(matriz[x + 1][y], matriz[x][y]);
            int maior = max(matriz[x + 1][y], matriz[x][y]);
            candidatos[cnt] = menor;
            candidatos[cnt + 1] = maior;
            candidatos[cnt + 2] = x + 1;
            candidatos[cnt + 3] = y;
            cnt += 4;
        }
        if (arr[x][y + 1] == 0 && matriz[x][y + 1] != -1)
        {
            int menor = min(matriz[x][y], matriz[x][y + 1]);
            int maior = max(matriz[x][y], matriz[x][y + 1]);
            candidatos[cnt] = menor;
            candidatos[cnt + 1] = maior;
            candidatos[cnt + 2] = x;
            candidatos[cnt + 3] = y + 1;
            cnt += 4;
        }

        int i = 0;
        while (i < cnt)
        {

            array<int, 2> used = {candidatos[i], candidatos[i + 1]};

            if (usados.count(used) == 0)
            {

                usados.insert(used);
                int new_x = candidatos[i + 2];
                int new_y = candidatos[i + 3];
                i += 4;
                int corresponde = pecas[used];
                arr[x][y] = corresponde;
                arr[new_x][new_y] = corresponde;
                problem(usados, x, y + 1);
                arr[x][y] = 0;
                arr[new_x][new_y] = 0;
                usados.erase(used);
            }
            else
            {
                i += 4;
                if (usados.size() == 28)
                {
                    for (int i = 1; i < 8; i++)
                    {
                        for (int j = 1; j < 9; j++)
                        {
                            cout << arr[i][j] << " ";
                        }
                        cout << endl;
                    }
                    cout << endl;
                }
            }
        }
    }
    else if (arr[x][y] != -1 && usados.size() < 28)
    {
        problem(usados, x, y + 1);
    }
}
int main()
{
    int n;
    cin >> n;

    for (int k = 0; k < n; k++)
    {
        geral = 0;
        for (int i = 0; i <= 9; i++)
        {
            arr[0][i] = -1;
            matriz[0][i] = -1;
            arr[8][i] = -1;
            matriz[8][i] = -1;
        }
        for (int i = 0; i <= 8; i++)
        {
            arr[i][0] = -1;
            matriz[i][0] = -1;
            arr[i][9] = -1;
            matriz[i][9] = -1;
        }

        for (int i = 1; i < 8; i++)
        {
            for (int j = 1; j < 9; j++)
            {
                cin >> matriz[i][j];
            }
        }
        set<array<int, 2>> used;
        problem(used, 1, 1);
        cout << "Teste " << k + 1 << endl;
        cout << geral << endl;
        ;
    }
}
