//Balanced Tunnel

/*
n cars numberedfrom 1 to n entered and exited
tunnel exactly once

all cars pass at constant speed

no overtaking,
if i overtakes any car j, i must be fined,
fined once only

i overtook j, if i entered tunnel later and exited earlier.
thne i must be fined if and only if it
overtook at least one other car

find number of cars that must be fined

n number of cars
next n integers of ids of cars in order of entering
next n integers of ids of cars exiting the tunnel
*/

#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> indices(n);
    vector<int> finalOrder(n);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        indices[x - 1] = i;
    }

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        finalOrder[i - 1] = indices[x - 1];
    }

    int res{};
    int curLowest = finalOrder[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (finalOrder[i] > curLowest) res++;
        curLowest = min(curLowest, finalOrder[i]);
    }

    cout << res;
}