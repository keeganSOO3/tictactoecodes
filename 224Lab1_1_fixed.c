#include <stdio.h>
#include <stdlib.h>

struct moves {
	char board[3][3];
} ;

void ClearBoard(struct moves *game){
	int i,j;
	for (i =0; i<3 ; i++){
		for (j=0; j<3; j++){
			game->board[i][j]=' ';
		}
	}
}

void DisplayBoard(struct moves game){ //prints empty board
	printf(" %c | %c | %c ", game.board[0][0],game.board[0][1],game.board[0][2]);
	printf("\n---|---|---|\n");
	printf(" %c | %c | %c ", game.board[1][0],game.board[1][1],game.board[1][2]);
	printf("\n---|---|---|\n");
	printf(" %c | %c | %c ", game.board[2][0],game.board[2][1],game.board[2][2]);
}

void PutMark(struct moves *game, int i, int j, char mark){
    if(game->board[i][j] != ' '){
        printf("This cell is already filled. Choose another cell.\n");
        return;
    }
    if (mark == 'x' || mark == 'o'){
        game->board[i][j] = mark;
    }
    else{
        printf("Invalid input. Only 'x' and 'o' are allowed.\n");
    }
}

int getWinner(struct moves game){ //check for winner, call in main 
    int i = 0;
    for (i = 0; i < 3; i++) {
        if (game.board[i][0] == game.board[i][1] && game.board[i][1] == game.board[i][2] && game.board[i][0] != ' ') { // checks each column (3 outcomes), we also use a != conditon to error check
            printf("Winner!\n");
            return 1;
        }
        if (game.board[0][i] == game.board[1][i] && game.board[1][i] == game.board[2][i] && game.board[0][i] != ' ') { // checks each row (3 outcomes)
            printf("Winner!\n");
            return 1;
        }
    }
    if (game.board[0][0] == game.board[1][1] && game.board[1][1] == game.board[2][2] && game.board[0][0] != ' ') { // checks top left to bottom right diagonal (1 outcome)
        printf("Winner!\n");
        return 1;
    }
    if (game.board[0][2] == game.board[1][1] && game.board[1][1] == game.board[2][0] && game.board[0][2] != ' ') { //checks top right to bottom left diagonal (1 outcome) 
        printf("Winner!\n");
        return 1;
    }
    return 0;
}
int main() {
    struct moves game;
    int check=0;
    int winner = 0; 
    int turn = 1;
    char mark;
    int i, j;
    ClearBoard(&game);
    DisplayBoard(game); 
    while (!winner) {
        if (turn == 1) {
            printf("Enter your mark (X or O): ");
            turn = 2;
        } else {
            printf("Enter your mark (X or O): ");
            turn = 1;
            
        }
        scanf(" %c", &mark);
        printf("Enter the row and column (1,2,3) and (1,2,3) respectively");
        scanf("%d%d", &i, &j);
        i--; 
        j--;
        PutMark(&game, i, j, mark); 
        DisplayBoard(game);
        check++;
        if (check ==9){
        	printf("Draw!\n");
        	return;
		}
        winner = getWinner(game);
        if (winner) {
            printf("Player %d wins!\n", turn);
        } else {
            turn = turn == 1 ? 2 : 1;
        }
    }
    return 0;
}
