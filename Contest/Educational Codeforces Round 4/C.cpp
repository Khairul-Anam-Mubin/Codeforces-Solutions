#include <bits/stdc++.h>
using namespace std;

bool IsOpen(char ch) {
    if (ch == '<' || ch == '{' || ch == '(' || ch == '[') return 1;
    return 0;
}
bool IsBalance(string str) {
    int len = str.size();
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (IsOpen(str[i])) cnt++;
        else cnt--;
        if (cnt < 0) return 0;
    }
    if (cnt == 0) return 1;
    return 0;
} 
char ReverseExpression(char ch) {
    if (ch == '}') return '{';
    if (ch == '>') return '<';
    if (ch == ']') return '[';
    if (ch == ')') return '(';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    if (!IsBalance(s)) {
        cout << "Impossible\n";
        return 0;
    }
    int ans = 0;
    stack <char> stk;
    for (char c: s) {
        if (IsOpen(c)) {
            stk.push(c);
        } else {
            if (stk.top() != ReverseExpression(c)) {
                ans++;
            } 
            stk.pop();
        }
    }
    cout << ans << "\n";
    return 0;
}