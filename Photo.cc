#include "Photo.h"
#include "Date.h"

Photo::Photo(const string& title, const string& category, const Date& date, const string& content){
    this->title = title;
    this->category = category;
    this->date = date;
    this->content = content;
}

Photo::Photo(){
    this->title = "";
    this->date = Date();
    this->content = "";
    this->category = "";
}

bool Photo::equals(const string& title) const{
    return this->title == title;
}

void Photo::print() const{
    cout << "Title: " << this->title << endl;
    this->date.print();
}

void Photo::display() const{
    cout << this->title << endl;
    this->date.print();
    cout << this->content << endl;
}


string Photo::getTitle() const{
    return this->title;
}

string Photo::getCategory() const{
    return this->category;
}

Date Photo::getDate() const{
    return this->date;
}

void Photo::print(ostream& out) const{
    out << this;
}

void Photo::display(ostream& out) const{
    out << this;
    cout << this->content << endl;
}

ostream& operator<<(ostream& out, const Photo& photo){
    out << "Title: " << photo.getTitle() << endl;
    out << "Category: " << photo.getCategory() << endl;
    out << "Date: " << photo.getDate() << endl;
    return out;
}