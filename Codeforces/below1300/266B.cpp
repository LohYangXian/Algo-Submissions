// Queue at the school

// Positions in queue are numbered from 1 to n from the front to the back. Initially, in the queue there are n children. Each child is either a boy or a girl. The queue is represented as a string s of length n, where the i-th character of s is "B" if the i-th child in the queue is a boy and "G" if it's a girl.
// Seems like girl and guy swaps positions at time t+1 if the guy is infront

//We can do a bubble sort ish solution, n^2 

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int t;

    cin >> n >> t;
    
    vector<char> v;
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        v.push_back(y);
    }


    for (int i = 0; i < t; i++) {
        int j = 0;
        while (j < n - 1) {
            if (v.at(j) == 'B' && v.at(j + 1) == 'G') {
                v.at(j) = 'G';
                v.at(j + 1) = 'B';
                j = j + 2;
            } else {
                j++;
            }
        }
    }

    string result;
    for (const auto& str: v) 
    {
        result += str;
    }

    cout << result;
    return 0;
}