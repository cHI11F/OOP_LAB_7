#include "Bookstore.h"
#include <iostream>
#include <algorithm>


Bookstore::Bookstore() : name(""), stock(0), averagePrice(0.0), rating(0.0) {}


Bookstore::Bookstore(const std::string& name, int stock, double averagePrice, double rating)
    : name(name), stock(stock), averagePrice(averagePrice), rating(rating) {}


std::string Bookstore::getName() const {
    return name;
}

int Bookstore::getStock() const {
    return stock;
}

double Bookstore::getAveragePrice() const {
    return averagePrice;
}

double Bookstore::getRating() const {
    return rating;
}


Bookstore Bookstore::findMaxStock(Bookstore bookstores[], int size, int searchStock) {
    for (int i = 0; i < size; ++i) {
        if (bookstores[i].getStock() == searchStock) {
            return bookstores[i]; 
        }
    }
    return Bookstore(); 
}


void Bookstore::sortByRating(Bookstore bookstores[], int size) {
    std::sort(bookstores, bookstores + size, [](const Bookstore& a, const Bookstore& b) {
        return a.getRating() > b.getRating();
        });
}


void Bookstore::printStoresWithPriceLessThan(Bookstore bookstores[], int size, double price) {
    std::cout << "Магазини з середньою ціною книги менше ніж " << price << ":\n";
    bool found = false; 
    for (int i = 0; i < size; ++i) {
        if (bookstores[i].getAveragePrice() < price) {
            std::cout << bookstores[i].getName() << " - рейтинг: " << bookstores[i].getRating() << "\n";
            found = true; 
        }
    }
    if (!found) {
        std::cout << "Не знайдено магазинів з середньою ціною менше ніж " << price << ".\n";
    }
}
