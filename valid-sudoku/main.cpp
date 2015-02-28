#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char> > &board) {
	if(board.size() != 9) {
		return false;
	}

	for(int i = 0; i < 9; i++) {
		if(board[i].size() != 9) {
			return false;
		}
	}	

	bool flag[9];

	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			flag[j] = false;
		}
		for(int j = 0; j < 9; j++) {
			if(board[i][j] != '.') {	
				int t = board[i][j] - '0';
				if(flag[t-1]) {
					return false;
				}	
				flag[t-1] = true;
			}
		}

		for(int j = 0; j < 9; j++) {
			flag[j] = false;
		}
		for(int j = 0; j < 9; j++) {
			if(board[j][i] != '.') {	
				int t = board[j][i] - '0';
				if(flag[t-1]) {
					return false;
				}	
				flag[t-1] = true;
			}
		}
	}

	for(int i = 0; i < 9; i+=3) {
		for(int j = 0; j < 9; j+=3) {
			for(int k = 0; k < 9; k++) {
				flag[k] = false;
			}
			for(int ii = i; ii < i+3; ii++) {
				for(int jj = j; jj < j+3; jj++) {
					if(board[ii][jj] != '.') {
						int t = board[ii][jj] - '0';
						if(flag[t-1]) {
							return false;
						}	
						flag[t-1] = true;
					}	
				}
			}	
		}
	}

	return true;
}

vector<vector<char> > createSudoku(string a[]) {
	vector<vector<char> > vv;
	for(int i = 0; i < 9; i++) {
		vector<char> v;
		for(int j = 0; j < 9; j++) {
			v.push_back(a[i][j]);	
		}
		vv.push_back(v);
	}
	return vv;	
}

int main(int argc, char *argv[]) {
	string a[] = {
		"53..7....",
		"6..195...",
		".98....6.",
		"8...6...3",
		"4..8.3..1",
		"7...2...6",
		".6....28.",
		"...419..5",
		"....8..79",
	};	
	vector<vector<char> > vv = createSudoku(a);
	cout << isValidSudoku(vv) << endl;
	return 0;
}
