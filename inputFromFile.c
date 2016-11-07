#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE * file;
	int i;
	char str[1000];
	file = fopen( "dic.txt" , "r");
	if (file)
	{
        for(i=0;i<25131;i++)
        {
            fscanf(file, "%s", str);
            printf("%s\n",str);
        }
	    fclose(file);
	}
	else
	{
		printf("Not opened\n");
	}
}
