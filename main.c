#include <stdio.h>
#include <unistd.h>

void	signal_handler(int signal)
{
	static unsigned char	output_char;
	static int				count;

	if (signal == 0)
	{
		
		output_char = output_char << 1;
		count++;
	}
	if (signal == 1)
	{
		output_char = output_char << 1;
		output_char = output_char | 1;
		count++;
	}
	if (8 == count)
	{
		write(1, &output_char, 1);
		count = 0;
	}
}

int main()
{
	signal_handler(0);
	signal_handler(1);
	signal_handler(0);
	signal_handler(0);
	signal_handler(1);
	signal_handler(0);
	signal_handler(0);
	signal_handler(0);
	
	return (0);
}