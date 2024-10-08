// <> for std lib and "" for user defined headers or files in the same project
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

int main() {
    testLibArray();
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
