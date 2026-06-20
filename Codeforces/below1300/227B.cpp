#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
    int n;
    unordered_map<int, int> m;
    int nQueries;

    int resVasya{};
    int resPetya{};

    cin >> n;
    for (int i = 1; i < n + 1; i++) {
        int x;
        cin >> x;
        m[x] = i;
    }

    cin >> nQueries;
    for (int i = 0; i < nQueries; i++) {
        int x;
        cin >> x;
        int a = m[x];
        resVasya += a;
        resPetya += n - a + 1;
    }

    cout << resVasya << " " << resPetya;
}