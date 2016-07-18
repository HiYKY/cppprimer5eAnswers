#ifndef EX7_12_H
#define EX7_12_H

#include <string>
#include <iostream>

using std::string;

struct Sales_data;
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
std::istream &read(std::istream &is, Sales_data &item);
std::ostream &print(std::ostream &os, const Sales_data &item);

struct Sales_data
{
	Sales_data() = default;
	Sales_data(const string &s) : bookNo(s) { }
	Sales_data(const string &s, unsigned n, double p) : 
			   bookNo(s), units_sold(n), revenue(p * n) { }
	Sales_data(std::istream &is) { read(is, *this); }

	Sales_data &combine(const Sales_data &);
	string isbn() const;
	
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

string Sales_data::isbn() const
{
	return bookNo;
}

Sales_data &Sales_data::combine(const Sales_data &trans)
{
	units_sold +=trans.units_sold;
	revenue += trans.revenue;
	return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

std::istream &read(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue;
	return os;
}
 
 #endif

