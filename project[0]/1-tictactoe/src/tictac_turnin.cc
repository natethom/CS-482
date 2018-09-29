#include <tictac_support.h>
#include <stdio.h>
#include <iostream>

using namespace std;
/**
	make_move: takes a board current_player and makes a legal
	(hopefully optimal) move

	args:
		int [][3] board: 3x3 array of ints representing the
		board current_player. The values of board are altered based
		on the move
			0: empty
			1: x
		 -1: o

	returns (int):
		the number of steps it took to choose the best move
		(current implementation returns 1 by default, 0 if no move made)
**/

#define NUM_ROWS 3
#define NUM_COLUMNS 3

int check_whose_turn(int board[][NUM_COLUMNS]){
	// figure out what move it is
	int current_player = 0;
	for( int i = 0; i < 3; i++ )
		for( int j = 0; j < 3; j++ )
			current_player += board[i][j];

	current_player = -current_player;
	if( current_player == 0 ){
		current_player = 1;
	}
	return current_player;
}

void copy_board(int board[][NUM_COLUMNS], int rhs_board[][NUM_COLUMNS]){
	for(int i = 0; i < 3; i++ ){
		for(int j = 0; j < 3; j++ ){
			board[i][j] = rhs_board[i][j];
		}
	}
}

void print_board(int board[][NUM_COLUMNS]){
	for(int i = 0; i < 3; i++ ){
		for(int j = 0; j < 3; j++ ){
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

bool check_for_win(int board[][NUM_COLUMNS], int current_player){
	int temp_board[NUM_ROWS][NUM_COLUMNS];
	bool won;
	for( int i = 0; i < 3; i++ ){
		for( int j = 0; j < 3; j++ ){
			if(board[i][j] == 0){
				copy_board(temp_board, board);
				temp_board[i][j] = current_player;

				//Check for vertical and horizontal victory
				for( int x = 0; x < 3; x++ ){
					won = true;
					for( int y = 0; y < 3; y++ ){
						if(temp_board[x][y] != current_player){
							won = false;
						}
					}
					if(won == true){
						board[i][j] = current_player;
						// cout << "CURRENT PLAYER WIN 1" << endl;
						return true;
					}
				}
				for( int y = 0; y < 3; y++ ){
					won = true;
					for( int x = 0; x < 3; x++ ){
						if(temp_board[x][y] != current_player){
							won = false;
						}
					}
					if(won == true){
						board[i][j] = current_player;
						// cout << "CURRENT PLAYER WIN 2" << endl;
						return true;
					}
				}
				//check for diagonal victories
				if(temp_board[0][0]==current_player&&temp_board[1][1]==current_player&&temp_board[2][2]==current_player){
					board[i][j] = current_player;
					// cout << "CURRENT PLAYER WIN 3" << endl;
					return true;
				}
				if(temp_board[0][2]==current_player&&temp_board[1][1]==current_player&&temp_board[2][0]==current_player){
					board[i][j] = current_player;
					// cout << "CURRENT PLAYER WIN 4" << endl;
					return true;
				}
			}
		}
	}
	return false;
}

bool check_for_opponent_win(int board[][NUM_COLUMNS], int opposing_player){
	int temp_board[NUM_ROWS][NUM_COLUMNS];
	bool won;
	for( int i = 0; i < 3; i++ ){
		for( int j = 0; j < 3; j++ ){
			if(board[i][j] == 0){
				copy_board(temp_board, board);
				temp_board[i][j] = opposing_player;

				//Check for vertical and horizontal victory
				for( int x = 0; x < 3; x++ ){
					won = true;
					for( int y = 0; y < 3; y++ ){
						if(temp_board[x][y] != opposing_player){
							won = false;
						}
					}
					if(won == true){
						board[i][j] = -opposing_player;
						// cout << "OPPOSING PLAYER WIN 1" << endl;
						return true;
					}
				}
				for( int y = 0; y < 3; y++ ){
					won = true;
					for( int x = 0; x < 3; x++ ){
						if(temp_board[x][y] != opposing_player){
							won = false;
						}
					}
					if(won == true){
						board[i][j] = -opposing_player;
						// cout << "OPPOSING PLAYER WIN 2" << endl;
						return true;
					}
				}
				//check for diagonal victories
				if(temp_board[0][0]==opposing_player&&temp_board[1][1]==opposing_player&&temp_board[2][2]==opposing_player){
					board[i][j] = -opposing_player;
					// cout << "OPPOSING PLAYER WIN 3" << endl;
					return true;
				}
				if(temp_board[0][2]==opposing_player&&temp_board[1][1]==opposing_player&&temp_board[2][0]==opposing_player){
					board[i][j] = -opposing_player;
					// cout << "OPPOSING PLAYER WIN 4" << endl;
					return true;
				}
			}
		}
	}
	return false;
}

int minimax(int board[][NUM_COLUMNS], int current_player){
	// print_board(board);
	int num_empty_spaces = 0;
	for(int i = 0; i < 3; i++ ){
		for(int j = 0; j < 3; j++ ){
			if(board[i][j] == 0){
				num_empty_spaces++;
			}
		}
	}
	//Basecase
	int temp_board[NUM_ROWS][NUM_COLUMNS];
	// cout << "MINIMAX NUM EMPTY SPACES: " << num_empty_spaces << endl;
	if(num_empty_spaces == 1 || num_empty_spaces == 0){
		//calculate board value
		if(current_player == 1){
			if(check_for_win(temp_board, current_player)){
				copy_board(temp_board, board);
				// cout <<	"LEAF 10" << endl;
				return 10;}
			else if(check_for_opponent_win(board, -current_player)){
				copy_board(temp_board, board);
				// cout <<	"LEAF -10" << endl;
				return -10;}
			else{
				// cout <<	"LEAF 0" << endl;
				return 0;}
		}
		else{
			if(check_for_win(temp_board, current_player)){
				copy_board(temp_board, board);
				// cout <<	"LEAF 10" << endl;
				return 10;}
			else if(check_for_opponent_win(board, -current_player)){
				copy_board(temp_board, board);
				// cout <<	"LEAF -10" << endl;
				return -10;}
			else{
				// cout <<	"LEAF 0" << endl;
				return 0;}
		}
	}
	else{
		int temp_board_value = -11;
		int max_board_value = -11;
		for(int i = 0; i < 3; i++ ){
			for(int j = 0; j < 3; j++ ){
				if(board[i][j] == 0){
					copy_board(temp_board, board);
					temp_board[i][j] = current_player;
					// cout << "MINIMAX PRE temp_board_value: " << temp_board_value << endl;
					temp_board_value = minimax(temp_board, -current_player);
					// cout << "MINIMAX POST temp_board_value: " << temp_board_value << endl;
					temp_board_value = -temp_board_value;
					if(temp_board_value > max_board_value){
						max_board_value = temp_board_value;
					}
				}
			}
		}
		return(max_board_value);
	}
}


int make_move( int board[][3] ){
	int current_player = check_whose_turn(board);
	int temp_board[3][3];
	int temp_board_value = -11;
	int max_board_value = -11;
	int max_board_coordinate_i = -1;
	int max_board_coordinate_j = -1;
	// cout << "Current Player: " << current_player << endl;

	if(check_for_win(board, current_player) == true){
		// cout << "OUTER CHECK IF I CAN WIN" << endl;
		return true;
	}
	else if(check_for_opponent_win(board, -current_player) == true){
		// cout << "OUTER CHECK IF OP CAN WIN" << endl;
		return true;
	}
	else{
		// cout << "FIND BEST MOVE" << endl;
		for(int i = 0; i < 3; i++ ){
			for(int j = 0; j < 3; j++ ){
				if(board[i][j] == 0){
					copy_board(temp_board, board);
					temp_board[i][j] = current_player;
					// cout << "OUTER TEMP BOARD VALUE: " << temp_board_value << endl;
					temp_board_value = minimax(temp_board, current_player);
					// cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
					// cout << "temp_board_value: " << temp_board_value << endl;
					if(temp_board_value > max_board_value){
						max_board_value = temp_board_value;
						max_board_coordinate_i = i;
						max_board_coordinate_j = j;
					}
				}
			}
		}
		// cout << "end max_board_value: " << max_board_value << endl;
		// cout << "end max_board_coordinate_i: " << max_board_coordinate_i << endl;
		// cout << "end max_board_coordinate_j: " << max_board_coordinate_j << endl;
		board[max_board_coordinate_i][max_board_coordinate_j] = current_player;
		return true;
	}
}
