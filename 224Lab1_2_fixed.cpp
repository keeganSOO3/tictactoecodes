#include <iostream>
using namespace std;

class TTC{	
public:
	TTC();
	void DisplayBoard();
	void ClearBoard();
	void PutMark(int i, int j, char k);
	int getWinner();
	
private:
	char board[3][3]; //board will be hidden
};


TTC::TTC(){ //constructor
	int i,j;
	for (i =0; i<3 ; i++){
		for (j=0; j<3; j++){
			board[i][j]=' ';
		}
	}
}
void TTC::ClearBoard(){
  int i,j;
  for (i =0; i<3 ; i++){
    for (j=0; j<3; j++){
      board[i][j]=' ';
    }
  }
}

void TTC :: DisplayBoard(){ //prints empty board
	cout<< board[0][0]<<"  |"<<board[0][1]<<"  |"<<board[0][2] << endl;
	cout<< "---|---|---|  " <<endl;
	cout<< board[1][0]<<"  |"<<board[1][1]<<"  |"<<board[1][2] << endl;
	cout<< "---|---|---|  " <<endl;
	cout<< board[2][0]<<"  |"<<board[2][1]<<"  |"<<board[2][2] << endl;
}

void TTC::PutMark(int i, int j, char k){
	if (board[i][j] == ' ') {
		if (k == 'o' || k == 'x'){
		board[i][j]=k;
		}
	else{
		cout << "Wrong input, please enter either x or o" << endl;
		}
		}
	else {
		cout << "This space is already occupied, please select a different space" << endl;
		}
}

int TTC::getWinner(){ //copy paste from C code
    int i = 0;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') { // checks each column (3 outcomes), we also use a != conditon to error check
        cout << "Winner!\n" << endl;
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') { // checks each row (3 outcomes)
        cout << "Winner!\n" << endl;
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') { // checks top left to bottom right diagonal (1 outcome)
        cout << "Winner!\n" << endl;
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') { //checks top right to bottom left diagonal (1 outcome) 
        cout << "Winner!\n" << endl;
        return 1;
    }
    return 0;
}

int main(){
	int count =0;
	int i, j;
	int turn = 1;
    char mark;
    int winner = 0;
    TTC game;
    game.ClearBoard();
    game.DisplayBoard();
    
    while (winner == 0) {
        if (turn == 1) {
            cout << "Enter your mark (x or o): ";
            cin >> mark;
            if (mark == 'k'){
            	cout << "Please enter your mark at a different spot\n";
			}
            turn = 2;
        } else {
            cout << "Enter your mark (x or o): ";
            cin >> mark;
            turn = 1;
        }
        cout << "Enter the row (1, 2, or 3) and column (1, 2, or 3) where you want to place your mark: ";
        cin >> i >> j;
        i--;
        j--;
        count++;
        if (count == 9){
        	cout << "Draw!\n";
        	return 1;
		}
        game.PutMark(i, j, mark);
        game.DisplayBoard();
        winner = game.getWinner();
        if (winner == 1) {
            cout << "Player " << turn << " wins!" << endl;
            break;
        }
    }
    return 0;
}


