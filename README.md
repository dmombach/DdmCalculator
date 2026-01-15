
---

# 📘 **DdmCalculator**

A clean, modern C++ project exploring numerical computation, value‑type design, and compile‑time programming.  
This repository reflects my ongoing journey to master professional C++ engineering practices through incremental, test‑driven development.

---

## 🚀 **Overview**

DdmCalculator is a small but thoughtfully designed C++ application that performs numerical computations using a modern, constexpr‑capable Fraction type.

**Fun fact:** “DDM” also happens to be my initials — the name is both personal and technical.

The project focuses on:

- strong value semantics  
- clean class design  
- compile‑time correctness  
- modern C++ idioms  
- incremental refactoring and testing  

It’s both a practical tool and a learning sandbox for deeper C++ concepts.

---

## 🧩 **Key Components**

### **Fraction Class (Core Numeric Type)**  
A fully constexpr‑capable rational number type supporting:

- arithmetic operators  
- comparison operators  
- unary operators  
- reduction via constexpr `gcd`  
- sign normalization  
- compile‑time evaluation  
- runtime safety checks  

This class is designed to behave like a true value type, with clean semantics and predictable behavior.

### **DDM Calculation Logic**  
Implements the Gordon Growth Model (Dividend Discount Model), which is defined as:

$$ \text{Value} = \frac{D_1}{r - g} $$

Where:

- \(D_1\) = expected dividend next year  
- \(r\) = required rate of return  
- \(g\) = dividend growth rate  

The calculator uses the Fraction class internally to maintain precision and correctness.

---

## 🧪 **Testing**

The project includes:

### ✔ **Compile‑time tests**  
Using `static_assert` to validate:

- arithmetic correctness  
- reduction logic  
- comparison behavior  
- sign normalization  
- constexpr evaluation  

### ✔ **Runtime tests**  
Ensuring behavior matches expectations under real execution.

This dual‑layer testing approach reinforces correctness and builds confidence in the implementation.

---

## 🛠️ **Technologies & Standards**

- **C++17** (constexpr, one‑argument static_assert, modern idioms)  
- Standard Library only — no external dependencies  
- Visual Studio / MSVC toolchain  

---

## 📈 **What I’m Learning Through This Project**

This repository documents my progression as I deepen my understanding of:

- idiomatic C++ class design  
- header‑only constexpr types  
- compile‑time programming  
- operator overloading  
- value semantics  
- incremental refactoring  
- clean architecture in small systems  

It’s a living project that evolves as I grow.

---

## 🗺️ **Roadmap**

- Add more financial models (e.g., multi‑stage DDM)  
- Expand compile‑time test coverage  
- Introduce concepts (C++20) for numeric constraints  
- Add CI pipeline for automated builds  
- Improve CLI interface or add a GUI wrapper  

---

## 🤝 **Contributions**

This project is primarily a personal learning journey, but suggestions, discussions, and pull requests are welcome.

---

## 📜 **License**

MIT License — feel free to explore, learn from, or build upon this project.

---
