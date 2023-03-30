#ifndef CRITERIA_H
#define CRITERIA_H

#include <iostream>
#include <string>
#include <iomanip>
#include "defs.h"
#include "Date.h"
#include "Photo.h"

using namespace std;

class Criteria {
    friend ostream& operator<<(ostream&, const Criteria&);
    public:
        virtual bool matches(const Photo& photo) const = 0;
        virtual void print(ostream& out) const = 0;
};

class Cat_Criteria : virtual public Criteria {
    public:
        Cat_Criteria(const string& category);
    protected:
        bool matches(const Photo& photo) const;
        void print(ostream& out) const;        
    private:
        string category;
};

class Date_Criteria : virtual public Criteria {
    public:
        Date_Criteria(const Date& start, const Date& end);
    protected:
        bool matches(const Photo& photo) const;
        void print(ostream& out) const;        
    private:
        Date start;
        Date end;
};

class CandD_Criteria : public Cat_Criteria, public Date_Criteria {
    public:
        CandD_Criteria(const Date& start, const Date& end, const string& category);
    protected:
        bool matches(const Photo& photo) const;
        void print(ostream& out) const;        
};

#endif