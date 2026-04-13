<p align="center">
  <img src="DdmCalculator.png" width="300" alt="DdmCalculator Logo" />
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C++-17/20/23-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" />
  <img src="https://img.shields.io/badge/CMake-3.20+-064F8C?style=for-the-badge&logo=cmake&logoColor=white" />
  <img src="https://img.shields.io/badge/GCC/Clang-11+-262D3A?style=for-the-badge&logo=llvm&logoColor=white" />
  <img src="https://img.shields.io/badge/Math-Financial%20Modeling-2E8B57?style=for-the-badge&logo=calculator&logoColor=white" />
  <img src="https://img.shields.io/badge/License-MIT-blue?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Status-Active-success?style=for-the-badge" />
</p>

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

## 🧭 Before / After: Evolution of the Fraction Class

This project intentionally reflects how my C++ skills have grown over time.  
The `Fraction` type is a good example of that progression.

### **Before (early version)**  
A simple, functional structure with minimal encapsulation and no compile‑time capabilities:

```cpp
class Fraction {
public:
    Fraction(int n, int d) : num(n), den(d) {}
    int num;
    int den;
};
```

### **After (current version)**  
A clean, modern, constexpr‑capable value type with full arithmetic, comparisons, reduction, and compile‑time validation:

```cpp
class Fraction {
public:
    constexpr Fraction(int numerator = 0, int denominator = 1);
    constexpr int numerator() const;
    constexpr int denominator() const;
    // full constexpr arithmetic, comparisons, reduction, etc.
private:
    int m_numerator;
    int m_denominator;
    static constexpr int gcd(int a, int b);
    constexpr void reduce();
};
```

### **What this evolution represents**  
- Moving from basic class syntax to **professional value‑type design**  
- Adding **constexpr** support for compile‑time evaluation  
- Introducing **operator overloading** for natural arithmetic  
- Implementing **sign normalization** and **fraction reduction**  
- Building a **compile‑time test suite** using `static_assert`  
- Developing a deeper understanding of **clean architecture** and **modern C++ idioms**

This section highlights not just the code, but the learning journey behind it — a core purpose of this repository.

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
