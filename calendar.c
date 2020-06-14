#include<stdio.h>
#include<string.h>

int main(int argc, char** argv)
{
	int mode = 0;
	if (strcmp(argv[1], "-i") == 0) {
		if (argc < 6){
			printf("Not enough args...");
			return 1;
		} 
		return addEvent(argv[2],argv[3],argv[4],argv[5]);
	}
	return 0;
}

int addEvent(char *event, char *date, char *timeFrom, char *timeTo)
{
	FILE *fp;
	char writeString[256];
	strcpy(writeString, date);
	strcat(writeString, ":");
	strcat(writeString, timeFrom);
	strcat(writeString, ":");
	strcat(writeString, timeTo);
	strcat(writeString, ":");
	strcat(writeString, event);
   	fp = fopen("cal", "w+");
   	fprintf(fp, writeString);
   	fclose(fp);
	return 0;
}

