#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void check_values_iterative(map<string, vector<string>> &devices, ll &answer)
{
    string start = "you", end = "out";
    vector<string> keys_to_check = {start};

    while (true)
    {
        vector<string> new_keys;
        for (const auto &el : keys_to_check)
        {
            if (el == end)
                answer++;
            else
            {
                const auto temp = devices[el];
                new_keys.insert(new_keys.end(), devices[el].begin(), devices[el].end());
            }
        }
        keys_to_check = new_keys;
        if (new_keys.size() < 1)
            break;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 613;
    ll answer = 0;
    map<string, vector<string>> devices;

    while (n--)
    {
        string temp, temp2;
        vector<string> values;

        getline(cin, temp);

        size_t pos = temp.find(':');
        string map_key = temp.substr(0, pos);
        string value_string = temp.substr(pos + 1);

        stringstream ss(value_string);

        while (getline(ss, temp2, ' '))
            if (temp2 != "")
                values.push_back(temp2);

        devices.insert({map_key, values});
    }

    check_values_iterative(devices, answer);
    cout << answer << endl;

    return 0;
}