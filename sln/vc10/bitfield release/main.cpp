#include "tbf.h"
#include "set.h"
int main() {
    setlocale(0,"Rus");
    int ans,flag,u,num;
    cout<<"           ������������ ������ �1\n";
    cout<<"                  ���������\n";
    cout<<"������ �������� ������� ������ 0826-2 ����� �����\n";
    cout<<"������� ����� ������������� �������\n";
    do 
      cin>>u;
    while (u<0);
    tset a(u),b(u),c(u);
    flag=0;
    do {
	cout<<"����\n1.������� ���������\n2.�������� �������\n3.�������� ��������� �� ���������\n4.����������� ��������\n";
    cout<<"5.����������� ��������\n6.������� ������� �� ���������\n7.��������� ���������\n8.�����\n";
    do
        cin>>ans;
    while ((ans<0)||(ans>8));
	if (ans==1) {
        cout<<"������� ���������\n";
        if ((flag==0)||(flag==2)) {cin>>a; flag=1;} else
		if (flag==1) {cin>>b; flag=2;}
    }
    if (ans==2) {
        if (flag>=1) {
		cout<<"������� ����� ��������\n";
        cin>>num;
        a.addmem(num);
		}
		if (flag<1) cout<<"��� �������� ���������� ������ 1 ���������\n";
    }
	if (ans==3) {
		if (flag==2) 
			if (a==b) cout<<"��������� �����\n"; else cout<<"��������� �� �����\n";
		if (flag<2) cout<<"��� �������� ���������� ������ 2 ���������\n";
	}
	if (ans==4) {
		if (flag==2) {
			c=a&b;
			cout<<c;
		}
		if (flag<2) cout<<"��� �������� ���������� ������ 2 ���������\n";
	}
	if (ans==5) {
		if (flag==2) {
			c=a|b;
			cout<<c;
		}
		if (flag<2) cout<<"��� �������� ���������� ������ 2 ���������\n";
	}
	 if (ans==6) {
        if (flag>=1) {
		cout<<"������� ����� ��������\n";
        cin>>num;
        a.delmem(num);
		}
		if (flag<1) cout<<"��� �������� ���������� ������ 1 ���������\n";
    }
	  if (ans==7) {
        if (flag>=1) {
			c=~a; cout<<c;	
		}
		if (flag<1) cout<<"��� �������� ���������� ������ 1 ���������\n";
    }
	if (ans==8) break;
}  while (1);
}