#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
#include <set>
#include <stdlib.h>
#include <time.h>
using namespace std;
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
    //começa dps do meio por isso o +1
    for (int i = 0; i < tamanho_r; i++)
    {
        R[i] = A[meio + i + 1];
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < tamanho_l && j < tamanho_r)
    {
        if (L[i] < R[j])
        {
            A[inicio + k] = L[i];
            i++;
            k++;
        }
        else
        {
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
    int A[10] = {6, 7, 8, 4, 3, 2, 1, 9, 10, 5};

    mergeSort(A, 0, 9);

    for (auto x : A)
    {
        cout << x << " ";
    }
    cout << endl;
}
