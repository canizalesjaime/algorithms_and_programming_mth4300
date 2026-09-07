# Lecture Notes

## table of contents
1. C++ Syntax
2. Functions
3. Operators 
4. Conditional Statements
5. Cin and Cout 
6. For Loops
7. While Loops
8. Arrays
9. Practice Examples


## **C++ Syntax Guide**  

### **Comments in C++**  
In C++, comments can be specified in two ways:  
- **Single-line comments**: Indicated by `//`, which marks everything after it on the same line as a comment.  
- **Multi-line comments**: Enclosed between `/*` and `*/`, allowing comments to span multiple lines.  

### **Statements and Semicolons**  
- A **statement** in C++ represents a single instruction or line of code.  
- Statements must be terminated with a **semicolon (`;`)**.  

### **Variables in C++**  
Variables in C++ allow developers to store and manage data of different types. Common variable types include:  

- **`int` (Integer)**: Represents whole numbers.  
  - Example:  
    ```cpp
    int x = 7;
    ```  
  - Variants include `short` (smaller range) and `long` (larger range).  

- **`float` (Floating-point number)**: Represents decimal numbers.  
  - Example:  
    ```cpp
    float y = 2.718;
    ```  
  - The `double` type offers higher precision at the cost of increased memory usage.  

- **`char` (Character)**: Represents a single character.  
  - Example:  
    ```cpp
    char a = 'd';
    ```  

- **`string` (String of characters)**: Represents a sequence of characters.  
  - Example:  
    ```cpp
    string word = "Hello World";
    ```  

- **`bool` (Boolean)**: Represents a value that is either `true` or `false`.  
  - Example:  
    ```cpp
    bool check = true;
    ```  

### **Rules for Variable Naming**  
Variable names in C++ must follow these rules:  
1. Keywords (reserved words) **cannot** be used as variable names.  
2. Variable names **cannot** start with a number.  
3. Variable names can only contain **alphanumeric characters and underscores (`_`)**.  

### **Preprocessor Directives**  
- Preprocessor directives begin with `#` and instruct the compiler to perform preprocessing before compilation.  
- Examples include:
  * ```#include <iostream>``` (for input-output operations)
  * ```#include <string>``` (for string manipulation)


### Scope of Variables
* The scope of a variable is determined by the curly braces ```{}``` in which it is declared.
  * A variable exists only within its enclosing block and cannot be accessed outside of it.


## Functions
A function is a reusable block of code that performs a specific operation. Functions may:

* Accept input parameters (arguments).
* Return a value (optional).

### Function Syntax
```cpp
return_type function_name(type_1 param_1, type_2 param_2, ..., type_n param_n)  
{
    // Function code
    return value_of_return_type;
}
```

### Function Declaration and Definition
* It is good practice to declare a function before defining it, especially when working with classes and object-oriented programming.
* The function declaration is placed above the main function, while the function definition appears below.


## **Operators in C++**  

### **Arithmetic Operators**  
Arithmetic operators perform mathematical operations on numeric values.  

| Operator | Description       | Example     |
|----------|-------------------|-------------|
| `+`      | Addition          | `x + y`     |
| `-`      | Subtraction       | `x - y`     |
| `*`      | Multiplication    | `x * y`     |
| `/`      | Division          | `x / y`     |
| `%`      | Modulus (remainder) | `15 % 2` results in `1` (works only with integers) |

### **Assignment Operator**  
| Operator | Description                 | Example     |
|----------|-----------------------------|-------------|
| `=`      | Assigns a value to a variable | `int x = 5;` |

### **Logical Operators**  
Logical operators evaluate conditions and return `true` or `false`.  

| Operator | Description               | Example                |
|----------|---------------------------|------------------------|
| `!`      | NOT (negation)             | `!true → false`       |
| `&&`     | AND (both must be true)    | `true && false → false` |
| `\|\|`     | OR (at least one is true)  | `true \|\| false → true` |
| `==`     | Equality check             | `5 == 5 → true`       |

---

### **Object-Oriented Programming and Operators**  
C++ supports **object-oriented programming (OOP)**, allowing developers to define their own **classes** and **customize operators** through **operator overloading**.  

### **Operator Overloading**  
Operator overloading enables assigning custom functionality to operators for user-defined types.  

For example, in the `string` class:  
```cpp
string str1 = "Hello";
string str2 = " World";
string result = str1 + str2;  // Concatenation using `+`
cout << result;  // Output: Hello World
```


## Conditional Statements
Conditional statements in C++ allow the program to make decisions based on certain conditions. These statements control the flow of execution by executing different code blocks depending on whether a condition is true or false. The most common conditional statements in C++ are:

### 1. if statement
The if statement executes a block of code if a specified condition evaluates to true.

```cpp
if (condition) { 
    // Code to be executed if condition is true
}
```

#### Example:

```cpp
int a = 10; 
if (a > 5) { 
    cout << "a is greater than 5" << endl;
}
```

### 2. else statement
The else statement is used in conjunction with if. It provides an alternative block of code that will be executed if the condition in the if statement is false.

```cpp
if (condition) { 
    // Code to be executed if condition is true
} else { 
    // Code to be executed if condition is false
}
```

#### Example:

```cpp 
int a = 3;
if (a > 5) { 
    cout << "a is greater than 5" << endl;
}
else { 
    cout << "a is not greater than 5" << endl; 
}
```

### 3. else if statement
The else if statement allows you to test multiple conditions. If the first if condition is false, the program checks the else if condition.

```cpp
if (condition1) {
     // Code to be executed if condition1 is true
}
else if (condition2) { 
    // Code to be executed if condition2 is true
} 
else { 
    // Code to be executed if none of the conditions are true
}
```

#### Example:

```cpp
int a = 7; 
if (a > 10) { 
    cout << "a is greater than 10" << endl;
} 
else if (a == 7) { 
    cout << "a is equal to 7" << endl;
} 
else { 
    cout << "a is less than or equal to 10 but not 7" << endl;
}
```

## cin and cout
### 1. What are `cin` and `cout`?

C++ uses **streams** for input and output.

```cpp
#include <iostream>
```

The two most common are:

```cpp
std::cin     // standard input
std::cout    // standard output
```

Think of them as:

```text
Keyboard → cin → Program → cout → Terminal
```

---

## 2. `std::cout` — Output

`std::cout` sends information **out of your program** to the terminal.

```cpp
std::cout << "Hello!";
```

The `<<` operator is called the **insertion operator**.

You can output variables:

```cpp
int age = 25;

std::cout << age;
```

Or combine values:

```cpp
std::cout << "Age: " << age << '\n';
```

Output:

```text
Age: 25
```

### New Lines

You can use:

```cpp
std::cout << "Hello\n";
```

or:

```cpp
std::cout << "Hello" << std::endl;
```

Both create a new line, although `'\n'` is usually preferred when you don't specifically need to flush the output stream.

---

### 3. `std::cin` — Input

`std::cin` receives information **into your program**.

```cpp
int age;

std::cin >> age;
```

The `>>` operator is called the **extraction operator**.

If the user enters:

```text
25
```

then:

```cpp
age == 25
```

The variable's type determines how `cin` interprets the input:

```cpp
int age;
double price;
char letter;

std::cin >> age;
std::cin >> price;
std::cin >> letter;
```

---

## 4. Putting `cout` and `cin` Together

A common pattern is:

```cpp
#include <iostream>

int main()
{
    int age;

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "You are " << age << " years old.\n";

    return 0;
}
```

Example:

```text
Enter your age: 25
You are 25 years old.
```

Remember:

```cpp
std::cout << value;   // program → terminal
std::cin >> value;    // terminal → program
```

The arrows give you a useful visual clue:

```text
cout <<    OUT
cin  >>    IN
```

---

## 5. Reading Multiple Values

You can chain `>>`:

```cpp
int x;
int y;

std::cin >> x >> y;
```

Input:

```text
10 20
```

Result:

```text
x = 10
y = 20
```

Likewise, `cout` can chain `<<`:

```cpp
std::cout << "x = " << x << ", y = " << y << '\n';
```

---

### 6. Strings and `getline()`

`cin >>` stops when it reaches whitespace.

```cpp
std::string name;

std::cin >> name;
```

If the user enters:

```text
John Smith
```

only `"John"` is stored.

To read an entire line:

```cpp
std::getline(std::cin, name);
```

Now:

```text
John Smith
```

is stored as the complete string.

---

### 7. Invalid Input

Suppose you expect an integer:

```cpp
int age;
std::cin >> age;
```

but the user enters:

```text
hello
```

`cin` cannot convert `"hello"` to an `int`, so the stream enters a **failure state**.

You can check for it:

```cpp
if (std::cin.fail())
{
    std::cout << "Invalid input!\n";
}
```

You can reset the error with:

```cpp
std::cin.clear();
```

Input validation becomes important when writing interactive programs.

### 8. `using namespace std;`

`using namespace std;` lets you use names from the C++ **standard library** without writing `std::` every time.

### Without It

```cpp
#include <iostream>
#include <string>

int main()
{
    std::string name;

    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Hello " << name << '\n';
}
```

### With It

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Hello " << name << '\n';
}
```

It essentially allows:

```text
std::cout    → cout
std::cin     → cin
std::string  → string
std::endl    → endl
```

`std` is a **namespace** containing much of the C++ standard library.

`using namespace std;` tells the compiler that names like `cout`, `cin`, and `string` can be found inside `std`.

It's convenient for **small programs and learning**, but in larger programs it's usually better to keep `std::` because importing the entire namespace can cause **name conflicts**.


## For Loops
In C++, loops are used to execute a block of code repeatedly. The two common types of loops are `for` loops and `while` loops. Here's a brief overview of for loops:

### `for` Loop

A `for` loop is used when you know in advance how many times you want to execute a statement or a block of statements. It consists of three parts:

1. **Initialization**: Set up a loop control variable.
2. **Condition**: Check if the loop should continue.
3. **Update**: Modify the loop control variable.

**Syntax:**

```cpp
for (initialization; condition; update) {
    // Code to be executed
}
```

#### Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 5; i++) {
        cout << i << " ";
    }
    return 0;
}
```


## While Loops
In C++, loops are used to execute a block of code repeatedly. The two common types of loops are `for` loops and `while` loops. Here's a brief overview of While loops:


### `while` Loop
A while loop is used when you do not know in advance how many times you need to execute a statement or a block of statements. The loop continues as long as a specified condition is true.

**Syntax:**

``` cpp
while (condition) {
    // Code to be executed
}
```

#### Example:

``` cpp
#include <iostream>
using namespace std;

int main() {
    int i = 0;
    while (i < 5) {
        cout << i << " ";
        i++;
    }
    return 0;
}
```
In this example, the loop continues as long as i is less than 5. It prints numbers from 0 to 4, just like the for loop example.

#### Key Differences
**Initialization and Update:** In a for loop, initialization and update happen in the loop statement, while in a while loop, they must be handled inside the loop body.
**Condition Checking:** Both loops check their conditions before executing the loop body, but for loops are generally used when the number of iterations is known ahead of time.

## Arrays
In C++, an array is a data structure that can hold a fixed-size sequence of elements of the same type. Arrays are useful for storing multiple values in a single variable and can be accessed using an index.

### Declaration and Initialization

**Declaration**:
To declare an array, you specify the type of its elements and the number of elements it will hold.

**Syntax:**

```cpp
type arrayName[arraySize];
```

#### Example:

```cpp
int numbers[5];
This declares an array named numbers that can hold 5 integers.
```

**Initialization:** You can initialize an array at the time of declaration by providing a list of values enclosed in curly braces.

**Syntax:**

```cpp
type arrayName[arraySize] = {value1, value2, value3, ..., valueN};
```

#### Example:

```cpp
int numbers[5] = {1, 2, 3, 4, 5};
```

### Accessing Elements
You access elements in an array using an index, with the first element at index 0.

**Syntax:**

```cpp
arrayName[index]
```

#### Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    cout << numbers[0]; // Outputs 1
    cout << numbers[4]; // Outputs 5
    return 0;
}
```


In this example, the loop starts with i set to 0, continues as long as i is less than 5, and increments i by 1 in each iteration. It prints numbers from 0 to 4.


## Practice Examples
1. Create a program that reads 10 real numbers from the standard input and calculates their sum. After the user enters the 10 numbers the program should print all the numbers entered by the user, and also print the sum of the numbers. 
2. Create a program that reads real numbers of type double from the user input until it reads a negative number or zero. The negative number (or zero) means that the input is over. You are allowed to assume that the input from the user will contain at least one positive element. The program should calculate the maximum of the numbers provided by the user.
