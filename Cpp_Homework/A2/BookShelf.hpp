#ifndef BOOKSHELF_H
#define BOOKSHELF_H
// #pragma once

# include <vector>
# include <string>
# include "Book.hpp"
	
class BookShelf  
{
	private:
		std::vector<Book> Shelf;

	public:

		BookShelf();
		void addBook(Book MYBook);
		void showBookShelf();
		~BookShelf();

};
#endif