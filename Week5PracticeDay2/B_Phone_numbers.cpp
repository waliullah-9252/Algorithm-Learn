#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string phoneNumber;

    cin >> n >> phoneNumber;

    string result = "";

    int i = 0;
    while (i <= n) {
        if (n - i >= 4) {
            result += phoneNumber.substr(i, 2) + "-";
            i += 2;
        } else {
            result += phoneNumber.substr(i, 3);
            i += 3;
        }
    }

    cout << result << endl;

    return 0;
}
