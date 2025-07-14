#include <iostream>
#include <vector>

using namespace std;

int cash;
vector<int> prices(14);

int getJ() {
    int c = cash;
    int shares = 0;
    for (int i = 0; i < 14; i++) {
        int price = prices[i];
        int addedShares = c / price;
        if (addedShares == 0) continue;
        shares += addedShares;
        c -= (addedShares * price);
    }
    return c + (shares * prices[13]);
}

int getS() {
    int c = cash;
    int shares = 0;

    for (int i = 3; i < 14; i++) {
        int ppp = prices[i - 3];
        int pp = prices[i - 2];
        int p = prices[i - 1];
        int n = prices[i];
        if (ppp < pp && pp < p && p < n) {
            c += shares * n;
            shares = 0;
        }

        if (ppp > pp && pp > p && p > n) {
            int buyingShares = c / n;
            shares += buyingShares;
            c -= buyingShares * n;
        }
    }

    return c + shares * prices[13];
}

int main() {
    cin >> cash;
    for (int i = 0; i < 14; i++) cin >> prices[i];

    int BNP = getJ();
    int TIMING = getS();

    cout << (BNP > TIMING ? "BNP" : (BNP == TIMING ? "SAMESAME" : "TIMING")) << '\n';
}