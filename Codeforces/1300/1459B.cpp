//Move and Turn

/*
each second robot moves 1 meter in either 4 dir
first step can choose any of the 4 directions, but then at the 
end of every second, it has to turn 90 deg left or right 

exactly n steps from starting position 
how many diff points can robot arrive to at the end

final orientation can be ignored

print a single integer -- number of diff possible locations
after exactly n steps

O(n^2)? 

we can simulate 
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a = n / 2;
    int b = n - a;

    if (n % 2 == 0) {
        cout << (a + 1) * (b + 1);
    } else {
        cout << (a + 1) * (b + 1) * 2;
    }
}