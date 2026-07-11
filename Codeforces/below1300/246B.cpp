// Increase and Decrease

/*
two elements of the array 

can increase number ai by 1 and decrease number aj by 1, ai = ai + 1 and aj = aj - 1

find max number of equal array elements he can get 


*/


#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x;
    int sum{};
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
    }
    if (sum % n == 0) {
        cout << n;
    } else {
        cout << n - 1;
    }
}