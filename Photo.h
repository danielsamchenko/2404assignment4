
#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"

using namespace std;

class Photo {
    friend ostream& operator<<(ostream&, const Photo&);
		
	public:
        Photo(const string& title, const string& category, const Date& date, const string& content);
        Photo();

        bool equals(const string& title) const;
        void print() const;
        void display() const;
        string getTitle() const;
        string getCategory() const;
        Date getDate() const;
        void print(ostream&) const;
        void display(ostream&) const;

	private:
		string title;
        string content;
        Date date;
        string category;
	
};
#endif
