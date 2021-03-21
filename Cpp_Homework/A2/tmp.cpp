# include <string>
# include <iostream>
# include <vector>

using namespace std;

class Book  
{
	private:
		string Name;
		string iSBN;
		vector<string> content;

	public:

        Book(string Name, string iSBN, vector<string> content)
        {
            this->Name = Name;
            this->iSBN = iSBN;
            this->content = content;
        }

		string getName(){return Name;}

		string getISBN(){return iSBN;}

		string getContent(int page)
        {
            if (page > content.size())
                return "Error";
            return content[page];
        }

		void addPage(string sentence)
        {
            content.push_back(sentence);
            return;
        }
		// ~Book();

};

class BookShelf  
{
	private:
		vector<Book> Shelf;

	public:

		BookShelf();
		void addBook(Book MYBook)
        {
            Shelf.push_back(MYBook);
            return;
        }
		void showBookShelf(){
            for (int i = 0; i < Shelf.size(); ++i)
            {
                cout << i << " " << Shelf[i].getName() << " " << Shelf[i].getISBN() << "\n";
                // printf("%d %s %s\n", i, Shelf[i].getName(), Shelf[i].getISBN());
            }
        }
		// ~BookShelf();

};

int main(void){
    vector<string> CONTENT1;

    CONTENT1.push_back("book1p1");
    CONTENT1.push_back("book1p2");
    CONTENT1.push_back("book1p3");

    Book tmp = Book("Eroiko", "123-456-789", CONTENT1);
    cout << tmp.getName() << " " << tmp.getISBN() << " " << tmp.getContent(0);
}