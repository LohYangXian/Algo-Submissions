//Appleman and Card Game

/*
n cards

each card has an uppcase letter on it

choose k cards

give some coins depending on the chosen k cards

calc how much cards have letter equal to letter on ith,
sum up the quantities

whats the max number of coins 
*/

#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n; int k;
    char x;
    unordered_map<char,int> m{};
    vector<pair<char,int>> v{};

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> x;
        m[x]++;
    }

    for (auto [key,value]: m) {
        v.push_back(pair{key,value});
    }

    sort(v.begin(), v.end(), [](auto const& a, auto const& b) {
        return a.second > b.second;
    });

    long long res{};
    int pointer{};
    while (k > 0) {
        long long amt = min(v[pointer].second, k);
        res += amt * amt;
        k -= amt;
        pointer++;
    }

    cout << res;
}