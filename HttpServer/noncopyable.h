#ifndef NON_COPYABLE_H
#define NON_COPYABLE_H 
class noncopyable
{
public:
	noncopyable() = default;
	noncopyable(const noncopyable& n) = delete;
	noncopyable& operator=(const noncopyable& n) = delete;
};
#endif