#include <string.h>

/*
** 面试用的在10分钟内可以写出的string类
   */
class String
{
public:
	String()
		:data_(new char[1])
	{
		*data_ = '\0';
	}

	String(const char* str)
		:data_(new char[strlen(str) + 1])
	{
		strcpy(data_, str);
	}

	String(const String& rhs)
		:data_(new char[rhs.size() + 1])
	{
		strcpy(data_, rhs.c_str());
	}

	~String()
	{
		delete [] data_; 
	}

	String& operator=(String rhs)
	{
		swap(rhs);
		return *this;
	}

	String(String&& rhs)
		:data_(rhs.data_)
	{
		rhs.data_ = nullptr;
	}

	size_t size() const
	{
		return strlen(data_);
	}

	const char* c_str() const
	{
		return data_;
	}

	void swap(String& rhs)
	{
		std::swap(data_, rhs.data_);
	}
private:
	char *data_;
};
