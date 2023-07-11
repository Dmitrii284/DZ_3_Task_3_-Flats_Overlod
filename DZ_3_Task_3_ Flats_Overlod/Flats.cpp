#include <cstdint>
#include <iostream>
#include<stdio.h>

/*
Задание 2.
Создать класс Flat (квартира).
Реализовать перегруженные операторы:
1. Проверка на равенство площадей квартир (операция
==).
2. Операцию присваивания одного объекта в другой
(операция =).
3. Сравнение двух квартир по цене (операция>)
*/

class Flat
{
private:
	double _area{0};
	double _price{ 0 };
public:
	Flat(double area = 0, double price = 0) : _area{ area }, _price{ price } { }

	Flat& operator=(Flat& flat)// По ссылке принимает объект класса Flat
	{
		if (this != &flat) // Сравниваем flat1 с flat2 (Смотр я как написано  в main  flat1 = flat2; Если мы напишем flat1 = flat1, то мы пропустим if
		{// if пишем для того чтобы не сравнивать один и тот же объект
			this->_area = flat._area;// 
			this->_price = flat._price;

			/*flat._area = 0;
			flat._price = 0;*/
		}

		return *this;
	}

	bool operator==(Flat& flat)
	{
		if (flat._area == this->_area) return true;
		return false;
	}

	double operator>(Flat& flat) { return this->_price > flat._price ? this->_price : flat._price; }

	void ShowData()
	{
		std::cout << "Price: " << _price << '\n';
		std::cout << "Area: " << _area << '\n';
	}
};

int main()
{
	setlocale(LC_ALL, "rus");

	Flat flat1{ 150.3, 115000.500 };
	Flat flat2{ 60.45, 24000.412 };
	printf("----------НАЧАЛЬНЫЕ ДАННЫЕ----------\n\n");
	printf("flat1 \n");
	flat1.ShowData();

	printf("\nflat2 \n");
	flat2.ShowData();
	// Присваивание квартир 
	printf("\n\nПрисваивание Площади и Стоимости Квартир: (из flat2 в flat1) \n\n");
	flat1 = flat2;

	printf("flat1 \n");
	flat1.ShowData();

	printf("\nflat2 \n");
	flat2.ShowData();
	printf("===================================\n\n");

	printf("Проверка на равенство площадей квартир(операция ==) \n\n");
	printf("flat1 == flat2: %i", flat1 == flat2);// %i" пишем какой тип вывести int

	printf("\n\nСравнение двух квартир по цене(операция >) \n\n");
	printf("flat1.price > flat2.price: %d ", flat1 > flat2, "\n\n\n");


	return 0;
}