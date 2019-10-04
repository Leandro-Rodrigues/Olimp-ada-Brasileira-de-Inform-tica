#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ulli unsigned long long int
#define INF 0x3f3f3f3f
#define pb push_back
#define pii pair<int, int>


int main() {
    int n, m;
    int x, v, y;
    int soma = 0;
    int vet[1005];

    cin >> m >> n;
    memset(vet, 0, sizeof vet);

    for (int i = 0; i < m; i++) {
	cin >> x >> v >> y;
 	vet[x] -= v;
	vet[y] += v;
	soma += v;
    }

    int melhor = 0;
    for (int i = 1; i <= n; i++) {
    	melhor += abs(vet[i]);
    }
    melhor /= 2;

    puts(melhor == soma ? "N" : "S");
    cout << melhor << endl;

    return 0;
}
