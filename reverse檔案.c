#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc,char **argv){
  int fd;
  int filesize;
  struct stat st;
  fd=open(argv[1],O_RDWR);
  stat(argv[1],&st);
  filesize=st.st_size;
  //lseek(fd,0,SEEK_END);
  //filesize=tell(fd); juice沒有這個函式
  for(int i=0;i<filesize/2;i++){
    char front[2]={0};
    char back[2]={0};
    lseek(fd,i,SEEK_SET);
    read(fd,front,1);

    lseek(fd,(-1)*i-1, SEEK_END);
    read(fd, back, 1);

    lseek(fd, i, SEEK_SET);
    write(fd, back, 1);

    lseek(fd, (-1)*i-1, SEEK_END);
    write(fd, front, 1);
  }
  close(fd);
  return 0;
}
