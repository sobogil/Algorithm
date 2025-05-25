#include <bits/stdc++.h>
using namespace std;

int n;
vector<char> ops = {' ', '+', '-'};

void dfs(int idx, string expr) {
    if (idx > n) {
        string evalExpr = "";
        for (char ch : expr) {
            if (ch != ' ') evalExpr += ch;
        }

        int sum = 0;
        int num = 0;
        char op = '+';
        for (int i = 0; i < evalExpr.size(); i++) {
            if (isdigit(evalExpr[i])) {
                num = num * 10 + (evalExpr[i] - '0');
            }
            if (!isdigit(evalExpr[i]) || i == evalExpr.size() - 1) {
                if (op == '+') sum += num;
                else if (op == '-') sum -= num;
                op = evalExpr[i];
                num = 0;
            }
        }

        if (sum == 0) {
            cout << expr << '\n';
        }
        return;
    }

    for (char op : ops) {
        dfs(idx + 1, expr + op + to_string(idx));
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        dfs(2, "1");
        cout << '\n';
    }
    return 0;
}