// Matryoshkas

/*
s - size of smallest nesting doll
m - number of dolls in a set

s, s+1, ... , s+ m - 1

find minimum number of sets
a = [2,2,3,4,3,1]

[1,2,3,4]
[2,3]

t test cases

n (number of dolls in all sets)
print k - min possible number of sets

sorted hashmap by key
check if key+1 exist, decre the number, continue. 
then add count
*/

#include <iostream>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int,int> m{};
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            m[x]++;
        }

        int groups{};
        
        for (auto [key,value]: m) {
            while (m[key] > 0) {
                groups++;
                int cur = key;
                while (m.find(cur) != m.end() && m[cur] != 0) {
                    m[cur]--;
                    cur++;
                }    
            }
        }
        

        cout << groups << "\n";
    }
}