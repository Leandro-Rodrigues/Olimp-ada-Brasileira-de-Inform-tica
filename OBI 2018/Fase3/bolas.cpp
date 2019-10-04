#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ulli unsigned long long int
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL

int main() {
	int num;
	int vet[10];
	char ans = 'S';
	memset(vet, 0, sizeof vet);
	
	for (int i = 0; i < 8; i++) {
		cin >> num;
		vet[num]++;
		if (vet[num] > 4) ans = 'N';
	}
	cout << ans << endl;
	return 0;
}
