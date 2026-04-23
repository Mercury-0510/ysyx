#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 3) {
        printf("missing variables!\n");
        return -1;
    }
    FILE *fpA;
    FILE *fpB;
	int ch;

	if ( (fpA = fopen(argv[1], "r")) == NULL) {
		perror("Open file fileA\n");
		exit(1);
	}
    if ( (fpB = fopen(argv[2], "w")) == NULL) {
        fclose(fpA);
        perror("Open file fileB\n");
        exit(1);
    }
	while ( (ch = fgetc(fpA)) != EOF)
		fputc(ch, fpB);
	fclose(fpA);
    fclose(fpB);
	return 0;
}
