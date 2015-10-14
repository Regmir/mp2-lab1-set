#include "set.h"

ostream& operator<<(ostream& stream,const tset& a) {
	cout<<"Соответствующее множеству битовое поле:\n";
	    stream<<a.bf;
	stream<<"\n";
    cout<<"Множество:\n";
    cout<<"{ ";
    for (int i=0;i<a.pow;i++) 
        if (a.checkmem(i)==1) cout<<i<<' ';
    cout<<"}\n";
    return stream;
}

istream& operator>>(istream& stream, tset& a){
    char c; int k; tset b(a.pow);
    a=b;
    do stream>>c; while (c!='{');
    do {
        stream>>k; a.addmem(k);
        do stream>>c; while ((c!=',')&&(c!='}'));
    }  
    while (c!='}');
    return stream;
}

int tset:: operator ==(const tset &b) {
	int flag;
	flag=1;
	if (bf==b.bf) flag=1; else flag=0;
	if (pow!=b.pow) flag=0;
	return flag;
}

tset& tset::operator=(const tset& b){
	pow=b.pow;
	bf=b.bf;
	return *this;
}

tset tset::operator&(const tset &b){
	tset ts(pow);
	ts.bf=bf&b.bf;
	if (b.pow>pow) ts.pow=b.pow; else ts.pow=pow;
	return ts;
}

tset tset::operator|(const tset &b){
	tset ts(pow);
	ts.bf=bf|b.bf;
	if (b.pow>pow) ts.pow=b.pow; else ts.pow=pow;
	return ts;
}

tset tset:: operator~(void){
	tset ts(*this);
	ts.bf=~ts.bf;
	return ts;
}

void tset::addmem(int numb) {
	bf.switchonbit(numb);
}

void tset::delmem(int numb) {
	bf.switchoffbit(numb);
}

int tset::checkmem (int numb) const {
    int flag;
	if (bf.checkbit(numb)==0) flag=0; else flag=1;
	return flag;
}

tset tset:: operator +(const tset &b){
	int temp;
	int j;
	tset temps2(b);
	temp=b.pow+pow;
	tset temps(temp);
	for (int i=0;i<pow;i++)
		if (checkmem(i)==1) temps.addmem(i);
	j=0;
	for (int i=pow;i<temp;i++) {
		if (temps2.checkmem(j)==1) temps.addmem(i);
		j++;
	}
	return temps;
}

tset tset:: operator +(const int &b){
	int temp;
	if (b<=(pow)) {
	temp=1+pow;
	tset temps(temp);
	for (int i=0;i<b;i++)
		if (checkmem(i)==1) temps.addmem(i);
	temps.addmem(b);
	for (int i=b;i<pow;i++) 
		if (checkmem(i)==1) temps.addmem(i+1);
	}
	return *this;
}