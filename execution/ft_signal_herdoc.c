#include ".././parsing/main.h"

void	signal_herdoc(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	exit(1);
}
