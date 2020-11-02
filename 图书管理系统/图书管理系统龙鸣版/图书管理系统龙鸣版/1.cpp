#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <string.h>
#define BOOKSCOUNT 5

  
  
using namespace std;
  
class books{
public:
    books(int _num, string _bookname, string _author, string _flag){num = _num; bookname = _bookname; author = _author;}
    books(){}
    int getnum(){return num;}
	void setnum(int i){num = i;}
    string getbookname(){return bookname;}
	void setbookname(string s){bookname = s;}
    string getauthor(){return author;}
	void setauthor(string s){author = s;}
    void operator=(const books &b )
    { 
         num = b.num;
         bookname = b.bookname;
         author = b.author;
    }
private:
    int num;
    string bookname;
    string author;
};
  
class booklog{
public:
    booklog(books a[BOOKSCOUNT]){
        for(int i = 0; i < BOOKSCOUNT; i++){
            b[i] = a[i];
        }
    }

	void createlbr(){                         //��Ϣ��¼��
		cout << "��ȡ��Ŀ�С�����" << endl;
		//int i;
		//int num;
		//string bookname;
		//string author;
		//for(int i = 0; i < BOOKSCOUNT; i++){
		//	cin >> num;
		//	b[i].setnum(num);
		//	cin >> bookname;
		//	b[i].setbookname(bookname);
		//	cin >> author;
		//	b[i].setauthor(author);
		//}
		ifstream fin("��Ŀ.txt");
		int num;
		string bookname;
		string author;
		for(int i = 0; i < BOOKSCOUNT; i++){
			fin >> num;
			b[i].setnum(num);
			fin >> bookname;
			b[i].setbookname(bookname);
			fin >> author;
			b[i].setauthor(author);
		}
	}

    void display(){                                    //��ʾ��ǰ��Ŀ
        cout << "������Ŀ��" << endl;
        cout << "���" << "          " << "����" << "      " << "����" << endl;
        for(int i = 0; i < BOOKSCOUNT; i++){
			if(b[i].getnum() != b[i-1].getnum()){
				cout << b[i].getnum() << "      ";
                cout << b[i].getbookname() << "      ";
                cout <<b[i].getauthor() << "      ";
			    cout << endl;
			}
        }
    }

	void sortbooks(){            //���鱾�ǰ�����������������,��ǰ����ð�ݷ�
		books temp;
		int i,j;
		for(i = 0; i < BOOKSCOUNT - 1; i++){
			for(j = 0; j < BOOKSCOUNT -1;j++){
				if(b[j].getnum() > b[j+1].getnum()){
					temp = b[j];
					b[j] = b[j+1];
					b[j+1] = temp;
				}
			}
		}
	}

    void borrowbook(){                             //����
        cout << "����Ҫ����Ŀ�ı��:" << endl;
        int i,j,k;
        cin >> j;
        for(i = 0; i < BOOKSCOUNT;i++){
            if(j == b[i].getnum()){
				for(k = i; k < BOOKSCOUNT;k++){
					if(k == BOOKSCOUNT -1){
						b[k].setnum(b[k-1].getnum());
					    b[k].setbookname(b[k-1].getbookname());
					    b[k].setauthor(b[k-1].getauthor());
					}
					else {
						b[k].setnum(b[k+1].getnum());
					    b[k].setbookname(b[k+1].getbookname());
					    b[k].setauthor(b[k+1].getauthor());
					}
				}
            }
        }
        cout << "����ɹ���" << endl;
        display();
    }
    void returnbook(){                            //����
        cout << "����Ҫ����Ŀ����Ϣ:" << endl;
		int num;
		string bookname;
		string author;
		cin >> num;
		b[BOOKSCOUNT-1].setnum(num);
		cin >> bookname;
		b[BOOKSCOUNT-1].setbookname(bookname);
		cin >> author;
		b[BOOKSCOUNT-1].setauthor(author);
        cout << "����ɹ���" << endl;
    }
    void findbook(){                             //����
        cout << "����Ҫ������Ŀ�ı��:" << endl;
        int i,j;
        cin >> i;
        for (j = 0; j < BOOKSCOUNT && j >= 0; j++){
            if(i == b[j].getnum()){
                cout << "���ҳɹ���������Ϣ���£�" << endl;
                cout <<b[j].getnum();
                cout << "      ";
                cout << b[j].getbookname();
                cout << "      ";
                cout <<b[j].getauthor();
                cout << endl;
            }
        }
		if(i <= 0 || i > BOOKSCOUNT ){
			cout << "�ֲ���Ŀ�в����ڱ��Ϊ" << i << "���飬�����Ƿ��������" << endl;
		}

    }
private:
    books b[BOOKSCOUNT];
};
  
int main(){
    books b[BOOKSCOUNT];
    booklog l(b);
	l.createlbr();
    char a;
	l.display();
    for(;;){
    cout << endl << endl << "������a.����  b.���� c.���� d.���� e.չʾ" << endl;
    cin >> a;
    switch(a){
    case'a':l.borrowbook();break;
    case'b':l.returnbook();break;
    case'c':l.findbook();break;
	case'd':l.sortbooks();break;
	case'e':l.display();break;
    default:cout << "�����ַ�����." << endl;
    }
    }
}