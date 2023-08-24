#include "othello.h"
using namespace std;

typedef pair<int, int> Move; //in implement?
typedef pair<int, int> Dir;
typedef vector<vector<Square>> Board;


pair<pair<Move, Board>, pair<int, int>> minimax(const Board &board, const Square &cur_side, int depth){ //move, board, cur_score, opp_score
  Othello othello(board);
  const Square opp = Othello::oppSide(cur_side);
  if(depth == 0){
    return {{{-1, -1}, board}, {othello.boardValue_weights(cur_side), othello.boardValue_weights(opp)}};
  }
  vector<pair<Move, Board>> all_moves = othello.allMoves(cur_side);
  if(all_moves.size() == 0){
    return {{{-1, -1}, board}, {othello.boardValue_weights(cur_side), othello.boardValue_weights(opp)}};
  }
  Move best_move;
  Board best_board;
  int best_score;
  int opp_score;
  bool first = true;
  for(const auto &move: all_moves){
    const pair<pair<Move, Board>, pair<int, int>> cur_ans = minimax(move.second, opp, depth - 1);
    if(first || cur_ans.second.second < best_score){
      best_move = move.first;
      best_board = move.second;
      best_score = cur_ans.second.second;
      opp_score = cur_ans.second.first;
      first = false;
    }
  }
  return {{best_move, best_board}, {best_score, opp_score}};
}


void printBoard(const Board &board){
  cerr << "###############" << endl;
  for(const auto &elem: board){
    for(const auto &elem2: elem){
      cerr << elem2 << " ";
    }
    cerr << endl;
  }
}

void play_game(){
  //unordered_map<Board, Move> memo; //should probably delete elements as well? (index groups of boards by number of pieces -- can't get fewer pieces on a future board so delete old boards)
  Board board(8, vector<Square>(8, Empty));
  board[3][3] = White;
  board[3][4] = Black;
  board[4][3] = Black;
  board[4][4] = White;
  
  Square side = White;
  while(true){
    const pair<pair<Move, Board>, pair<int, int>> ans = minimax(board, side, 4);
    if(ans.first.first.first == -1){
      cerr << "no more moves" << endl;
      break;
    }
    cerr << side << ": " << ans.first.first.first << ", " << ans.first.first.second << endl;
    printBoard(ans.first.second);
    board = ans.first.second;
    side = Othello::oppSide(side); //should make this a static function
  }
}

Square get_side(char ch){
  return (ch == 'w')? White: Black;
}

Board init_board(){
  Board board(8, vector<Square>(8, Empty));
  /*
  board[3][3] = White;
  board[3][4] = Black;
  board[4][3] = Black;
  board[4][4] = White;
  */
  return board;
}

string convert_move(const Move &move){
  unordered_map<int, char> coord = {
    {0, 'a'},
    {1, 'b'},
    {2, 'c'},
    {3, 'd'},
    {4, 'e'},
    {5, 'f'},
    {6, 'g'},
    {7, 'h'}};
  return coord[move.second] + to_string(move.first + 1);
  //return coord[move.first] + to_string(move.second + 1);
}

Move get_move(const string str){
  unordered_map<char, int> coord = {
    {'a', 0},
    {'b', 1},
    {'c', 2},
    {'d', 3},
    {'e', 4},
    {'f', 5},
    {'g', 6},
    {'h', 7}};
    return {str[1] - '1', coord[str[0]]};
    //return {coord[str[0]], str[1] -'1'};
}
int main() { //might have to define typedefs, enums over here (and in othello.cpp)
  //int turns = 8;
  Othello othello;
  string ch;
  getline(cin, ch);
  const Square side = get_side(ch[0]);
  cerr << side << endl; //0 == Empty, 1 == White, 2 == Black
  const Square opp = Othello::oppSide(side);
  Board board = init_board();
  string cmd;
  cout << "ok" << endl;
  cerr << "findme5" << endl;
  while(true){
    //printBoard(board);
    //cerr << "entered while" << endl;
    getline(cin, cmd);
    cerr << "cmd: " << cmd << endl;
    if(cmd[0] == 'm'){ //incoming move
      string str_move = cmd.substr(7, 2);
      //ignore 4 init moves, same side moves
      /*
      if(get_side(cmd[5]) == side){
        continue;
      }
      */
      /*
      if(str_move == "d4" || str_move == "d5" || str_move == "e4" || str_move == "e5"){
        continue;
      }
      */
      const Move move = get_move(str_move);
      const Square move_side = (cmd[5] == 'b')? Black: White;
      cerr << "m move: " << move.first << ", " << move.second << endl;
      othello.setBoard(board);
      board = othello.evalMove(move, move_side, true).first;
    }
    else if(cmd[0] == 'g'){ //move request
      //printBoard(board);
      const pair<pair<Move, Board>, pair<int, int>> ans = minimax(board, side, 4);
      //board = ans.first.second;
      cerr << "g move: " << ans.first.first.first << ", " << ans.first.first.second << endl;
      cout << convert_move(ans.first.first) << endl;
       
    }
    else if(cmd == "done"){
      break;
    }
    
    printBoard(board);
    /*
    --turns;
    if(turns == 0){
      return 0;
    }
    */
  }
}
