//Sending a Sequence over the network

/*
sequence a is split into segments (each element belongs to
exactly one segment, each segment is a group
of consecutive lements of sequence)

for each segment, length is written next to it
either to the left , or right of it

resulting sequence b is sent over the network
For example, we needed to send the sequence a=[1,2,3,1,2,3]
. Suppose it was split into segments as follows: [1]+[2,3,1]+[2,3]
. Then we could have the following sequences:

b=[1,1,3,2,3,1,2,3,2]
,
b=[1,1,3,2,3,1,2,2,3]
,
b=[1,1,2,3,1,3,2,2,3]
,
b=[1,1,2,3,1,3,2,3,2]
.

given sequence b. Is there a sequence a that works? 

t cases 
n size of b
n integers in b

try O(n) or O(n log n) result

YES or NO
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<bool> R(n + 1, false);
        R[0] = true;

        vector<long long> v;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            v.push_back(x);
        }

        for (int i = 0; i < n; i++) {

            // CASE 1:
            // v[i] is written on the LEFT
            //
            // [ length, ..., ..., ... ]
            //
            // if first i elements are already valid,
            // consume v[i] elements + the marker itself
            if (R[i] && i + v[i] + 1 <= n) {
                R[i + v[i] + 1] = true;
            }

            // CASE 2:
            // v[i] is written on the RIGHT
            //
            // [ ..., ..., ..., length ]
            //
            // if the segment contains v[i] elements,
            // it starts at i - v[i]
            if (i - v[i] >= 0 && R[i - v[i]]) {
                R[i + 1] = true;
            }
        }

        if (R[n]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}