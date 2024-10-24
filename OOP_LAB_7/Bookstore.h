#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <string>

class Bookstore {
private:
    std::string name;       
    int stock;              
    double averagePrice;    
    double rating;          

public:
    
    Bookstore();

    
    Bookstore(const std::string& name, int stock, double averagePrice, double rating);

   
    std::string getName() const;
    int getStock() const;
    double getAveragePrice() const;
    double getRating() const;

    
    static Bookstore findMaxStock(Bookstore bookstores[], int size, int searchStock); 
    static void sortByRating(Bookstore bookstores[], int size);                    
    static void printStoresWithPriceLessThan(Bookstore bookstores[], int size, double price); 
};

#endif 