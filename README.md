# Mini OOP Project - Store Data Management

*Author: Cătălin Gabriel Badea*  
*University: UPB ACS*  
*Year: 2024*  

---

## 📌 General Description

This is a homework developed for the Object-Oriented Programming (OOP) course at university.  
The goal was to implement a simple program to manage store data using custom classes, without STL, and handling text files for input and output.

Although the project was an academic assignment, it is designed and documented to demonstrate my programming style, clarity, and code modularity.  

In short: it’s a small project but showcases how I apply learned concepts and organize code to be readable and extensible. I know it's not much to see here.

---

## 🎯 Project Requirements

- Reading lists of products and clients from text files (`produse.txt` and `clienti.txt`).  
- Storing and managing data in dedicated classes (`Product`, `Client`, `Order`).  
- Processing orders, checking and updating stock.  
- Generating two output files:  
  - `output_comenzi.txt` with detailed client order information.  
  - `output_stoc_ramas.txt` with updated stock after processing.  
- The program must run from the command line with the input files as arguments.  
- Major restriction: NO STL usage to better understand implementations from scratch.

---

## 🛠️ Our Approach

- Created clear structures and classes for products, clients, and orders, with member variables and specific functions.  
- Used dedicated functions for reading files (e.g., `ReadNumberOfElements` for counting items).  
- Implemented selling logic with the `SellProduct` function, updating stock and order prices.  
- To avoid STL, worked with dynamically allocated arrays and manually managed memory.  
- Maintained unique IDs using static variables `nextId` for products and orders.  
- Code contains many explanatory comments detailing each step, making it easy to follow and understand.  
- Exception handling is minimalistic since the requirements didn’t specify details — in case of missing stock, the program simply terminates.

---

## 📂 Project Structure

- Source code is organized across multiple `.h` and `.cpp` files for clarity and modularity.  
- Comments inside the code explain in detail the implemented functions and logic.  
- Input (`produse.txt`, `clienti.txt`) and output files are plain text, easy to check.

---

## ⚠️ Note

This is just a university project for educational purposes and not a fully developed or production-ready software.  
However, it is a good practical example of applying OOP principles and working with text files in C++.

---

## 📌 Acknowledgments

Thank you for your interest!  
If you have questions or suggestions, I’m open to discussions.

---

*For more details, please check the comments inside the source code.*

---

*— Cătălin Gabriel Badea*
