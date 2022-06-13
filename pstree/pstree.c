#include <stdio.h>
#include <assert.h>
#include <filesystem>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int opt;
  bool need_show_pids = false;
  bool need_numeric_sort = false;
  bool need_version = false;
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
