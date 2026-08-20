//Basket Ball Exercise

/*
2 . n students

2 rows of the same size 
n ppl in each row

numbered 1 to n in each row

choose players from left to right,
index of each chosen player (excl first one)
will be strictly greater than prev index player

no consecutive students belong to same row

a team consist of any number of students

he shld choose students in a way that total height is max

help demid find max height

n students in each row
n heights
n heights


*/
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> row1{};
    vector<long long> row2{};
    vector<long long> dp1(n, 0);
    vector<long long> dp2(n, 0);

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        row1.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        row2.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            dp1[i] = row1[i];
            dp2[i] = row2[i];
        } else if (i == 1) {
            dp1[i] = row1[i] + dp2[i - 1];
            dp2[i] = row2[i] + dp1[i - 1];
        } else {
            dp1[i] = max(row1[i] + dp2[i - 1], row1[i] + max(dp1[i - 2], dp2[i - 2]));
            dp2[i] = max(row2[i] + dp1[i - 1], row2[i] + max(dp2[i - 2], dp1[i - 2]));
        }
    }
    cout << max(dp1[n - 1], dp2[n - 1]);
}