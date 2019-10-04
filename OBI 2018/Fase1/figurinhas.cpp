#include <bits/stdc++.h>	
using namespace std;

#define lli long long int
#define ulli unsigned long long int
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL

int main() {
	int n, cari, comp;
	int ans = cari, cont = 0;
	int vet[100000];

	memset(vet, 0, sizeof vet);
	cin >> n >> cari >> comp;
	for (int i = 0; i < cari; i++) {
		int x;
		cin >> x;
		vet[x] = -1;
	}

	for (int i = 0; i < comp; i++) {
		int x;
		cin >> x;
		if(vet[x] == -1) {
			cont++;
			vet[x] = 0;
		}
	}
	cout << ans - cont << endl;
	return 0;
}
