#include "tbf.h"
void tbitfield::switchonbit (int numb) {
	unsigned int mask;
	if ((numb<bitcount)&&(0<=numb)) {
	    mask=1<<numb;
	    a[numb/massize]=a[numb/massize]|mask;
	}
}

void tbitfield::switchoffbit (int numb) {
	unsigned int mask;
	if ((numb<bitcount)&&(0<=numb)) {
	    mask=1<<numb;
	    mask=~mask;
	    a[numb/massize]=a[numb/massize]&mask;
	}
}

int tbitfield::checkbit (int numb) const {
    int flag;
	if ((numb>bitcount)||(numb<0)) flag=0;
	unsigned int mask;
	if ((numb<bitcount)&&(0<=numb)) {
	    mask=1<<numb;
	    mask=~mask;
	    if (a[numb/massize]==(a[numb/massize]&mask)) flag=0; else flag=1;
	}
	return flag;
}

int tbitfield:: operator ==(const tbitfield &bf) {
	int flag;
	flag=1;
	if (bitcount!=bf.bitcount) flag=0;
	for (int i=0; i<(intcount); i++) {
	    if(a[i]!=bf.a[i]) flag=0;
	}
	return flag;
}

tbitfield& tbitfield::operator=(const tbitfield &bf){
    if (intcount!=bf.intcount) {
	    intcount=bf.intcount;
	    delete[]a;
	    a=new unsigned int[intcount];
	}
	bitcount=bf.bitcount;
	for(int i=0;i<intcount;i++)
	a[i]=bf.a[i];
	return *this;
}

tbitfield tbitfield::operator&(const tbitfield &bf){
    int temp;  
	if (bitcount>bf.bitcount) temp=bitcount; else temp=bf.bitcount;
	tbitfield tempbf(temp); 
	if (intcount<bf.intcount) temp=intcount; else temp=bf.intcount;
	for (int i=0; i<temp; i++)
		tempbf.a[i]=bf.a[i]&a[i];
	return tempbf;
}

tbitfield tbitfield::operator|(const tbitfield &bf){
    int temp; tbitfield tempbf(bf);  
	if (bitcount>bf.bitcount) tempbf=*this; else tempbf=bf;
	if (intcount<bf.intcount) temp=intcount; else temp=bf.intcount;
	for (int i=0; i<temp; i++)
		tempbf.a[i]=bf.a[i]|a[i];
	return tempbf;
}

tbitfield tbitfield:: operator~(void){
	tbitfield temp(*this);
	for(int i=0;i<temp.intcount;i++)
		 temp.a[i]=~temp.a[i];
	 return temp;
}

ostream& operator<<(ostream& stream,const tbitfield& a) {
    tbitfield tbf(a);
	for(int i=0;i<a.bitcount;i++) 
	    stream<<tbf.checkbit(i);
	stream<<"\n";
    return stream;
}

istream& operator>>(istream& stream, tbitfield& a){
    int j; char c;
    cout<<"¬ведите битовое поле\n";
    j=0;
    do {
        c=getch();
        cout<<c;
        if (c=='1') a.switchonbit(j);
        else if (c!='0') {
            j=a.bitcount+1;
            break;
        }
        j++;
    }
    while ((j<a.bitcount)&&(c!='\n'));
    cout<<'\n';
    return stream;
}