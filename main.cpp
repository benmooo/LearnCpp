// <> for std lib and "" for user defined headers or files in the same project
#include <functional>
#include <iostream>

// the #define preprocessor directive is used to define constants and it is just
// simple text substitution, and lacks type safety and scooping. the complier
// will replace the #define with the actual value at compile time all over the
// code but it is not global across the whole project, it is only in the current
// file however, we can access the value by including the header file which
// defines the constant if we indeed want to use it across multiple files
#define PI 3.14159
#define NEWLINE '\n'

using namespace std;

void testConsoleIn();
void testTwoLine();
void testVariablesAndTypes();
void testOperators();
void testStatementsAndFlowControl();
void testFunction();
void testDivide();
void testRecursion();
void testOverload();
void testTemplate();
void testNonTypeTemplate();
void testNamespaceAndUsing();
void testNamespaceAliasing();

void testArray();
void testMultipleDimensionalArray();
void testArrayAsArguments();
void testLibArray();

void testCharSequence();

void testPointer();
void testPointer2();
void testPointerAndArray();

void testEnums();

int main() {
    testEnums();
    return 0;
}

void testConsoleIn() {
    int a, b, sum;

    cin >> a;
    cin >> b;
    sum = a + b;

    cout << "the sum is : " << sum;
}

void testTwoLine() {
    std::cout << "hello;" << endl;
    std::cout << "world;" << endl;
}

void testVariablesAndTypes() {
    // typed const variable
    const float pi = 3.14;
    const float tau = 2 * pi;

    int a = 10;
    float b = 3.14;
    double c = 2.71828;
    char d = 'a';
    bool e = true;
    std::string f = "Hello, World!";
}

void testOperators() {
    //  assign operators =
    //  arithmetic operators +, -, *, /, %
    //  comparison operators <, >, <=, >=, ==, !=
    //  logical operators &&, ||, !
    //  bitwise operators &, |, ^, ~, <<, >>
    // compound assignment operators +=, -=, *=, /=, %=
    // increment and decrement operators ++, --
    // conditional ternary operator ?
    // explicit type conversion operators (int to float, float to int)
    // sizeof operator, this operator accepts a type or a variable and returns
    // the size of the type in bytes

    int a = 10;
    int b = 20;
    int c = a + b;
    c = a - b;
    c = a * b;
    c = a / b;
    c = a % b;

    int d = sizeof(b);
    cout << "size of b is " << d << " bytes" << endl;
}

void testStatementsAndFlowControl() {
    bool ok = true;
    if (ok) {
        cout << "this is true" << endl;
    } else {
        cout << "this is false" << endl;
    }

    // while loop
    int x = 0;
    while (x < 10) {
        cout << "x is: " << x << endl;
        x++;
    }

    // do while -- executes at least once
    int y = 0;
    do {
        cout << "y is: " << y << endl;
        y++;
    } while (y < 10);

    // for loop
    for (int i = 0; i < 10; i++) {
        cout << "i is: " << i << endl;
    }

    for (int n = 0, i = 100; n != i; n++, i--) {
        cout << "n is: " << n << ";"
             << "i is: " << i << endl;
    }

    // switch
    int z = 5;
    switch (z) {
    case 1:
        cout << "z is 1" << endl;
        break;

    case 2:
        cout << "z is 2" << endl;
        break;

    case 3:
        cout << "z is 3" << endl;
        break;

    default:
        cout << "z is not 1, 2, or 3";
    }
}

// arguements by reference other than by value which might alter the reference
// value
void duplicateR(int &a, int &b) {
    a += 3;
    b += 3;
}

void duplicate(int a, int b) {
    a += 3;
    b += 3;
}

int add(int a, int b) { return a + b; }
void testFunction() {
    int a, b;
    cin >> a;
    cin >> b;
    cout << "a + b is " << add(a, b) << endl;

    duplicateR(a, b);
    cout << "a is " << a << "and b is " << b << endl;
}

// on the flip side, functions with reference arguments are generally percived
// as functions that modify the arguments passed, because that is why reference
// parameters are actually for
//
// The solution is for the function that garantees that the arguments are not
// modified by this function is qualifying the parameters as constant.

string concatenate(const string &a, const string &b) { return a + b; }

// inline funtions, calling functions generally envolves overhead(stacking
// arguments, jump.. etc) and thus for very short functions, it maybe more
// efficient to simply insert the code of the function where it is called.
inline int square(const int &x) { return x ^ 2; }

// default values in parameters
int divide(const int &a, const int &b = 2) { return a / b; }

void testDivide() {
    int res;
    res = divide(9, 4);
    res = divide(9);
    cout << "division result: " << res << endl;
}

long factorial(long a) {
    if (a <= 1) {
        return 1;
    }
    return a * factorial(a - 1);
}

void testRecursion() {
    long seed = 9;
    long res = factorial(seed);
    cout << "factorial " << seed << " is " << res << endl;
}

// overloaded functions

int sum(int a, int b) { return a + b; }
double sum(double a, double b) { return a + b; }

// a function can not be overloaded only by return type, at least one of its
// parameters have different types
void testOverload() {
    int a = 1, b = 2;
    double c = 3.1, d = 5.423432;

    cout << "sum of " << a << " and " << b << " is " << sum(a, b) << endl;
    cout << "sum of " << c << " and " << d << " is " << sum(c, d) << endl;
}

// function templates
// overloaded functions may have the same definition, for example
// line 197 and line 198
// sum is overload with different parameter types, but with the exact same body
// the function could be overloaded for a lot of types, and it could make all
// sense with the same body. For cases like this, we can use function templates
template <typename T> T sum(T a, T b) { return a + b; }

// instantiate a template is apply the template to a specific type
void testTemplate() {
    float a = 1.223, b = 12.231;
    float res = sum<float>(a, b);
    cout << "sum of " << a << " and " << b << " is " << res << endl;
}

// Non-type template arguments
template <typename T, int N> T fixedMultiply(T a) { return a * N; }

// note: the type of non-type template arguments must be constant expressions
// that are known at compile time. this is a restriction set the the c++
// standard for templates to enable certain compile-time computations and
// optimizations.
void testNonTypeTemplate() {
    double seed = 123.231;
    cout << "fixed multiply with fixed facotr " << 2 << " with seed " << seed
         << " and res is " << fixedMultiply<double, 2>(seed) << endl;
}

// namespace
// only one entity can exists with a particular name in a particular scope.
// this is seldom a problem for local names, since blocks tend to be relatively
// short and names have particular purpose within them, such as naming a counter
// variable, an argument, etc..
//
// But non-local names bring more possibilities for name collision, especially
// considering that libraries may declare many funcitons, types and variables,
// neither of them local in nature, and some of them are very generic.
//
// Namespaces allow us to group named entities into a single unit, and to
// prevent name collisions among them;
namespace first {
int x = 5;
int y = 10;
} // namespace first

namespace second {
double x = 3.1416;
double y = 2.7183;
} // namespace second

void testNamespaceAndUsing() {
    using first::x;
    using second::y;
    cout << x << '\n';
    cout << y << '\n';
    cout << first::y << '\n';
    cout << second::x << '\n';
}

// namespace aliasing
// existing namespaces can be aliased with new names
// namespace new_name = current_name;
// for example
namespace my_std = std;

void testNamespaceAliasing() {
    my_std::cout << "namespace alias .." << my_std::endl;
}

void testArray() {
    int foo[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int res;
    for (int i = 0; i < 10; i++) {
        res += foo[i];
    }
    cout << "res: " << res << endl;
}

void testMultipleDimensionalArray() {
    int foo[3][5];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "for[i][j]: " << foo[i][j] << endl;
        }
    }
}

void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << "arr[" << i << "]: " << arr[i] << endl;
    }
}

void testArrayAsArguments() {
    int foo[] = {1, 2, 3, 4, 5, 6};
    printArray(foo, 6);
}

// library arrays
// the arrays above are directly implemented as a language feature, inherited
// from c language but by restrictint its copy and easily decayed into pointers,
// they probaly suffer from an excess of optimizations.
//
// To overcome this issues, cpp provides an alternative array type as a standard
// container. it's a type template (a class template) defined in header <array>
//
// Suffice it to say that they operate in a similar way, except that they are
// allowed being copied(an expensive operation that copy the entire block of
// memory) and decayed into pointers only when explicitly requested.

#include <array>

void testLibArray() {
    array<int, 6> foo = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < foo.size(); i++) {
        ++foo[i];
    }

    // range based for loop
    for (int item : foo) {
        cout << item << endl;
    }
}

void testCharSequence() {
    // the following two declarations are equivalent which means that the string
    // literal is literal constants. and their type a null-terminated array of
    // chars.
    char foo[] = {'a', 'b', 'c', '\0'};
    char bar[] = "abc";

    // array of chars with null terminated vs string
    // arrays have a fixed size that needs to be specified either explictitly or
    // implicitly when declared. questions have exactly 29 characters. while
    // string are simple strings, no size is specified. this is because strings
    // have a dynamic size determined during runtime. while the size of arrays
    // is determined by compile time, before the program runs.

    char questions[] = "What is the meaning of life?";
    string question2 = "where do you live";

    // in any case, null-terminated character sequence and strings can be
    // transform from one another
    char myntcs[] = "hellow world";
    string myString = myntcs; // implicitly convert null-terminated character
                              // sequence to string
    const char *cPtr = myString.c_str(); // explicit conversion to
                                         // null-terminated character sequence
}

// pointers
// pointers are variables that store the memory address of another variable.
// they are used to indirectly access the value of the variable they point to.
// pointers are declared using the * operator, and they can be dereferenced
// using the * operator.
//
// address of operator &
// the address of operator & returns the memory address of the varable it it
// applied to.
//
// dereference operator *
// the dereference operator * returns the value stored at the memeory address it
// is applied to.
//
// declaration of pointers
// type * name
// int * number
// double * decimal
// char * character
// note that the asterisk is used when declaring a pointer only means it's a
// pointer and should not be confused with the dereference operator *. They are
// different things.

void testPointer() {
    int firstValue, secondValue;
    int *myPointer;

    myPointer = &firstValue;
    *myPointer = 10;
    myPointer = &secondValue;
    *myPointer = 20;

    cout << "first value: " << firstValue << endl;
    cout << "second value: " << secondValue << endl;
}

void testPointer2() {
    int firstValue = 5, secondValue = 15;
    int *p1, *p2;

    p1 = &firstValue;
    p2 = &secondValue;

    *p1 = 10;  // firstValue = 10
    *p2 = *p1; // secondValue = 10
    p1 = p2;   // now p1 points to secondValue;

    *p1 = 20; // secondValue = 20
    cout << "first value: " << firstValue << endl;
    cout << "second value: " << secondValue << endl;
}

// Pointers and arrays
// The concept of array is related to pointers. In fact, array works very much
// like pointers to their first element. and array can be implicitly converted
// to pointers of the proper type

void testPointerAndArray() {
    // int arr[] = {1, 2, 3, 4, 5};
    // int *p;

    // p = arr; // implicitly convert array to pointer

    // and p and arr are equivalent and would have very similar properties. The
    // main difference is that p can be assigned to another pointer of the same
    // type, while arr can never be re-assigned. and always represent the same
    // block of 5 elements of type int.

    // arr = p; // thus, this is invalid.

    int numbers[5];
    int *p;
    p = numbers;
    *p = 10; // the first element of numbers is 10

    p++;     // increment the pointer, now it points to the second element of
             // numbers
    *p = 20; // the second element of numbers is 20
    p = &numbers[2]; // now p points to the third element of numbers
    *p = 30;         // the third element of numbers is 30
    p = numbers + 3; // now p points to the fourth element of numbers
    *p = 40;

    p = numbers;   // now p points to the first element of numbers
    *(p + 4) = 50; // the fifth element of numbers is 50

    for (int elem : numbers) {
        cout << elem << endl;
    }

    // pointers and arrays support the same set of operations, with the same
    // meaning for both.The main difference is that pointers can be assigned new
    // addresses, while arrays can not.

    // we often make assumptions about array brackets as specifying the index of
    // an element of the array. well, in fact these brackets are a differenceing
    // operator knows as the offset operator. they dereference the variable they
    // follow just as * does, but they also add the number between brackets to
    // the address being dereferenced. for example:
    //

    numbers[3] = 0;
    *(numbers + 3) = 0;
    // both of the above lines are equivalent either numbers is an array or a
    // pointer, and mean the same thing
    //
    // Remember that if an array, its name can be used as a pointer to its first
    // element.
}

// Pointer initialization;
void testPointerInitialization() {
    int myVar;
    int *foo = &myVar;
    int *bar = foo;
}

// Pointer arithmetics
// Pointers can be added and subtracted to point to the next element

void testPointerArithmetics() {
    char *charP;   // say 1000
    short *shortP; // 2000
    long *longP;   // 3000

    charP++;  // size char is 1 byte, now charP points to 1001
    shortP++; // size short is 2 bytes, now shortP points to 2002
    longP++;  // size long is 4 bytes, now longP points to 3004

    // which is same as
    charP += 1;
    shortP += 1;
    longP += 1;

    char *p;
    *p++ = *charP++; // which is smae as *(p++) = *(charP++)
    // which is same as the following
    *p = *charP;
    ++p;
    ++charP;
}

// Pointers and constants

void testPointerAndConstants() {
    int x;
    int y = 10;
    const int *p = &y;
    x = *p; // ok: reading p
    // *p = x; // error: modifying p, which is const-qualified

    // one of the use case of pointers of const elements is function parameters:
    // a function that takes pointers to non-const as parameters can modify the
    // value passed as argument. while a funciton that takes pointers to const
    // can not.

    // function pointers
}

// dynamic memory allocation
void testDynamicMemoryAllocation() {
    int *p = new int; // allocate memory for an integer
    *p = 10;          // assign value to the memory location
    delete p;         // deallocate the memory

    int *p1 = new int[10];
    for (int i = 0; i < 10; i++) {
        p1[i] = i; // assign values to the memory locations
    }
    delete[] p1; // deallocate the memory
}

void testDynamicMemoryAllocation2() {
    // Notice how the value within brackets in the new statement is a variable
    // value entered by the user (i), not a constant expression:
    int i, n;
    int *p;
    cout << "How many numbers would you like to type? ";
    cin >> i;
    p = new (nothrow) int[i];
    if (p == nullptr)
        cout << "Error: memory could not be allocated";
    else {
        for (n = 0; n < i; n++) {
            cout << "Enter number: ";
            cin >> p[n];
        }
        cout << "You have entered: ";
        for (n = 0; n < i; n++)
            cout << p[n] << ", ";
        delete[] p;
    }
}

// Structures
struct Movie {
    string title;
    int year;
};

void testStructures() {
    Movie movie1 = {"The Shawshank Redemption", 1994};

    // pointers to structures
    Movie *movie2 = &movie1;

    movie2->title = "The Godfather"; // which is equivalent to (*movie2).title =
                                     // "The Godfather";
    movie2->year = 1972;
}

// nested structures
struct Address {
    string street;
    string city;
    string state;
    int zip;
};

struct Person {
    string name;
    int age;
    Address *address;
};

void testNestedStructures() {
    Address address1 = {"123 Main St", "Anytown", "CA", 12345};
    Person person1 = {"John Doe", 30, &address1};

    // pointers to nested structures
    Person *person2 = &person1;

    person2->name = "Jane Doe";
    person2->age = 25;
    person2->address->street = "456 Elm St";
    person2->address->city = "Anytown";
    person2->address->state = "NY";
    person2->address->zip = 67890;
}

// type aliasing : typedef & using
typedef int i32;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef char *pChar;
typedef char field[50];

//  a second syntax to define type aliases was introduced in the C++
using f32 = float; // C++11 feature

void testTypeAliasing() {
    i32 a = -10;
    u32 b = 100;
    char ch = 'a';
    pChar c = &ch;
    field name;
    f32 f;
}

// Unions allow one portion of memory to be accessed as different data types.
// Its declaration and use is similar to the one of structures, but its
// functionality is totally different: The size of this type is the one of the
// largest member element.
//
// When unions are members of a class (or structure), they can be declared with
// no name. In this case, they become anonymous unions, and its members are
// directly accessible from objects by their member names.
struct Book1 {
    char title[50];
    char author[50];
    union {
        float dollars;
        int yen;
    } price;
} book1;
struct Book2 {
    char title[50];
    char author[50];
    union {
        float dollars;
        int yen;
    };
} book2;
void testUnions() {
    book1.price.dollars = 10.5;
    book2.dollars = 10.5;
}

// Enums
enum Color { RED, GREEN, BLUE };

enum Months {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
} y2k;

// enum types with enum class
enum class Colors { BLACK, BLUE, GREEN, CYAN, RED, PURPLE, YELLOW, WHITE };

// Enumerated types declared with enum class also have more control over their
// underlying type; it may be any integral data type, such as char, short or
// unsigned int, which essentially serves to determine the size of the type.
// This is specified by a colon and the underlying type following the enumerated
// type
enum class EyeColor : char { BLUE, GREEN, BROWN, BLACK };

void testEnums() {
    Color c = RED;
    cout << "c is " << c << endl;
    y2k = DECEMBER;
}

// class
class Rectangle {
    int width, height;

  public:
    void set_values(int w, int h);
    int area();
};

void Rectangle::set_values(int w, int h) {
    width = w;
    height = h;
}

int Rectangle::area() { return width * height; }

class Circle {
    float radius;

  public:
    Circle(float);
    Circle();
    float area();
};

// construct overloading
Circle::Circle(float r) { radius = r; }
Circle::Circle() { radius = 1; }
float Circle::area() { return 3.14 * radius * radius; }

void testClass() {
    Circle circle; // ok, default constructor called
    // Circle circle1(); // oops, default constructor NOT called
}

class Dummy {
  public:
    bool isitme(Dummy &param);
};

bool Dummy::isitme(Dummy &param) {
    if (&param == this)
        return true;
    else
        return false;
}

int add(const int &a, const int &b) {
    return a + b;
}

int add(const int *a, const int *b) {
    return *a + *b;
}

// type conversion
void testTypeConversion() {
    int a = 10;
    float b = 3.14;
    double c = 2.71828;
    char d = 'a';
    bool e = true;
    string f = "Hello, World!";

    // implicit conversion
    int i = a + b;
    long g;
    g = a;
}
