#include "tbf.h"
#include "set.h"
int main() {
    setlocale(0,"Rus");
    int ans,flag,u,num;
    cout<<"           Лабораторная работа №1\n";
    cout<<"                  Множества\n";
    cout<<"Работу выполнил студент группы 0826-2 Лапин Артем\n";
    cout<<"Введите целый положительный универс\n";
    do 
      cin>>u;
    while (u<0);
    tset a(u),b(u),c(u);
    flag=0;
    do {
	cout<<"Меню\n1.Задание множества\n2.Добавить элемент\n3.Сравнить множества на равенство\n4.Пересечение множеств\n";
    cout<<"5.Объединение множеств\n6.Удалить элемент из множества\n7.Отрицание множества\n8.Выход\n";
    do
        cin>>ans;
    while ((ans<0)||(ans>8));
	if (ans==1) {
        cout<<"Введите множество\n";
        if ((flag==0)||(flag==2)) {cin>>a; flag=1;} else
		if (flag==1) {cin>>b; flag=2;}
    }
    if (ans==2) {
        if (flag>=1) {
		cout<<"Введите номер элемента\n";
        cin>>num;
        a.addmem(num);
		}
		if (flag<1) cout<<"Для операции необходимо ввести 1 множество\n";
    }
	if (ans==3) {
		if (flag==2) 
			if (a==b) cout<<"Множества равны\n"; else cout<<"Множества не равны\n";
		if (flag<2) cout<<"Для операции необходимо ввести 2 множества\n";
	}
	if (ans==4) {
		if (flag==2) {
			c=a&b;
			cout<<c;
		}
		if (flag<2) cout<<"Для операции необходимо ввести 2 множества\n";
	}
	if (ans==5) {
		if (flag==2) {
			c=a|b;
			cout<<c;
		}
		if (flag<2) cout<<"Для операции необходимо ввести 2 множества\n";
	}
	 if (ans==6) {
        if (flag>=1) {
		cout<<"Введите номер элемента\n";
        cin>>num;
        a.delmem(num);
		}
		if (flag<1) cout<<"Для операции необходимо ввести 1 множество\n";
    }
	  if (ans==7) {
        if (flag>=1) {
			c=~a; cout<<c;	
		}
		if (flag<1) cout<<"Для операции необходимо ввести 1 множество\n";
    }
	if (ans==8) break;
}  while (1);
}