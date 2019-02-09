#include <iostream>
#include <queue>

#define cell pair<int, int>

using namespace std;

char arr[111][111];
bool vis[111][111];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
string dir[] = {"U", "L", "D", "R"};

string bfs(cell s, cell t) {
    queue<pair<cell, string>> q;
    q.push(make_pair(s, ""));
    vis[s.first][s.second] = true;
    while (!q.empty()) {
        pair<cell, string> v = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (!vis[v.first.first + dx[i]][v.first.second + dy[i]]) {
                vis[v.first.first + dx[i]][v.first.second + dy[i]] = true;
                if ((v.first.first + dx[i]) == t.first &&
                    (v.first.second + dy[i]) == t.second) {
                    return v.second + dir[i];
                }
                if (arr[v.first.first + dx[i]][v.first.second + dy[i]] == '.') {
                    q.push(make_pair(make_pair(v.first.first + dx[i], v.first.second + dy[i]), (v.second + dir[i])));
                }
            }
        }
    }
    return "";
}

int main() {

    ios::sync_with_stdio(false);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        arr[i][0] = '#';
        arr[i][m + 1] = '#';
    }

    for (int i = 1; i <= m; i++) {
        arr[0][i] = '#';
        arr[n + 1][i] = '#';
    }

    cell s, t;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                arr[i][j] = '.';
            }
            if (c == 'S') {
                s.first = i;
                s.second = j;
                arr[i][j] = '.';
            }
            if (c == 'T') {
                t.first = i;
                t.second = j;
                arr[i][j] = '.';
            }
            if (c == '#') {
                arr[i][j] = '#';
            }
        }
    }

    string path = bfs(s, t);

    if (path.length() == 0) {
        cout << -1;
        return 0;
    }

    cout << path.length() << endl;

    cout << path;

    return 0;
}