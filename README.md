
<div align="center">
  <h1>Competitive Programming Setup for VSCode on macOS</h1>
</div>

## 📋 Overview

This guide will help you set up a **competitive programming environment** in <b>Visual Studio Code</b> on <b>macOS</b>. You'll get:

- 🛠️ GCC compiler (C++)
- ⚡ Code Runner extension for quick execution
- 📦 `stdc++.h` header integration
- 🏃‍♂️ Automated compile & run script
- 🎯 Optimized VSCode settings

---

## 🏁 Quick Start

Follow these steps to get your environment ready:

### 1️⃣ Install Homebrew

Open your terminal and run:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

---

### 2️⃣ Install GCC (C++ Compiler)

```bash
brew install gcc
gcc --version
```
<details>
<summary>Why GCC?</summary>
GCC is the standard compiler for C++ in most contests. Installing via Homebrew ensures you get the latest version.
</details>

---

### 3️⃣ Add `stdc++.h` Header (for C++ Competitive Programming)

#### 3.1 Create the Required Folder

```bash
sudo mkdir -p /usr/local/include/bits
```

#### 3.2 Add the `stdc++.h` File

Download or copy the contents of [`stdc++.h`](https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/precompiled/stdc++.h) and save it as:

```bash
sudo nano /usr/local/include/bits/stdc++.h
```
Paste the contents, save, and exit.

---

### 4️⃣ Install Code Runner Extension in VSCode

1. Open VSCode
2. Go to Extensions (`⇧⌘X`)
3. Search for <b>Code Runner</b> and install it

---

### 5️⃣ Update VSCode Settings

Append the contents of the provided `settings.json` to your VSCode settings for optimal C++ workflow.

---

### 6️⃣ Create `run_program.sh` for Automated Compilation & Input

This script will help you compile and run C++ files with custom input files easily. Make sure to:

- Place `run_program.sh` in your project folder
- Make it executable:
  ```bash
  chmod +x run_program.sh
  ```
- Edit as needed for your workflow

---

## 💡 Tips & Troubleshooting

- If you get permission errors, use `sudo` where needed.
- For C++17/20, update your compile flags in `settings.json` and `run_program.sh`.
- Use the built-in VSCode terminal for best results.

---

## 📚 Resources

- [VSCode Docs](https://code.visualstudio.com/docs)
- [Code Runner Extension](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)
- [GCC Documentation](https://gcc.gnu.org/onlinedocs/)
- [Competitive Programming Book](https://cpbook.net/)

