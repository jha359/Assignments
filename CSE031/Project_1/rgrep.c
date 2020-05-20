#include <stdio.h>
#define MAXSIZE 4096

/**
 * You can use this recommended helper function 
 * Returns true if partial_line matches pattern, starting from
 * the first char of partial_line.
 */
int matches_leading(char *partial_line, char *pattern) {
  // Implement if desire 

  return 0;
}

/**
 * You may assume that all strings are properly null terminated 
 * and will not overrun the buffer set by MAXSIZE 
 *
 * Implementation of the rgrep matcher function
 */
int rgrep_matches(char *line, char *pattern) 
{
	int begin = 0;
	int i = 0;
	int j = 0;
	int skip = 0;
	int cmatch = 0;
	int pmatch = 0;

	for( ; *(line + begin) != '\0'; begin++)
	{
		j = 0;
//if pattern begins with '.'
		if( *(pattern) == '.')
		{
			if(*(pattern + 1) == '?')
			{
				if(*(pattern + 2) == *(line + begin + 1))
				{
					j = j + 2;
					i = begin + 1;
					pmatch = 1;
				}
				else if(*(pattern + 2) == *(line + begin))
				{
					j = j + 2;
					i = begin;
					pmatch = 1;
				}
			}
			else if(*(pattern + 1) == '+')
			{
				for(int x = begin; *(line + x) != *(pattern + 2); x++)
				{
					begin = x;
					if( *(line + x) == '\0')
					{
						return 0;
					}
				}
				if( *(line + begin + 1) == *(pattern + 2))
				{
					j = j + 2;
					i = begin + 1;
					pmatch = 1;
				}
				else
				{
					i = 0;
				}
			}
			else if(*(pattern + 1) == '\\')
			{
				pmatch = 1;
			}
			else if(*(line + begin + 1) == *(pattern + 1))
			{
				j = 1;
				i = begin + 1;
				pmatch = 1;
			}
		}
//if pattern begins with '\'		
		else if( *(pattern) == '\\')
		{
			if( *(line + begin) == *(pattern))
			{
				pmatch = 1;
			}
			else if( *(line + begin) == *(pattern + 1))
			{
				j = j + 1;
				i = begin;
				pmatch = 1;
			}
		}
		else
		{
			if( *(line + begin) == *(pattern))
			{
				i = begin;
				pmatch = 1;
			}
		}

// Condition checking begins, god help me

		if(pmatch == 1)
		{
			for( ; pmatch == 1; i++ , j++)
			{
				skip = 0;
//'?' Wildcard
				if( *(pattern + j + 1) == '?')
				{
					if( *(pattern + j) == 92)
					{
						if(*(line + i) != '?')
						{
							pmatch = 0;
						}
						else
						{
							j++;
						}
					}
					else if( *(pattern + j) == '.')
					{
						if( *(pattern + j + 2) == *(line + i + 1))
						{
							skip = 1;
							j = j + 2;
							i++;
						}
						else if( *(pattern + j + 2) == *(line + i))
						{
							skip = 1;
							j = j + 2;
						}
						else if( *(pattern + j + 2) == '\0' || *(pattern + j + 2) == '\n')
						{
							skip = 1;
							j = j + 2;
						}
					}
					else if( *(line + i) == *(pattern + j + 2))
					{
						skip = 1;
						j = j + 2;
					}
					else if( *(line + i) == *(pattern + j))
					{
						skip = 1;
						j = j + 1;
					}
					else if( *(pattern + j + 2) == '\0' || *(pattern + j + 2) == '\n')
					{
						skip = 1;
						j = j + 2;
					}
					else
					{
						pmatch = 0;
					}
				}

// '+' Wildcard
				else if( *(pattern + j + 1) == '+')
				{
					int k = i;
					if( *(pattern + j) == '\\')
					{
						if(*(line + i) != '+')
						{
							pmatch = 0;
						}
						j++;
					}
					else if( *(pattern + j) == '.')
					{
						if(*(pattern + j + 2) == '\0' || *(pattern + j + 2) == '\n')
						{
							cmatch = 1;
						}
						else
						{
							for( ; *(line + k) != *(pattern + j + 2); k++)
							{
								i = k;
							}
							if(*(line + k) != *(pattern + j + 2))
							{
								pmatch = 0;
							}
							else
							{
								j = j + 2;
								i = i + 1;
							}
						}
					}
					else
					{
						if(*(line + i) == *(pattern + j) && *(pattern + j + 2) == '\0')
						{
							i = k;
							cmatch = 1;
						}
						else
						{					
							for( ; *(line + k) == *(pattern + j); k++)
							{
								i = k;
							}
							if(*(line + k) == *(pattern + j + 2))
							{
								j = j + 2;
								i = i + 1;
							}
							else if(*(line + k) == *(pattern + j + 3))
							{
								j = j + 3;
								i = i + 1;
							}
							else
							{
								pmatch = 0;
							}
						}
					}
				}

// '.' Wildcard

				else if( *(pattern + j) == '.')
				{
					if(*(pattern + j + 1) == '\0')
					{
						cmatch = 1;
					}
					skip = 1;
				}

// '\' Wildcard
				else if(*(pattern + j) == '\\')
				{
					if(*(pattern + j + 1) == '.')
					{
						if(*(pattern + j + 2) == '?')
						{
							if(*(pattern + j + 1) == *(line + i))
							{
								j = j + 3;
								i = i + 1;
								
							}
							else if(*(pattern + j + 3) == *(line + i))
							{
								j = j + 3;
							}
						}
						else if(*(pattern + j + 2) == '+')
						{
							int k = i;
							for( ; *(line + k) == '.'; k++)
							{
								i = k;
							}
							if(*(line + k) == '\0' || *(line + k) == '\n')
							{
								return 1;
							}
							else if(*(line + k) == *(pattern + j + 3))
							{
								i = i + 1;
								j = j + 3;
							}
							else
							{
								pmatch = 0;
							}
						}
						else
						{
							j = j + 1;
						}
					}
					else if(*(pattern + j + 1) == '\\')
					{
						if(*(pattern + j + 2) == '?')
						{
							if(*(pattern + j + 1) == *(line + i))
							{
								j = j + 3;
								i = i + 1;
								
							}
							else if(*(pattern + j + 3) == *(line + i))
							{
								j = j + 3;
							}
						}
						else if(*(pattern + j + 2) == '+')
						{
							int k = i;
							for( ; *(line + k) == '\\'; k++)
							{
								i = k;
							}
							if(*(line + k) == '\0' || *(line + k) == '\n')
							{
								return 1;
							}
							else if(*(line + k) == *(pattern + j + 3))
							{
								i = i + 1;
								j = j + 3;
							}
							else
							{
								pmatch = 0;
							}
						}
						else
						{
							if(*(line + i) != *(pattern + j + 1))
							{
								pmatch = 1;
							}
							j = j + 1;
						}
					}
				}
// Basic comparison

				else if	(*(line + i) != *(pattern + j) && skip == 0)
				{
					pmatch = 0;
				}
	
				if( *(pattern + j) == '\0' || *(pattern + j) == '\n')
				{
					cmatch = 1;
					break;
				}
				
				}
					if(cmatch == 1)
					{
					return 1;
					}
					begin = i;
		}
	}
	if(cmatch == 0)
	{
		return 0;
	}
return 1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PATTERN>\n", argv[0]);
        return 2;
    }

    /* we're not going to worry about long lines */
    char buf[MAXSIZE];

    while (!feof(stdin) && !ferror(stdin)) {
        if (!fgets(buf, sizeof(buf), stdin)) {
            break;
        }
        if (rgrep_matches(buf, argv[1])) {
            fputs(buf, stdout);
            fflush(stdout);
        }
    }

    if (ferror(stdin)) {
        perror(argv[0]);
        return 1;
    }

    return 0;
}
