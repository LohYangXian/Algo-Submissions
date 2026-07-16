// Candy Bags

/*
n younger brothers, even number

n^2 bags
k from 1 to n^2, exactly one bag with k candies

give n bags of candies to each brother so all brothers have same
number of candies
*/

#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v{};
    for (int i = 1; i <= n * n; i++) {
        v.push_back(i);
    }

    int l = 0;
    int r = v.size() - 1;
    while (l < r) {
        cout << v[l] << " " << v[r] << "\n";
        l++;
        r--;
    }
}