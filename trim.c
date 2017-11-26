#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <trim.h>

const int MAX_LEN_STR = 20;

void usage(){
  printf("trim str chars\n");
  exit(1);
}

char *ltrim(char *dest, const char *c){
  if(! (dest && strlen(dest) && c && strlen(c))) return dest;
  int cPos = 0;

  do{
    if(*dest == *(c+cPos)){
      int dPos = 0;
      do{
        *(dest+dPos) = *(dest+dPos+1);
      }while(*(++dPos+dest) != '\0');
      return ltrim(dest, c);
    }
  }while(*(++cPos+c) != '\0');
  return dest;
}

char *rtrim(char *dest, const char *c){
  if(! (dest && strlen(dest) && c && strlen(c))) return dest;
  int cPos = 0;

  do{
    if(*(dest+strlen(dest)-1) == *(c+cPos)){
      *(dest+strlen(dest)-1) = '\0';
      return rtrim(dest, c);
    }
  }while(*(++cPos+c) != '\0');
  return dest;
}

char *trim(char *dest, const char *c){
  return ltrim(rtrim(dest, c), c);
}

int main(int argc, char **argv){
  if(argc != 3) usage();
  if(strlen(argv[1]) > MAX_LEN_STR || strlen(argv[2]) > MAX_LEN_STR) usage();

  printf("in1:%s in2:%s\n", argv[1], argv[2]);
  printf("out:%s\n", trim(argv[1], argv[2]));
}
