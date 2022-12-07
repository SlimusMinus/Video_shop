#include "Video_shop.h"

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Welcome in my video shop\n\n";
	Video_shop films1{ "Capitan America", "Gay Richi", "Action movie", 9.2, 150 };
	Video_shop films2{ "The Dictator", "Ivan Usovich", "Comedy", 7.1, 45 };
	Video_shop films3{ "Babbysitters", "Ridly Scott", "Comedy", 6.4, 130 };
	Video_shop films4{ "X-Men", "Martin Scorsez ", "Action movie", 8.25, 80 };
	Video_shop films5{ "Docotor Strande", "Piter Jekson", "Action movie", 8.94, 68.42 };
	Video_shop films6{ "The mummy", "Stiven Spilberg", "Horror", 5.45, 65.10 };
	Video_shop films7{ "Mist", "Gay Richi", "Horror", 6.35, 29.34 };
	Video_shop films8{ "Back to back", "Ivan Usovich","Comedy", 8.54, 56 };
	Video_shop films9{ "Silent Hill", "Stiven Spilberg", "Horror", 6.98, 45.05 };
	Video_shop films10{ "Hulk", "Tim Borton", "Action movie", 9, 15.39 };
	Video_shop* ar_films = new Video_shop [10] {films1, films2, films3, films4, films5, films6, films7, films8, films9, films10};
	for (int i = 0; i < 10; i++)
		cout << ar_films[i];
	Video_shop films;
	films.offfstream(*&ar_films);

	
	int k = 0,i;
	do
	{
		system("cls");
		cout << "Enter action 1 - read, 2 - search, 3 - the most popular film, 4 - print all, 5 - del, 6 - sort" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
		{
			films.ifffstream();
			system("cls");
			Video_shop films;
			films.ifffstream();

		}break;

		case 2:
		{
			films.ifffstream(); 
			system("cls");
			films.search(*&ar_films);
			films.offfstream(*&ar_films);
			
		}break;
		case 3:
		{
			films.ifffstream(); 
			system("cls");
			films.sort(*&ar_films);
			films.offfstream(*&ar_films);
			
		}break;
		case 4:
		{
			films.ifffstream(); 
			system("cls");
			for (int i = 0; i < 10; i++)
				cout << ar_films[i];
			films.offfstream(*&ar_films);
		}break;
		case 5:
		{
			films.ifffstream(); 
			system("cls");
			films.Del(*&ar_films);
			films.offfstream(*&ar_films);
		}break;
		case 6:
		{
			films.ifffstream(); 
			system("cls");
			films.sort_par(*&ar_films);
			films.offfstream(*&ar_films);
		}break;
		default:
			cout << "This number is hot found" << endl;
			break;
		}
		cout << "If you wanna continue press 1, no - 0" << endl;
		cin >> i;
		system("cls");

	} while (i == 1);
	

	
}