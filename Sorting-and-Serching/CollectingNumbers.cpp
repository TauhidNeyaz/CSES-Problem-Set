#include <iostream>
#include <vector>
using namespace std;

int countRounds(const vector<int>& arr, int n) {

    vector<int> idx(n+1);
    for (int i = 0; i < arr.size(); ++i) {
        idx[arr[i]] = i;
    }

    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if (idx[i+1] < idx[i])
            ++ans;
    }

    return ans;

}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    
    cout << countRounds(arr, n) << endl;

    return 0;
}
