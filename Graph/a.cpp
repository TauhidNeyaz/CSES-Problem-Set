#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define vll vector<long long int>
#define vvll vector<vector<long long int>>
#define lb cout<<endl


void functionToSolve() {

    int n; cin >> n;
    vector<ll> v(n);

    for (auto &i : v) {
        cin>>i;
    }

    ll sum = 0;
    for (ll i = 0; i < n-2; ++i) {
        sum += v[i];
    }

    v[n-2] -= sum;

    cout << v[n-1] - v[n-2] << endl;

    
}

int main()
{
    
    int testCase; cin>>testCase;
    
    while (testCase--) {
        
        functionToSolve();
        
    }
    
    return 0;
    
}