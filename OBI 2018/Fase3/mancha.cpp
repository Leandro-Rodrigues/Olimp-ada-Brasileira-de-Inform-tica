#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ulli unsigned long long int
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    char mat[1005][1005];

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    bool okl = 1, okc = 1;

    for (int i = 0; i < n; i++) {
        bool aux = 0, meio = 0;
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == '*' && !aux) aux = 1;
            if (mat[i][j] == '.' && aux) meio = 1;
            if (mat[i][j] == '*' && meio) okl = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        bool aux = 0, meio = 0;
        for (int j = 0; j < n; j++) {
            if (mat[j][i] == '*' && !aux) aux = 1;
            if (mat[j][i] == '.' && aux) meio = 1;
            if (mat[j][i] == '*' && meio) okc = 0;
        }
    }
    //cout << "linha = " << okl << "\ncoluna = " << okc << "\n";
    cout << ((okl && okc) ? "S" : "N") << "\n";

    return 0;
}
