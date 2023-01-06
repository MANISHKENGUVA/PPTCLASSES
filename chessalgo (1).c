#include <stdio.h>
#include <stdbool.h>
int res[8][8];

void printing(){
  for (int i=0;i<8;i++){
    for (int j=0;j<8;j++){
      printf("%d ",res[i][j]);
    }
    printf("\n");
  }
}

bool checking(int x_next,int y_next){
  if (res[x_next][y_next] ==-1 && x_next>=0 && x_next<8 && y_next>=0 && y_next<8){
    return true;
  }
  else{
    return false;
  }
}

int next_step(int x,int y,int step,int x_move[8],int y_move[8]){
  int x_next,y_next;
  if (step == 64){
    return 1;
  }
  for (int i=0;i<8;i++){
    x_next = x+x_move[i];
    y_next = y+y_move[i];
    if (checking(x_next,y_next)){
      res[x_next][y_next] = step;
      step++;
      if (next_step(x_next,y_next,step, x_move, y_move) == 1){
        return 1;
      }
      else{
        res[x_next][y_next] = -1;
      }  
    }
  }
  return 0;
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
  next_step(0,0,1,x_move,y_move);
  printing();
}

int main(void) {
  Knight();
  return 0;
}