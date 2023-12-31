/*Name:Uche Hadassah
This program receives and stores the details of 5 books, 
finds the index of the most expensive book,displays it 
and displays the list of all the books*/
#include<iostream>
#include<cstring>
using namespace std;
const int BOOKMAX = 5;
struct Book
{
	char author[100];
	char title[100];
	char publisher[100];
	int yearOfPublication;
	int isbn = 0;
	double price;
};

//Function prototypes
int mostExpIdx(Book[], int);
void displayBooks(Book[], int);
int main()
{
	Book bookDetails[BOOKMAX];

	for(int i = 0;i<BOOKMAX;i++)// Receives the details of the book from the user
	{
		cout << "Enter the details of book "<<i+1;
		cout << "\nTitle:";
		cin.getline(bookDetails[i].title, 100);
		cout << "Author:";
		cin.getline(bookDetails[i].author, 100);
		cout << "Publisher:";
		cin.getline(bookDetails[i].publisher, 100);
		cout << "Year of publication:";
		do
		{//Ensures the year is valid
			cin >> bookDetails[i].yearOfPublication;
			while (bookDetails[i].yearOfPublication < 1 || bookDetails[i].yearOfPublication > 2023)
			{
				cout << "Invalid year. Please enter the year of publication:";
				cin >> bookDetails[i].yearOfPublication;
			}
		} while (bookDetails[i].yearOfPublication < 1 || bookDetails[i].yearOfPublication > 2023);
		bookDetails[i].isbn = i;//Sets the ISBN
		cout << "Price:";
		do
		{//Ensures the price is valid
			cin >> bookDetails[i].price;
			while (bookDetails[i].price <= 0.0)
			{
				cout << "Invalid price. Please enter the price of the book:";
				cin >> bookDetails[i].price;
			}
		} while (bookDetails[i].price <= 0.0);
		cin.ignore();
	}
	cout << "\nThe index of the most expensive book is:" << mostExpIdx(bookDetails, BOOKMAX);
	int expIdx = mostExpIdx(bookDetails, BOOKMAX);
	displayBooks(bookDetails + expIdx, 1);//Display the most expensive book
	displayBooks(bookDetails, BOOKMAX);
}

int mostExpIdx(Book book[], int size)
{
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (book[i].price > book[index].price)
		{
			index = i;
		}
	}
	return index;//Returns the index
}

void displayBooks(Book book[], int size)
{
	for (int j = 0; j < size; j++)//Prints out the details of every book
	{
		cout << "\nBOOK " << j + 1;
		cout << "\nTitle:" << book[j].title;
		cout << "\nAuthor:" << book[j].author;
		cout << "\nPublisher:" << book[j].publisher;
		cout << "\nYear of publication:" << book[j].yearOfPublication;
		cout << "\nISBN:BOOK00" << book[j].isbn;
		cout << "\nPrice:$" << book[j].price;
		cout << endl;
	}
}
