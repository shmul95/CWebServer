## ✅ TODO

Here's the planned roadmap for improving and extending **CWebServer**:

### 1. Finalize Static Routing System

* Fully implement automatic routing based on the directory and file structure as described.
* Ensure consistent mapping of directories and files to URL paths without manual configuration.

---

### 2. Implement Dynamic Routing System

* Support dynamic routing via specially named directories for parameterized URL handling.

#### Example Dynamic Routing Structure:

```
/public
├── user-id
│   ├── user.html        # General handler for dynamic parameter (e.g., `/user/12`)
│   ├── user-0.html      # Specific handler for user ID `0` (e.g., `/user/0`)
│   └── 404.html         # Fallback if no matching handler is found
```

#### Dynamic Routing Logic:

* Requests matching dynamic placeholders (`user-id`) serve `user-<id>.html` if available.
* If a specific handler isn't available, the general handler (`user.html`) is served.
* If neither exist, the fallback `404.html` is served.

---

### 3. Built-in Authentication System

* Implement integrated authentication with zero backend configuration required by the user.
* Authentication functionality will be activated by the presence of specific HTML files.

#### Required Authentication Files:

```
/public
├── login.html       # Login page; backend handles authentication
├── signin.html      # Signup page; backend handles user registration
└── logout.html      # Logout page; backend manages session termination
```

#### Authentication Flow:

* Server detects the above files and automatically handles authentication processes, session management, and user account creation.
* Users only need to provide these HTML files; backend logic is automatic.
