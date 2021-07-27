/*
	file_char_data.c

	Reads a file and prints number of characters,
	tabs, space, newline, alphabets, digits, special
	characters.
*/

#include <stdio.h>
#include <ctype.h>

typedef struct file_data
{
	int num_char;
	int num_newline;
	int num_tab;
	int num_space;
	int num_alpha;
	int num_digit;
	int num_special;
	int num_word;
} file_data;

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("No/invalid filename given. Try again.\n");
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");

	if (!fp)
	{
		printf("No such file exists. Try again.\n");
		return 2;
	}

	char ch;
	file_data fd = {0}; // 0 initialization to everything

	while ((ch = fgetc(fp)) != EOF)
	{
		printf("%c", ch);
		fd.num_char++;

		if (ch == '\n')
			fd.num_newline++;
		else if (ch == '\t')
			fd.num_tab++;
		else if (ch == ' ')
		{
			fd.num_space++;
			fd.num_word++;
		}
		else if (isalpha(ch))
			fd.num_alpha++;
		else if (isdigit(ch))
			fd.num_digit++;
		else
			fd.num_special++;
	}
	fd.num_word++;

	printf("\n\n");
	printf("Number of characters: %d\n", fd.num_char);
	printf("Number of newlines  : %d\n", fd.num_newline);
	printf("Number of tabs      : %d\n", fd.num_tab);
	printf("Number of alphabets : %d\n", fd.num_alpha);
	printf("Number of digits    : %d\n", fd.num_digit);
	printf("Number of special ch: %d\n", fd.num_special);
	printf("Number of words     : %d\n", fd.num_word);

	return 0;
}