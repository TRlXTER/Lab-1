#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
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
    }
    else {
        cout << "Подстрок между двумя цифрами нет" << endl;
    }
    return 0;
}
