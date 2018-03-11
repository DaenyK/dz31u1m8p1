#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <stdint.h>
#include <time.h>
#include <windows.h>

using namespace std;

unsigned short int q;

void main()

{
	setlocale(LC_ALL, "Russian");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	srand(time(NULL));

	unsigned short int nz;

	do
	{
		cout << "Введите номер задания: ";
		cin >> nz;
		switch (nz)
		{
		case 1:
		{
			cout << "Даны две фамилии.Определить, какая из них длиннее.\nвводите на англ языке\n";
			char surname1[20], surname2[20];
			printf("введите первую фамилию:");
			scanf("%s", surname1);
			printf("введите вторую фамилию:");
			scanf("%s", surname2);
			int end1, end2;
			end1 = strlen(surname1);
			end2 = strlen(surname2);

			if (end1 > end2)
				printf("первая фамилия длиннее\n");
			else if (end1 == end2)
				printf("фамилии одинаковые по длине\n");
			else if (end1 < end2)
				printf("вторая фамилия длиннее\n");
		}break;

		case 2:
		{
			cout << "Даны названия трех городов.Вывести на экран самое длинное и" << endl
				<< "самое короткое название\nвводите на англ языке\n";

			char city1[20], city2[20], city3[20];
			printf("введите название первого города:");
			scanf("%s", city1);
			printf("введите название второго города:");
			scanf("%s", city2);
			printf("введите название третьего города:");
			scanf("%s", city3);
			int end1, end2, end3;
			end1 = strlen(city1);
			end2 = strlen(city2);
			end3 = strlen(city3);

			if (end1 > end2 && end2 > end3)
				printf("название первого самое длинное, название третьего - короткое\n\n");
			else if (end1 > end3 && end3 > end2)
				printf("название первого самое длинное, название второго - короткое\n\n");
			else if (end2 > end3 && end3 > end1)
				printf("название второго самое длинное, название первого - короткое\n\n");
			else if (end2 > end1 && end1 > end3)
				printf("название второго самое длинное, название третьего - короткое\n\n");
			else if (end3 > end1 && end1 > end2)
				printf("название третьего самое длинное, название второго - короткое\n\n");
			else if (end3 > end2 && end2 > end1)
				printf("название третьего самое длинное, название первого - короткое\n\n");
			else if (end1 == end2&& end2 == end3)
				printf("длины названия городов одинаковые\n\n");
			else
				printf("длины названия 2-x городов одинаковые\n\n");
		}break;

		case 3:
		{
			cout << "Дано слово. Вывести на экран его третий символ\nвводите лучше на англ языке\n";
			char word[20];
			printf("введите любое слово: ");
			scanf("%s", word);
			printf("третий символ вашего слова: %c\n\n", word[2]);
		}break;

		case 4:
		{
			cout << "Введите массив символов из 12 элементов." << endl
				<< "Замените каждый символ - цифру на символ '!'\n\n";
			char symbol[13];
			symbol[12] = '/0';
			printf("введите любые символы (цифры, буквы, знаки и т.д.): ");
			scanf("%s", symbol);
			for (int i = 0; i < 13; i++)
			{
				int code = (int)symbol[i];
				if (code >= 48 && code <= 57)
					symbol[i] = '!';
			}

			for (int i = 12; i < strlen(symbol); i++)
			{
				symbol[i] = '\0';
			}

			printf("после: %s\n\n", symbol);
		}break;

		case 5:
		{
			cout << "Дана матрица символов размером 2×6. Сколько раз среди данных" << endl
				<< "символов встречаются символы +, -, *.\n\n";
			int plus = 0, minus = 0, star = 0;
			int mas[2][6];
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					mas[i][j] = 33 + rand() % 17;
					printf("%c \t", mas[i][j]);
					if (mas[i][j] == 43)
						plus++;
					if (mas[i][j] == 45)
						minus++;
					if (mas[i][j] == 42)
						star++;
				}
				cout << endl;
			}

			cout << "\nзнак плюса встретился: " << plus << " раз\n";
			cout << "знак минуса встретился: " << minus << " раз\n";
			cout << "знак звездочки встретился: " << star << " раз\n\n";
		}break;

		case 6:
		{
			cout << "что-то не получается, так чтобы  массив вводилась именно кириллица\n";
			cout << "Введите массив символов из 15 элементов. Подсчитать количество" << endl
				<< "гласных русских букв.\n\n";
			char symbol[16];
			symbol[15] = '/0';
			printf("введите любые символы (цифры, буквы, знаки и т.д.): ");
			scanf("%s", symbol);
			int count = 0;

			/*for (int i = -128; i <= 128; i++)
			{
				printf("%d - %c\t", i, i);
			}
			cout << endl << endl;*/

			for (int i = 0; i < 16; i++)
			{
				int code = (int)symbol[i];
				if (code == -31 || code == -27 || code == -24 || code == -17 || code == -12)
					count++;
				else if (code == -5 || code == -3 || code == -2 || code == -1)
					count++;
				/*else if (code == 224 || code == 229 || code == 232 || code == 238 || code == 243)
					count++;
				else if (code == 251 || code == 253 || code == 254 || code == 255)
					count++;*/
			}

			printf("количество гласных букв: %d\n\n", count);
		}break;

		case 7:
		{
			cout << "Дан массив символов, среди которых есть символ двоеточие ‘:’." << endl
				<< "Определить, сколько символов ему предшествует.\n\n";
			char sentence[] = "your number: eight";
			printf("%s\n", sentence);
			int i;
			for (i = 0; i < strlen(sentence); i++)
			{
				if (sentence[i] == ':')
					break;
			}
			printf("переод знаком двоеточия %d символов\n\n", i);
		}break;

		case 8:
		{
			cout << "Дан массив символов. Определить, сколько раз входит в него группа букв abc.\n\n";
			char sentence[16];
			sentence[15] = '\0';
			printf("введите предложение: ");
			scanf("%s", sentence);
			int count = 0;

			for (int i = 0; i < strlen(sentence); i++)
			{
				if (sentence[i] == 'a')
					if (sentence[i + 1] == 'b')
						if (sentence[i + 2] == 'c')
							count++;
			}
			printf("группа букв abc встречается %d раз\n\n", count);
		}break;

		case 9:
		{
			cout << "Заданы две строки. Построить новую строку, состоящую из символов, которые " << endl
				<< "входят в первую строку, но не входят во вторую.\n\n";

			char s1[10], s2[10];

			printf("введите первую строку: ");
			scanf("%s", s1);

			printf("введите вторую строку: ");
			scanf("%s", s2);
			int a = 0;
			for (int i = 0; i <strlen(s1); i++)
			{
				for (int j = 0; j < strlen(s2); j++)
				{
					if (s1[i] == s2[j])
						s1[i] =' ';
				}
			}
			printf("новая строка: %s\n\n", s1);

		}break;
		}


		cout << "Хотите продолжить 1/0?";
		cin >> q;


		switch (q)
		{
		case 1:
			system("cls");
			break;
		default:
			cout << "ошибка" << endl;
		}
	} while (nz > 0);


}