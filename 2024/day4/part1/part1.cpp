#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

namespace
{
    void countSub(string &temp, int &answer)
    {
        size_t offset = 0;
        while (temp.find("XMAS", offset) != string::npos)
        {
            const auto it = temp.find("XMAS", offset);
            answer++;
            offset = it + 1;
        }
    }

    void count(string &temp, int &answer)
    {
        countSub(temp, answer);
        std::ranges::reverse(temp);
        countSub(temp, answer);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int xy = 140, a = xy, index = 0, answer = 0;
    vector<vector<char>> matrix(xy);

    while (xy--)
    {
        string temp;
        cin >> temp;
        for (const auto &el : temp)
            matrix[index].push_back(el);
        index++;
    }

    // Find horizontal
    for (int i = 0; i < a; i++)
    {
        string temp;
        for (int j = 0; j < a; j++)
            temp += matrix[i][j];
        count(temp, answer);
    }

    // Find vertical
    for (int i = 0; i < a; i++)
    {
        string temp;
        for (int j = 0; j < a; j++)
            temp += matrix[j][i];
        count(temp, answer);
    }

    // Find diagonals (ugly code)
    for (int i = 0; i < a; i++)
    {
        string temp;
        int x = i, y = 0;
        while (x < a && y < a)
        {
            temp += matrix[x][y];
            x++;
            y++;
        }
        count(temp, answer);
    }

    for (int j = 1; j < a; j++)
    {
        string temp;
        int x = 0, y = j;
        while (x < a && y < a)
        {
            temp += matrix[x][y];
            x++;
            y++;
        }
        count(temp, answer);
    }

    for (int i = 0; i < a; i++)
    {
        string temp;
        int x = i, y = 0;
        while (x >= 0 && y < a)
        {
            temp += matrix[x][y];
            x--;
            y++;
        }
        count(temp, answer);
    }

    for (int j = 1; j < a; j++)
    {
        string temp;
        int x = a - 1, y = j;
        while (x >= 0 && y < a)
        {
            temp += matrix[x][y];
            x--;
            y++;
        }
        count(temp, answer);
    }

    cout << answer << "\n";

    return 0;
}
