//Unlucky Ticket

/*
even number of digits

lucky if sum of digits in first half matches sum of digits in second half

each digit in first half corresponds to some digit from the second half so that each digit 
each digit is strictly more or less than each corresponding digit from second half


*/
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    string str;

    vector<int> v1{};
    vector<int> v2{};
    cin >> n >> str;

    for (int i = 0; i < n; i++) {
        v1.push_back(str[i] - '0');
    }

    for (int i = n; i < 2 * n; i++) {
        v2.push_back(str[i] - '0');
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for (int i = 0; i < n; i++) {
        cout << v1[i] << " " << v2[i];
        if (v1[i] >= v2[i]) {
            for (int j = 0; j < n; j++) {
                cout << v2[j] << " " << v1[j];
                if (v2[j] >= v1[j]) {
                    cout << "NO";
                    return 0;
                }
            }
            cout << "YES";
            return 0;
        }
    }
    cout << "YES";
}