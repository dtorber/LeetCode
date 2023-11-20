class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>> pendents;
        int n = maze.size(), m = maze[0].size(), i, j;
        int distancia[n][m];
        vector<int> actual;

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) 
                distancia[i][j] = INT_MAX;
        }

        distancia[entrance[0]][entrance[1]] = 0;
        pendents.push(entrance);

        while (pendents.size() > 0) {
            actual = pendents.front();
            pendents.pop();
            i = actual[0];
            j = actual[1];

            //si ja es un borde i no te mur hem arribat a l'eixida mes propera
            if ((i == n - 1 || j == m - 1 || i == 0 || j == 0) && maze[i][j] == '.' && i != entrance[0] && j != entrance[1]) return distancia[i][j];

            if (i + 1 < n && maze[i + 1][j] == '.' && distancia[i + 1][j] > distancia[i][j] + 1) {
                vector<int> aux;
                aux.push_back(i + 1);
                aux.push_back(j);
                pendents.push(aux);
                distancia[i + 1][j] = distancia[i][j] + 1;
            }
            if (i - 1 >= 0 && maze[i - 1][j] == '.' && distancia[i - 1][j] > distancia[i][j] + 1) {
                vector<int> aux;
                aux.push_back(i - 1);
                aux.push_back(j);
                pendents.push(aux);
                distancia[i - 1][j] = distancia[i][j] + 1;
            }
            if (i + 1 < n && maze[i][j + 1] == '.' && distancia[i][j + 1] > distancia[i][j] + 1) {
                vector<int> aux;
                aux.push_back(i);
                aux.push_back(j + 1);
                pendents.push(aux);
                distancia[i][j + 1] = distancia[i][j] + 1;
            }
            if (i + 1 < n && maze[i][j - 1] == '.' && distancia[i][j - 1] > distancia[i][j] + 1) {
                vector<int> aux;
                aux.push_back(i);
                aux.push_back(j - 1);
                pendents.push(aux);
                distancia[i][j - 1] = distancia[i][j] + 1;
            }
        }

        return -1;
    }
};