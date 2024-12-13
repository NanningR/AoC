#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;

namespace
{
    ll findFirstIndex(vector<ll> const &elements)
    {
        const auto &it = ranges::find(elements, -1);
        return distance(elements.begin(), it);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;

    ll answer = 0;
    vector<ll> elements;

    for (size_t i = 0; i < s.size(); i++)
    {
        int num = s[i] - '0';
        const ll count = i / 2;

        if (num == 0)
            continue;
        const bool empty = i % 2 != 0;

        while (num--)
        {
            if (empty)
                elements.push_back(-1);
            else
                elements.push_back(count);
        }
    }

    for (size_t j = elements.size() - 1; j > 0; j--)
    {
        if (elements[j] == -1)
            continue;
        const auto index = findFirstIndex(elements);
        iter_swap(elements.begin() + j, elements.begin() + index);
    }

    // now we just remove the lone dot
    for (size_t i = 0; i < elements.size(); i++)
        if (elements[i] == -1)
            elements.erase(elements.begin() + i);

    for (size_t i = 0; i < elements.size(); i++)
    {
        const auto &num = elements[i];
        if (num == -1)
            break;
        answer += num * i;
    }

    cout << answer << "\n";

    return 0;
}
