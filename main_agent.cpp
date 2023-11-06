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


// toos function
void toss(string name){
   
    // Create a random number generator engine
    random_device rd;  // Obtain a random seed from the hardware
    mt19937 rng(rd()); // Mersenne Twister engine seeded with rd()

    // Define the range
    int min_value = 1;
    int max_value = 1000;

    // Create a distribution that generates numbers within the range [min_value, max_value]
    uniform_int_distribution<int> distribution(min_value, max_value);

    // Generate a random number within the specified range
    int random_number = distribution(rng);
      
    // check who will start first
    if(random_number&1){
        cout<<name<<" won the toss  \n";
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
    cout<<"computer"<<" won the toss \n";
    playerTurn = false;
    tokencomp='X';
    token='O';
    
       if(tokencomp=='X'){
          mp['X']="computer";
          mp['O']=name;
        }
    }

}

// Function to display the Tic Tac Toe board
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
void displayBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout<<endl;
    }
}


// Function to check if the board is full
bool isBoardFull(const vector<vector<char>>& board) {
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
int evaluateBoard(const vector<vector<char>>& board) {
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
int minimax(vector<vector<char>>& board, int depth, bool isMaximizer) {
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
cout<<"Tic Tac Toe Game: Human vs AI Agent \n";
cout<<"----------------------------------- \n";
  int cntwin=0;
  int cnt_draw=0;;
  int cnt_total=0;
   //input the name of the player
   cout<<"Enter your name : \n";
   cin>>name;
while(true){
 int choice_st;
    cout<<"1.enter 1 to play series \n";
    cout<<"2.enter 2 to exit \n";
    cin>>choice_st;
  
if(choice_st==1){
    cnt_total++;

toss(name);
grid();
 vector<vector<char>> board(3, vector<char>(3, EMPTY_CELL));
    while (true) {
        displayBoard(board);

        if (playerTurn) {
            cout<<"your trun:\n";
            int row, col;
            int choice;
            cout<<"1.enter 1 to play match \n";
            cout<<"2.enter 2 to exit \n";
            cin>>choice;
            if(choice==1){
        cout << mp[token]<<"'s turn. Enter row number and column number within given range (0-2): ";
        cin >> row >> col;
            if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != EMPTY_CELL) {
            cout << "Invalid move. Try again." <<endl;
                continue;
            }

            board[row][col] = token;
        }
         else {
         cout<<"computer win:" <<endl;
            break;
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
        else{
           cout << "computer's turn:" <<endl;
            makeAIMove(board);
              if (evaluateBoard(board) == 10) {
            displayBoard(board);
            cout << "Computer wins!!!" <<endl;
            break;
        } 
        else if (evaluateBoard(board) == -10) {
            displayBoard(board);
            cout << "You win!!!" <<endl;
            cntwin++;
            break;
        } 
        else if (isBoardFull(board)) {
            displayBoard(board);
            std::cout << "It's a draw!" << std::endl;
            cnt_draw++;
            break;
        }

          playerTurn = !playerTurn;
        }
    }
}
  
else{
 
    cout<<"Total number of games played : "<<cnt_total<<endl;
    cout<<"Total number of games won by You : "<<cntwin<<endl;
    cout<<"Total number of games draw : "<<cnt_draw<<endl;
    cout<<"Thank you for playing! have a peaceful day \n"<<endl;
    exit(0);
}
}
    return 0;
}