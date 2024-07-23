#include<iostream>
#include<vector>
using namespace std;

   bool isValid(vector<vector<char> >& board, int row, int col, char c) {
        // Check the row
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) {
                return false;
            }
        }

        // Check the column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c) {
                return false;
            }
        }

        // Check the 3x3 box
        int boxRow = row / 3 * 3;
        int boxCol = col / 3 * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[boxRow + i][boxCol + j] == c) {
                    return false;
                }
            }
        }

        return true;
    }

 bool solve(vector<vector<char> >& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    int main(){
    	vector<vector<char> >board(9,vector<char>(9,'.'));
    	for(int i=0;i<9;i++){
    		for(int j=0;j<9;j++){
    			cout<<"enter the value at "<<i<<"row and "<<j<<"col"<<endl;
    			cin>>board[i][j];
			}
		}
		solve(board);
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		return 0;
	}
