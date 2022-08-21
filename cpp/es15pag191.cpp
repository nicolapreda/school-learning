#include <iostream>
#include <string>
using namespace std;


struct book{	
	int code;
	char title[40];
	char author[40];
	int year;
	char editor[40];
};

void coll(int nBooks);
void searchCode(int code, int nBooks);
void searchName(char title[40], int nBooks);
void show(int index);


book library[100];

int main() {
	
	int nBooks;

	cout<<"Insert book to add: ";
	cin>>nBooks;
	for(int i=0; i<nBooks; i++){
		
		cout<<"insert book code";
		cin>>library[i].code;
		cout<<"insert book title";
		cin>>library[i].title;
		cout<<"insert book author";
		cin>>library[i].author;
		cout<<"insert book year";
		cin>>library[i].year;
		cout<<"insert book editor";
		cin>>library[i].editor;		
	}
	coll(nBooks);
	int code;
	char name[40];

	cout<<"Insert book code to search: ";
	cin>>code;
	
	searchCode(code, nBooks);
	
	cout<<"Insert book title to search: ";
	cin>>name;	
	
	searchName(name, nBooks);
	
	return 0;
}

void coll(int nBooks){
	
	cout<<"books of collections are: ";
	for(int i=0; i<nBooks; i++){
		
		cout<<library[i].title<<" ";
	}
	
	cout<<endl;
	
}

void searchCode(int code, int nBooks){
	
	cout<<"book with code "<<code<<" contains:  "<<endl;
	
	for(int i=0; i<nBooks; i++){
		
		if(library[i].code == code){
			show(i);
		}
		
	}
}
