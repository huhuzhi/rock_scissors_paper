#include "stdafx.h"

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>


void paintpic(char a)
{
	char paper[20][43] = {
		"               .'`                       \n",
		"            `$######|. ;@####|.          \n",
		"           '&#@;  |######&|$###;         \n",
		"          .%##;   :@###|.   :@#|.        \n",
		"          '&#$`   ;###!    `$######@;    \n",
		"  :@#####%|@#%.  .%##!    '&####$|&##|   \n",
		" !##$'`|#####%.         .|###%.   :&#$`  \n",
		" !##!    '&##%.        .|##!     ;@#@:   \n",
		" '&##;     :@$'               .!###$`    \n",
		"  .%##&:     :'             !@######%`   \n",
		"    '&#@;                   :@##&&@###;  \n",
		"     :@#%.                         |##!  \n",
		"    .%##!                     `;%####|   \n",
		"    :@#%.              `%#########&:     \n",
		"    `$##;            .|##@!.             \n",
		"     `$##$`        .|###|.               \n",
		"       ;@##@|.   ;&###|.                 \n",
		"         '$########&:                    \n",
		"             .':`                        \n",
		"                                         \n"
	};
	char rock[20][43] = {
		"                                         \n",
		"                    .:|%%!`              \n",
		"            :&##############$'           \n",
		"          .%##&;'!@#$`    :@######@!.    \n",
		"      `%#####|   ;@&'  :&###@%;:|&###%.  \n",
		"    .|###&&##;   :@@: |#@:         !##$` \n",
		"    ;##|  '$#!   .%#%;$#;           !##! \n",
		"    |##!   :@#|   '$#$$#&;..:$@;    :&#%.\n",
		" `$####%.   `$#@:  `$#&&#####&!`    `$#$`\n",
		".%##;`$#$'    ;@#@;'%###@!.         '&#$`\n",
		".%#@:  !##$'    !###@!.             :@#%.\n",
		" ;@#$`   !@##%%##@;                 |##; \n",
		"  ;##@:    '$##%`                  ;##%` \n",
		"   '$##@!..|#&'                  '&##$`  \n",
		"     `$#####&:               .!@###@:    \n",
		"         `%##$`           :&####&:       \n",
		"           ;@##%`     '$####@!.          \n",
		"             !@####@####@|`              \n",
		"                :$###&:                  \n",
		"                                         \n"
	};

	char scissors[20][43] = {
		"                                         \n",
		"           '%@#@$;.                      \n",
		"         |##########$`                   \n",
		"       .|##|      !@##@;                 \n",
		"       '&#$`        `$##@!               \n",
		"        |##|.         `%#######@!.       \n",
		"         |###|.          !#@||@####!     \n",
		"     `!%$&@#####%`      :&#!    `$##@:   \n",
		"  '&################%` .%#|.    .%####;  \n",
		" :&#&:          `!$@;  ;#@:     ;#@%&#&' \n",
		" !##!                .:$#$`    :@#! !##! \n",
		" :@#&:           .%######&:  .%#@;  ;##| \n",
		"  '&#####@&@#######|.   !######|.   ;##| \n",
		"     :%@######@@##$` `;$@######$'   |##; \n",
		"                !######&|:`  .!@#%.:@#$` \n",
		"                 :@#|.         !#&$##@:  \n",
		"                 '$##%'. .`:!%@#####%.   \n",
		"                  .|###########&!`       \n",
		"                                         \n",
		"                                         \n"
	};


	int i = 0;
	if(a=='r')
		for (i = 0; i < 20; i++)
			printf("%s", rock[i]);
	else if(a=='s')
		for (i = 0; i < 20; i++)
			printf("%s", scissors[i]);
	else if (a == 'p')
		for (i = 0; i < 20; i++)
			printf("%s", paper[i]);
	else
		printf("");
}


char * choosetostring(char *result, char choose)
{
	if (choose == 'r')
	{
		strcpy(result, "rock");
		return result;
	}
	else if (choose == 's')
	{
		strcpy(result, "scissors");
		return result;
	}
	else if (choose == 'p')
	{
		strcpy(result, "paper");
		return result;
	}
	else
		return NULL;
}

int judge(char player, char computer)
{
	char playerchoose[10];
	char computerchoose[10];
	if ((player == 'r' || player == 's' || player == 'p') && (computer == 'r' || computer == 's' || computer == 'p'))
	{
		if (((player == 'r') && (computer == 's')) || ((player == 's') && (computer == 'p')) || ((player == 'p') && (computer == 'r')))
		{
			printf("You Win!\n");
		}
		else if (((player == 's') && (computer == 'r')) || ((player == 'p') && (computer == 's')) || ((player == 'r') && (computer == 'p')))
		{
			printf("Computer Win!\n");
		}
		else
		{
			printf("It is a draw!\n");
		}
		printf("You choose %s\n", choosetostring(playerchoose, player));
		paintpic(player);
		printf("Computer choose %s\n", choosetostring(computerchoose, computer));
		paintpic(computer);
		return 1;
	}
	else
	{
		printf("Input error.\n\n");
		return -1;
	}
}

int main() 
{ 
	char playername[21] = { 0 };
	printf("Please input your name: ");
	scanf("%s", playername);
	while (strlen(playername) >= 20)
	{
		printf("Name Too Long, please input your name: ");
		scanf("%s", playername);
	}

	int count = 0;
	int ct = 0;
	printf("how many times do your want to play: ");
	scanf("%d", &count);
	while ( count< 0 || count >= 20)
	{
		printf("Too much, please input how many times do your want to play: ");
		scanf("%d", &count);
	}

	char computer = NULL;
	char player = NULL;
	char choose[3] = { 'r','s','p' };
	char c = NULL;
	while (ct<count)
	{
		system("cls");
		printf("Please input your choose, r=rock,s=scissors,p=paper,q=quit: \n");
		fflush(stdin);
		player = NULL;
		scanf("%c", &player);
		
		while ((c = getchar()) != '\n'&&c != EOF);

		if (player == 'q'|| player == 'Q')
		{
			break;
		}
		computer = choose[rand() % 3];
		if(judge(player, computer)==1)
			ct++;
		system("pause");

	}
	printf("Bye, %s,\n", playername);
	system("pause");
	return 0; 
}
