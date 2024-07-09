# Password Strength Checker

## Overview
The Password Strength Checker is a web-based application that allows users to enter passwords and receive feedback on their strength. The application consists of a frontend developed using HTML, CSS, and JavaScript, and a backend implemented in C++ for analyzing the password strength.

## Features
- **Frontend**: A form for users to input passwords.
- **Backend**: A C++ program that analyzes password strength based on length, complexity, and character variety.
- **Integration**: JavaScript for handling user interactions, displaying strength indicators, and providing feedback.

## Directory Structure
Password-Strength-Checker/
│
├── project/
│ ├── backend/
│ │ ├── password_checker.cpp
│ │ ├── password_checker (compiled executable)
│ │
│ ├── node_modules/
│ │ ├── express/
│ │
│ ├── index.html
│ ├── styles.css
│ ├── script.js
│ ├── server.js
│ ├── package.json
│ ├── package-lock.json
│
└── README.md

## Prerequisites
- Node.js and npm
- g++ compiler
- jsoncpp library

## Setup Instructions

### 1. Clone the Repository
```sh
git clone https://github.com/your-username/password-strength-checker.git
cd password-strength-checker/project
2. Install Node.js Dependencies
npm install
3. Install jsoncpp Library
On Ubuntu or Debian-based systems:
sudo apt-get update
sudo apt-get install libjsoncpp-dev
4. Compile the C++ Program
cd backend
g++ -I/usr/include/jsoncpp password_checker.cpp -o password_checker -ljsoncpp
cd ..
5. Start the Node.js Server
npm start
Usage
Open your web browser and navigate to http://localhost:3000.
Enter a password in the provided form.
Submit the form to see the password strength and feedback.
Troubleshooting
If you encounter json/json.h: No such file or directory, ensure the jsoncpp library is installed and the include path is correct.
If the server doesn't start, make sure you have installed the express module by running npm install express.

Example

Example Password Strength Check
Password: TestPassword123!
Result:
{
    "strength": "Strong",
    "feedback": []
}

Example Weak Password Check
Password: 1234
Result:
{
    "strength": "Weak",
    "feedback": [
        "Password should be at least 8 characters long.",
        "Password should contain at least one uppercase letter.",
        "Password should contain at least one lowercase letter.",
        "Password should contain at least one special character."
    ]
}

License
This project is licensed under the MIT License.

Author
Joseph N. Mtakai
