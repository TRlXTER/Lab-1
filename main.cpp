#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    int n, m;
    cin >> n >> m;

    int minMoves = (n + 1) / 2;
    
    int answer = ((minMoves + m - 1) / m) * m;

    if (answer <= n) {
        cout << answer << endl;
    } else {
        cout << -1 << endl;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int lastDigitPos = -1;
    int bestStart = -1;
    int bestLen = 0;

    for (int i = 0; i < (int)s.size(); ++i) {
        if (isdigit(static_cast<unsigned char>(s[i]))) {
            if (lastDigitPos != -1) {
                int curLen = i - lastDigitPos - 1;

                if (curLen > bestLen) {
                    bestLen = curLen;
                    bestStart = lastDigitPos + 1;
                }
            }

            lastDigitPos = i;
        }
    }

    if (bestLen > 0) {
        cout << "Самая длинная подстрока: ";
        cout << s.substr(bestStart, bestLen) << endl;
    } else {
        cout << "Подстрок между двумя цифрами нет" << endl;
    }

    return 0;
}
