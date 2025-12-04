#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pi = pair<int, int>;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll largest_area = 0;
    int n = 496, index = 0;
    vector<pi> inputs;

    while (n--)
    {
        string temp, temp2;
        cin >> temp;

        stringstream ss(temp);
        vector<int> numbers;

        while (getline(ss, temp2, ','))
            numbers.push_back(stoi(temp2));

        inputs.push_back({numbers[0], numbers[1]});
    }

    for (int i = 0; i < inputs.size(); i++)
    {
        pi pair_to_check = inputs[i];
        for (int j = 0; j < i; j++)
        {
            pi pair_to_compare = inputs[j];
            vector<ll> x_values, y_values;
            x_values.push_back(pair_to_check.first);
            x_values.push_back(pair_to_compare.first);
            y_values.push_back(pair_to_check.second);
            y_values.push_back(pair_to_compare.second);

            sort(x_values.begin(), x_values.end());
            sort(y_values.begin(), y_values.end());

            ll computed_area = (x_values[1] - x_values[0] + 1) * (y_values[1] - y_values[0] + 1);
            if (computed_area > largest_area)
                largest_area = computed_area;
        }
    }

    cout << largest_area << endl;

    return 0;
}