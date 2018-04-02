// Calctlator.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
float Operation(int, char, int);
char   DeleteSpaceAndIllegalCharacters(void);
size_t FindParentheses(char temporaryArray[]);
size_t FindMultiplicationAndDivision(char[], int, int);
size_t FindPlusAndMinus(char[], int, int);
bool   IllegalCharactersCheck(char tempchar);
float  ChooseNumber(char);
int leftBrackets = 0, rightBrackets = 0;//  '(' and ')'
void deleteStr(char[], int, int);
size_t NumberOfExecution(char[], char);
float result = 0;

int    main(void)
{
	char  calc[50] = { 0 };int i = 0;
	cout << "Please input calculation formula to calculate: ";
	while ((calc[i] = DeleteSpaceAndIllegalCharacters()) != '\n')
	{
		if (calc[i] != '\0')
			i++;
	}
	calc[i]='\0';
	while (FindParentheses(calc))
	{
		while (FindMultiplicationAndDivision(calc, 0, strlen(calc)))
		{
			int cheng = FindMultiplicationAndDivision(calc, 0, strlen(calc));
			result = Operation(calc[cheng - 1], calc[cheng], calc[cheng + 1]);
			calc[cheng - 1] = 'T';
			deleteStr(calc, cheng, 2);
		}
		while (FindPlusAndMinus(calc, 0, strlen(calc)))
		{
			int add = FindPlusAndMinus(calc, 0, strlen(calc));
			result = Operation(calc[add - 1], calc[add], calc[add + 1]);
			cout << "Answer: " << result << endl;
			calc[add - 1] = 'T';
			deleteStr(calc, add, 2);
		}
		calc[leftBrackets] = calc[leftBrackets + 1];
		for (int temp = leftBrackets+1;temp<strlen(calc-2);temp++)
		{
			calc[temp] = calc[temp + 2];
		}
		calc[strlen(calc) - 2] = '\0';
	}

	while (FindMultiplicationAndDivision(calc,0,strlen(calc)))
	{
		int cheng = FindMultiplicationAndDivision(calc, 0, strlen(calc));
		result = Operation(calc[cheng - 1], calc[cheng], calc[cheng + 1]);
		calc[cheng - 1] = 'T';
		deleteStr(calc, cheng, 2);
	}
	
	while (FindPlusAndMinus(calc, 0, strlen(calc)))
	{
		int add = FindPlusAndMinus(calc, 0, strlen(calc));
		result = Operation(calc[add - 1], calc[add], calc[add + 1]);
		calc[add - 1] = 'T';
		deleteStr(calc, add, 2);
	}

	cout << "Answer: " << result << endl;
    return 0;
}

float Operation(int previous, char operators, int latter)
{
	switch (int(operators))
	{
	case 43:
		return ChooseNumber(previous) + ChooseNumber(latter);
		break;
	case 45:
		return ChooseNumber(previous) - ChooseNumber(latter);
		break;
	case 42:
		return ChooseNumber(previous) * ChooseNumber(latter);
		break;
	case 47:
		if (0 == latter)
		{
			cout << "Input ERROR!\a\a" << endl;
			exit(-1);
		}
		return ChooseNumber(previous) / ChooseNumber(latter);
		break;
	}
	return 0;
}

bool   IllegalCharactersCheck(char tempchar)// YES RETURN TRUE
{
	if ((int)tempchar == 45 || (int)tempchar == 47 || (int)tempchar == 104 || ((int)tempchar >= 40 &&(int)tempchar <= 43) || ((int)tempchar >= 48 && (int)tempchar <= 57))
		return false;
	return true;
}

char   DeleteSpaceAndIllegalCharacters(void)
{
	char tempchar = getchar();
// 	if (IllegalCharactersCheck(tempchar)==1)
// 	{
// 		cout << "You have entered illegal characters (such as Chinese characters or other not space  characters)." << endl;
// 		exit(-1);
// 	}
	if ( tempchar != ' ' )
			return tempchar;
	return '\0';
}

size_t FindParentheses(char temporaryArray[])
{
	for (int i = 0; i < strlen(temporaryArray); i++)
	{
		
		if ('('==temporaryArray[i])
		{
			leftBrackets = i;
			for (int j = i; j < strlen(temporaryArray); j++)
			{
				if (')'==temporaryArray[j])
				{
					rightBrackets = j;
				}
			}
			if (rightBrackets==0)
			{
				cout << "Input ERROR,Please check!\a\n" << endl;
				exit(-2);
			}
			
		}
	}
	return NO;
}
size_t FindMultiplicationAndDivision(char temporaryArray[], int begin, int finall)
{
	for (int i = begin; i < finall; i++)
	{
		if ('*'==temporaryArray[i]||'/'==temporaryArray[i])
		{
			return i;
		}
	}
	return NO;
}
size_t FindPlusAndMinus(char temporaryArray[], int begin, int finall)
{
	for (int i = begin; i < finall; i++)
	{
		if ('+' == temporaryArray[i] || '-' == temporaryArray[i])
		{
			return i;
		}
	}
	return NO;
}
float ChooseNumber(char temp)
{
	if (temp=='T')
	{
		return result;
	}
	switch ((int)temp)
	{
	case 48:
		return 0;
	case 49:
		return 1;
	case 50:
		return 2;
	case 51:
		return 3;
	case 52:
		return 4;
	case 53:
		return 5;
	case  54:
		return 6;
	case 55:
		return 7;
	case 56:
		return 8;
	case 57:
		return 9;
	}
	return -3;
}

void deleteStr(char tempArray[],int begin,int lengh)
{
	int i;
	if (begin==strlen(tempArray)-3)//deal to end
	{
		tempArray[begin] = '\0';
		return;
	}
	if (strlen(tempArray)==3)//deal to start
	{
		tempArray[0] = '\0';
		return;
	}

	for ( i=begin;i<strlen(tempArray)-lengh;i++)
	{
		tempArray[i] = tempArray[i + lengh];
	}
	tempArray[strlen(tempArray) - 2] = '\0'; 
	return;
}

size_t NumberOfExecution(char tempArray[], char c)
{
	size_t sum = 0;
	for (size_t i = 0; i < strlen(tempArray); i++)
	{
		if (tempArray[i]==c)
		{
			sum++;
		}
	}
	return sum;
}//No use


