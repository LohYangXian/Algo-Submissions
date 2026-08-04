//Alyona and a Narrow Fridge

/*
h rows, 2 columns

she can install many shelves between two rows
a shelf is two cells wide

n bottles of milk
ith bottle is ai cells tall, 1 cell wide

no stacking bottles
largest k such taht she can put bottles 1,2,3...k in fridge
at the same time

n bottles
h height of fridge

I think its a binary search qns
u have to pair 2 closest bottles together to save space
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long h;
    cin >> n >> h;

    vector<long long> prefix{};
    int res = 0;
    
    for (int i = 0; i < n; i++) {
        long long x; 
        cin >> x;
        prefix.push_back(x);
        sort(prefix.begin(), prefix.end(), greater<int>());

        long long reqHeight = 0;
        for (int j = 0; j < prefix.size(); j += 2) {
            reqHeight += prefix[j];
        }

        if (reqHeight > h) {
            cout << res;
            return 0;
        }
        res++;
    }
    cout << res;
}