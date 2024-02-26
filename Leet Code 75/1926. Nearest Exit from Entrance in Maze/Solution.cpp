class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> pendents;
        int n = maze.size(), m = maze[0].size(), i, j;
        int distancia[n][m];
        pair<int, int> actual;

        distancia[entrance[0]][entrance[1]] = 0;
        pendents.push({entrance[0], entrance[1]});

        while (pendents.size() > 0) {
            actual = pendents.front();
            pendents.pop();
            i = actual.first;
            j = actual.second;
            //si ja es un borde i no te mur hem arribat a l'eixida mes propera
            if ((i == n - 1 || j == m - 1 || i == 0 || j == 0) && !(i == entrance[0] && j == entrance[1])) return distancia[i][j];

            if (i + 1 < n && maze[i + 1][j] == '.') {
                pendents.push({i + 1, j});
                maze[i + 1][j] = '+';
                distancia[i + 1][j] = distancia[i][j] + 1;
            }
            if (i > 0 && maze[i - 1][j] == '.') {
                pendents.push({i - 1, j});
                maze[i - 1][j] = '+';
                distancia[i - 1][j] = distancia[i][j] + 1;
            }
            if (j + 1 < m && maze[i][j + 1] == '.') {
                pendents.push({i, j + 1});
                maze[i][j + 1] = '+';
                distancia[i][j + 1] = distancia[i][j] + 1;
            }
            if (j > 0 && maze[i][j - 1] == '.') {
                pendents.push({i, j - 1});
                maze[i][j - 1] = '+';
                distancia[i][j - 1] = distancia[i][j] + 1;
            }
        }

        return -1;
    }
};