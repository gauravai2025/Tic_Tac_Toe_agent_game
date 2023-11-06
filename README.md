
# Tic Tac Toe Game Agent with Minimax Algorithm

![Tic Tac Toe Screenshot](screenshot.png)

This project implements a Tic Tac Toe game agent using the Minimax algorithm. The Minimax algorithm is a decision-making algorithm commonly used in two-player games to determine the optimal move for a player.

## Features

- Play against a computer-based Tic Tac Toe game agent.
- The game agent uses the Minimax algorithm to make optimal moves.
- Interactive command-line interface for playing the game.

## How it Works

The Minimax algorithm is a recursive algorithm that explores all possible game states by simulating moves for both players. It assigns a score to each possible move and chooses the move with the highest score when it's the computer's turn or the move with the lowest score when it's the opponent's turn.

The algorithm uses the following steps:

1. If it's the computer's turn, loop through available moves, simulate each move, and call the Minimax function recursively for the opponent's turn.
2. If it's the opponent's turn, loop through available moves, simulate each move, and call the Minimax function recursively for the computer's turn.
3. Evaluate and return the best move with the highest score for the computer or the lowest score for the opponent.
   
## working of Project

1.Define Grid 
<br>
2.Enter name of player
<br>
3. Player have option to play series of game or exit. <br>
4. Toss will be done by generating random positive number.First move decided by even or odd number. If odd number generate then  player will play first otherwise computer will make first move.<br>
5.If player won the toss then have to select character X or O, otherwise agent is ssigned with X <br>
6.After each move, grid is evaluated to decide winner.<br>
7. If winner is decide for a game then player will have option to play another match or exit.<br> 
8. After series of games is finished then print total games played, number of match won by player and number of match drawn. 


