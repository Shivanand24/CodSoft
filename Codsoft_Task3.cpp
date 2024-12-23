#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>   
using namespace std;

void display_board(const vector<vector<char>>& board) {
    cout << "+-------+-------+-------+" << endl;
    for (int row = 0; row < 3; row++) {
        cout << "|       |       |       |" << endl;
        for (int col = 0; col < 3; col++) {
            cout << "|   " << board[row][col] << "   ";
        }
        cout << "|" << endl;
        cout << "|       |       |       |" << endl;
        cout << "+-------+-------+-------+" << endl;
    }
}

char check_win(const vector<vector<char>>& board) {
    
    int win_conditions[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, 
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, 
        {0, 4, 8}, {2, 4, 6}             
    };

    for (const auto& condition : win_conditions) {
        if (board[condition[0] / 3][condition[0] % 3] == board[condition[1] / 3][condition[1] % 3] &&
            board[condition[1] / 3][condition[1] % 3] == board[condition[2] / 3][condition[2] % 3] &&
            board[condition[0] / 3][condition[0] % 3] != ' ') {
            return board[condition[0] / 3][condition[0] % 3];
        }
    }
    return ' ';
}

bool is_full(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell >= '1' && cell <= '9') {
                return false;
            }
        }
    }
    return true;
}

bool check_move(const vector<vector<char>>& board, int move) {
    if (move < 1 || move > 9) {
        return false;
    }
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    return board[row][col] >= '1' && board[row][col] <= '9';
}

void make_move(vector<vector<char>>& board, int move, char player) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = player;
}

void computer_move(vector<vector<char>>& board) {
    while (true) {
        int move = rand() % 9 + 1; 
        if (check_move(board, move)) {
            make_move(board, move, 'X');
            break;
        }
    }
}

void game() {
    vector<vector<char>> board = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    while (true) {
        display_board(board);
        int move;
        cout << "Enter your move (1-9) or 0 to quit: ";
        cin >> move;

        if (move == 0) {
            cout << "Goodbye!" << endl;
            break;
        }

        if (check_move(board, move)) {
            make_move(board, move, 'O');
            char winner = check_win(board);
            if (winner != ' ') {
                display_board(board);
                cout << "You won!" << endl;
                break;
            } else if (is_full(board)) {
                display_board(board);
                cout << "It's a tie!" << endl;
                break;
            }

            computer_move(board);
            winner = check_win(board);
            if (winner != ' ') {
                display_board(board);
                cout << "Computer won!" << endl;
                break;
            } else if (is_full(board)) {
                display_board(board);
                cout << "It's a tie!" << endl;
                break;
            }
        } else {
            cout << "Invalid move, try again." << endl;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); 
    game();
    return 0;
}