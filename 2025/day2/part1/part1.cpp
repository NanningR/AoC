#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll answer = 0;
    char del = ',', del2 = '-';

    string input, temp, temp2;
    getline(cin, input);
    stringstream ss(input);
    vector<ll> numbers;

    while (getline(ss, temp, del))
    {
        stringstream ss2(temp);
        while (getline(ss2, temp2, del2))
        {
            numbers.push_back(stol(temp2));
        }
    }

    for (int i = 0; i <= numbers.size() - 1; i += 2)
    {
        ll num = numbers[i];
        ll stop = numbers[i + 1];

        while (num <= stop)
        {
            string strnum = to_string(num);
            int length = strnum.size();
            if (length % 2 > 0)
            {
                num++;
                continue;
            }
            string part1 = strnum.substr(0, length / 2);
            string part2 = strnum.substr(length / 2);
            if (part1 == part2)
                answer += num;
            num++;
        }
    }

    cout << answer << endl;

    return 0;
}