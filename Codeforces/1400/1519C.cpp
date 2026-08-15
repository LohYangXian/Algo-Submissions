//Berland Regional

/*
n universities, 1 to n

n students
ith student is enrolled in u, skill of s

if chooses size of team to be k
each uni send k strongest in first team
next k strongest so on,
no team if < k

stregnth of region is total skill of all present teams
if no teams, strength = 0

find strength of each region for each k from 1 to n

t cases
n (number of unis and students)
n integers of university
n integers of programming skill

find O(1) soln, k = 1 <= k <= n


*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> students(n);
        vector<vector<long long>> uni(n);
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            students[i] = x; 
        }

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            uni[students[i] - 1].push_back(x);
        }

        for (auto& arr: uni) {
            sort(arr.rbegin(), arr.rend());
        }

        for (auto& arr: uni) {
            for (int i = 1; i < arr.size(); i++) {
                arr[i] += arr[i - 1];
            }
        }

        sort(uni.begin(), uni.end(), [](const auto& a, const auto& b) {
            return a.size() > b.size();
        });

        for (int i = 1; i <= n; i++) {
            long long total = 0;
            for (auto& arr: uni) {
                if (arr.size() < i) {
                    break;
                }
                total += arr[((arr.size() / i) * i) - 1];
            }
            cout << total << " ";
        }
        cout << "\n";
    }
}