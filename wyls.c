


#include <stdio.h>

#include <dirent.h>

#include <errno.h>

#include <stdlib.h>

#include <sys/stat.h>

#include <unistd.h>

#include <string.h>

#include <time.h>

#include <pwd.h>

#include <grp.h>


int main(int argc, char ** argv) {
  struct group * grp;
  struct passwd * user;
  char * getcwd(char * buf, size_t size);
  int days;
  struct stat buf;
  DIR * d;
  struct dirent * dir;
  char * max = argv[argc - 1];
  long int bytesconvo;

  char time[50];
  char * option1 = "-n";
  char * option2 = "-h";
  char * option3 = "-hn";
  char * option4 = "-nh";
  if (strchr(max, '-') != NULL) {

    perror("file not found");
    exit(1);
  }
  for (int i = 1; i < argc; i++) {
    stat(max, & buf);

    if (strchr(argv[i], '-') != NULL && strcmp(argv[i], option1) == 0) {
      if (S_ISDIR(buf.st_mode)) {
        d = opendir(max);
        if (d) {
          while ((dir = readdir(d))) {
            if (dir -> d_name[0] != '.') {
              days = strftime(time, 50, "%d", localtime( & buf.st_mtime));
              if (days < 180) {

                strftime(time, 50, "%B %d %H:%M", localtime( & buf.st_mtime));
              } else {
                strftime(time, 50, "%B %d %y %H:%M", localtime( & buf.st_mtime));
              }
              if(S_ISLNK(buf.st_mode)){
                printf((S_ISLNK(buf.st_mode)) ? "d" : "-");}
                     else{
              printf((S_ISDIR(buf.st_mode)) ? "d" : "-");}
              printf((buf.st_mode & S_IRUSR) ? "r" : "-");
              printf((buf.st_mode & S_IWUSR) ? "w" : "-");
              printf((buf.st_mode & S_IXUSR) ? "x" : "-");
              printf((buf.st_mode & S_IRGRP) ? "r" : "-");
              printf((buf.st_mode & S_IWGRP) ? "w" : "-");
              printf((buf.st_mode & S_IXGRP) ? "x" : "-");
              printf((buf.st_mode & S_IROTH) ? "r" : "-");
              printf((buf.st_mode & S_IWOTH) ? "w" : "-");
              printf((buf.st_mode & S_IXOTH) ? "x" : "-");
              printf(" ");
              printf("%d", getuid());
              printf(" ");
              printf("%d", getgid());
              printf(" ");

              printf("%ld", sizeof(dir -> d_name));
              printf(" ");
              printf("%s", time);
              printf(" ");
              printf(dir -> d_name);
              printf("\n");
            }
          }
          closedir(d);
        }
      }
      return 0;
    } else if (strchr(argv[i], '-') != NULL && strcmp(argv[i], option2) == 0) {

      grp = getgrgid(getgid());
      user = getpwuid(getuid());
      if (S_ISDIR(buf.st_mode)) {
        d = opendir(max);
        if (d) {
          while ((dir = readdir(d))) {
            if (dir -> d_name[0] != '.') {

              days = strftime(time, 50, "%d", localtime( & buf.st_mtime));
              if (days < 180) {

                strftime(time, 50, "%B %d %H:%M", localtime( & buf.st_mtime));
              } else {
                strftime(time, 50, "%B %d %y %H:%M", localtime( & buf.st_mtime));
              }
              if(S_ISLNK(buf.st_mode)){
                printf((S_ISLNK(buf.st_mode)) ? "d" : "-");}
                     else{
              printf((S_ISDIR(buf.st_mode)) ? "d" : "-");}
              printf((buf.st_mode & S_IRUSR) ? "r" : "-");
              printf((buf.st_mode & S_IWUSR) ? "w" : "-");
              printf((buf.st_mode & S_IXUSR) ? "x" : "-");
              printf((buf.st_mode & S_IRGRP) ? "r" : "-");
              printf((buf.st_mode & S_IWGRP) ? "w" : "-");
              printf((buf.st_mode & S_IXGRP) ? "x" : "-");
              printf((buf.st_mode & S_IROTH) ? "r" : "-");
              printf((buf.st_mode & S_IWOTH) ? "w" : "-");
              printf((buf.st_mode & S_IXOTH) ? "x" : "-");
              printf(" ");
              printf("%s", user -> pw_name);
              printf(" ");
              printf("%s", grp -> gr_name);
              printf(" ");

              if (sizeof(dir -> d_name) > 1000 && sizeof(dir -> d_name) < 1000000) {
                bytesconvo = sizeof(dir -> d_name) / 1000;
                printf("%ld", bytesconvo);
                printf("%s", "K");
              } else if (sizeof(dir -> d_name) > 1000000 && sizeof(dir -> d_name) < 1000000000) {
                bytesconvo = sizeof(dir -> d_name) / 1000000;
                printf("%ld", bytesconvo);
                printf("%s", "M");
              } else if (sizeof(dir -> d_name) > 1000000000) {
                bytesconvo = sizeof(dir -> d_name) / 1000000000;
                printf("%ld", bytesconvo);
                printf("%s", "G");
              } else {
                printf("%ld", sizeof(dir -> d_name));
              }

              printf(" ");
              printf("%s", time);
              printf(" ");
              printf(dir -> d_name);
              printf("\n");
            }
          }
          closedir(d);
        }
      }
      return 0;
    } else if (strchr(argv[i], '-') != NULL && strcmp(argv[i], option3) == 0) {

     
      grp = getgrgid(getgid());
      user = getpwuid(getuid());
      if (S_ISDIR(buf.st_mode)) {
        d = opendir(max);
        if (d) {
          while ((dir = readdir(d))) {
            if (dir -> d_name[0] != '.') {

              days = strftime(time, 50, "%d", localtime( & buf.st_mtime));
              if (days < 180) {

                strftime(time, 50, "%B %d %H:%M", localtime( & buf.st_mtime));
              } else {
                strftime(time, 50, "%B %d %y %H:%M", localtime( & buf.st_mtime));
              }
            if(S_ISLNK(buf.st_mode)){
                printf((S_ISLNK(buf.st_mode)) ? "d" : "-");}
                     else{
              printf((S_ISDIR(buf.st_mode)) ? "d" : "-");}
              printf((buf.st_mode & S_IRUSR) ? "r" : "-");
              printf((buf.st_mode & S_IWUSR) ? "w" : "-");
              printf((buf.st_mode & S_IXUSR) ? "x" : "-");
              printf((buf.st_mode & S_IRGRP) ? "r" : "-");
              printf((buf.st_mode & S_IWGRP) ? "w" : "-");
              printf((buf.st_mode & S_IXGRP) ? "x" : "-");
              printf((buf.st_mode & S_IROTH) ? "r" : "-");
              printf((buf.st_mode & S_IWOTH) ? "w" : "-");
              printf((buf.st_mode & S_IXOTH) ? "x" : "-");
              printf(" ");
              printf("%s", user -> pw_name);
              printf(" ");
              printf("%s", grp -> gr_name);
              printf(" ");

              if (sizeof(dir -> d_name) > 1000 && sizeof(dir -> d_name) < 1000000) {
                bytesconvo = sizeof(dir -> d_name) / 1000;
                printf("%ld", bytesconvo);
                printf("%s", "K");
              } else if (sizeof(dir -> d_name) > 1000000 && sizeof(dir -> d_name) < 1000000000) {
                bytesconvo = sizeof(dir -> d_name) / 1000000;
                printf("%ld", bytesconvo);
                printf("%s", "M");
              } else if (sizeof(dir -> d_name) > 1000000000) {
                bytesconvo = sizeof(dir -> d_name) / 1000000000;
                printf("%ld", bytesconvo);
                printf("%s", "G");
              } else {
                printf("%ld", sizeof(dir -> d_name));
              }

              printf(" ");
              printf("%s", time);
              printf(" ");
              printf(dir -> d_name);
              printf("\n");
            }
          }
          closedir(d);
        }
      }
      return 0;
    } else if (strchr(argv[i], '-') != NULL && strcmp(argv[i], option4) == 0) {

      grp = getgrgid(getgid());
      user = getpwuid(getuid());
      if (S_ISDIR(buf.st_mode)) {
        d = opendir(max);
        if (d) {
          while ((dir = readdir(d))) {
            if (dir -> d_name[0] != '.') {

              days = strftime(time, 50, "%d", localtime( & buf.st_mtime));
              if (days < 180) {

                strftime(time, 50, "%B %d %H:%M", localtime( & buf.st_mtime));
              } else {
                strftime(time, 50, "%B %d %y %H:%M", localtime( & buf.st_mtime));
              }

             if(S_ISLNK(buf.st_mode)){
                     printf((S_ISLNK(buf.st_mode)) ? "d" : "-");}
                     else{
              printf((S_ISDIR(buf.st_mode)) ? "d" : "-");}
              printf((buf.st_mode & S_IRUSR) ? "r" : "-");
              printf((buf.st_mode & S_IWUSR) ? "w" : "-");
              printf((buf.st_mode & S_IXUSR) ? "x" : "-");
              printf((buf.st_mode & S_IRGRP) ? "r" : "-");
              printf((buf.st_mode & S_IWGRP) ? "w" : "-");
              printf((buf.st_mode & S_IXGRP) ? "x" : "-");
              printf((buf.st_mode & S_IROTH) ? "r" : "-");
              printf((buf.st_mode & S_IWOTH) ? "w" : "-");
              printf((buf.st_mode & S_IXOTH) ? "x" : "-");
              printf(" ");
              printf("%s", user -> pw_name);
              printf(" ");
              printf("%s", grp -> gr_name);
              printf(" ");

              if (sizeof(dir -> d_name) > 1000 && sizeof(dir -> d_name) < 1000000) {
                bytesconvo = sizeof(dir -> d_name) / 1000;
                printf("%ld", bytesconvo);
                printf("%s", "K");
              } else if (sizeof(dir -> d_name) > 1000000 && sizeof(dir -> d_name) < 1000000000) {
                bytesconvo = sizeof(dir -> d_name) / 1000000;
                printf("%ld", bytesconvo);
                printf("%s", "M");
              } else if (sizeof(dir -> d_name) > 1000000000) {
                bytesconvo = sizeof(dir -> d_name) / 1000000000;
                printf("%ld", bytesconvo);
                printf("%s", "G");
              } else {
                printf("%ld", sizeof(dir -> d_name));
              }

              printf(" ");
              printf("%s", time);
              printf(" ");
              printf(dir -> d_name);
              printf("\n");
            }
          }
          closedir(d);
        }
      }
      return 0;
    } else if (strchr(argv[i], '-') != NULL) {

      perror("not an option");
      if (S_ISDIR(buf.st_mode)) {
        d = opendir(max);
        if (d) {
          while ((dir = readdir(d))) {
            if (dir -> d_name[0] != '.') {
              puts(dir -> d_name);
            }
          }
          closedir(d);
        }
      }
      return 0;
    } else {
      perror("unsupported option doggo");
    }
  }

  if (argc == 1) {
    perror("no arguments found");
  }

  return 0;

};


