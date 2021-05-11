#include <stdio.h>
#include <string.h> 
#include <errno.h>
#include <stdlib.h>
#include<string>
#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>

using namespace std;


int fc ;
int bv_init(char *fs_file) {
int re;
FILE *file;
file = fopen(fs_file, "w");

    if (file == NULL)
    {
        printf("File does not exists \n");
		printf("Creating the file \n");
		
			if(fprintf(file, NULL)){
				re= 0;
			}else{
				
				re -1;
				printf("an error: %s\n", strerror(errno));
			}
		
	}
		
		fclose(file);	
	
	return re;
}

int bv_destroy(const char *fileName) {

FILE *fi=fopen(fileName,"r");
fclose(fi);
int *mem= (int *)malloc(sizeof(int));
int i=fflush(fi);
if(i!=NULL){
return 0;
}else{
return -1;
}
free(mem);
}

int bv_open(const char *fileName, int mode) {
FILE * fp;
int BV_RDONLY = 0;
int BV_WCONCAT = 1;
int BV_WTRUNC = 2;
int errnum;
int ret;
   
	if(mode==BV_RDONLY){
		fp = fopen (fileName, "r");
		fc = fgetc(fp);

		if(fp!= NULL){
			ret= 0;
		}else{
			errnum = errno;
			ret= -1;
			printf("an error: %s\n", strerror(errnum));
		}
	}else if(mode==BV_WCONCAT){
		fp = fopen (fileName, "a");
		fc = fgetc(fp);
		if(fp!= NULL){
			ret= 0;
		}else{
			errnum = errno;
			ret= -1;
			printf("an error: %s\n", strerror(errnum));
		}
	}else if(mode==BV_WTRUNC){
		fp = fopen (fileName, "w");
		fc = fgetc(fp);
		if(fp!= NULL){
			ret= 0;
		}else{
			errnum = errno;
			ret= -1;
			printf("an error: %s\n", strerror(errnum));
		}
	}
	return ret;
}

int bv_close(const char *fileName) {
	FILE *fl=fopen(fileName,"r");
	fc=fgetc(fl);
int errnum = errno;
int re;
int i=fclose(fl);
if(i==0){
printf("File closed successfully");
re=0;
}else{
printf("an error: %s\n", strerror(errnum));
re= -1;
}
return re;
}




int bv_write(const char *fileName, const void *buf, size_t count) {
	int re;
FILE *fl=fopen(fileName,"w");
int iNodeIndex=fgetc(fl);
 if(iNodeIndex){
	 fwrite(buf, count, 1, fl);
	 printf("Success");
	 re= 0;
	}else{
	int errnum = errno;
	printf("An error occurred: %s\n", strerror(errnum));
	 re= -1;
 }
 return re;
}

int bv_read(const char *fileName, void *buf, size_t count) {
long size=NULL;
FILE *fl=fopen(fileName,"r");

	count=fread (buf,1,size,fl);
	if(count!=NULL){
	printf("Success");
	return 0;
	}else{
	int errnum = errno;
	printf("An error occurred: %s\n", strerror(errnum));
	return -1;
	}
}



int bv_unlink(const char* fileName) {
int flag=remove(fileName);
if(flag == 0) {
      printf("File deleted successfully");
	  return 0;
   } else {
      printf("Error: unable to delete the file");
	  int errnum = errno;
	  printf("Error while deleting the file %s\n", strerror(errnum));
	  return -1;
   }
}


int bv_ls(const char *dirname) {
	DIR *dir;
    struct dirent *dirent;
	dir = opendir (dirname);
	  if (dir != NULL) {

        while ((dirent = readdir (dir)) != NULL) {
            switch (dirent->d_type) {
            case DT_REG:
                printf ("%s\n", dirent->d_name);
				
                break;

            case DT_DIR:
                printf ("%s\n", dirent->d_name);
                break;

            case DT_LNK:
                printf ("%s\n", dirent->d_name);
                break;

            default:
                printf ("%s\n", dirent->d_name);
            }
        }

        closedir (dir);

    } else {
        printf ("Error when opening the directory %s\n", dirname);
    }
	  return EXIT_SUCCESS;
}
