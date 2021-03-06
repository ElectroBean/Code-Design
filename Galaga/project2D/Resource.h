#pragma once
#include <iostream> 
#include <memory> 

template<class T>
class Resource
{
public:
	Resource(const std::string& filename) : m_filename(filename)
	{
		m_data = std::unique_ptr<T>(new T(filename.c_str()));
	};
	~Resource() {};

	std::string getFilename() { return m_filename; }
private:
	std::unique_ptr<T> m_data;
	std::string m_filename;
};