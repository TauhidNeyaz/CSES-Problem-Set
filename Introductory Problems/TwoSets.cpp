#include <bits/stdc++.h>
using namespace std;

int main() {
    int num; 
    cin >> num;

    // Calculate the total sum of first `num` natural numbers
    long long total_sum = 1LL * num * (num + 1) / 2;

    // If the total sum is odd, it is impossible to split it into two equal parts
    if (total_sum % 2 != 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        long long half_sum = total_sum / 2;
        vector<int> mark(num + 1, 0);  // To mark the elements in the first subset

        int idx = num;
        long long size = 0;

        // Fill the first subset greedily from the largest element down to 1
        while (half_sum > 0) {
            if (half_sum >= idx) {
                half_sum -= idx;
                mark[idx] = 1;  // Mark the element as part of the first subset
                ++size;  // Increment size of the first subset
            }
            --idx;
        }

        // Output the size of the first subset
        cout << size << endl;

        // Output the elements of the first subset
        for (int i = 1; i <= num; ++i) {
            if (mark[i]) cout << i << " ";
        }
        cout << endl;

        // Output the size of the second subset
        cout << num - size << endl;

        // Output the elements of the second subset
        for (int i = 1; i <= num; ++i) {
            if (!mark[i]) cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
