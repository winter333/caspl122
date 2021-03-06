#include "util.h"
#include "task2.h"

#define STDOUT 1
#define SYS_EXIT 1
#define SYS_READ 3
#define SYS_WRITE 4
#define SYS_OPEN 5
#define SYS_CLOSE 6
#define SYS_STAT 106
#define SYS_GETDENTS 141

#define S_IWUSR 00200
#define S_IXUSR 00100

#define MAX_SIZE 8192

int main (int argc , char* argv[], char* envp[])
{
  char buf[MAX_SIZE];
  char bufy[MAX_SIZE];
  struct linux_dirent *dnt =(struct linux_dirent*)buf;
  struct stat *sta =(struct stat *)bufy;
  int sum=0,exec=0,stati;
  if (argc>1){
     if (strcmp(argv[1],"-e") ==0){
	exec=1;
     }
  }

  int target=system_call(SYS_OPEN,".",0);
  int size=system_call(SYS_GETDENTS,target,buf,MAX_SIZE);
  while(sum<size){
	  if(dnt->d_name[0] != '.'){
		if(exec==1){
			system_call(SYS_STAT,dnt->d_name,sta);
			stati = sta->st_mode & S_IWUSR;
			if (stati != 0){
				stati = sta->st_mode & S_IXUSR;
				if (stati != 0){
					system_call(SYS_WRITE,STDOUT,dnt->d_name,strlen(dnt->d_name));
	  				system_call(SYS_WRITE,STDOUT,"\n",1);
				}
			}
		}
		else{
			system_call(SYS_WRITE,STDOUT,dnt->d_name,strlen(dnt->d_name));
	  		system_call(SYS_WRITE,STDOUT,"\n",1);
		}
	  }
	  sum+=dnt->d_reclen;
	  dnt=(struct linux_dirent*)(buf+sum);
  }
  system_call(SYS_WRITE,STDOUT,"\n",1);
  system_call(SYS_WRITE,STDOUT,"\n",1);
  return 0;
}