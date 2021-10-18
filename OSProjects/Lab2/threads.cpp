#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <sstream>
#include <unistd.h>

void killTime(int secs){
  struct timeval start, now;
  if(gettimeofday(&start, 0) < 0){
    perror("gettimeofday");
    exit(1);
  }
  while(1){
    if(gettimeofday(&now, 0) < 0){
      perror("gettimeofday");
      exit(1);
    }
    if(now.tv_sec - start.tv_sec > secs ||
       now.tv_sec - start.tv_sec == secs && now.tv_usec >= start.tv_usec){
      return;
    }
  }
}

void *run(void *arg){
  killTime(5);
  return 0;
}

int main(int argc, char *argv[]){
  int nThreads;
  std::istringstream arg1(argv[1]);
  arg1 >> nThreads;
  pthread_t thread[nThreads-1];
  int code;

  for(int i = 0; i < nThreads-1; i++){
    code = pthread_create(&thread[i], 0, run, 0);
    if(code){
      std::cerr << "pthread_create failed: " << strerror(code) << std::endl;
      exit(1);
    }
  }
  run(0);
  for(int i = 0; i < nThreads-1; i++){
    code = pthread_join(thread[i], 0);
    if(code){
      std::cerr << "pthread_join failed: " << strerror(code) << std::endl;
      exit(1);
    }
  }
  return 0;
}
