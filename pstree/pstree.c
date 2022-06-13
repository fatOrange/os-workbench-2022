#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#define false 0
#define true 1

typedef struct ProcessInfo_s
{
    
    int pid; //1
    char * name;//2
    char state;//3
    int ppid;//4
    long unsigned utime;//14
    long unsigned vsize;//23
} ProcessInfo_t;

typedef struct ProcessNode_s
{
    
    int child_size;
    struct ProcessNode_s* children;
    struct ProcessNode_s* parent;
    ProcessInfo_t process_info;

} ProcessNode_t;


ProcessNode_t * build_process_tree(char * folder)
{
    DIR *dp;
    struct dirent *ep;
    dp = opendir ("/");
    if (dp != NULL)
    {
        while (ep = readdir (dp))
        {
            switch (ep->d_type)
            {
            case DT_UNKNOWN:
                printf("unknow ");
                break;
            case DT_REG:
                printf("regular_file ");
                printf("%s",ep->d_name);
                if(strcmp(ep->d_name,"stat"))
                {
                    printf("%s",ep->d_name);
                    FILE *fp;
                    ssize_t read;
                    char *line = NULL;
                    size_t len = 0;
                    while ((read = getline(&line, &len, fp)) != -1) 
                    {
                        printf("Retrieved line of length %zu :\n", read);
                        printf("%s", line);                        
                    }
                    free(line);
                }
                break;
            case DT_DIR:
                printf("directory ");
                printf("%s",ep->d_name);
                if(strcmp(ep->d_name,"task"))
                {
                    ProcessNode_t *node = build_process_tree(ep->d_name);
                }
                break;
            // case DT_FIFO:
            //     printf("pipe ");
            //     break;
            // case DT_SOCK:
            //     printf("socket ");
            //     break;
            // case DT_CHR:
            //     printf("character device ");
            //     break;
            // case DT_BLK:
            //     printf("block device ");
            //     break;
            // case DT_LNK:
            //     printf("link device");
            //     break;
            default:
                break;
            }
            mode_t a = IFTODT(DT_LNK);
            printf("%d ",ep->d_reclen);

            printf("\n"); 
            // put (ep->d_off);
            // puts ("--------------");
        }
        (void) closedir (dp);
    }
    else
        perror ("Couldn't open the directory");

}

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
