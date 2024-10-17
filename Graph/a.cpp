#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n;
        cin >> n;

        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        long long result = 0;

        // Forward direction
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 99 && i + j <= n; j++) {
                int idx2 = i + j;
                int diff = abs(arr[i] - arr[idx2]);

                if (diff < j) continue;

                if (diff == j) {
                    result += j + 1;
                } else if (diff > j && (diff - j) % 2 == 0) {
                    long long mid1 = (i + idx2 - diff) / 2;
                    if ((i + idx2 - diff) % 2 == 0 && mid1 >= 1 && mid1 <= n) {
                        result += 1;
                    }

                    long long mid2 = (i + idx2 + diff) / 2;
                    if ((i + idx2 + diff) % 2 == 0 && mid2 >= 1 && mid2 <= n) {
                        result += 1;
                    }
                }
            }
        }

        // Backward direction
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 99 && i - j >= 1; j++) {
                int idx2 = i - j;
                int diff = abs(arr[i] - arr[idx2]);

                if (diff < j) continue;

                if (diff == j) {
                    result += j + 1;
                } else if (diff > j && (diff - j) % 2 == 0) {
                    long long mid1 = (i + idx2 - diff) / 2;
                    if ((i + idx2 - diff) % 2 == 0 && mid1 >= 1 && mid1 <= n) {
                        result += 1;
                    }

                    long long mid2 = (i + idx2 + diff) / 2;
                    if ((i + idx2 + diff) % 2 == 0 && mid2 >= 1 && mid2 <= n) {
                        result += 1;
                    }
                }
            }
        }

        cout << result << "\n";
    }

    return 0;
}
