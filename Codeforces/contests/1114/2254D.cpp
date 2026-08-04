//Silhouette

/*
a rray of n > 0 integers

for each element ai , shadow bi is sum of all element sin a that are strictly smaller than ai (shld we sort?)

given array b, reconstruct the lexicographically smallest valid array a consisting of positive

if no exist output -1

t cases

O(n) solution
*/
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<pair<long long,int>> v{};

        cin >> n;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            v.push_back({x, i});
        }

        sort(v.begin(), v.end());

        vector<long long> res(n);
        int pointer = 0;
        long long rollingSum = 0;
        if (v[0].first != 0) {
            cout << -1 << "\n";
            continue;
        }

        bool solved = false;
        long long previousValue = 0;

        for (int i = 1; i < n; i++) {
            if (v[i].first == v[i - 1].first) {
                continue;
            }

            int groupSize = i - pointer;
            long long diff = v[i].first - rollingSum;

            if (diff % groupSize != 0) {
                cout << -1 << "\n";
                solved = true;
                break;
            } else {

                long long value = diff / groupSize;

                if (value <= previousValue || value <= 0) {
                    cout << -1 << "\n";
                    solved = true;
                    break;
                }

                for (int j = pointer; j < i; j++) {
                    res[j] = value;
                }

                previousValue = value;

                rollingSum += value * groupSize;
                pointer = i;
            }
        }

        if (solved == true) {
            continue;
        }

        if (v[pointer].first != rollingSum) {
            cout << -1 << "\n";
            continue;
        }

        long long finalValue = previousValue + 1;

        for (int i = pointer; i < n; i++) {
            res[i] = finalValue;
        }

        vector<long long> ans(n);

        for (int i = 0; i < n; i++) {
            ans[v[i].second] = res[i];
        }

        
        for (long long x : ans) {
            cout << x << " ";
        }

        cout << "\n";
    }
}