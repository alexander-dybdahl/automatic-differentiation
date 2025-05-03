# Automatic Differentiation in C++

This project implements both **forward-mode** and **reverse-mode automatic differentiation** in modern C++, without any external dependencies.

## 🧠 Overview

- **Forward Mode**: Uses dual numbers to compute derivatives alongside function evaluation.
- **Reverse Mode**: Builds a computational graph at runtime and applies the chain rule in reverse for efficient gradient computation.

Both modes are implemented from scratch using standard C++ and tested with basic examples.

## 📁 Project Structure

```
AUTOMATIC-DIFFERENTIATION/
├── include/                   # Public headers
│   ├── forward_ad.hpp         # Forward-mode AD implementation
│   └── reverse_ad.hpp         # Reverse-mode AD implementation
├── src/                       # (Optional) Implementation sources
├── examples/                  # Usage examples (entry points)
│   ├── forward_example.cpp    # Demonstrates forward-mode AD
│   └── reverse_example.cpp    # Demonstrates reverse-mode AD
├── .vscode/                   # VSCode tasks and launch config
│   ├── tasks.json             # Build instructions
│   └── launch.json            # Run/debug configs
├── .gitignore                 # Ignore build artifacts
├── CMakeLists.txt             # (optional, not used here)
└── README.md
```

## 🚀 How to Build and Run (VSCode + MSVC)

### Prerequisites

- Windows with **Visual Studio Build Tools** (MSVC)
- **VSCode**
- The MSVC environment initialized with `vcvars64.bat`

### 🔨 Build

From VSCode:

- Press `Ctrl+Shift+B`
- Select:
  - `Build Forward Example (with MSVC)` → builds `forward.exe`
  - `Build Reverse Example (with MSVC)` → builds `reverse.exe`

### ▶️ Run

From the integrated terminal or Run/Debug tab:

```
./forward.exe
./reverse.exe
```

## ✅ Example Output

### Forward Mode:
```
f(x) = 1.81859
df/dx = 0.0770038
```

### Reverse Mode:
```
Function output: 1.68294
df/dx1 = 0.841471
df/dx2 = 1.0806
```

## 🧩 What You Can Extend

- Support for `exp`, `log`, `cosh`, `tanh`, etc.
- Vector-valued functions or Jacobians
- Expression trees for graph visualization
- CMake-based builds for cross-platform use
- Unit testing with Catch2 or GoogleTest
