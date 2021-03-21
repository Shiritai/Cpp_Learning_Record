# include "Book.hpp"

using namespace std;

Book(string Name, string iSBN, vector<string> content)
{
	this->Name = Name;
	this->iSBN = iSBN;
    this->CONTENT(CONTENT);
}

string Book::getName(){
    return Name;
}

string Book::getISBN(){
    return iSBN;
}

string Book::getContent(int page){
    if (page > content.size())
        return (string) "Error";
    return content[page];
}

void Book::addPage(string sentence){
    content.push_back(sentence);
    return;
}

	
Book::~Book() = default;