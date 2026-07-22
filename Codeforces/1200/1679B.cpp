//Stone Age Problem

/*
array a of n integers

given q queries of two types:

Replace ith element in array with x
Replace each element in array with x

After each query, calc the sum of all elements in array


*/

#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    int q;
    cin >> n >> q;

    vector<long long> v{};
    vector<int> lastUpdated(n , 0);
    long long x;

    long long sum{};
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
        v.push_back(x);
    }

    long long globalValue = 0;
    int globalVersion = 0;
    

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos;
            long long val;
            cin >> pos >> val;
            pos--;

            long long oldVal;

            if (lastUpdated[pos] == globalVersion) {
                oldVal = v[pos];
            } else {
                oldVal = globalValue;
            }

            sum += val - oldVal;
            v[pos] = val;
            lastUpdated[pos] = globalVersion;

        } else {
            long long val;
            cin >> val;
            
            globalVersion++;
            globalValue = val;
            sum = 1LL * n * val;
        }
        
        cout << sum << "\n";
    }
}