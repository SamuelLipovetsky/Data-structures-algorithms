// não pode sair desta rota.Este pequeno problema pode ser corrigido diretamente na leitura da entrada : basta ignorarmos todas as estradas que partem de uma cidade que pertence à rota para uma que não pertence a ela, pois não poderemos usá - las para encontrar o menor caminho !Assim, basta lermos a entrada ignorando as estrada inúteis e depois aplicarmos o algoritmo de Dijkstra !Segue o código para melhor entendimento :
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>

#define INF 999999999

using namespace std;

int n, m, c, k;
int grafo[1010][1010];
int custo[1010];

queue<int> fila;

// função de infinitar o grafo e o vetor custo
void infinite()
{
    for (int i = 0; i <= n; i++)
    {
        custo[i] = INF;
        for (int j = 0; j <= n; j++)
            grafo[i][j] = INF;
    }
}

// algoritmo de Dijkstra
int dijkstra(int ori, int dest)
{
    custo[ori] = 0;
    fila.push(ori);
    while (!fila.empty())
    {
        int i = fila.front();
        fila.pop();
        for (int j = 0; j < n; j++)
        {
            if (grafo[i][j] != INF && custo[j] > custo[i] + grafo[i][j])
            {
                custo[j] = custo[i] + grafo[i][j];
                fila.push(j);
            }
        }
    }
    return custo[dest];
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &c, &k);
    while (n != 0 || m != 0 || c != 0 || k != 0)
    {

        infinite(); // infinite o grafo e o vetor custo

        for (int i = 1; i <= m; i++)
        { // para cada estrada

            // declare e leia os valores de u, v e p
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);

            if (u >= c && v >= c)
            { // se as duas cidades estiverem fora da rota

                // adicione a estra normalmente
                grafo[u][v] = p;
                grafo[v][u] = p;
            }
            // se v pertencer à rota
            if (u >= c && v < c)
                grafo[u][v] = p; // adicione apenas a estrada que chega em v

            // se u pertencer à rota
            if (u < c && v >= c)
                grafo[v][u] = p; // adicione apenas a estrada que chega em u

            // se as duas cidades forem cidades consevutivas da rota
            if (u < c && v < c && abs(u - v) == 1)
            {

                //adiciono a estrada normalmente
                grafo[u][v] = p;
                grafo[v][u] = p;
            }
        }

        printf("%d", dijkstra(k, c - 1)); // imprimo o valor do menor caminho, usando o algoritmo de Dijkstra

        scanf("%d %d %d %d", &n, &m, &c, &k);
    }
}
