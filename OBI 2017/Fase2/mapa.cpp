#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ulli unsigned long long int
#define INF 0x3f3f3f3f
#define pb push_back
#define pii pair<int, int>

char mapa[105][105];

void inicializa(int l, int c) {
	for (int i = 0; i < l + 1; ++i) {
		mapa[i][0] = '.';
		mapa[i][c + 1] = '.';
	}	
	for (int j = 0; j < c + 1; ++j) {
		mapa[0][j] = '.';
		mapa[l + 1][j] = '.';
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int l, c;
	int a, b;

	cin >> l >> c;
	inicializa(l, c);

	for (int i = 1; i <= l; ++i) {
		for (int j = 1; j <= c; ++j) {
			cin >> mapa[i][j];
			if (mapa[i][j] == 'o') {
				a = i;
				b = j;
			}
		}
	}

	while (true) {
		mapa[a][b] = '.';
		if (mapa[a + 1][b] == 'H') a++;
		else if (mapa[a - 1][b] == 'H') a--;
		else if (mapa[a][b + 1] == 'H') b++;
		else if (mapa[a][b - 1] == 'H')b--;
		else break;
	}
	cout << a << " " << b << endl;
	return 0;
}
