#ifndef SET_H
#define SET_H
#include "tbf.h"
class tset {
	tbitfield bf;
	int pow;
public:
	tset(int mp):pow(mp),bf(mp){}
	
	tset(const tset& s):pow(s.pow),bf(s.bf){}
    
	tset(const tbitfield &b):bf(b){
		pow=sizeof(bf)-2*sizeof(int);
	}
	
	operator tbitfield() {return bf;}

	friend ostream& operator<<(ostream& stream, const tset& a);

    friend istream& operator>>(istream& stream, tset& a);

	int operator==(const tset &bf);

	tset& operator=(const tset &bf);

	tset operator&(const tset &bf);

	tset operator|(const tset &bf);

	tset operator~(void);

	void addmem (int numb); 
	
	void delmem (int numb);
	
	int checkmem(int numb) const;

	tset operator+(const tset &b);

	tset operator+(const int &b);
};
#endif