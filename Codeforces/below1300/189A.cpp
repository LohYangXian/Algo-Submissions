// Cut Ribbon

/*
length = n

after cutting each piece shld have lengths a, b and c

after the cutting number of ribbon pieces shld be maximum

maximise the number of pieces, but u can only cut into lengths of a b and c
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int a;
    int b;
    int c;

    int x; int y; int z;

    cin >> n >> a >> b >> c;

    vector<int> dp(n + 1, numeric_limits<int>::min());
    vector<int> pieces{};

    pieces.push_back(a);
    pieces.push_back(b);
    pieces.push_back(c);

    int count{};

    dp[0] = 0;
    
    for (int i = 0; i <= n; i++) {
        for (int p: pieces) {
            if (i >= p && dp[i - p] != numeric_limits<int>::min()) {
                dp[i] = max(dp[i], dp[i - p] + 1);
            }
        } 
    }

    cout << dp[n];
}