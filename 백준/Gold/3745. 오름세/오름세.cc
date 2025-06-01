#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;

        int n = stoi(line);  
        vector<int> prices;

        getline(cin, line);
        stringstream ss(line);
        int x;
        while (ss >> x) prices.push_back(x);

        vector<int> lis;
        for (int price : prices) {
            auto it = lower_bound(lis.begin(), lis.end(), price);
            if (it == lis.end()) lis.push_back(price);
            else *it = price;
        }

        cout << lis.size() << '\n';
    }

    return 0;
}