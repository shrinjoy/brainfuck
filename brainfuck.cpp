// brainfuck.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
char brainfuckChar[30000];//30k bytes of programable array;
int currentcounter=0;
int tempmem;
int loopstartindex=0;
int loopendindex=0;
int main()
{
	const std::string input=",.,.,.,.";
	for (int inp_indxcount = 0; inp_indxcount < input.length(); inp_indxcount++)
	{

		if (input[inp_indxcount] == '<')
		{
			if (currentcounter != 0)
			{
				currentcounter--;
			}
		}
		if (input[inp_indxcount] == '>')
		{	
			if (currentcounter < sizeof(brainfuckChar)/sizeof(char))
			{
				currentcounter++;
			}
		}
		else if (input[inp_indxcount] == '+')
		{
			
			brainfuckChar[currentcounter] = brainfuckChar[currentcounter] +1;
		}
		else if (input[inp_indxcount] == '-')
		{
			std::cout << "sub" << std::endl;
			brainfuckChar[currentcounter] = brainfuckChar[currentcounter] - 1;
		}
		else if (input[inp_indxcount] == '[')
		{
			std::cout << "loop start" << std::endl;
			loopstartindex = inp_indxcount;
		}
		else if (input[inp_indxcount] == ']' && brainfuckChar[currentcounter] !=0 )
		{
			std::cout << "loop end" << std::endl;
			inp_indxcount = loopstartindex;
		}
		else if (input[inp_indxcount] == '.')
		{
			int out = brainfuckChar[currentcounter];
			std::cout << out << std::endl;
		}
		else if (input[inp_indxcount] == 'c')
		{
			
			std::cout << brainfuckChar[currentcounter] << std::endl;
		}
		else if (input[inp_indxcount] == ',')
		{
			
			int inp;
			std::cin >> inp;
			brainfuckChar[currentcounter] = inp;
		}
		else
		{
			;; //anything apart from +-<>[],. will be ignored
		}
	}

	return 0;
}


/*> = increases memory pointer, or moves the pointer to the right 1 block.
< = decreases memory pointer, or moves the pointer to the left 1 block.
+ = increases value stored at the block pointed to by the memory pointer
- = decreases value stored at the block pointed to by the memory pointer
[ = like c while(cur_block_value != 0) loop.
] = if block currently pointed to's value is not zero, jump back to [
, = like c getchar(). input 1 character.
. = like c putchar(). print 1 character to the console*/