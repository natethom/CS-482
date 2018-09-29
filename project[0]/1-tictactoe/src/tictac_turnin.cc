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

bool check_for_win(int board[][NUM_COLUMNS], int current_player){
	if(board[0][0]+board[0][1] == 2 && board[0][2] != -1 && current_player == 1){
		board[0][2] = current_player;
		return true;
	}
	else if(board[0][0]+board[0][1] == -2 && board[0][2] != 1 && current_player == -1){
		board[0][2] = current_player;
		return true;
	}

	else if(board[0][0]+board[1][1] == 2 && board[2][2] != -1 && current_player == 1){
		board[2][2] = current_player;
		return true;
	}
	else if(board[0][0]+board[1][1] == -2 && board[2][2] != 1 && current_player == -1){
		board[2][2] = current_player;
		return true;
	}

	else if(board[0][0]+board[1][0] == 2 && board[2][0] != -1 && current_player == 1){
		board[2][0] = current_player;
		return true;
	}
	else if(board[0][0]+board[1][0] == -2 && board[2][0] != 1 && current_player == -1){
		board[2][0] = current_player;
		return true;
	}

	else if(board[0][1]+board[1][1] == 2 && board[2][1] != -1 && current_player == 1){
		board[2][1] = current_player;
		return true;
	}
	else if(board[0][1]+board[1][1] == -2 && board[2][1] != 1 && current_player == -1){
		board[2][1] = current_player;
		return true;
	}

	else if(board[0][2]+board[1][2] == 2 && board[2][2] != -1 && current_player == 1){
		board[2][2] = current_player;
		return true;
	}
	else if(board[0][2]+board[1][2] == -2 && board[2][2] != 1 && current_player == -1){
		board[2][2] = current_player;
		return true;
	}

	else if(board[0][2]+board[1][1] == 2 && board[2][0] != -1 && current_player == 1){
		board[2][0] = current_player;
		return true;
	}
	else if(board[0][2]+board[1][1] == -2 && board[2][0] != 1 && current_player == -1){
		board[2][0] = current_player;
		return true;
	}

	else if(board[1][0]+board[1][1] == 2 && board[1][2] != -1 && current_player == 1){
		board[1][2] = current_player;
		return true;
	}
	else if(board[1][0]+board[1][1] == -2 && board[1][2] != 1 && current_player == -1){
		board[1][2] = current_player;
		return true;
	}

	else if(board[2][0]+board[2][1] == 2 && board[2][2] != -1 && current_player == 1){
		board[2][2] = current_player;
		return true;
	}
	else if(board[2][0]+board[2][1] == -2 && board[2][2] != 1 && current_player == -1){
		board[2][2] = current_player;
		return true;
	}

	else{
		return false;
	}
}




int make_move( int board[][3] )
{
	int current_player = check_whose_turn(board);
	cout << current_player << endl;

	if(check_for_win(board, current_player) == true){
		return true;
	}
	else{
		for(int i = 0; i < 3; i++ ){
			for(int j = 0; j < 3; j++ ){
				if(board[i][j] == 0){
					int temp_board[3][3]
					cout << board << endl << endl;
					cout << temp_board << endl << endl;

				}
			}
	}
}






// 	// default behavior: find any unoccupied square and make the move
// 	for( int i = 0; i < 3; i++ )
// 		for( int j = 0; j < 3; j++ )
// 			// find an empty square
// 			if( board[i][j] == 0 )
// 			{
// 				// that's the move
// 				printf( "player [%d] made move: [%d,%d]\n", current_player, i, j );
// 				board[i][j] = current_player;
// 				return 1;
// 			}
//
// 	// no move was made (board was full)
// 	return 0;
// }
