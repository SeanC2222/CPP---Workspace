/* Author: SeanC
 * Date: Nov 11, 2014
 *
 * ticTacToe.cpp
 * 
 * File purpose: This game plays Tic-Tac-Toe between two users
 * 
 * Inputs: 	char cPlay			Whether users are ready to play
 * 		   	string userMove		Holds user input for chosen location (RC)
 *
 * Outputs: char** gameBoard	Holds current game board
 * 			int xWins, oWins	Holds user wins, whichever is greater is output
 */                                                                          //
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

bool displayIntro();
int game(int);
void buildBoard(char**);
void showBoard(char**);
void updateBoard(char**, int[], char);
bool getUserMove(char**, int[], char);
int checkWinner(char**);
int checkRowsAndColumns(char**);
int checkDiagonals(char**);

int main(int argc, char* argv[]){

	int winner, games, gameCount = 0, xWins = 0, oWins = 0;
	if (argc > 1){
		games = atoi(argv[1]);
	} else {
		games = 1;
	}

	do{
		if(displayIntro()){
			winner = game(gameCount);

			if (winner == 0){
				cout << "It was a draw!" << endl;
			} else if (winner % 'X' == 0){
				cout << "X's win! Good job Player 1!" << endl;
				xWins++;
			} else if (winner % 'O' == 0){
				cout << "O's win! Good job Player 2!" << endl;
				oWins++;
			} else {
				cout << "It was a draw!" << endl;
			}
		}
		gameCount++;
	}while (gameCount < games);

	if (xWins > oWins){
		cout << "Player 1 is the overall winner with " << xWins << " win(s)!" << endl;
	} else if (oWins > xWins){
		cout << "Player 2 is the overall winner with " << oWins << " win(s)!" << endl;
	} else {
		cout << "Overall it was a draw! Both players had " << xWins << "!" << endl;
	}
	return 0;
}

bool displayIntro(){

	char cPlay;

	for (int i = 0; i < 20; i++){
		cout << " ";
	}
	cout << "Welcome to Tic-Tac-Toe!";
	for (int i = 0; i < 20; i++){
		cout << " ";
	}
	cout << endl;
	cout << "This is the classic game of Tic-Tac-Toe where 2 players try to "
		 << "\nconnect three X's or three O's. User 1 will be X's and"
		 << "\nUser 2 will be O's.";
	cout << "Ready to begin? ('y'/'n') ";
	cPlay = tolower(cin.get());
	cout << endl;
	if (cin.peek()!= '\n' || (cPlay != 'n' && cPlay != 'y')){
		cout << "Not valid input.\n"
			 << "Ready to begin? ('y'/'n') ";
		cin.ignore(100,'\n');
	} else {
		cin.get();
	}

	if (cPlay == 'y'){
		return true;
	} else {
		return false;
	}
}

int game(int gameCount){

	int *move;
	char **gameBoard;
	gameBoard = new char*[3];
	for (int i = 0; i < 3; i++){
		gameBoard[i] = new char[3];
	}

	buildBoard(gameBoard);

	int turns = 0;
	int checkWin = 0;
	do{
		char player;
		if (turns % 2 == 0){
			if (gameCount % 2 == 0)
				player = 'X';
			else
				player = 'O';
		} else {
			if (gameCount % 2 == 0)
				player = 'O';
			else
				player = 'X';
		}
		showBoard(gameBoard);

		move = new int[2];
		if (getUserMove(gameBoard, move, player)){
			updateBoard(gameBoard, move, player);
			delete[] move;
			turns++;
		} else {
			cout << "Invalid input, try again." << endl;
		}
		checkWin = checkWinner(gameBoard);
		if(checkWin){
			break;
		}
	}while (turns < 9);

	showBoard(gameBoard);

	for (int i = 0; i < 3; i++){
		delete[] gameBoard[i];
	}
	delete[] gameBoard;

	return checkWin;
}

void buildBoard(char **gameBoard){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			gameBoard[i][j] = '-';
		}
	}
	return;
}

void showBoard(char** gameBoard){

	cout << "  0 1 2" << endl;
	cout << "0 ";

	for (int i = 0; i < 3; i++){
		cout << gameBoard[0][i] << " ";
	}
	cout << endl;

	cout << "1 ";
	for (int i = 0; i < 3; i++){
		cout << gameBoard[1][i] << " ";
	}
	cout << endl;

	cout << "2 ";
	for (int i = 0; i < 3; i++){
		cout << gameBoard[2][i] << " ";
	}
	cout << endl << endl;
	return;
}

bool getUserMove(char** gameBoard, int move[], char player){

	string userMove;
	bool trigger;
	do{
		cout << "What is your move player ";
		if (player == 'X'){
			cout << "1 ";
		} else {
			cout << "2 ";
		}
		cout << "? (Format \"RC\" where 'R' is the row and 'C' is the column) ";
		getline(cin, userMove);
		cout << endl;
		if(userMove.length() == 2){
			for (int i = 0; i < userMove.length(); i++){
				if (userMove.at(i) >= '0' && userMove.at(i) <= '2') {
					trigger = false;
				} else {
					trigger = true;
					break;
				}
			}
		} else {
			trigger = true;
		}
	}while(trigger);
	move[0] = userMove.at(0) - '0';
	move[1] = userMove.at(1) - '0';

	if (gameBoard[move[0]][move[1]] == '-'){
		return true;
	} else {
		return false;
	}
}

void updateBoard(char** gameBoard, int move[], char player){

	gameBoard[move[0]][move[1]] = player;
	return;
}

int checkWinner(char** gameBoard){
	int rowColumnWin = checkRowsAndColumns(gameBoard),
		diagonalWin = checkDiagonals(gameBoard);
	return(rowColumnWin + diagonalWin);
}

int checkRowsAndColumns(char** gameBoard){
	//Checks rows & columns at the same time
	int  sum1 = 0, sum2 = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			sum1 += gameBoard[i][j];
			sum2 += gameBoard[j][i];
		}

		if (sum1 % 'X' == 0 || sum1 % 'O' == 0){
			return sum1;
		}
		if (sum2 % 'X' == 0 || sum2 % 'O' == 0){
			return sum2;
		}
		sum1 = 0;
		sum2 = 0;
	}
	return 0;
}

int checkDiagonals(char** gameBoard){
	//Checks Diagonal from [0][0] to [i][i]
	int sum1 = 0, sum2 = 0;
	for (int i = 0, j = 0; i < 3; i++, j++){
		sum1 += gameBoard[i][j];
	}

	//Checks Diagonal from [i][0] to [0][i]
	sum2 = 0;
	for (int i = 2, j = 0; i >= 0; i--, j++){
		sum2 += gameBoard[i][j];
	}
	if(sum1 % 'X' == 0 || sum1 % 'O' == 0){
		return sum1;
	}
	if(sum2 % 'X' == 0 || sum2 % 'O' == 0){
		return sum2;
	}
	return 0;
}

