#include <iostream>
#include "Bookstore.h"

int main() {
    int SIZE; 
    std::cout << "Введіть кількість магазинів: ";
    std::cin >> SIZE;
    std::cin.ignore(); 

    Bookstore* bookstores = new Bookstore[SIZE]; 

    
    for (int i = 0; i < SIZE; ++i) {
        std::string name;
        int stock;
        double averagePrice;
        double rating;

        std::cout << "Введіть назву магазину #" << (i + 1) << ": ";
        std::getline(std::cin, name);
        std::cout << "Введіть кількість книг на складі: ";
        std::cin >> stock;
        std::cout << "Введіть середню ціну книги: ";
        std::cin >> averagePrice;
        std::cout << "Введіть рейтинг магазину: ";
        std::cin >> rating;
        std::cin.ignore(); 

        bookstores[i] = Bookstore(name, stock, averagePrice, rating); 
    }

    
    int searchStock;
    std::cout << "Введіть кількість книг у магазині для пошуку: ";
    std::cin >> searchStock;

    Bookstore maxStore = Bookstore::findMaxStock(bookstores, SIZE, searchStock);
    if (maxStore.getStock() > 0) {
        std::cout << "Знайдений магазин: " << maxStore.getName() << " - рейтинг: " << maxStore.getRating() << "\n";
    }
    else {
        std::cout << "Магазин з такою кількістю книг не знайдено.\n";
    }

    
    Bookstore::sortByRating(bookstores, SIZE);
    std::cout << "Сортування магазинів за рейтингом:\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << bookstores[i].getName() << " - рейтинг: " << bookstores[i].getRating() << "\n";
    }

    
    double priceLimit;
    std::cout << "Введіть середню ціну для фільтрації: ";
    std::cin >> priceLimit;
    Bookstore::printStoresWithPriceLessThan(bookstores, SIZE, priceLimit);

    delete[] bookstores; 
    return 0;
}
