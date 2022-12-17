#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<cmath>

#define ll long long 
#define mod 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define vl vector<long long int>
#define vvl vector<vector<long long int>>
#define pl pair<long long int, long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define forev(i,n) for(int i=n-1;i>=0;i--)

using namespace std;

struct Mov {
	int si, sj, ei, ej;
};


class Piece {
public:
	vector<vector<int>> moves; 

	int max_steps;
	int color;
};

class Queen : public Piece {
public:
	Queen(int color) {
		moves = {
			{-1,-1,-1,0,1,1,1,0},
			{-1,0,1,1,1,0,-1,-1}
		};
		max_steps = 10;
		color = color;
	}
};

class DummyPiece : public P

class Chess {
public:
	map<pair<int, int>, Piece > board;
	bool white_turn = 1;
	int n = 8;
	Chess() {
		for (int i = 0; i < 8; i++) {
			Queen q(0);
			board[{0, i}] = q;
			board[{1,i}] = q;

			Queen black(1);
			board[{n-1,i}] = black;
			board[{n-2,i}] = black;
		}
	}

	bool validate_bounds(pair<int,int> p) {
		if (p.first < 0 || p.first > 8 || p.second < 0 || p.second >8)return false;
		return true;
	}

	bool validate_color(pair<int, int> start, pair<int, int> end) {
		int start_color = board[{start.first, start.second}].color;
		int end_color = board[{end.first, end.second}].color;
		if (start_color == end_color) return false;
		return true;
	}
	bool move(vector<pair<int,int>> cur_move) {
		auto start = cur_move[0], end = cur_move[1];

			// add return false isntead of exception
		// add validation end should not be same as current 
		validate_bounds(start);
		validate_bounds(end);
		validate_color(start, end);
		
		auto piece = board[start];
		auto moves = piece.moves;
		for (int i = 0; i < moves[0].size(); i++) {
			int dx = moves[0][i], dy = moves[1][i];
			int ni = start.first, nj = start.second;
			int cnt = piece.max_steps;
			while (cnt--) {
				ni += dx, nj += dy;
				if (!validate_bounds({ ni,nj }))break;
				if (ni == end.first && nj == end.second) {
					board[{start.first, start.second}] = NULL;

					board[{ni, nj}] = piece;
					white_turn = !white_turn;
					return true;
				}
			}
		}
		
		return false;
	}

	bool play(vector<Mov> moves) {
		
		for (auto mov : moves) {
			if (!move({ {mov.si,mov.sj},{mov.ei,mov.ej} })) {
				return false;
			}
		}
	}

	bool input(int si, int sj, int ei, int ej) {
		Mov move;
		move.si = si;
		move.sj = sj;
		move.ei = ei;
		move.ej = ej;
		play({ move });
	}



};


int main() {

	Chess chess;
	while (true) {
		int si, sj, ei, ej;
		cin >> si >> sj >> ei >> ej;
		chess.input(si, sj, ei, ej);
	}


	return 0;
}

