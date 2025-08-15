#include <bits/stdc++.h>
using namespace std;

// ================== 算法实现部分 ==================
class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.length(), MOD = 1e9 + 7;
        vector<vector<int>> f(n + 1, vector<int>(26, 0));
        for (int i = 1; i <= n; ++i) {
            int c = s[i - 1] - 'a';
            for (int j = 0; j < 26; ++j) {
                if (c != j) {
                    f[i][j] = f[i - 1][j];
                } else {
                    int cur = 1;
                    for (int k = 0; k < 26; ++k)
                        cur = (cur + f[i - 1][k]) % MOD;
                    f[i][j] = cur;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) ans = (ans + f[n][i]) % MOD;
        return ans;
    }
};

// ================== 自动化测试框架 ==================
struct TestCase {
    string input;
    int expected;
};

void runTests() {
    vector<TestCase> tests = {
        {"abc", 7},       // a,b,c,ab,ac,bc,abc
        {"aba", 6},       // a,b,aa,ab,ba,aba
        {"aaa", 3},       // a,aa,aaa
        {"abcd", 15}      // 所有非空子序列
    };

    Solution sol;
    int passed = 0;

    for (int i = 0; i < tests.size(); ++i) {
        int output = sol.distinctSubseqII(tests[i].input);
        bool ok = (output == tests[i].expected);
        cout << "Test " << i + 1 << ": "
             << "Input=\"" << tests[i].input << "\" "
             << "Expected=" << tests[i].expected << " "
             << "Output=" << output << " "
             << (ok ? "✅ Pass" : "❌ Fail") << "\n";
        if (ok) passed++;
    }

    cout << "\nSummary: " << passed << "/" << tests.size() << " passed.\n";
}

int main() {
    runTests();
    return 0;
}
