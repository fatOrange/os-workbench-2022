#include <stdio.h>
#include <assert.h>
#include <unistd.h>

#define false 0
#define true 1

int main(int argc, char *argv[]) {
  int opt;
  int need_show_pids = false;
  int need_numeric_sort = false;
  int need_version = false;
  while((opt = getopt(argc,argv,"Vpn"))!= -1)
  {
      switch(opt)
      {
          case 'n':
              need_numeric_sort = true;
              break;
          case 'p':
              need_show_pids = true;
          case 'V':
              need_version = true;
      }
  }

  
  assert(!argv[argc]);
  return 0;
}
