#include <stdio.h>
#include <string.h>
char zstr[50];
int zarr[50];

int compare(int i){
  int count=0;
  for (int j=0;zstr[j]!='#';j++){
    if (zstr[j] == zstr[i+j]){
      count++;
    }
    else{
      break;
    }
  }
  return count;
}

void zalgo(char str[],char pat[]){
  int r;
  strcpy(zstr,pat);
  strcat(zstr, "#");
  strcat(zstr, str);
  printf("%s",zstr);
  for (int i=1;i<strlen(zstr);i++){
    if (zstr[i] == zstr[0]){
      r = compare(i);
      zarr[i] = r;
    }
    else{
      zarr[i] = 0;
    }
  }
}

int main(void) {
  char str[] = "xyzzyxyzzyxxz";
  char pat[] = "zyx";
  zalgo(str,pat);
  for (int i=0;i<strlen(zstr);i++){
    if (zarr[i] == strlen(pat)){
      printf("\n%d ",i-strlen(pat)-1);
    }
  }
  
  return 0;
}