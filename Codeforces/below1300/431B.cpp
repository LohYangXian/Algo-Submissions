// Shower Line

/*
2 3 1 5 4

Think of a queue structure

2 3 talks, 1 5 talks, 4 does not talk

2 showers, 3 1 talks , 5 4 talks

3 showers, 1 5 talks, 4 does not

find an initial order of students in the line that the total happiness of all students will be maximum

theres always 5 ppl only, so lets prioritise that way by who gets most attempt in talking

1: x 
2: x x
3: x x x
4: x x x x
5: x x

01 + 10 + 23 + 32 + 
12 + 21 + 34 + 43 +
23 + 32 +
34 + 43

01 + 10 +  
12 + 21 + 



2 (34) + 2 (43) + 2 (23) + 2 (32) + 01 + 10 + 12 + 21

1,2,3,4,5
1,2 3,4 5
2,3 4,5
3,4 5
4,5


*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<int>> a(5, vector<int>(5));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> p{0, 1, 2, 3, 4};
    int ans = 0;

    do {
        int cur = 0;

        cur += a[p[0]][p[1]] + a[p[1]][p[0]];
        cur += a[p[1]][p[2]] + a[p[2]][p[1]];
        cur += a[p[2]][p[3]] + a[p[3]][p[2]];
        cur += a[p[3]][p[4]] + a[p[4]][p[3]];

        cur += a[p[1]][p[2]] + a[p[2]][p[1]];
        cur += a[p[2]][p[3]] + a[p[3]][p[2]];

        ans = max(ans, cur);

    } while (next_permutation(p.begin(), p.end()));

    cout << ans;
}