#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void main() 
{
	int num1[5][6];
	int num2[6];
	int i, j, k, a=0, b=0, c=0;
	int cnt = 0;
	int sn1 = 0;

	srand((unsigned int)time(NULL));//��÷ ��ȣ ����
	for (i = 0; i < 6; i++) {
		num2[i] = (rand() % 45) + 1;
		for (j = 0; j < i; j++) {
			if (num2[i] == num2[j]) i--;
		}
	}

	while (a==0)
	{
		printf("========����========\n");
		printf("1. ���� ����\n");
		printf("2. ��÷ Ȯ��\n(���� ������ Ȯ�� ����)\n");
		printf("3. ���α׷� ����\n");
		printf("====================\n");
		printf("��ȣ�� ���� ���ּ��� : ");
		scanf("%d", &a);
		system("cls");
		switch (a)
		{
		case 1:
			if (cnt == 1)
			{
				printf("�̹� ������ ������ �ֽ��ϴ�.\n������ ����\n");
				printf("��====�١�====�١�====�١�====�ڡ�====�ڡ�====�ڡ�====��\n");
				for (i = 0;i < b;i++)
				{
					for (k = 0;k < 6;k++)
						printf("%d	", num1[i][k]);
					printf("\n");
				}
				printf("��====�١�====�١�====�١�====�ڡ�====�ڡ�====�ڡ�====��\n");
				a = 0;
				Sleep(2000);
				system("cls");
			}
			else
			{
				printf("���� �� ���� �� �� ������ �ּ���.(�ִ� 5����� ����) : ");
				scanf("%d", &b);
				for (i = 0;i < b;i++)
				{
					printf("%d ��° ���� ���� �ڵ� ���� 1. ���� 2. �ڵ� : ", i+1);
					scanf("%d", &c);
					if (c == 1)
					{
						printf("1~45 �߿� �ߺ����� �ʰ� ��ȣ�� �Է����ּ���.\n");
						printf("���� ���� ���� ���� ���� ���� �Է��� Enter\n");
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
						printf("�ڵ� ������ ��ȣ\n");
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
				printf("��÷ ��ȣ\n");
				printf("��====�١�====�١�====�١�====�ڡ�====�ڡ�====�ڡ�====��\n");
				printf("%d	%d	%d	%d	%d	%d\n", num2[0], num2[1], num2[2], num2[3], num2[4], num2[5]);
				printf("��====�١�====�١�====�١�====�ڡ�====�ڡ�====�ڡ�====��\n");
				for (i = 0;i < b;i++)
				{
					for (j = 0;j < 6;j++)
					{
						if (num1[i][j] == num2[j])
							sn1 = sn1 + 1;
					}
					if (sn1 == 6)
						printf("%d ��° ���� 1�� ��÷!!\n", i + 1);
					else if (sn1 == 5)
						printf("%d ��° ���� 2�� ��÷!!\n", i + 1);
					else if (sn1 == 4)
						printf("%d ��° ���� 3�� ��÷!!\n", i + 1);
					else if (sn1 == 3)
						printf("%d ��° ���� 4�� ��÷!!\n", i + 1);
					else if (sn1 == 2)
						printf("%d ��° ���� 5�� ��÷!!\n", i + 1);
					else
						printf("%d ��° ���� ��...\n", i + 1);
					sn1 = 0;
				}
				printf("�ƹ� Ű�� ������ ���� �� �� �ֽ��ϴ�.(ó��ȭ�� ���ư���� 0�Է�)");
				scanf("%d", &a);
				system("cls");
			}
			else
			{
				printf("���� ������ Ȯ�� �����մϴ�.\n");
				Sleep(1000);
				system("cls");
				a = 0;
			}
			break;
		case 3:
			printf("���α׷��� ����˴ϴ�.\n");
			break;
		default:
			a = 0;
			break;
		}
	}
}