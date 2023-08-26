#include<bits/stdc++.h>
using namespace std;
 // define the grid

int row;
int column;
// define the tokens for agent
char tokencomp='X';
char token;
// define the player
string name;

bool playerTurn = false; // false for player decide who will start first by toss
bool tie1=false;
// map the tokens to the player
unordered_map<char,string> mp;

const char EMPTY_CELL = ' ';
// define the empty cell
 vector<vector<char>> board(3, std::vector<char>(3, EMPTY_CELL));

 //input the name of the player
void toss(){
    cout<<"Enter your name : \n";
    cin>>name;
    // Create a random number generator engine
    std::random_device rd;  // Obtain a random seed from the hardware
    std::mt19937 rng(rd()); // Mersenne Twister engine seeded with rd()

    // Define the range
    int min_value = 1;
    int max_value = 1000;

    // Create a distribution that generates numbers within the range [min_value, max_value]
    std::uniform_int_distribution<int> distribution(min_value, max_value);

    // Generate a random number within the specified range
    int random_number = distribution(rng);
      
    // check who will start first
    if(random_number&1){
        cout<<name<<" will start first \n";
        cout<<"choose your token X or O \n";
        cin>>token;

    while(token!='X' && token!='O'){
        cout<<"Invalid token \n";
        cout<<"choose your token X or O \n";
        cin>>token;
    }

        playerTurn=true;

        if(token=='X')
        tokencomp='O';
        else
        tokencomp='X';

// // check if the token is valid or not


        if(token=='X'){
          mp['X']=name;
          mp['O']="computer";
        }
            
            else{
                mp['X']="computer";
                mp['O']=name;
    
            }
    }
    
    else{
    cout<<"computer"<<" will start first \n";
    tokencomp='X';
    token='O';
    
       if(tokencomp=='X'){
          mp['X']="computer";
          mp['O']=name;
        }
    }


  
}




void grid()
{

  // define grid graphically
 cout<<"overview of grid \n";
cout<<"     |   |    "<<endl;
cout<<" 0,0 |0,1|0,2 "<<endl;
cout<<"_____|___|___ "<<endl;
cout<<" 1,0 |1,1|1,2 "<<endl;
cout<<"_____|___|___ "<<endl;
cout<<" 2,0 |2,1|2,2 "<<endl;
cout<<"     |   |    "<<endl;



}

// Function to display the Tic Tac Toe board
void displayBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout<<endl;
    }
}


// Function to check if the board is full
bool isBoardFull(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == EMPTY_CELL) {
                return false;
            }
        }
    }
    return true;
}


// Function to evaluate the board for the minimax algorithm
int evaluateBoard(const std::vector<std::vector<char>>& board) {
    // Check rows, columns, and diagonals for wins
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) && board[i][0] != EMPTY_CELL) {
            return (board[i][0] == tokencomp) ? 10 : -10;
        }
        if ((board[0][i] == board[1][i] && board[1][i] == board[2][i]) && board[0][i] != EMPTY_CELL) {
            return (board[0][i] == tokencomp) ? 10 : -10;
        }
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) && board[0][0] != EMPTY_CELL) {
        return (board[0][0] == tokencomp) ? 10 : -10;
    }
    if ((board[0][2] == board[1][1] && board[1][1] == board[2][0]) && board[0][2] != EMPTY_CELL) {
        return (board[0][2] ==tokencomp) ? 10 : -10;
    }
    return 0; // No winner
}



// Minimax algorithm
int minimax(std::vector<std::vector<char>>& board, int depth, bool isMaximizer) {
    int score = evaluateBoard(board);

    if (score == 10) {
        return score - depth; // Higher scores for faster wins
    }
    if (score == -10) {
        return score + depth; // Lower scores for faster losses
    }
    if (isBoardFull(board)) {
        return 0; // Draw
    }

    if (isMaximizer) {
        int bestScore = -1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == EMPTY_CELL) {
                    board[i][j] = tokencomp;
                    bestScore = std::max(bestScore, minimax(board, depth + 1, false));
                    board[i][j] = EMPTY_CELL;
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == EMPTY_CELL) {
                    board[i][j] = token;
                    bestScore = std::min(bestScore, minimax(board, depth + 1, true));
                    board[i][j] = EMPTY_CELL;
                }
            }
        }
        return bestScore;
    }
}

// Function to make the AI's move using the Minimax algorithm
void makeAIMove(vector<vector<char>>& board) {
    int bestScore = -1000;
    int bestMoveRow = -1;
    int bestMoveCol = -1;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == EMPTY_CELL) {
                board[i][j] = tokencomp;
                int score = minimax(board, 0, false);
                board[i][j] = EMPTY_CELL;

                if (score > bestScore) {
                    bestScore = score;
                    bestMoveRow = i;
                    bestMoveCol = j;
                }
            }
        }
    }

    board[bestMoveRow][bestMoveCol] = tokencomp;
}


int main(){
toss();
grid();

    while (true) {
        displayBoard(board);

        if (playerTurn) {
            int row, col;
        cout << mp[token]<<"'s turn. Enter row number and column number within given range (0-2): ";
        cin >> row >> col;
            if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != EMPTY_CELL) {
            cout << "Invalid move. Try again." <<endl;
                continue;
            }

            board[row][col] = token;
        }
         else {
        cout << "computer's turn:" <<endl;
            makeAIMove(board);
        }

        if (evaluateBoard(board) == 10) {
            displayBoard(board);
            cout << "Computer wins!!!" <<endl;
            break;
        } else if (evaluateBoard(board) == -10) {
            displayBoard(board);
            cout << "You win!!!" <<endl;
            break;
        } else if (isBoardFull(board)) {
            displayBoard(board);
            std::cout << "It's a draw!" << std::endl;
            break;
        }

        playerTurn = !playerTurn;
    }

    return 0;
}