
// M arrays

/*
n positive integers
and a positive integer m

divide elements of this array
into some arrays

can order the lements in
the new arrays as u want                                                                                                                  

if each adj numbers, sum divisible by m

one array works too

O(n) soln
*/
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int m;
        cin >> n >> m;
        vector<int> v{};
        unordered_map<int,int> freqCount{};
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            x %= m;
            freqCount[x]++;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        int l = 0;
        int r = n - 1;

        int res{};

        if (freqCount[0] > 0) res++;
        while (l < n && v[l] == 0) {
            l++;
        }

        while (l <= r) {
            if (v[l] + v[r] == m) {
                res++;
                bool lastIsLeft;
                int lastVal;
                if (freqCount[v[l]] >= freqCount[v[r]]) {
                    lastIsLeft = false;
                    lastVal = v[r];
                } else {
                    lastIsLeft = true;
                    lastVal = v[l];
                }
                freqCount[v[l]]--;
                freqCount[v[r]]--;
                l++;
                r--;
                while (l <= r) {
                    if (lastIsLeft == true) {
                        if (v[r] + lastVal == m) {
                            lastIsLeft = false;
                            lastVal = v[r];
                            freqCount[v[r]]--;
                            r--;
                        }
                        else {
                            break;
                        }
                    } else {
                        if (v[l] + lastVal == m) {
                            lastIsLeft = true;
                            lastVal = v[l];
                            freqCount[v[l]]--;
                            l++;
                        } else {
                            break;
                        }
                    }
                }
            } else if (v[l] + v[r] < m) {
                l++;
                res++;
            } else {
                r--;
                res++;
            }
        }
        cout << res << "\n";
    }
}