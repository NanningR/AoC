#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

namespace
{
    int iterations = 2000;

    ll mixAndPrune(ll secret)
    {
        ll temp = secret * 64;
        temp = temp ^ secret;
        temp %= 16777216;

        ll temp2 = round(temp / 32);
        temp2 = temp2 ^ temp;
        temp2 %= 16777216;

        ll result = temp2 * 2048;
        result = result ^ temp2;
        result %= 16777216;

        return result;
    }

    ll generateSecret(ll secret)
    {
        ll result = secret;
        for (int i = 0; i < 2000; i++)
            result = mixAndPrune(result);

        return result;
    }
}

int main()
{
    int n = 2374;
    ll answer = 0;

    vector<ll> numbers;
    vector<ll> secrets;

    while (n--)
    {
        numbers.emplace_back();
        cin >> numbers.back();
    }

    for (const auto &el : numbers)
    {
        ll temp = generateSecret(el);
        secrets.push_back(temp);
    }

    for (const auto &el : secrets)
        answer += el;

    cout << answer << '\n';

    return 0;
}
