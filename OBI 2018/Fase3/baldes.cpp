#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ulli unsigned long long int
#define INF 0x3f3f3f3f
#define pb push_back
#define pii pair<int, int>

const int t = 100005;
pii baldes[t];
pii arvMaior[4 * t];
pii arvMenor[4 * t];

pii max(const pii &a, const pii &b) {
	return pii(max(a.first, b.first), (a.first >= b.first) ? a.second : b.second);
}

pii min(const pii &a, const pii &b) {
	return pii(min(a.first, b.first), (a.first <= b.first) ? a.second : b.second);
}

void constroiMaior(int no, int esq, int dir) {
	if (esq == dir) {
		arvMaior[no] = baldes[dir];
		return;
	}
	int meio = (esq + dir) >> 1;
	constroiMaior(2 * no, esq, meio);
	constroiMaior(2 * no + 1, meio + 1, dir);
	arvMaior[no] = max(arvMaior[2 * no], arvMaior[2 * no + 1]);
}

void constroiMenor(int no, int esq, int dir) {
	if (esq == dir) {
		arvMenor[no] = baldes[dir];
		return;
	}
	int meio = (esq + dir) >> 1;
	constroiMenor(2 * no, esq, meio);
	constroiMenor(2 * no + 1, meio + 1, dir);
	arvMenor[no] = min(arvMenor[2 * no], arvMenor[2 * no + 1]);
}

void attMaior(int no, int esq, int dir, int val, int pos) {
	if (esq == dir) {
		arvMaior[no].first = max(arvMaior[no].first, val);
		return;
	}
	int meio = (esq + dir) >> 1;
	if (pos <= meio)
		attMaior(2 * no, esq, meio, val, pos);
	else attMaior(2 * no + 1, meio + 1, dir, val, pos);
	arvMaior[no] = max(arvMaior[2 * no], arvMaior[2 * no + 1]);
}

void attMenor(int no, int esq, int dir, int val, int pos) {
	if (esq == dir) {
		arvMenor[no].first = min(arvMenor[no].first, val);
		return;
	}
	int meio = (esq + dir) >> 1;
	if (pos <= meio)
		attMenor(2 * no, esq, meio, val, pos);
	else attMenor(2 * no + 1, meio + 1, dir, val, pos);
	arvMenor[no] = min(arvMenor[2 * no], arvMenor[2 * no + 1]);
}

pii consultaMaior(int no, int esq, int dir, int ql, int qr) {
	if (esq > qr || dir < ql)
		return pii(-INF, 0);
	if (esq >= ql && dir <= qr)
		return arvMaior[no];
	int meio = (esq + dir) >> 1;
	return max(consultaMaior(2 * no, esq, meio, ql, qr), consultaMaior(2 * no + 1, meio + 1, dir, ql, qr));
}

pii consultaMenor(int no, int esq, int dir, int ql, int qr) {
	if (esq > qr || dir < ql)
		return pii(INF, 0);
	if (esq >= ql && dir <= qr)
		return arvMenor[no];
	int meio = (esq + dir) >> 1;
	return min(consultaMenor(2 * no, esq, meio, ql, qr), consultaMenor(2 * no + 1, meio + 1, dir, ql, qr));
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m, op;
	int a, b, x;
	int pos, val;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> x;
		baldes[i].first = x;		
		baldes[i].second = i;		
	}
	constroiMaior(1, 1, n);
	constroiMenor(1, 1, n);
	
	while (m--) {
		cin >> op;
		if (op == 1) {
			cin >> val >> pos;
			attMaior(1, 1, n, val, pos);
			attMenor(1, 1, n, val, pos);
		}
		else {
			cin >> a >> b;
			pii auxMaior = consultaMaior(1, 1, n, a, b);
			int posMaior = auxMaior.second;
			int maior = auxMaior.first;
			int menor = min(consultaMenor(1, 1, n, a, posMaior - 1).first, consultaMenor(1, 1, n, posMaior + 1, b).first);
			int ans = maior - menor;
			
			pii auxMenor = consultaMenor(1, 1, n, a, b);
			int posMenor = auxMenor.second;
			menor = auxMenor.first;
			maior = max(consultaMaior(1, 1, n, a, posMenor - 1).first, consultaMaior(1, 1, n, posMenor + 1, b).first);
			ans = max(ans, maior - menor);
			cout << ans << "\n";
		}
	}
    return 0;
}
