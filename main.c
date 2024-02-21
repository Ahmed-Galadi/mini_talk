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

void send_bits(unsigned char character)
{
	unsigned char	output;
	int				i;

	output = 0;
	i = 8;
	while (i--)
	{
		output = (character >> i) & 1;
		if (output)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
}

int main()
{
	send_bits('H');
	
	return (0);
}