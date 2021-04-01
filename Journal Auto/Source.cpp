#include<iostream>
#include<Windows.h>
#include<sstream>



int main()
{
	SYSTEMTIME time;
	GetLocalTime(&time);
	
	std::string stringYear="./"+std::to_string(time.wYear);
	std::string stringMonth = std::to_string(time.wMonth);

	LPCSTR year = stringYear.c_str();
	LPCSTR month = stringMonth.c_str();

	
	CreateDirectory(year, NULL);
	SetCurrentDirectory(year);
	CreateDirectory(month,NULL);
	SetCurrentDirectory(month);

	
	
	
	std::string date = std::to_string(time.wDay) +"_"+ std::to_string(time.wMonth) +"_"+ std::to_string(time.wYear) + ".docx";
	LPCSTR filename = date.c_str();
	
	int a;
	CreateFile(filename, GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_NEW,FILE_ATTRIBUTE_NORMAL,NULL);
	ShellExecute(NULL, "open", filename, NULL, NULL, SW_SHOWDEFAULT);
	


	

}