class cashRegister
{
private:
	int cashOnHand;
public:
	cashRegister(); //Конструктор Устанавливает сумму наличных в кассе по умолчанию.
	cashRegister(int cashIn); //Конструктор Устанавливает наличные в кассе на определенную сумму.
	int getCurrentBalance();	//Возвращается значение CashOnHand.
	void acceptAmount(int amountIn);//Функция получения суммы, внесенной клиентом
	//и обновить сумму в реестре.
};

// Этот класс определяет элементы для реализации товаров.


class dispenserType
{
private:
	int numberOfItems; //переменная для хранения количества предметов в магазине
	int cost; //переменная для хранения стоимости товара
public:
	dispenserType(); //Конструктор Устанавливает стоимость и количество предметов в раздатчике по умолчанию.
	dispenserType(int setNoOfItems, int setCost); //Конструктор Устанавливает указанные значения
	int getNoOfItems();	//Возвращается значение NumberOfItems.
	int getCost();	//Функция отображения стоимости товара. Возвращается значение стоимости.
	void makeSale(); //Функция уменьшения количества элементов на 1.
};


cashRegister::cashRegister()
{
	cashOnHand = 500;
}

cashRegister::cashRegister(int cashIn)
{
	cashOnHand = cashIn;
}

int cashRegister::getCurrentBalance()
{
	return cashOnHand;
}

void cashRegister::acceptAmount(int amountIn)
{

	cashOnHand = cashOnHand + amountIn;
}

dispenserType::dispenserType()
{
	numberOfItems = 50;
	cost = 50;
}

dispenserType::dispenserType(int setNoOfItems, int setCost)
{
	numberOfItems = setNoOfItems;
	cost = setCost;
}

int dispenserType::getNoOfItems()
{
	return numberOfItems;
}

int dispenserType::getCost()
{
	return cost;
}

void dispenserType::makeSale()
{
	numberOfItems--;
}

#include <iostream>

void showSelection();
void sellProduct(dispenserType& product, cashRegister& pCounter);
int main()
{
	setlocale(LC_ALL, "Russian");
	cashRegister counter;
	dispenserType candy(100, 50);
	dispenserType chips(100, 65);
	dispenserType gum(75, 45);
	dispenserType cookies(50, 85);
	int choice;
	showSelection();
	std::cin >> choice;
	while (choice != 5)
	{
		switch (choice)
		{
		case 1:
			sellProduct(candy, counter);
			break;
		case 2:
			sellProduct(chips, counter);
			break;
		case 3:
			sellProduct(gum, counter);
			break;
		case 4:
			sellProduct(cookies, counter);
			break;
		default:
			std::cout << "Неверный выбор" << std::endl;
		}
		showSelection();
		std::cin >> choice;
	}
	return 0;
}

void showSelection()
{
	std::cout << "Выберете продукт " << std::endl;
	std::cout << "1 Конфеты" << std::endl;
	std::cout << "2 Чипсы" << std::endl;
	std::cout << "3 Жвачка" << std::endl;
	std::cout << "4 Печеньки" << std::endl;
	std::cout << "5 Выйти" << std::endl;
}

void sellProduct(dispenserType& product, cashRegister& pCounter)
{
	int amount; //переменная для хранения введенной суммы
	int amount2; //переменная для хранения необходимой дополнительной суммы
	if (product.getNoOfItems() > 0) //если товар не пуст
	{
		std::cout << "Внесите " << product.getCost() << std::endl;
		std::cin >> amount;
		if (amount < product.getCost())
		{
			std::cout << "Внесите еще " << product.getCost() - amount << std::endl;
			std::cin >> amount2;
			amount = amount + amount2;
		}

		if (amount = product.getCost())
		{
			pCounter.acceptAmount(amount);
			product.makeSale();
			std::cout << "Заберите ваш товар" << std::endl;
		}
		if (amount > product.getCost())
		{
			pCounter.acceptAmount(amount - product.getCost());
			product.makeSale();
			std::cout << "Заберите ваш товар и вашу сдачу в размере" << amount - product.getCost() << std::endl;
		}
		else
			std::cout << "Денег не хватает" << "Заберите ваши деньги." << std::endl;
	}
	else
		std::cout << "Извините, товар закончился" << std::endl;
}