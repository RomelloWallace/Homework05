/*
 Author: Romello Wallace
 Date: 3/9/2021
 Homework 5
 This is a  program that replicates the n and h options of ls. 
*/
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


/* time format prints time last modifed and if the days are greater than one 180 it will print the year*/
void timeFormat(struct stat buf) {

  char time[50];
  int days = 0;
  days = strftime(time, 50, "%d", localtime( & buf.st_mtime));
  if (days < 180) {

    strftime(time, 50, "%B %d %H:%M", localtime( & buf.st_mtime));
  } else {
    strftime(time, 50, "%B %d %y %H:%M", localtime( & buf.st_mtime));
  }

  printf("%s", time);
  printf("%s", " ");

};
/*in an effort to clean up code a little, get IDs will prit the user and group uids*/
void getIDs() {

  printf("%d", getuid());
  printf("%s"," ");
  printf("%d", getgid());
  printf("%s"," ");
}
/* RWX will print the file permissions in RWX format*/
void RWX(struct stat buf) {

  if (S_ISLNK(buf.st_mode)) {
    printf((S_ISLNK(buf.st_mode)) ? "%sd" : "%s-");
  } else {
    printf((S_ISDIR(buf.st_mode)) ? "%sd" : "%s-");
  }
  printf(buf.st_mode & S_IRUSR) ? "%sr" : "%s-");
  printf(buf.st_mode & S_IWUSR) ? "%sw" : "%s-");
  printf(buf.st_mode & S_IXUSR) ? "x" : "-");
  printf(buf.st_mode & S_IRGRP) ? "r" : "-");
  printf(,buf.st_mode & S_IWGRP) ? "w" : "-");
  printf(buf.st_mode & S_IXGRP) ? "x" : "-");
  printf(,buf.st_mode & S_IROTH) ? "r" : "-");
  printf(buf.st_mode & S_IWOTH) ? "w" : "-");
  printf(buf.st_mode & S_IXOTH) ? "x" : "-");
  printf("%s"," ");
}

int main(int argc, char ** argv) {
  /*lines 74 through87 are the various data types created and necessary for the program*/
  struct group * grp;
  struct passwd * user;
  char * getcwd(char * buf, size_t size);

  struct stat buf;
  DIR * d;
  struct dirent * dir;
  char * max = argv[argc - 1];
  long int bytesconvo;

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
    /*option 1 will format based of of n of ls method*/
    if (strchr(argv[i], '-') != NULL && strcmp(argv[i], option1) == 0) {
      /*checks for directory, if it isa  directory it will open and start iterating through files*/
      if (S_ISDIR(buf.st_mode)) {
        d = opendir(max);
        if (d) {
          while ((dir = readdir(d))) {
            if (dir -> d_name[0] != '.') {
              RWX(buf);
              getIDs();
              printf("%ld", sizeof(dir -> d_name));
              printf("%s"," ");
              timeFormat(buf);
              printf("%s", dir -> d_name);
              printf("%s\n");
            }
          }
          /*close directory once finished to avoid errors*/
          closedir(d);
        }
      }
      return 0;
    }
    /*option two will follow h of ls method*/
    else if (strchr(argv[i], '-') != NULL && strcmp(argv[i], option2) == 0) {

      grp = getgrgid(getgid());
      user = getpwuid(getuid());
      if (S_ISDIR(buf.st_mode)) {
        d = opendir(max);
        if (d) {
          while ((dir = readdir(d))) {
            if (dir -> d_name[0] != '.') {
              RWX(buf);
              printf("%s", user -> pw_name);
              printf("%s"," ");
              printf("%s", grp -> gr_name);
              printf("%s"," ");
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
              printf("%s"," ");
              timeFormat(buf);
              printf("%s"," ");
              printf("%s",dir -> d_name);
              printf("%s\n");
            }
          }
          closedir(d);
        }
      }
      return 0;
    }
    /*combines n and h option*/
    else if (strchr(argv[i], '-') != NULL && strcmp(argv[i], option3) == 0) {
      /*grp and user will print the names of the user and group who own the files*/
      grp = getgrgid(getgid());
      user = getpwuid(getuid());
      /*check if argument is directory and iterate through if it is.*/
      if (S_ISDIR(buf.st_mode)) {
        d = opendir(max);
        if (d) {
          while ((dir = readdir(d))) {
            if (dir -> d_name[0] != '.') {
              RWX(buf);
              printf("%s", user -> pw_name);
              printf("%s"," ");
              printf("%s", grp -> gr_name);
              printf("%s"," ");

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

              printf("%s", " ");
              timeFormat(buf);
              printf("%ld", sizeof(dir -> d_name));

              printf("%s"," ");
              printf("%s",dir -> d_name);
              printf("%s\n");
            }
          }
        }
        closedir(d);
      }
      return 0;
    }
    /*combines n and h option of ls*/
    else if (strchr(argv[i], '-') != NULL && strcmp(argv[i], option4) == 0) {
      grp = getgrgid(getgid());
      user = getpwuid(getuid());
      if (S_ISDIR(buf.st_mode)) {
        d = opendir(max);
        if (d) {
          while ((dir = readdir(d))) {
            if (dir -> d_name[0] != '.') {
              RWX(buf);
              printf("%s", user -> pw_name);
              printf("%s"," ");
              printf("%s", grp -> gr_name);
              printf("%s"," ");
              /*byte combo is very messy but i couldnt figure out a proper function formatto clean it up*/
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

              printf("%s"," ");
              timeFormat(buf);
              printf("%ld", sizeof(dir -> d_name));

              printf("%s"," ");
              printf("%s",dir -> d_name);
              printf("%s\n");
            }
          }
        }
        closedir(d);
      }
      return 0;
    }
    /*if argument contains - but isnt an option will print not an option and list directory if final argument is a directory*/
    else if (strchr(argv[i], '-') != NULL) {

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
      /*if all else fails then the option isnt supported and the program will terminate*/
      perror("unsupported option");
    }
  }
  return 0;

}
