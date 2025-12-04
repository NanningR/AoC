#include <cassert>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

namespace
{
    char obstacle = '#', visited = 'X';
    constexpr char up = '^', down = 'v', to_left = '<', to_right = '>';

    char direction = up;

    bool checkMoveValid(vector<vector<char>> const &matrix, pair<int, int> const &newPos)
    {
        return matrix[newPos.first][newPos.second] != obstacle;
    }

    void rotateDirection(char &currentDirection)
    {
        switch (currentDirection)
        {
        case up:
            currentDirection = to_right;
            break;
        case to_right:
            currentDirection = down;
            break;
        case down:
            currentDirection = to_left;
            break;
        case to_left:
            currentDirection = up;
            break;
        default:
            break;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int xy = 130, original = xy, index = 0, answer = 0;

    pair<int, int> position;
    vector<vector<char>> matrix(xy);
    set<pair<int, int>> visitedPositions;

    while (xy--)
    {
        string s;
        cin >> s;

        for (int i = 0; i < s.size(); i++)
        {
            const auto &_char = s[i];
            matrix[index].push_back(_char);

            if (_char == direction)
                position = {index, i};
        }
        index++;
    }

    while (true)
    {
        pair newPosition = {0, 0};
        auto const oldPosition = position;

        if (direction == up)
            newPosition = {position.first - 1, position.second};
        else if (direction == down)
            newPosition = {position.first + 1, position.second};
        else if (direction == to_left)
            newPosition = {position.first, position.second - 1};
        else if (direction == to_right)
            newPosition = {position.first, position.second + 1};
        else
            break;

        bool yValid = newPosition.first >= 0 && newPosition.first <= original - 1;
        bool xValid = newPosition.second >= 0 && newPosition.second <= original - 1;

        if (!(yValid && xValid))
            break;

        if (checkMoveValid(matrix, newPosition))
        {
            position = newPosition;
            matrix[oldPosition.first][oldPosition.second] = visited;
            matrix[newPosition.first][newPosition.second] = direction;

            bool alreadyVisited = false;
            for (auto const &el : visitedPositions)
                if (el.first == oldPosition.first && el.second == oldPosition.second)
                    alreadyVisited = true;

            if (!alreadyVisited)
            {
                answer++;
                visitedPositions.insert(oldPosition);
            }
        }

        else
            rotateDirection(direction);
    }

    // The last position is never counted
    answer++;
    cout << answer << "\n";

    return 0;
}
