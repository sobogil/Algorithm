#include<bits/stdc++.h>
using namespace std;

int n,d,k,c,a[30001];

int main(){
    cin >> n >> d >> k >> c;
    vector<int> sushi(n);
    for (int i = 0; i < n; ++i) {
        cin >> sushi[i];
    }

    vector<int> count(d + 1, 0); 
    int unique_count = 0;

    for (int i = 0; i < k; ++i) {
        if (count[sushi[i]] == 0) unique_count++;
        count[sushi[i]]++;
    }

    int result = unique_count + (count[c] == 0 ? 1 : 0);

    for (int i = 1; i < n; ++i) {
        int remove = sushi[i - 1];
        int add = sushi[(i + k - 1) % n];

        count[remove]--;
        if (count[remove] == 0) unique_count--;

        if (count[add] == 0) unique_count++;
        count[add]++;

        int total = unique_count + (count[c] == 0 ? 1 : 0);
        result = max(result, total);
    }

    cout << result << '\n';
}