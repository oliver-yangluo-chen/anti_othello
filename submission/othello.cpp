#include "othello.h"
using namespace std;


//enum Square{White, Black, Empty}; //define in implement?

typedef pair<int, int> Move; //in implement?
typedef pair<int, int> Dir;
typedef vector<vector<Square>> Board;


Board board(8, vector<Square>(8, Empty));
vector<Dir> dir_vec = {
  {0, 1}, {1, 0},
  {0, -1}, {-1, 0},
  {1, 1}, {-1, -1},
  {-1, 1}, {1, -1}};

Square Othello::oppSide(const Square &side){
  if(side == White){
    return Black;
  }
  if(side == Black){
    return White;
  }
  return Empty;
}

Move Othello::addDir(const Move &move, const Dir &dir){
  return {move.first + dir.first, move.second + dir.second};
}

bool Othello::validMove(const Move &move){
  return move.first >= 0 && move.first < 8 && move.second >= 0 && move.second < 8;
}
int Othello::boardValue_weights(const Square &side){
  int value = 0;
  const Square opp = oppSide(side);
  for(int i = 0; i < 8; ++i){
    for(int j = 0; j < 8; ++j){
      if(board[i][j] == side){
        value += max(abs(i-4), abs(i-3)) + max(abs(j-4), abs(j-3)) - 1;
      }
      else if(board[i][j] == opp){
        value -= max(abs(i-4), abs(i-3)) + max(abs(j-4), abs(j-3)) - 1;
      }
    }
  }
  return value;
}
int Othello::boardValue(const Square &side){
  int value = 0;
  for(const auto &period: board){
    for(const auto &elem: period){
      value += (elem == side)? 1: 0;
    }
  }
  return value;
}

bool Othello::evalRay(Move ray, const Move &dir, const Square &side){
  //cerr << "entered evalRay" << endl;
  Square opp = oppSide(side);
  bool ans = false;
  ray = addDir(ray, dir);
  while(validMove(ray) && board[ray.first][ray.second] == opp){ //must always be on opposite
    ans = true;
    ray = addDir(ray, dir);
  }
  if(!validMove(ray) || board[ray.first][ray.second] != side){
    ans = false;
  }
  //cerr << "finished evalRay" << endl;
  return ans;
}
Othello::Othello(){
  cerr << "empty init" << endl;
}
Othello::Othello(const Board &new_board){
  board = new_board;
}
void Othello::setBoard(const vector<vector<Square>> &new_board){
  board = new_board;
}

pair<Board, bool> Othello::evalMove(const Move &move, const Square &side, const bool place){
  //cerr << "entered evalMove" << endl;
  Board ans = board;
  Square opp = oppSide(side);
  bool valid = false;
  for(const auto dir: dir_vec){
    if(evalRay(move, dir, side)){
      valid = true;
      //Move ray = move;
      for(Move ray = addDir(move, dir); ans[ray.first][ray.second] == opp; ray = addDir(ray, dir)){ //check board instead of ans?; guaranteed to not fail because is valid (will bump into own side before
        ans[ray.first][ray.second] = side;
      }
    }
  }
  if(valid || place){ //only put last piece if a ray was actually valid
    ans[move.first][move.second] = side;
  }
  //cerr << "finished evalMove" << endl;
  return {ans, valid};
}

vector<pair<Move, Board>> Othello::allMoves(const Square &side){
  //cerr << "entered allMoves" << endl;
  vector<pair<Move, Board>> moves_vec;
  
  for(int i = 0; i < 8; ++i){
    for(int j = 0; j < 8; ++j){
      if(board[i][j] == Empty){
        pair<Board, bool> outcome = evalMove({i, j}, side, false);
        if(outcome.second){ //is a valid move (something actually changed)a
          moves_vec.push_back({{i, j}, outcome.first});
        }
      }
    }
  }
  //cerr << "finished allMoves" << endl;
  return moves_vec;
}
