#ifndef __SALES_ITEM__H__
#define __SALES_ITEM__H__

#include <iostream>
#include <string>

class Sales_item
{
friend std::istream& operator>>(std::istream&, Sales_item&);
friend std::ostream& operator<<(std::ostream&, const Sales_item&);
friend Sales_item operator+(const Sales_item&, const Sales_item&);
friend bool operator==(const Sales_item&, const Sales_item&);
friend bool operator!=(const Sales_item&, const Sales_item&);
public:
	Sales_item() = default;
	Sales_item(const std::string &book):BookNo(book){}
	Sales_item(std::istream &is)
	{
		is >> *this;
	}
public:
	Sales_item& operator+=(const Sales_item &hs);
	std::string isbn() const
	{
		return BookNo;
	}
	double avg_price() const;
private:
	std::string BookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
inline bool compareIsbn(const Sales_item &lhs, const Sales_item &rhs)
{
	return lhs.isbn() == rhs.isbn();
}

inline bool operator==(const Sales_item &lhs, const Sales_item &rhs)
{
	return lhs.revenue == rhs.revenue &&
		lhs.units_sold == rhs.units_sold &&
		lhs.isbn() == rhs.isbn();
}

inline bool operator!=(const Sales_item &lhs, const Sales_item &rhs)
{
	return !(lhs == rhs);
}

Sales_item& Sales_item::operator+=(const Sales_item &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

std::istream& operator>>(std::istream &in, Sales_item &rhs)
{
	double price;
	in >> rhs.BookNo >> rhs.units_sold >> price;
	if (in){
		rhs.revenue = rhs.units_sold * price;
	}else{
		rhs = Sales_item();		//reset object to default state
	}

	return in;
}

std::ostream& operator>>(std::ostream &out, const Sales_item &rhs)
{
	out << rhs.isbn() << " " << rhs.units_sold << " " 
		<< rhs.revenue << " " << rhs.avg_price();

	return out;
}

double Sales_item::avg_price() const 
{
	if (units_sold){
		return revenue / units_sold;
	}else{
		return 0;
	}
}
#endif //__SALES_ITEM__H__
