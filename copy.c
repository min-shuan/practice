#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc,char **argv){
  int fd_in,fd_out;
  int readsize;
  char buf[1024];

  //開檔
  fd_in=open(argc[1],O_RDONLY);
  fd_out=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,00060);

  //檢查開檔
  if(fd_in == -1){
    printf("Open input file failed\n");
    return 0;
  }
  if(fd_out == -1){
    printf("Open input file failed\n");
    return 0;
  }
  while(1){
    //讀檔
    readsize=read(fd_in,buf,1024);
    if(readsize<=0){
      break;
    }
    write(fd_out,buf,readsize);
  }

  //關檔
  close(fd_in);
  close(fd_out);

}
