using namespace std;

#ifndef BOOK_H
#define BOOK_H
// #pragma once

# include <string>
# include <vector>

class Book  
{
	private:
		std::string Name;
		std::string iSBN;
		vector<std::string> content;


	public:

		Book(std::string Name, std::string iSBN, vector<std::string> CONTENT);
		std::string getName();
		std::string getISBN();
		std::string getContent(int page);
		void addPage(std::string sentence);
		~Book();

};
#endif