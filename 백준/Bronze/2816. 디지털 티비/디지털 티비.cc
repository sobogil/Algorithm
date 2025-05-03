#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> channels(n);
    for (int i = 0; i < n; ++i) {
        cin >> channels[i];
    }

    string result;
    int pointer = 0;

    int idx1 = find(channels.begin(), channels.end(), "KBS1") - channels.begin();
    while (pointer < idx1) {
        result += '1'; 
        pointer++;
    }
    while (pointer > 0) {
        result += '4'; 
        swap(channels[pointer], channels[pointer - 1]);
        pointer--;
    }

    int idx2 = find(channels.begin(), channels.end(), "KBS2") - channels.begin();
    if (idx2 == 0) idx2 = 1;

    pointer = 0;
    while (pointer < idx2) {
        result += '1'; 
        pointer++;
    }
    while (pointer > 1) {
        result += '4'; 
        swap(channels[pointer], channels[pointer - 1]);
        pointer--;
    }

    cout << result << '\n';
}