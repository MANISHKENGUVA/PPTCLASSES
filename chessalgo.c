#include <stdio.h>
#include <stdbool.h>
int res[8][8];

bool checking(int x_next,int y_next){
  if (res[x_next][y_next] ==-1 && x_next>=0 && x_next<8 && y_next>=0 && y_next<8){
    return true;
  }
  else{
    return false;
  }
}

void next_step(int x,int y,int step,int res,int x_move[8],int y_move){
  int x_next,y_next;
  for (int i=0;i<8;i++){
    x_next = x+x_move[i];
    y_next = y+y_move[i];
    if (checking(x_next,y_next)){
      res[x_next][y_next] = step;
      step++;
      next_step(x_next,y_next,step,res, x_move, y_move);
    }
    else{
      res[x_next][y_next] = -1;
    }
  }
}

void Knight(){
  for (int i=0;i<8;i++){
    for (int j=0;j<8;j++){
      res[i][j] = -1;
    }
  }
  res[0][0] = 0;
  int x_move[8]={2,1,-1,-2,-2,-1,1,2};
  int y_move[8]={1,2,2,1,-1,-2,-2,-1};
  next_step(0,0,1,res,x_move,y_move);
}

int main(void) {
  Knight();
  return 0;
}