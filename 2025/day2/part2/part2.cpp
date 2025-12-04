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
            vector<string> chunks_to_check;
            for (int j = 0; j < (strnum.size() / 2); j++)
            {
                string chunk = strnum.substr(j + 1, j + 1);
                chunks_to_check.push_back(strnum.substr(0, j + 1));
            }

            for (const auto &chunk : chunks_to_check)
            {
                bool valid = true;
                for (int k = chunk.size(); k < strnum.size(); k += chunk.size())
                {
                    string check_chunk = strnum.substr(k, chunk.size());
                    if (check_chunk != chunk)
                    {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                {
                    answer += num;
                    break;
                }
            }

            num++;
        }
    }

    cout << answer << endl;

    return 0;
}