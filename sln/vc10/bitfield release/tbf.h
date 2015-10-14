#ifndef TBF_H
#define TBF_H
#include <iostream>
#include <conio.h>
#include <clocale>
using namespace std;
#define massize 32
class tbitfield {
	unsigned int* a;
	int bitcount;
	int intcount;
public:
	tbitfield( int n) {
		if (n>=0) {
		intcount=(n/massize)+1;
		a=new unsigned int[intcount];
		bitcount=n;
		for (int i=0; i<(intcount); i++) {
		    a[i]=0;
		}
		}
	}
	
	tbitfield(const tbitfield &bf) {
		intcount=bf.intcount;
		a=new unsigned int[intcount];
		bitcount=bf.bitcount;
		for (int i=0; i<(intcount); i++) {
		    a[i]=bf.a[i];
		}
	}
	
	friend ostream& operator<<(ostream& stream, const tbitfield& a);

    friend istream& operator>>(istream& stream, tbitfield& a);
	
	void switchoffbit (int numb); 
	
	void switchonbit (int numb);
	
	int checkbit (int numb) const;
	
	int operator==(const tbitfield &bf);

	tbitfield& operator=(const tbitfield &bf);

	tbitfield operator&(const tbitfield &bf);

	tbitfield operator|(const tbitfield &bf);

	tbitfield operator~(void);

	~tbitfield() {
		delete[] a;
	}
};
#endif