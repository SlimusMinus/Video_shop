#include "Video_shop.h"

ostream& operator<<(ostream& os, Video_shop& film)
{
    os << film.name << "\t\t     " << film.author << "\t\t" << film.genre << "\t\t" << " rating is " << film.rating << "\t\t" << film.price << " $" << endl;
    return os;
}

Video_shop::Video_shop()
{
	name = " ";
	author = " ";
	genre = " ";
	rating = 0;
	price = 0;
}

Video_shop::Video_shop(string name, string author, string genre, double rating, double price)
{
    this->name = name;
	this->author = author;
    this->genre = genre;
    this->rating = rating;
    this->price = price;
}

void Video_shop::Print()
{
	cout << name << "\t\t     " << author << "\t\t" << genre << "\t\t" << " rating is " << rating << "\t\t" << price << " $" << endl;
}

void Video_shop::ifffstream()
{
	
	cout << "Read file" << endl;
	ifstream fin;
	Video_shop* new_films = new Video_shop[10];

	fin.open("Films_videoshop.txt");
	
	try
	{
		if (!fin.is_open())
			throw exception("File is not open");
		else
		{
			int i = 0;
			cout << "File is open" << endl;
			while (fin.read((char*)&new_films[i], sizeof(Video_shop)))
			{
				new_films[i].Print();
				i++;
			}
			cout << "End of read" << endl;
			fin.close();
			system("Films_videoshop.txt");
		}
	}
	catch (const exception& str)
	{
		system("cls");
		cout << str.what() << endl;
	}
    
}

void Video_shop::offfstream(Video_shop films[])
{
	ofstream fout;
	fout.open("Films_videoshop.txt");
	try
	{
		if (!fout.is_open())
			throw exception("File is not open");
		else
		{
			cout << "File is open" << endl;
			for (int i = 0; i < 10; i++)
			{
				fout.write((char*)&films[i], sizeof(Video_shop));
			}
			cout << "End of write" << endl;
			fout.close();
			system("Films_videoshop.txt");
		}
	}
	catch (const exception& str)
	{
		system("cls");
		cout << str.what() << endl;
	}

}

void Video_shop::search(Video_shop films[])
{
	int u = 0;
	int key1;
	bool w;
	do
	{
		cout << "Вы выбрали поиск, теперь выберете параметр для поиска 1 - название, 2 - режиссер, 3 - жанр" << endl;
		cin >> key1;
		switch (key1)
		{
		case 1:
		{

			cout << "Enter rname" << endl;
			cin >> name;
			for (int i = 0; i < 10; i++)
			{
				if (films[i].name == name) 
					films[i].Print();
				if (films[i].name != name) 
					u++;
			}
			if (u == 10) cout << "Такого названия нет" << endl;


		}break;
		case 2:
		{
			cout << "Enter author" << endl;
			cin >> name;
			for (int i = 0; i < 10; i++)
			{
				if (films[i].author == author) 
					films[i].Print();
				if (films[i].author != author)
					u++;
			}
			if (u == 5) cout << "Такого author нет" << endl;
		}break;
		case 3:
		{
			cout << "Enter genre" << endl;
			cin >> genre;
			for (int i = 0; i < 10; i++)
			{
				if (films[i].genre == genre) 
					films[i].Print();
				if (films[i].genre != genre) 
					u++;

			}
			if (u == 10) cout << "Такого genre нет" << endl;

		}break;
		default:
		{
			cout << "Такой параметр отсутствует" << endl;
		}break;
		}
		cout << "Если вы хотите осуществить поиск ещё по какому-то параметру, то нажмите 1 если нет то 0" << endl;
		cin >> w;
	} while (w == 1);
	delete[]films;
}

void Video_shop::sort(Video_shop films[])
{
	cout << " ******************* Sort rating ******************* " << endl;
	for (int i = 0; i < 10; i++)
		for (int j = i + 1; j < 10; j++)
			if (films[i].rating < films[j].rating)
				swap(films[i], films[j]);
	cout << films[0] << endl;
}

void Video_shop::Del(Video_shop*& films)
{
	int num;
	int size = 10;
	bool key = 1;
	do
	{
		system("cls");
		cout << "Choose the number of organisation you want to delete " << endl;
		cin >> num;
		cout << endl;
		if (num - 1 <= size && num - 1 >= 0)
		{
			Video_shop* tmp = new Video_shop [size - 1];
			for (unsigned short i = 0; i < num - 1; ++i)
					tmp[i] = films[i];
			for (unsigned short i = num - 1; i < size - 1; ++i)
				tmp[i] = films[i + 1];
			delete[]films;
			films = tmp;
			size -= 1;

			for (int i = 0; i < size; ++i)
				cout << tmp[i];
			cout << '\n';

			cout << "Delete one more? 1 - yes, 0 - no" << endl;
			cin >> key;
		}
		else
		{
			cout << "Error\n";
			cout << "Try again? 1 - yes, 0 - no" << endl;
			cin >> key;
		}
	} while (key);
	
}

void Video_shop::sort_par(Video_shop films[])
{
	int keys;
	bool q;
	do
	{
		cout << "Вы выбрали сортировку, теперь выберете параметр для сортировки 1 - название, 2 - цена" << endl;
		cin >> keys;
		switch (keys)
		{
		case 1:
		{
			for (int i = 0; i < 5; i++)
				for (int j = i + 1; j < 5; j++)
					if (films[j].name < films[i].name)
						swap(films[i], films[j]);
			for (int i = 0; i < 10; i++)
				films[i].Print();

		}break;
		case 2:
		{

			for (int i = 0; i < 5; i++)
				for (int j = i + 1; j < 5; j++)
					if (films[j].price < films[i].price)
						swap(films[i], films[j]);
			for (int i = 0; i < 10; i++)
				films[i].Print();

		}break;
		default:
		{
			cout << "Такой параметр отсутствует" << endl;
		}break;
		}
		cout << "Если вы хотите отсортировать ещё по какому-то параметру, то нажмите 1 если нет то 0" << endl;
		cin >> q;
	} while (q == 1);
	delete[]films;
}