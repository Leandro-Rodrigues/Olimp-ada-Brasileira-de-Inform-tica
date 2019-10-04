#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ulli long long unsigned
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL

const int t = 1005;

int n, m;
int distancias[t];
bool visitado[t];
vector< pair<int, int> > lista[t];

void dj1(int s) {
    memset(distancias, INF, sizeof distancias);
    memset(visitado, 0, sizeof visitado);
    distancias[s] = 0;

    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > fila; // fila ordenada ao contrário
    fila.push(make_pair(0, s));

    while (true) {
        int da_vez = -1;

        while (!fila.empty()) {
            int atual = fila.top().second;
            fila.pop();

            if (!visitado[atual]) {
                da_vez = atual;
                break;
            }
        }

        if (da_vez == -1) break;
        visitado[da_vez] = 1;

        for (int i = 0; i < lista[da_vez].size(); i++) {
            int v = lista[da_vez][i].second;
            int distancia = lista[da_vez][i].first;

            if (distancias[v] > distancias[da_vez] + distancia) {
                distancias[v] = distancias[da_vez] + distancia;
                fila.push(make_pair(distancias[v], v));
            }
        }
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, dist;
    int local;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> dist;
        lista[a].push_back(make_pair(dist, b));
        lista[b].push_back(make_pair(dist, a));
    }
    cin >> local;
    dj1(local);

    int menor = INF, maior = 0;
    for (int i = 1; i <= n; i++) {
        if (i != local) {
            menor = min(menor, distancias[i]);
            maior = max(maior, distancias[i]);
        }
    }

    cout << maior - menor << "\n";
    return 0;
}
