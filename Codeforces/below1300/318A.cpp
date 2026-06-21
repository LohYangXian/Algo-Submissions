// Even Odds
// 1 3 5 7 9 // 2 4 6 8 10
#include <iostream>
using namespace std;
int main() {
    long long n;
    long long k;
    cin >> n >> k;
    
    long long odd_count = (n + 1) / 2;
    long long answer;
    if (k <= odd_count)
        answer = 2*k - 1;
    else
        answer = 2*(k - odd_count);
    
    cout << answer;
}