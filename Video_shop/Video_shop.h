#include <iostream>
#include <ctime>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include <fstream>

using namespace std;
class Video_shop
{
	string name;
	string author;
	string genre;
	double rating;
	double price;
public:
	Video_shop();
	Video_shop(string name, string author, string genre, double rating, double price);
	void Print();
	friend ostream& operator << (ostream& os, Video_shop& film);
	void offfstream(Video_shop films[]);
	void ifffstream();
	void search(Video_shop films[]);
	void sort(Video_shop films[]);
	void Del(Video_shop *&films);
	void sort_par(Video_shop films[]);
};


