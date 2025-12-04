#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;

// should be ran in release mode..

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 25;
    string s, temp;
    vector<string> stones;

    getline(cin, s);
    stringstream ss(s);

    while (getline(ss, temp, ' '))
        stones.push_back(temp);

    while (n--)
    {
        int plus = 0;
        vector<string> new_vec(stones.size());

        for (int i = 0; i < stones.size(); i++)
        {
            auto &ref = stones[i];
            ll digitEl = stoll(ref);

            if (digitEl == 0)
                new_vec[i + plus] = "1";

            else if (ref.size() % 2 == 0)
            {
                size_t end = ref.size() / 2;
                string a = string(ref.begin(), ref.begin() + end);
                string b = string(ref.begin() + end, ref.end());

                // ensure leading zeroes are removed
                const ll temp1 = stoll(a);
                const ll temp2 = stoll(b);

                new_vec[i + plus] = to_string(temp1);
                new_vec.insert(new_vec.begin() + (i + plus + 1), to_string(temp2));
                plus++;
            }

            else
            {
                ll value = digitEl * 2024;
                new_vec[i + plus] = to_string(value);
            }
        }

        stones = new_vec;
    }

    cout << stones.size() << "\n";

    return 0;
}