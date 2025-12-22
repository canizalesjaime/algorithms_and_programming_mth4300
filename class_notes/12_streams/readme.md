# Lecture notes

## table of contents
1. File Streams
2. String Streams
3. Practice Examples


## File Streams
In C++, inputting and outputting files is handled using file streams from the ```<fstream>``` library. This library provides three key classes for file operations:

* ifstream: For reading from files (input file stream).
* ofstream: For writing to files (output file stream).
* fstream: For both reading and writing (input-output file stream).

### Including the ```<fstream>``` Library
Before working with files, you need to include the header:
```cpp
#include <fstream>
```

### Opening and Closing Files
To perform file operations, you need to open a file. Streams can be opened either in the constructor or using the .open() method.

* Opening a file: When you open a file for reading or writing, the file stream is associated with a file on your disk.
* Closing a file: It's good practice to close the file after operations to free up system resources.


#### Reading from Files (ifstream)
To read from a file, use the ifstream class.
##### Example:
```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("example.txt"); // Open file for reading
    if (!inputFile.is_open()) {             // Check if the file was successfully opened
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) { // Read file line by line
        std::cout << line << std::endl;     // Output each line to the console
    }

    inputFile.close();                      // Close the file
    return 0;
}
```

##### Explanation:
* std::ifstream inputFile("example.txt");: Opens the file example.txt for reading.
* std::getline(inputFile, line);: Reads one line from the file at a time into the line variable.
* inputFile.close();: Closes the file after reading.

#### Writing to Files (ofstream)
To write to a file, use the ofstream class. If the file doesn't exist, it will be created. If it exists, by default, it will be overwritten unless a specific mode is used.

##### Example:
```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream outputFile("output.txt"); // Open file for writing
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    outputFile << "This is a line of text.\n"; // Write a line of text
    outputFile << "Another line of text.\n";   // Write another line

    outputFile.close(); // Close the file
    return 0;
}
```
##### Explanation:
* std::ofstream outputFile("output.txt");: Opens output.txt for writing. If the file doesn't exist, it is created.
* outputFile << "text";: Writes text to the file.
* outputFile.close();: Closes the file after writing.


#### Reading and Writing Files (fstream)
To both read from and write to a file, use the fstream class. You need to specify the mode explicitly using flags such as std::ios::in (for reading) and std::ios::out (for writing).

##### Example:
```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::fstream file("data.txt", std::ios::in | std::ios::out | std::ios::app); // Open for reading and writing, append mode
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // Write to file
    file << "Adding some new data.\n";

    // Move the file pointer to the beginning for reading
    file.seekg(0, std::ios::beg);

    // Read from file
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close(); // Close the file
    return 0;
}
```
##### Explanation:
* std::fstream file("data.txt", std::ios::in | std::ios::out);: Opens data.txt for both reading and writing.
* file << "text";: Writes to the file.
* file.seekg(0, std::ios::beg);: Moves the file pointer back to the start to read from the file.
* std::getline(file, line);: Reads lines from the file.


### File Open Modes
When opening files, you can use different modes to control how the file is accessed:
* std::ios::in: Open for reading.
* std::ios::out: Open for writing (default behavior is to overwrite the file).
* std::ios::app: Append to the file without erasing its content.
* std::ios::binary: Open the file in binary mode (useful for non-text data).


### Example of specifying modes:
```cpp
std::ofstream file("data.txt", std::ios::out | std::ios::app);  // Open for writing and append mode
```

### Checking for File Errors
You can check if a file was successfully opened using the .is_open() method. Additionally, file streams support several flags to detect errors:

* fail(): Checks if a failure occurred (e.g., trying to read past the end of the file).
* eof(): Checks if the end of file has been reached.
* bad(): Checks for non-recoverable errors like hardware failure.
* good(): Returns true if no errors occurred.


#### Example:
```cpp
std::ifstream inputFile("data.txt");
if (!inputFile) {
    std::cerr << "Failed to open the file!" << std::endl;
}
```

### Example Summary: Copying File Contents
Here's a full example of how to read from one file and write its content into another:

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt");  // Open input file for reading
    std::ofstream outputFile("output.txt"); // Open output file for writing

    if (!inputFile || !outputFile) {
        std::cerr << "Error opening files!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) { // Read each line from input
        outputFile << line << std::endl;    // Write each line to output
    }

    inputFile.close();  // Close input file
    outputFile.close(); // Close output file
    return 0;
}
```

### Conclusion
Use ifstream for reading, ofstream for writing, and fstream for both reading and writing.
Always check if the file was opened successfully.
Remember to close the file after operations to release resources.
Use appropriate file open modes depending on whether you want to overwrite, append, or open in binary mode.


## String Streams 
`std::stringstream` is a C++ class that lets you treat a **string like a stream** (similar to how you treat files or `std::cin`).

This means you can:
- **build strings** using the `<<` operator  
- **parse strings** using the `>>` operator  
- **read/write** to the internal string buffer  
- **convert values** between types easily  

It lives in the header:

```cpp
#include <sstream>
```

---

### Writing to a string (using it like an output stream)

```cpp
#include <sstream>
#include <string>
#include <iostream>

int main() {
    std::stringstream ss;
    ss << "Value: " << 42 << ", Pi: " << 3.14;

    std::string result = ss.str();
    std::cout << result;  // Value: 42, Pi: 3.14
}
```

### Good for:
- building strings piece-by-piece  
- formatting the same way you would with `cout`  

---

### Reading from a string (using it like an input stream)

```cpp
#include <sstream>
#include <string>
#include <iostream>

int main() {
    std::string data = "24 apples 13 oranges";
    std::stringstream ss(data);

    int x, y;
    std::string a, b;

    ss >> x >> a >> y >> b;

    std::cout << x << " " << a << " " << y << " " << b;
}
```

### Useful for:
- tokenizing strings  
- reading mixed types  
- parsing structured text  

---

### Resetting or reusing a stringstream

`clear()` resets stream state flags  
`str("")` replaces the internal buffer

```cpp
ss.clear();      // reset error/eof flags
ss.str("");      // clear the contents
```

---

### Converting values to/from strings (common use)

### **Convert int → string**
```cpp
int n = 123;
std::stringstream ss;
ss << n;
std::string s = ss.str();
```

### **Convert string → int**
```cpp
std::string s = "456";
std::stringstream ss(s);
int n;
ss >> n;  // n = 456
```

---

### stringstream modes
You can control whether it's input/output/both:

```cpp
std::stringstream ss;                 // in + out
std::istringstream iss("123 456");    // input only
std::ostringstream oss;               // output only
```

---

### std::stringstream vs std::istringstream vs std::ostringstream

#### **stringstream**
- Input + Output

#### **istringstream**
- Input only (parsing)

#### **ostringstream**
- Output only (building a string)

---

### Example: Parsing a CSV line

```cpp
std::string line = "Bob,35,Engineer";
std::stringstream ss(line);
std::string name, age, job;

getline(ss, name, ',');
getline(ss, age, ',');
getline(ss, job, ',');

std::cout << name << " " << age << " " << job;
```

---

### **When should you use stringstream?**
Use it when you need:
- type-safe conversions  
- tokenizing strings  
- custom parsing  
- stream-style formatting  
- to treat a string like a file or input stream  


## practice examples
1. Read the [link list](./practice_examples/link_list.txt) from the file and store it in a stl list. Insert three nodes with the values 1,2 and 3 into the stl list. Sort the list by referencing [stl list documentation](https://cplusplus.com/reference/list/list/), then write the sorted list with the inserted values into a new file and name it ```modified_link_list.txt```. Reference the documentation and note the runtime and spacetime complexity for insert and sort.
2. Add another one 