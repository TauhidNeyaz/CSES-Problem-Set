#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    
    int n, m;
    cin >> n >> m;

    multiset<int> ticketPrices;
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        ticketPrices.insert(price);
    }

    for (int i = 0; i < m; i++) {
        int maxPrice;
        cin >> maxPrice;

        auto it = ticketPrices.upper_bound(maxPrice);
        if (it == ticketPrices.begin()) {
            cout << -1 << endl;
        } else {
            --it;
            cout << *it << endl;
            ticketPrices.erase(it);
        }
    }

    return 0;
}
