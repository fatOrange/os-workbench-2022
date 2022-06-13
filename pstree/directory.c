#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int
main (void)
{
  DIR *dp;
  struct dirent *ep;

  dp = opendir ("/");
  if (dp != NULL)
    {
      while (ep = readdir (dp))
      {
        printf("%s ",ep->d_name);
        printf("%u ",ep->d_ino);
        printf("%d ",ep->d_type);
        switch (ep->d_type)
        {
        case DT_UNKNOWN:
            printf("unknow ");
            break;
        case DT_REG:
            printf("regular_file ");
            break;
        case DT_DIR:
            printf("directory ");
            break;
        case DT_FIFO:
            printf("pipe ");
            break;
        case DT_SOCK:
            printf("socket ");
            break;
        case DT_CHR:
            printf("character device ");
            break;
        case DT_BLK:
            printf("block device ");
            break;
        case DT_LNK:
            printf("link device");
            break;
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

  return 0;
}