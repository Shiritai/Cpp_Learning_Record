#include "BookShelf.hpp"
# include "Book.hpp"
	
BookShelf::BookShelf()
{
	
}

void BookShelf::addBook(Book MYBook){
    Shelf.push_back(MYBook);
    return;
}

void BookShelf::showBookShelf(){
    for (int i = 0; i < Shelf.size(); ++i){
        printf("%d %s %s\n", i, Shelf[i].getName(), Shelf[i].getISBN());
    }
}
	
BookShelf::~BookShelf()
{
	
}