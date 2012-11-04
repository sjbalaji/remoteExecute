/* sys.c --- 
 * Filename: sys.c
 * Description: 
 * Author: balaji
 * Email:  sjbalajimdu@gmail.com
 * Organization:  IIT Madras
 * Created: Sat Nov  3 22:34:41 2012 (+0530)
 * Last-Updated: Sun Nov  4 01:03:09 2012 (+0530)
 *           By: balaji
 *     Update #: 46
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 1000
#define SLEN 100

int main (int argc, char * argv[]) {
  char username[LEN];
  char password[LEN];
  char commandFile[LEN];
  char command[LEN];
  char hostFile[LEN];
  char line[LEN];
  char ip[SLEN];
  char temp[LEN];
  char completecommand[LEN];
  FILE *hostfile= NULL, *commandfile=NULL;

  int i;
  if(argc == 1)
    {
      printf("Usage is remoteExecute -u username -p password -c commandFile -h hostFiles");
    }
  else
    {
      for (i=2;i<=argc;i=i+2)
	{
	  if(strcmp("-u",argv[i-1])==0)
	    {
	      strcpy(username,argv[i]);
	      #ifdef DEBUG_ON
	      printf("Username parsed \n");
	      printf("Usename is %s\n",username);
	      #endif
	    }
	  if(strcmp("-p",argv[i-1])==0)
	    {
	      strcpy(password,argv[i]);
	      #ifdef DEBUG_ON
	      printf("Password parsed \n");
	      printf("Password is %s\n",password);
	      #endif
	    }
	  if(strcmp("-c",argv[i-1])==0)
	    {
	      strcpy(commandFile,argv[i]);
	      commandfile = fopen(commandFile,"r");
	      #ifdef DEBUG_ON
	      printf("commandFile parsed \n");
	      printf("commandFile is %s\n",commandFile);
	      #endif
	    }
	  if(strcmp("-h",argv[i-1])==0)
	    {
	      strcpy(hostFile,argv[i]);
	      hostfile = fopen(hostFile,"r");
	      #ifdef DEBUG_ON
	      printf("hostFile parsed \n");
	      printf("hostFile is %s\n",hostFile);
	      #endif
	    }

	}

    }

  if(commandfile==NULL) {
    printf("Enter a valid command file\n");
    return 1;
  } else {
  	sprintf(command," '");
    while(fgets(line, sizeof(line), commandfile)) {
  	line[strlen(line)-1]='\0';
  	sprintf(temp," %s;",line);
  	strcat(command,temp);
  	}
  	strcat(command," '");
  	#ifdef DEBUG_ON
  	printf("Command formed -->%s \n",command);
  	#endif
  }

  if(hostfile==NULL) {
    printf("Enter a valid host file\n");
    return 1;
  } else {
    while(fgets(ip, sizeof(ip), hostfile)) {
	ip[strlen(ip)-1]='\0';
	#ifdef DEBUG_ON
	printf("IP read is -->%s ",ip);
	#endif
	sprintf(completecommand," sshpass -p '%s' ssh %s@%s %s &",password,username,ip,command);
	#ifdef DEBUG_ON
	printf("%s\n",completecommand);
	#endif
	system(completecommand);	
    }

  }

  return 0;
}
