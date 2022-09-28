#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long trekking(vector<vector<int>> &mapa);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int M;
    cin >> M;
    vector<vector<int>> mapa;
    mapa.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        mapa[i0].resize(M);
        for (int i1 = 0; i1 < M; i1++) {
            cin >> mapa[i0][i1];
        }
    }
    long long returnedValue;
    returnedValue = trekking(mapa);
    cout << returnedValue << "\n";
    return 0;
}
