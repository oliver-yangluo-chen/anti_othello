#pragma once //included repeated files/libraries only once
#include <vector>
#include <utility>
#include <stdlib.h>
#include <algorithm>
#include <utility>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

enum Square{Empty, White, Black}; //define in implement?

/*
todo:
  functions:
    evaluate a move (should return a copy of board to test valid moves)
    find valid moves (also allows minimax to check if game is over -- outcome doesn't matter, only score does)
    different scoring functions
  other stuff:
    something to memoize moves (board -> move)
    everything should be relative to side (class does not have specific side, functions take in side as parameter)
    
 */

class Othello{
private:

  typedef pair<int, int> Move; //in implement?
  typedef pair<int, int> Dir;
  typedef vector<vector<Square>> Board;
  
  /*
  Board board(8, vector<Square>(8, Empty));
  vector<Dir> dir_vec = {
    {0, 1}, {1, 0},
    {0, -1}, {-1, 0},
    {1, 1}, {-1, -1},
    {-1, 1}, {1, -1}};
  */

  Move addDir(const Move &move, const Dir &dir);
  bool validMove(const Move &move);
  bool evalRay(Move ray, const Move &dir, const Square &side);
public:
  Othello();
  Othello(const Board &new_board);
  static Square oppSide(const Square &side);
  void setBoard(const Board &new_board);
  int boardValue_weights(const Square &side);
  int boardValue(const Square &side);
  pair<Board, bool> evalMove(const Move &move, const Square &side, const bool place); //each move is represented as a board so no need to evaluate move (might change later due to memory)
  vector<pair<Move, Board>> allMoves(const Square &side);
};
