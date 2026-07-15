//Free Cash

/*
n people

ith person comes exactly at h hours m minutes

cafe spends less than a minute to serve each client, 
client comes in and sees that there is no free
cash, then he leaves immediately

serve all n customers next day and get more profit

ensure that at each moment of time the number of working
cashes is no less than the number of clients in cafe

minimum number of cashes to work at his cafe next day
*/
#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int>m{};

    int h;
    int min;
    for (int i = 0; i < n; i++) {
        cin >> h >> min;

        m[h * 60 + min]++;
    }

    int res{};
    for (auto [key, value]: m) {
        res = max(res, value);
    }

    cout << res;
}