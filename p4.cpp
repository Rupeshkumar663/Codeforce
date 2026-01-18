#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Maps characters to their 3x3 matrix representation.
map<char, vector<string>> segments;

// Populates the segments map with the 7-segment display patterns.
void setup_segments() {
    segments['0'] = {" _ ", "| |", "|_|"};
    segments['1'] = {"   ", "  |", "  |"};
    segments['2'] = {" _ ", " _|", "|_ "};
    segments['3'] = {" _ ", " _|", " _|"};
    segments['4'] = {"   ", "|_|", "  |"};
    segments['5'] = {" _ ", "|_ ", " _|"};
    segments['6'] = {" _ ", "|_ ", "|_|"};
    segments['7'] = {" _ ", "  |", "  |"};
    segments['8'] = {" _ ", "|_|", "|_|"};
    segments['9'] = {" _ ", "|_|", " _|"};
    segments['+'] = {"   ", " _ ", " _ "};
    segments['-'] = {"   ", " _ ", "   "};
    segments['*'] = {"   ", " _ ", " _ "}; // Simplified representation, treat same as +
    segments['%'] = {"   ", "   ", "   "}; // Simplified representation
    segments['='] = {"   ", " _ ", " _ "};
}

// Converts a 3x3 matrix to a single string for use as a map key.
string matrix_to_key(const vector<string>& matrix) {
    string key = "";
    for (const auto& row : matrix) {
        key += row;
    }
    return key;
}

// Evaluates a sequential equation from left to right.
bool evaluate_equation(const vector<char>& equation_chars, int rhs) {
    long long current_val = 0;
    char current_op = '+';
    
    for (size_t i = 0; i < equation_chars.size(); ++i) {
        if (isdigit(equation_chars[i])) {
            int num = equation_chars[i] - '0';
            if (current_op == '+') current_val += num;
            else if (current_op == '-') current_val -= num;
            else if (current_op == '*') current_val *= num;
            else if (current_op == '%') current_val %= num;
        } else {
            current_op = equation_chars[i];
        }
    }
    return current_val == rhs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    setup_segments();
    map<string, char> segment_map;
    for (const auto& pair : segments) {
        segment_map[matrix_to_key(pair.second)] = pair.first;
    }

    int n;
    cin >> n;
    cin.ignore(); // Consume the newline

    vector<string> input_lines(3);
    for (int i = 0; i < 3; ++i) {
        string line;
        getline(cin, line);
        input_lines[i] = line;
    }
    
    // Pad lines to ensure consistent length for parsing
    int expected_len = n * 3;
    for (int i = 0; i < 3; ++i) {
        if (input_lines[i].length() < expected_len) {
            input_lines[i].resize(expected_len, ' ');
        }
    }

    vector<vector<string>> char_matrices(n, vector<string>(3));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            char_matrices[i][j] = input_lines[j].substr(i * 3, 3);
        }
    }

    vector<char> original_chars(n);
    for (int i = 0; i < n; ++i) {
        original_chars[i] = segment_map[matrix_to_key(char_matrices[i])];
    }
    
    // Extract the RHS value
    string rhs_str = string(1, original_chars[n-1]);
    int rhs_val = stoi(rhs_str);

    // Iterate through each character (excluding RHS)
    for (int i = 0; i < n - 1; ++i) {
        vector<string> original_matrix = char_matrices[i];

        // Try toggling each of the potential 7 segment positions
        vector<pair<int, int>> toggle_positions = {
            {0, 1}, {1, 0}, {1, 2}, {1, 1}, {2, 0}, {2, 1}, {2, 2}
        };

        for (auto const& pos : toggle_positions) {
            int r = pos.first;
            int c = pos.second;
            
            vector<string> temp_matrix = original_matrix;
            
            if (temp_matrix[r][c] == ' ') {
                temp_matrix[r][c] = (r == 0 || r == 2) ? '_' : '|';
            } else {
                temp_matrix[r][c] = ' ';
            }

            string new_matrix_key = matrix_to_key(temp_matrix);

            if (segment_map.count(new_matrix_key)) {
                char new_char = segment_map[new_matrix_key];
                
                vector<char> temp_chars = original_chars;
                temp_chars[i] = new_char;
                
                // Evaluate the corrected equation
                if (evaluate_equation(temp_chars, rhs_val)) {
                    cout << i + 1 << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}