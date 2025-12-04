/* NOT FUNCTIONAL
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using mmap = multimap<int, vector<int>>;

pi get_closest_keys(mmap const &box_positions)
{
    int last = 0, lowest = 1000;
    pi lowest_keys = {0, 0};

    for (const auto &[key, value] : box_positions)
    {
        int new_low = key - last;
        if (last > 0 && new_low < lowest)
        {
            lowest = new_low;
            lowest_keys = {key, last};
        }

        last = key;
    }

    return lowest_keys;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll answer = 0;
    multimap<int, vector<int>> box_positions;

    int box_count = 20, num_connections = 10;

    while (box_count--)
    {
        int added_together = 0;
        string temp, temp2;

        vector<int> coordinates;
        cin >> temp;

        stringstream ss(temp);
        while (getline(ss, temp2, ','))
        {
            int coordinate = stoi(temp2);
            coordinates.push_back(coordinate);
            added_together += coordinate;
        }

        box_positions.insert({added_together, coordinates});
    }

    pi closest = get_closest_keys(box_positions);

    cout << answer << endl;

    return 0;
}
*/