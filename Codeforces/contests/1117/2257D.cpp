//Bermuda Rectangle

/*
area of rectangle is S
sides are ints

bottom left is 0 , 0

how many cells from a rectangle with sides x and y,
whose bottom left corner is at (0,0) can be located within
the bermuda rectangle

if it exists a rectangle that stasifies thegiven constraints
of bermuda rect and contains that cell

t cases

S area, q queries

q lines of x, y


*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long S;
        int q;
        cin >> S >> q;

        vector<long long> width{};
        vector<long long> height{};

        for (long long i = 1; i * i <= S; i++) {
            if (S % i == 0) {
                width.push_back(i);
                height.push_back(S / i);
            }
        }

        int size = width.size();
        for (int i = size - 1; i >= 0; i--) {
            long long w = height[i];
            long long h = width[i];

            if (w != width.back()) {
                width.push_back(w);
                height.push_back(h);
            }
        }

        int k = width.size();

        vector<long long> prefixSum(k + 1, 0);
        long long prevWidth = 0;
        for (int i = 0; i < k; i++) {
            long long stripW = width[i] - prevWidth;
            long long stripArea = stripW * height[i];

            prefixSum[i + 1] = prefixSum[i] + stripArea;

            prevWidth = width[i];
        }

        while (q--) {
            long long x;
            long long y;

            cin >> x >> y;

            int xSplit = lower_bound(width.begin(), width.end(), x) - width.begin();
            int low = 0;
            int high = k - 1;
            int ySplit = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (height[mid] > y) {
                    ySplit = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
     
            long long ans = 0;

            int fullLast = xSplit - 1;

            if (xSplit < k && width[xSplit] == x) {
                fullLast = xSplit;
            }

            if (fullLast >= 0) {
                int clippedLast = min(fullLast, ySplit);

                if (clippedLast >= 0) {
                    ans += width[clippedLast] * y;
                }

                int startNormal = clippedLast + 1;

                if (startNormal <= fullLast) {
                    ans += prefixSum[fullLast + 1] - prefixSum[startNormal];
                }
            }

            if (xSplit < k && width[xSplit] > x) {
                long long startWidth = (xSplit == 0 ? 0 : width[xSplit - 1]);

                if (x > startWidth) {
                    long long partialWidth = x - startWidth;
                    long long partialHeight = min(y, height[xSplit]);

                    ans += partialWidth * partialHeight;
                }
            }

            cout << ans << "\n";
        }
    }
}