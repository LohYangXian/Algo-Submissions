// Stones on the table
#include <string>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string stones;
    cin >> stones;
    int answer{0};
    for (int i = 1; i < n; i++) {
        if (stones[i] == stones[i - 1]) {
            answer++;
        }
    }
    cout << answer;
    
}