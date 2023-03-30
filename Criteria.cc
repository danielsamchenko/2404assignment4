#include "Criteria.h"
#include "Photo.h"
#include "Date.h"



Cat_Criteria::Cat_Criteria(const string& category){
    this->category = category;
}

bool Cat_Criteria::matches(const Photo& photo) const{
    return photo.getCategory() == this->category;
}

void Cat_Criteria::print(ostream& out) const{
    out << "Category: " << this->category << endl;
}

Date_Criteria::Date_Criteria(const Date& start, const Date& end){
    this->start = start;
    this->end = end;
}

bool Date_Criteria::matches(const Photo& photo) const{
    //create the function without a <= and >= operator
    return (photo.getDate() > this->start || photo.getDate() == this->start) && (photo.getDate() < this->end || photo.getDate() == this->end);
}

void Date_Criteria::print(ostream& out) const{
    out << "Start Date: " << this->start << endl;
    out << "End Date: " << this->end << endl;
}

CandD_Criteria::CandD_Criteria(const Date& start, const Date& end, const string& category) : Cat_Criteria(category), Date_Criteria(start, end){
}

bool CandD_Criteria::matches(const Photo& photo) const{
    return Cat_Criteria::matches(photo) && Date_Criteria::matches(photo);
}

void CandD_Criteria::print(ostream& out) const{
    Cat_Criteria::print(out);
    Date_Criteria::print(out);
}

ostream& operator<<(ostream& out, const Criteria& criteria){
    criteria.print(out);
    return out;
}