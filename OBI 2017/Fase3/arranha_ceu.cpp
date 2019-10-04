#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ulli unsigned long long int
#define INF 0x3f3f3f3f
#define pb push_back
#define pii pair<int, int>

const int t = 100005;
int arv[t];

void att(int val, int pos) {
	while (pos <= t) {
		arv[pos] += val;
		pos += (pos & -pos);
	}
}

int consulta(int pos) {
	int soma = 0;
	while (pos) {
		soma += arv[pos];
		pos -= (pos & -pos);
	}
	return soma;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int vet[t];
	int n, q;
	int op, val, pos;
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> vet[i];
		att(vet[i], i);
	}
	
	while (q--) {
		cin >> op;
		if (!op) {
			cin >> pos >> val;
			int diff = val - vet[pos];
			vet[pos] = val;
			att(diff, pos);
		}
		else {
			cin >> pos;
			cout << consulta(pos) << "\n";
		}
	}
	
	return 0;
}
