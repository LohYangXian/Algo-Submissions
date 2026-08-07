#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n);
        
        vector<int> chunks{};
        vector<int> truncated{};

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v[i] = x;
        }

        for (int x: v) {
            if (truncated.empty() || truncated.back() != x) {
                truncated.push_back(x);
                chunks.push_back(1);
            } else {
                chunks.back()++;
            }
        }

        int m = truncated.size();
        int bonus = 0;

        for (int i = 0; i + 1 < m; i++) {
            if (chunks[i] >= 2 && chunks[i + 1] >= 2) {
                bonus = 2;
                break;
            }

            if (chunks[i + 1] >= 2) {
                if (i - 1 < 0 || truncated[i + 1] != truncated[i - 1]) {
                    bonus = max(bonus, 1);
                }
            }

            if (chunks[i] >= 2) {
                if (i + 2 >= m || truncated[i] != truncated[i + 2]) {
                    bonus = max(bonus, 1);
                }
            }
        }

        cout << m + bonus << "\n";
    }
}