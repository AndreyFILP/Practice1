#include <iostream>
using namespace std;

class str  // упрощенный аналог string
{
private:
    char* s; // указатель на строку символов (без завершающего символа '\0')
    int n;   // размер строки символов
public:
    str() : s(nullptr), n(0) {} // конструктор по умолчанию
    str(const char *st) // конструктор, принимающий постоянную строку текста
    {
        int i = 0;
        for (i = 0; st[i] != '\0'; i++); // вычисляем длину входной строки
        n = i;
        s = new char[n];
        for (i = 0; i < n; i++) s[i] = st[i]; // копируем строку st, включая нулевой символ
    }
    str(str& T) // конструктор копирования
    {
        n = T.n;
        s = new char[n];
        for (int i = 0; i < n; i++) s[i] = T.s[i];
    }
    ~str() { delete[] s;}
    /*operator char* ()  // преобразование типа str в строку char*
    {
        return &s[0];
    } 
    str& operator = (str& st) // перегрузка оператора присваивания
    {}*/
    void print() // печать строки
    {
        char* p = new char[n + 1];  // сформируем строку с символом '\0' в конце
        for (int i = 0; i < n; i++) p[i] = s[i];
        p[n] = '\0';
        cout << p << endl;
        delete[] p;
    }
    int length() { return n; }
    char at(int k) // извлечение символа с индексом k
    {
        return (k >= 0 && k < n) ? s[k] : '\0';
    }
    void setchar(char ch, int k) // установить символ в позицию с индексом k
    {
        if (k >= 0 && k < n) s[k] = ch;
    }
};

int main()
{
    str s1, s2("wqeqrwe"), s3(s2);
    //char* p = str("ddddd");
    s1.print();
    s2.print(); 
    cout << s2.length() << "   "<< s2.at(2) << endl;
    s3.setchar('z', 2);
    s3.print();
}