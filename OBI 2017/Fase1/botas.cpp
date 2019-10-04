##include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ulli unsigned long long int
#define INF 0x3f3f3f3f
#define pb push_back
#define pii pair<int, int>

int ladod[61], ladoe[61];

int main() {
    int n, tam, soma = 0;
    char lado;

    while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> tam >> lado;

			if (lado == 'E')
				ladoe[tam]++;
			else ladod[tam]++;
		}

		for (int i = 30; i <= 60; i++) {
			if (ladod[i] < ladoe[i])
				soma += ladod[i];

		   else soma += ladoe[i];
		}
		cout << soma << endl;

		for (int i = 30; i <= 60; i++) {
			ladod[i] = 0;
			ladoe[i] = 0;
		}
		soma = 0;
    }
    return 0;
}
