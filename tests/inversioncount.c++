#include <iostream>
using namespace std;
long long int cnt = 0;
//aprendido : tomar cuidado com o tamanho do input
void merge(int *A, int inicio, int meio, int fim)
{
    int tamanho_l = meio - inicio + 1;
    int tamanho_r = fim - meio;
    int L[tamanho_l] = {};
    int R[tamanho_r] = {};
    for (int i = 0; i < tamanho_l; i++)
    {
        L[i] = A[inicio + i];
    }
    for (int i = 0; i < tamanho_r; i++)
    {
        R[i] = A[meio + i + 1];
    }
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < tamanho_l && j < tamanho_r)
    {

        if (L[i] <= R[j])
        {

            A[inicio + k] = L[i];
            i++;
            k++;
        }

        else
        {

            cnt += tamanho_l - i;

            A[inicio + k] = R[j];
            j++;
            k++;
        }
    }
    while (i < tamanho_l)
    {
        A[inicio + k] = L[i];

        i++;
        k++;
    }

    while (j < tamanho_r)
    {
        A[inicio + k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int *A, int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        mergeSort(A, inicio, meio);
        mergeSort(A, meio + 1, fim);
        merge(A, inicio, meio, fim);
    }
}
int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        int arr[m];

        for (int j = 0; j < m; j++)
        {
            cin >> arr[j];
        }
        cnt = 0;
        mergeSort(arr, 0, m - 1);

        cout << cnt << endl;
    }
}
