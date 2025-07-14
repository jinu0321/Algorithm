#include <iostream>
#include <vector>
#include <map>
#define FORI(n) for (int i = 0; i < n; i++)
#define FORJ(n) for (int j = 0; j < n; j++)
#define FORK(n) for (int k = 0; k < n; k++)

using namespace std;

vector<vector<int>> boxes(4, vector<int>(4));
map<int, map<int, bool>> visited;

int main() {
    FORI(4) FORJ(4) cin >> boxes[i][j];
    int answer = 0;
    
    FORI(4) {
        vector<int> v = boxes[i];
        int startX = v[0], startY = v[1], endX = v[2], endY = v[3];
        for (int j = startX + 1; j <= endX; j++) {
            for (int k = startY + 1; k <= endY; k++) {
                if (visited[j][k]) continue;
                visited[j][k] = true;
                answer++; 
            }
        }
    }

    cout << answer << '\n';
}