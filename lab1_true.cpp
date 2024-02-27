#include <iostream>

class cashRegister {
private:
    int cashOnHand;
public:
    cashRegister() {
        cashOnHand = 500;
    }

    cashRegister(int cash) {
        cashOnHand = cash;
    }

    int getCurrentBalance() {
        return cashOnHand;
    }

    void acceptAmount(int amount) {
        cashOnHand += amount;
    }
};

class dispenserType {
private:
    int numberOfItems;
    int typeCost;
public:
    dispenserType() {
        numberOfItems = 50;
        typeCost = 50; // Установим стоимость продукта по умолчанию в 50
    }

    dispenserType(int items, int cost) {
        numberOfItems = items;
        typeCost = cost;
    }

    int getNoOfItems() {
        return numberOfItems;
    }

    int getCost() {
        return typeCost;
    }

    void makeSale() {
        if (numberOfItems > 0) {
            numberOfItems--;
        }
        else {
            std::cout << "Извините, товар закончился." << std::endl;
        }
    }
};

void showSelection() {
    std::cout << "1. Конфеты" << std::endl;
    std::cout << "2. Чипсы" << std::endl;
    std::cout << "3. Жвачка" << std::endl;
    std::cout << "4. Печенье" << std::endl;
}

void sellProduct(dispenserType& dispenser, cashRegister& cashReg) {
    int choice;
    std::cout << "Сделайте выбор: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "Вы выбрали конфеты." << std::endl;
        break;
    case 2:
        std::cout << "Вы выбрали чипсы." << std::endl;
        break;
    case 3:
        std::cout << "Вы выбрали жвачку." << std::endl;
        break;
    case 4:
        std::cout << "Вы выбрали печенье." << std::endl;
        break;
    default:
        std::cout << "Неверный выбор." << std::endl;
        return;
    }

    if (dispenser.getNoOfItems() > 0) {
        std::cout << "Стоимость товара: " << dispenser.getCost() << std::endl;
        int amount;
        std::cout << "Введите сумму: ";
        std::cin >> amount;

        if (amount >= dispenser.getCost()) {
            dispenser.makeSale();
            cashReg.acceptAmount(dispenser.getCost());
            std::cout << "Спасибо за покупку! Возьмите ваш товар." << std::endl;
        }
        else {
            std::cout << "Недостаточно средств." << std::endl;
        }
    }
    else {
        std::cout << "Извините, товар закончился." << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    dispenserType candyDispenser;
    cashRegister cashReg;

    std::cout << "Добро пожаловать! Выберите продукт:" << std::endl;
    showSelection();

    sellProduct(candyDispenser, cashReg);

    return 0;
}
