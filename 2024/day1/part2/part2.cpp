#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 1000;
    ll answer = 0;
    vector<int> a;
    vector<int> b;

    while (n--)
    {
        int q, w;
        cin >> q >> w;
        a.push_back(q);
        b.push_back(w);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (const auto &el : a)
    {
        int q = count(b.begin(), b.end(), el);
        answer += (q * el);
    }

    cout << answer << endl;
    return 0;
}
