/*
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.

*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int intinput(int bufsize){
	int outnum;
	char buf[bufsize];

	do{
		printf("\n");
		if (!fgets(buf, bufsize, stdin)){
			return 1;
		}
		outnum = atoi(buf);

	}
	while (outnum == 0);
	return outnum;

}


int main(){
	int board[9] = {0, 0, 0, 0, 0, 0, 0 ,0 ,0}; /* the board is a 2d array as the real tictactoe board is 2d edit: 1d now jesus that was an awful idea */
	bool winner = false;
	bool xsturn = true; /*if true it is x if false it is o*/
	printf("Welcome to TicTacToe! X goes first, do not enter more then 9 characters or seg fault. moves from left to right up to down and index starts at 1\n");
	printf("123\n456\n789");
	do{
		int square = 0; /* What square to play on*/
		bool used = false; /*If the space is used*/
		printf((xsturn) ? "\n\nX's turn!" : "\n\nO's turn!");
		do{
			square = intinput(10);

			used = board[square - 1];
		}
		while(square < 1 || square > 9 || used);
		
		board[square - 1] += (xsturn + 1);
		char boardx[9];
		for(int i = 0;i < 9;i++){
			switch(board[i]){
				case 0:
					boardx[i] = (i + 1) + '0';
					break;
				case 1:
					boardx[i] = 'O';
					break;
				case 2:
					boardx[i] = 'X';
					break;
				default:
					printf("I'm sorry Dave, I can't do that for you.");
					exit(0);
			}
		}


		printf("%c%c%c\n%c%c%c\n%c%c%c", boardx[0], boardx[1], boardx[2], boardx[3], boardx[4], boardx[5], boardx[6], boardx[7], boardx[8]); /*This is awful but I do not know what else to do.*/
		xsturn = !xsturn;
		int notzerocount = 0;
		for(int i = 0;i < 9;i++){
			if (i % 3 == 0 &&  board[i] == board[i + 1] && board[i] == board[i + 2] || board[i] == board[i + 3] && board[i]  == board[i + 6] || i == 2  && board[2] == board[4] && board[2]\
				       	== board[6] || i == 0 &&  board[0] == board[4] && board[0] == board[8]){
				switch(board[i]){
					case 2:
						printf("\n\nX wins!\n");
						winner = true;
						break;
					case 1:
						printf("\n\nO wins\n!");
						winner = true;
						break;
						
				}
			}
			if (board[i] != 0){
				notzerocount++;
			}
		}
		if (notzerocount == 9){
			printf("\n\nTie\n");
			winner = true;
		}
	}
	while(!winner);

	return 0;
}
