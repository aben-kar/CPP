# C++ Module 00 - Learning Concepts

## **Exercise 00: Megaphone**

**Core Concepts:**
- **Command-line arguments** (`argc`, `argv`)
- **String manipulation** - converting to uppercase
- **std::cout** for output
- **C++ strings** (`std::string`) vs C-style strings
- **Basic Makefile** structure with C++ compilation flags
- **Character manipulation** using `std::toupper()` or manual conversion

**Key Skills:**
- Iterating through command-line arguments
- Processing each character in a string
- Handling edge cases (no arguments provided)

---

## **Exercise 01: PhoneBook**

**Core Concepts:**
- **Classes and Objects** - defining `PhoneBook` and `Contact` classes
- **Member variables (attributes)** - storing contact data
- **Member functions (methods)** - ADD, SEARCH operations
- **Access specifiers** - `private` vs `public`
- **Arrays** - fixed-size array of 8 contacts (no dynamic allocation)
- **std::cin** for user input
- **std::string** for storing text fields
- **Input validation** - checking for empty fields
- **std::iomanip** - formatting output in columns (10 chars wide, right-aligned)
  - `std::setw()` - set column width
  - `std::right` - right-align text
- **String truncation** - limiting display to 10 chars with dot
- **Circular buffer logic** - replacing oldest contact when full

**Class Design:**
```cpp
class Contact {
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
public:
    // Getters/setters
};

class PhoneBook {
private:
    Contact _contacts[8];
    int _currentIndex;
    int _totalContacts;
public:
    void add();
    void search();
};
```

**Additional Skills:**
- **Header files** (`.hpp`) - class declarations
- **Separate compilation** - multiple `.cpp` files
- **Include guards** - preventing double inclusion
- **Program loop** - continuous command prompt until EXIT
- **Input parsing** - reading and validating user commands
