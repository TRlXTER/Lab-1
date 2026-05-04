#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int minMoves = (n + 1) / 2;

    int answer = ((minMoves + m - 1) / m) * m;

    if (answer <= n) {
        cout << answer << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
