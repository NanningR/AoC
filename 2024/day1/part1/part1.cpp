#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 1000;
    int answer = 0;
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

    for (int i = 0; i < a.size(); i++)
    {
        int low = min(a[i], b[i]);
        int high = max(a[i], b[i]);
        const int dif = high - low;
        answer += dif;
    }

    cout << answer << endl;
    return 0;
}
