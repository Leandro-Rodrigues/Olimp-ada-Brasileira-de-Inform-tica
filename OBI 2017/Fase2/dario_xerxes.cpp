#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ulli long long unsigned
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fL

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int vet[] = {0, 1, 2, 3, 4, 0, 1};
    int n, d, x;
    int contd = 0, contx = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d >> x;
        if (vet[d + 2] == x || vet[d + 1] == x)
            contd++;
        else contx++;
    }
    puts(contx > contd ? "xerxes" : "dario");

    return 0;
}
