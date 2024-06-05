#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void main() 
{
	int num1[4][5];
	int num2[5];
	int i, j, k, a=0, b=0, c=0;
	int cnt = 0;
	int sn1 = 0;

	srand((unsigned int)time(NULL));//당첨 번호 생성
	for (i = 0; i < 6; i++) {
		num2[i] = (rand() % 45) + 1;
		for (j = 0; j < i; j++) {
			if (num2[i] == num2[j]) i--;
		}
	}

	while (a==0)
	{
		printf("========복권========\n");
		printf("1. 복권 구입\n");
		printf("2. 당첨 확인\n(복권 구입후 확인 가능)\n");
		printf("3. 프로그램 종료\n");
		printf("====================\n");
		printf("번호를 선택 해주세요 : ");
		scanf("%d", &a);
		system("cls");
		switch (a)
		{
		case 1:
			if (cnt == 1)
			{
				printf("이미 구입한 복권이 있습니다.\n구입한 복권\n");
				printf("☆====☆★====☆★====☆★====★☆====★☆====★☆====☆\n");
				for (i = 0;i < b;i++)
				{
					for (k = 0;k < 6;k++)
						printf("%d	", num1[i][k]);
					printf("\n");
				}
				printf("☆====☆★====☆★====☆★====★☆====★☆====★☆====☆\n");
				a = 0;
				Sleep(2000);
				system("cls");
			}
			else
			{
				printf("구입 할 복권 수 를 선택해 주세요.(최대 5장까지 가능) : ");
				scanf("%d", &b);
				for (i = 0;i < b;i++)
				{
					printf("%d 번째 복권 수동 자동 선택 1. 수동 2. 자동 : ", i+1);
					scanf("%d", &c);
					if (c == 1)
					{
						printf("1~45 중에 중복되지 않게 번호를 입력해주세요.\n");
						printf("숫자 숫자 숫자 숫자 숫자 숫자 입력후 Enter\n");
						scanf("%d %d %d %d %d %d", &num1[i][0], &num1[i][1], &num1[i][2], &num1[i][3], &num1[i][4], &num1[i][5]);
						printf("\n");
					}
					else if (c == 2)
					{
						for (j = 0; j < 6; j++) {
							num1[i][j] = (rand() % 45) + 1;
							for (k = 0; k < j; k++) {
								if (num1[i][j] == num1[i][k]) j--;
							}
						}
						printf("자동 생성된 번호\n");
						printf("%d %d %d %d %d %d\n\n", num1[i][0], num1[i][1], num1[i][2], num1[i][3], num1[i][4], num1[i][5]);
					}
				}
				a = 0;
				cnt = 1;
				Sleep(2000);
				system("cls");
			}
			break;
		case 2:
			if (cnt == 1)
			{
				printf("당첨 번호\n");
				printf("☆====☆★====☆★====☆★====★☆====★☆====★☆====☆\n");
				printf("%d	%d	%d	%d	%d	%d\n", num2[0], num2[1], num2[2], num2[3], num2[4], num2[5]);
				printf("☆====☆★====☆★====☆★====★☆====★☆====★☆====☆\n");
				for (i = 0;i < b;i++)
				{
					for (j = 0;j < 6;j++)
					{
						if (num1[i][j] == num2[j])
							sn1 = sn1 + 1;
					}
					if (sn1 == 6)
						printf("%d 번째 복권 1등 당첨!!\n", i + 1);
					else if (sn1 == 5)
						printf("%d 번째 복권 2등 당첨!!\n", i + 1);
					else if (sn1 == 4)
						printf("%d 번째 복권 3등 당첨!!\n", i + 1);
					else if (sn1 == 3)
						printf("%d 번째 복권 4등 당첨!!\n", i + 1);
					else if (sn1 == 2)
						printf("%d 번째 복권 5등 당첨!!\n", i + 1);
					else
						printf("%d 번째 복권 꽝...\n", i + 1);
					sn1 = 0;
				}
				printf("아무 키나 눌러서 종료 할 수 있습니다.(처음화면 돌아가기는 0입력)");
				scanf("%d", &a);
				system("cls");
			}
			else
			{
				printf("복권 구입후 확인 가능합니다.\n");
				Sleep(1000);
				system("cls");
				a = 0;
			}
			break;
		case 3:
			printf("프로그램이 종료됩니다.\n");
			break;
		default:
			a = 0;
			break;
		}
	}
}
