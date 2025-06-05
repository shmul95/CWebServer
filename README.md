# CWebServer

A minimal, declarative web server built in C, where routes are automatically defined by the directory structure, eliminating manual configuration.

---

## 📌 Overview

**CWebServer** automatically maps directories to URL routes. Each directory and file in your project structure becomes a route, removing the need for extensive manual configuration.

---

## 🛠️ How It Works

### Directory Structure:

```
/CWebServer
│
├── public
│   ├── index.html      --> "/"
│   ├── about.html      --> "/about"
│   └── users
│       ├── index.html  --> "/users"
│       └── profile.html --> "/users/profile"
```

### Route Mapping:

* Directories map to URL routes.
* `index.html` serves as the default page for a directory.

| File Path                    | Route            |
| ---------------------------- | ---------------- |
| `/public/index.html`         | `/`              |
| `/public/about.html`         | `/about`         |
| `/public/users/index.html`   | `/users`         |
| `/public/users/profile.html` | `/users/profile` |

---

## 🚀 Getting Started

### Clone the Project:

```bash
git clone https://github.com/shmul95/CWebServer.git
cd CWebServer
```

### Build the Server:

```bash
make
```

### Run the Server:

```bash
./server
```

Your server will now serve files based on your directory structure.

---

## ✨ Benefits

* **Zero configuration:** Just organize files and directories—routes appear automatically.
* **Easy to maintain:** Add or remove routes by modifying files and folders.
* **Performance:** Lightweight and fast due to its minimal design in pure C.

---

## ⚙️ Customizing Routes

To add new routes, simply create or move files/directories within your `public` folder. No further configuration is required.

Example:

```bash
mkdir -p public/blog
echo "<h1>My Blog</h1>" > public/blog/index.html
```

This creates a new `/blog` route immediately.

---

## ✅ Contributions

Contributions are welcome! Please fork and submit a pull request.

Some ideas of what I'll do next
[TODO](TODO.md)

---

## 📝 License

This project is licensed under the MIT License.
