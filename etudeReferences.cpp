
#include <iostream>
#include <string>
#include <algorithm>

struct structS {  // to_class
    int a;
    std::string b;
};

template<class T>
void tfunc(T&& tmp) 
{
    const_cast<int&>(tmp) += 10;
    std::cout<< "ref c = " << tmp << "\n";
}

void sfun(structS&& s) 
{
    s.a = 0;
    s.b = "0_sfun";
}


int main()
{
//    using namespace std;
    using std::cout;
    using std::endl;

// Вспомним

    // литералы   
    // https://learn.microsoft.com/ru-ru/cpp/cpp/numeric-boolean-and-pointer-literals-cpp?view=msvc-170
    // rvalue, lvalue
    // int x = 5;
    // int y = x+1;

    char ch = '1';
    cout << ch << endl;

    ch &= ~1;     // ? Чет - нечет
    cout << ch << endl;

// char = 8 bit  max_char =  2^ 8 -1 = 255  0-127; -1 - 128  https://cplusplus.com/reference/climits/ 
// unsigned char - от 0 до  255    https://en.cppreference.com/w/cpp/types/numeric_limits

    cout << "sizeof(char) = " << sizeof(char) << "\tsizeof(short) = " << sizeof(short) << endl;
    cout << "sizeof(int ) = " << sizeof(int) << "\tsizeof(long long) = " << sizeof(long long) << endl;
    cout << "sizeof(float) = " << sizeof(float) << "\tsizeof(double) = " << sizeof(double) << endl;

// коварство float
    float x1 = 1200;
    float y1 = 0.0001;
    float z1 = x1 + y1;
    cout << z1 << endl;


// rvalue, lvalue
// int x = 5;
// int y = x+1;


    auto val = 1.3;  // 1.2
    cout << "sizeof(val) = " << sizeof(val) <<  endl;

    decltype(val) val2;
    cout << "sizeof(val2) = " << sizeof(val2) << endl;



 // циклы   for (;;);  while(true);

    int* ptr = new int[20] {5,6,7,8,9};

    for (int i(0); i < 20; i++)
        cout << ptr[i] << " ";
    cout << " >  for 1 \n";

    char* shptr = new (ptr) char[80];

    delete[]  ptr;

 //   Ref
    int arr[5]{ 1,3,7,9,5 };

    for (auto & a : arr) 
        a = a * a;;

    for (auto a : arr)
        cout << a << " ";
    cout << " >  for 2 \n\n\n";

#if 0

// 1 
    int digit = 0x1f2f3f7f;

  //  char* pch = reinterpret_cast<char*>(&digit);
    char* pch = (char*)(&digit);

    for (int i = 0; i < 4; i++)
        std::cout << (int)pch[i] << " ";


// 2
    structS* p = new structS{ 1,"2 text" };
    std::cout << "\n" << p->b << "\n\n";



// 3
    int a = 1;
    const int& c = a;

    tfunc(c);
    std::cout << "a = " << a << "\n\n";


    int&& d = c+0;

    tfunc(d);
    std::cout << "a = " << a << "  d = " << d << "\n";

    int f = d;
    std::cout << "a = " << a << "  f= " << f << "\n\n";


// 4

   

    int * y = new int(3);
    int* ptr = new int[15];
    for (int i = 0; i < 15; ptr[i] = i++);

    delete y;

    delete[] ptr;

    std::cout << y;

    int ar[10]{0};
    for (int i = 0; i < 10; ar[i] = i++);

    auto ls { [](int& x) { 
        for (int i = 0; i < rand(); i++);
        std::cout << x << " "; }
    };

    for (int& a : ar) {
        ls(a);
    }
    std::cout << "\n";

    for_each(ar, ar + 10, ls);


    //parallel_policy

#endif

}
