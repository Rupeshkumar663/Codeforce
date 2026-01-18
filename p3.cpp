#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

// Direction constants
const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;

// Direction vectors for row and column changes
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// State of the light beam (row, col, entry_direction)
struct State {
    int r, c, dir;

    bool operator<(const State& other) const {
        if (r != other.r) return r < other.r;
        if (c != other.c) return c < other.c;
        return dir < other.dir;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    int max_cells = 0;

    // Iterate through all possible starting cells and directions
    for (int r_start = 0; r_start < m; ++r_start) {
        for (int c_start = 0; c_start < n; ++c_start) {
            // Only start a traversal from a mirror
            if (grid[r_start][c_start] == '0') {
                continue;
            }

            for (int d_start = 0; d_start < 4; ++d_start) {
                set<State> path_states;
                set<pair<int, int>> path_cells;

                int r = r_start;
                int c = c_start;
                int direction = d_start;

                while (r >= 0 && r < m && c >= 0 && c < n) {
                    State current_state = {r, c, direction};

                    // Check for a loop (same cell and same entry direction)
                    if (path_states.count(current_state)) {
                        max_cells = max(max_cells, (int)path_cells.size());
                        break;
                    }

                    // Add current state to path tracking
                    path_states.insert(current_state);
                    path_cells.insert({r, c});

                    // Update direction based on cell content
                    char cell_type = grid[r][c];
                    if (cell_type == '/') {
                        if (direction == UP) direction = RIGHT;
                        else if (direction == DOWN) direction = LEFT;
                        else if (direction == LEFT) direction = DOWN;
                        else if (direction == RIGHT) direction = UP;
                    } else if (cell_type == '\\') {
                        if (direction == UP) direction = LEFT;
                        else if (direction == DOWN) direction = RIGHT;
                        else if (direction == LEFT) direction = UP;
                        else if (direction == RIGHT) direction = DOWN;
                    }
                    // For '0', direction remains unchanged

                    // Move to the next cell
                    r += dr[direction];
                    c += dc[direction];
                }
            }
        }
    }

    cout << max_cells << endl;

    return 0;
}