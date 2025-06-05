## ✅ TODO

Here's the roadmap for improving and extending **CWebServer**:

---

### 1. Finalize Static Routing System

* Implement automatic URL-to-directory/file mapping, ensuring full functionality and correctness.
* Eliminate any manual configuration for static routes.

---

### 2. Implement Dynamic Routing System

* Introduce dynamic URL handling through specifically named directories.

#### Example Dynamic Routing Structure:

```
/public
├── user-id
│   ├── user.html         # General handler (e.g., `/user/12`)
│   ├── user-0.html       # Specific handler (`/user/0`)
│   └── 404.html          # Fallback handler
```

#### Routing Logic:

* Prioritize specific handlers (`user-<id>.html`).
* Use general handler (`user.html`) as default.
* Use fallback (`404.html`) if neither handler exists.

---

### 3. Built-in Authentication System

* Automatically manage authentication without additional backend configuration.
* Trigger authentication logic by the presence of these HTML files:

```
/public
├── login.html       # Login functionality
├── signin.html      # User registration functionality
└── logout.html      # Logout functionality
```

* Backend handles sessions, registrations, logins, and logouts seamlessly.

---

### 4. Integrated Database Management

* Link dynamic routing functionality directly with database tables.
* For each dynamic route directory (e.g., `user-id`), ensure there is a corresponding database table (`user`) containing:

  * A public and unique attribute named `id` (public means this attribute cannot be a sensitive field like a password).
  * Additional attributes as required.

#### Database and Routing Example:

```
Route: /user/12
│
├── Directory: user-id
│   └── user.html
│
├── Database Table: user
│   └── Columns: id (unique, public), name, email, ...
```

* Server uses `id` from URL to fetch and serve data from the matching database entry automatically.

