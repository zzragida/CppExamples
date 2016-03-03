#include <iostream>
#include <locale>

using namespace std;

int main()
{
	locale en("en_US");
	//locale gb("ko_KR");

	wstring dollars = use_facet<moneypunct<wchar_t>>(en).curr_symbol();
	//wstring pounds = use_facet<moneypunct<wchar_t>>(gb).curr_symbol();

	wcout << L"In the US, the currency symbol is " << dollars << endl;
	//wcout << L"In Great Britain, the currency symbol is " << pounds << endl;
	
	return 0;
}
