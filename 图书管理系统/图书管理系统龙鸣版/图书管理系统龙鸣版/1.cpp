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

	void createlbr(){                         //信息的录入
		cout << "读取书目中。。。" << endl;
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
		ifstream fin("书目.txt");
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

    void display(){                                    //显示当前书目
        cout << "现有书目：" << endl;
        cout << "编号" << "          " << "书名" << "      " << "作者" << endl;
        for(int i = 0; i < BOOKSCOUNT; i++){
			if(b[i].getnum() != b[i-1].getnum()){
				cout << b[i].getnum() << "      ";
                cout << b[i].getbookname() << "      ";
                cout <<b[i].getauthor() << "      ";
			    cout << endl;
			}
        }
    }

	void sortbooks(){            //给书本们按读者输入的序号排序,当前采用冒泡法
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

    void borrowbook(){                             //借书
        cout << "输入要借书目的编号:" << endl;
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
        cout << "借书成功！" << endl;
        display();
    }
    void returnbook(){                            //还书
        cout << "输入要还书目的信息:" << endl;
		int num;
		string bookname;
		string author;
		cin >> num;
		b[BOOKSCOUNT-1].setnum(num);
		cin >> bookname;
		b[BOOKSCOUNT-1].setbookname(bookname);
		cin >> author;
		b[BOOKSCOUNT-1].setauthor(author);
        cout << "还书成功！" << endl;
    }
    void findbook(){                             //查找
        cout << "输入要查找书目的编号:" << endl;
        int i,j;
        cin >> i;
        for (j = 0; j < BOOKSCOUNT && j >= 0; j++){
            if(i == b[j].getnum()){
                cout << "查找成功。该书信息如下：" << endl;
                cout <<b[j].getnum();
                cout << "      ";
                cout << b[j].getbookname();
                cout << "      ";
                cout <<b[j].getauthor();
                cout << endl;
            }
        }
		if(i <= 0 || i > BOOKSCOUNT ){
			cout << "现藏书目中不存在编号为" << i << "的书，请检查是否输入错误" << endl;
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
    cout << endl << endl << "操作：a.借书  b.还书 c.查找 d.排序 e.展示" << endl;
    cin >> a;
    switch(a){
    case'a':l.borrowbook();break;
    case'b':l.returnbook();break;
    case'c':l.findbook();break;
	case'd':l.sortbooks();break;
	case'e':l.display();break;
    default:cout << "操作字符错误." << endl;
    }
    }
}