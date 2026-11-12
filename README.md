# DSA01 – Assignment 3 (CO3)
## C++ Constructors, Destructors and Operator Overloading

### Student Details

| Field | Details |
|---|---|
| Name | Jason Joshva M J |
| Register Number | 192511209 |
| Department | Computer Science and Engineering |
| Assignment | Assignment 3 |
| Course Outcome | CO3 |
| Programming Language | C++ |
| Standard | C++17 |
| Compiler | Microsoft Visual C++ (MSVC) 19.51.36260 |
| IDE / Environment | Visual Studio 2026 |

---

## 1. Assignment Overview

This assignment focuses on implementing and evaluating advanced Object-Oriented Programming concepts in C++.

The primary objective is to understand how constructors, destructors, copy operations and operator overloading control object creation, memory management and operator behaviour.

The assignment consists of seven individual programming tasks based on real-world scenarios.

### 2. Concepts Covered

- Default and parameterised constructors
- Constructor overloading and constructor delegation
- Member initializer lists
- Copy constructors
- Shallow copying and deep copying
- Copy assignment operators
- Destructors and dynamic memory allocation
- Rule of Three
- Arithmetic and comparison operator overloading
- Stream insertion and extraction operators
- Prefix and postfix increment operators
- Subscript operator overloading
- Complex number operations
- Exception handling and memory management

---

## 3. Task Descriptions

### Q1 – Constructors and Constructor Overloading (6 Marks)

**Scenario:** Library Book Records

Implemented a Book class using default, parameterised and overloaded constructors.

Key implementations:
- Constructor delegation
- Member initializer lists
- Validation of the number of book copies
- Exception handling for negative copy values

### Q2 – Copy Constructors: Shallow and Deep Copies (7 Marks)

**Scenario:** Hospital Prescription Records

Implemented a Prescription class that manages dynamically allocated medicine arrays.

Key implementations:
- Deep-copy constructor
- Copy assignment operator
- Destructor
- Self-assignment protection
- Independent copies of prescription records

### Q3 – Dynamic Constructors and Destructors (7 Marks)

**Scenario:** Auditorium Seat Booking

Implemented a dynamically allocated two-dimensional seat map.

Key implementations:
- Dynamic memory allocation using `new`
- Memory release using `delete[]`
- Seat booking and cancellation
- Stack and heap object creation
- Destructor execution and resource cleanup

### Q4 – Arithmetic and Stream Operator Overloading (7 Marks)

**Scenario:** Money Arithmetic for a Billing Counter

Implemented a Money class that stores monetary values in paise.

Key implementations:
- Addition (`+`)
- Subtraction (`-`)
- Equality (`==`)
- Compound addition (`+=`)
- Stream insertion (`<<`)
- Stream extraction (`>>`)

### Q5 – Increment, Comparison and Subscript Operators (6 Marks)

**Scenario:** Music Playlist and Track Timer

Implemented Time and Playlist classes.

Key implementations:
- Prefix increment (`++i`)
- Postfix increment (`i++`)
- Comparison operators
- Subscript operator (`[]`)
- Index validation and exception handling
- Time rollover

### Q6 – Rules of Operator Overloading (7 Marks)

**Scenario:** Simple Text Class for an SMS Gateway

Implemented a custom Text class using dynamically allocated character arrays.

Key implementations:
- Copy constructor
- Copy assignment operator
- Destructor
- Concatenation (`+`)
- Equality (`==`)
- Inequality (`!=`)
- Stream insertion (`<<`)
- Self-assignment protection

### Q7 – Complex Number Class from First Principles (10 Marks)

**Scenario:** AC Circuit Impedance Calculator

Designed and implemented a Complex class for electrical impedance calculations.

Key implementations:
- Complex number constructors
- Addition and subtraction
- Multiplication and division
- Equality comparison
- Magnitude calculation
- Series and parallel impedance calculations
- Division-by-zero exception handling

---

## 4. Repository Structure

```text
DSA01-192511209-Assignment3/
│
├── README.md
├── .gitignore
│
├── Q1/
│   ├── Task01_Constructors.cpp
│   └── Q1_Output.png
│
├── Q2/
│   ├── Task02_CopyConstructor.cpp
│   └── Q2_Output.png
│
├── Q3/
│   ├── Task03_DynamicConstructorDestructor.cpp
│   └── Q3_Output.png
│
├── Q4/
│   ├── Task04_MoneyOperators.cpp
│   └── Q4_Output.png
│
├── Q5/
│   ├── Task05_IncrementComparisonSubscript.cpp
│   └── Q5_Output.png
│
├── Q6/
│   ├── Task06_TextOperatorRules.cpp
│   └── Q6_Output.png
│
└── Q7/
    ├── Task07_ComplexImpedance.cpp
    └── Q7_Output.png
```

*Add the output screenshots to their respective folders before submission.*

---

## 5. Compilation and Execution

All programs were compiled independently using Microsoft Visual C++ (MSVC) with the C++17 standard.

### Compilation Command

```powershell
cl /EHsc /std:c++17 filename.cpp
```

### Execution Command

```powershell
.\filename.exe
```

### Individual Compilation Commands

| Question | Compilation Command |
|---|---|
| Q1 | `cl /EHsc /std:c++17 Task01_Constructors.cpp` |
| Q2 | `cl /EHsc /std:c++17 Task02_CopyConstructor.cpp` |
| Q3 | `cl /EHsc /std:c++17 Task03_DynamicConstructorDestructor.cpp` |
| Q4 | `cl /EHsc /std:c++17 Task04_MoneyOperators.cpp` |
| Q5 | `cl /EHsc /std:c++17 Task05_IncrementComparisonSubscript.cpp` |
| Q6 | `cl /EHsc /std:c++17 Task06_TextOperatorRules.cpp` |
| Q7 | `cl /EHsc /std:c++17 Task07_ComplexImpedance.cpp` |

---

## 6. Execution Results

All seven C++ programs were successfully compiled and executed using Visual Studio Developer PowerShell.

The observed executions demonstrated:

- Successful construction and validation of Book objects.
- Independent prescription copies through deep copying.
- Dynamic allocation and destruction of auditorium seat maps.
- Correct monetary arithmetic and operator overloading.
- Prefix and postfix increment behaviour.
- Safe text copying, concatenation and assignment.
- Complex arithmetic and impedance calculations.

The individual console output screenshots are maintained in the respective question folders.

---

## 7. Complexity Analysis

| Question | Main Operation | Time Complexity |
|---|---|---|
| Q1 | Book object construction | O(1) |
| Q2 | Deep copying n medicines | O(n) |
| Q3 | Seat map allocation | O(R × S) |
| Q4 | Money arithmetic | O(1) |
| Q5 | Increment and playlist access | O(1) |
| Q6 | Text concatenation | O(n + m) |
| Q7 | Complex number arithmetic | O(1) |

---

## 8. Learning Outcomes

Through this assignment, I gained practical experience in:

1. Understanding constructor overloading and object initialisation.
2. Managing dynamically allocated memory using constructors and destructors.
3. Identifying problems associated with shallow copying.
4. Implementing deep copying and the Rule of Three.
5. Overloading operators to improve code readability.
6. Understanding object lifetimes and resource management.
7. Applying object-oriented programming concepts to practical engineering problems.

---

## 9. Conclusion

This assignment provided practical exposure to advanced C++ programming concepts, particularly constructors, destructors, dynamic memory allocation, copy semantics and operator overloading.

By implementing seven different problem scenarios, the assignment helped strengthen the understanding of object lifecycle management, memory ownership, safe resource handling and user-defined operator behaviour.

The completed programs demonstrate the application of C++ object-oriented programming concepts to real-world scenarios while maintaining modularity, readability and structured implementation.

---

**Submitted by:** Jason Joshva M J  
**Register Number:** 192511209  
**Assignment:** DSA01 – Assignment 3 (CO3)
