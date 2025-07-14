#include <iostream>
#include <vector>
#include <algorithm>
#define FORI(n) for (int i = 0; i < n; i++)
#define FORJ(n) for (int j = 0; j < n; j++)
#define FORK(n) for (int k = 0; k < n; k++)
#define FOR(items) for (auto item : items)

using namespace std;

vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

bool isVowel(char c) {
    return find(vowels.begin(), vowels.end(), c) != vowels.end();
}

bool isGood(string s) {
    bool isGood = false;
    FOR(s) {
        if (isVowel(item) == true) isGood = true;
    }

    if (!isGood) return isGood;

    if (s.length() >= 3) {
        for (int i = 2; i < s.size(); i++) {
            char pp = s[i - 2];
            char p = s[i - 1];
            char n = s[i];
            if (isVowel(pp) && isVowel(p) && isVowel(n)) return false;
            if (!isVowel(pp) && !isVowel(p) && !isVowel(n)) return false;
        }
    }

    if (s.length() >= 2) {
        for (int i = 1; i < s.length(); i++) {
            char p = s[i - 1];
            char n = s[i];
            if (s.substr(i - 1, 2) == "ee" || s.substr(i - 1, 2) == "oo") continue;
            if (p == n) return false;
        }
    }
    
    return isGood;
}

int main() {
    while (true) {
        string s; cin >> s;
        if (s == "end") return 0;
        if (isGood(s)) {
            cout << "<" << s <<"> is acceptable.\n";
        } else {
            cout << "<" << s <<"> is not acceptable.\n";
        }
    }   
}