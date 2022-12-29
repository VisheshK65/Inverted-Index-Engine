#include "info.h"

/*function used to assign respective color to the text*/
void red()
{
	printf("\033[1;31m");
}

void green()
{
	printf("\033[1;32m");
}

void yellow()
{
	printf("\033[1;33m");
}

/*reset the color from the set to system default color*/
void reset()
{
	printf("\033[0m");
}
