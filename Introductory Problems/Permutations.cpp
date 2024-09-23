#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;

    vector<int> ans;

    if (n == 1) {
        cout << "1" << endl;
        return 0;
    }

    if (n <= 3) {
        cout << "NO SOLUTION";
        return 0;
    }

    if (n == 4) {
        cout<< "2 4 1 3"<<endl;
        return 0;
    }

    if (n % 2) {
        ans.resize(n);
        int mid = (n / 2);
        ans[mid] = n;
        int k = 0;

        for (int i = n - 1; i >= 2; i -= 2) {
            ans[k++] = i;
        }
        int l = mid + 1;
        for (int i = n - 2; i >= 1; i -= 2) {
            ans[l++] = i;
        }
    } else {
        for (int i = 1; i <= n; i += 2) {
            ans.push_back(i);
        }
        for (int i = 2; i <= n; i += 2) {
            ans.push_back(i);
        }
    }

    for (auto &i : ans) {
        cout << i << " ";
    }
    cout<<endl;

    
}