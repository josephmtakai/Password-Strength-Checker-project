#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <json/json.h>

bool containsUppercase(const std::string& str) {
    return std::any_of(str.begin(), str.end(), ::isupper);
}

bool containsLowercase(const std::string& str) {
    return std::any_of(str.begin(), str.end(), ::islower);
}

bool containsDigit(const std::string& str) {
    return std::any_of(str.begin(), str.end(), ::isdigit);
}

bool containsSpecialCharacter(const std::string& str) {
    return std::any_of(str.begin(), str.end(), ::ispunct);
}

std::string analyzePassword(const std::string& password) {
    int score = 0;
    std::vector<std::string> feedback;

    if (password.length() >= 8) {
        score++;
    } else {
        feedback.push_back("Password should be at least 8 characters long.");
    }

    if (containsUppercase(password)) {
        score++;
    } else {
        feedback.push_back("Password should contain at least one uppercase letter.");
    }

    if (containsLowercase(password)) {
        score++;
    } else {
        feedback.push_back("Password should contain at least one lowercase letter.");
    }

    if (containsDigit(password)) {
        score++;
    } else {
        feedback.push_back("Password should contain at least one digit.");
    }

    if (containsSpecialCharacter(password)) {
        score++;
    } else {
        feedback.push_back("Password should contain at least one special character.");
    }

    std::string strength;
    if (score <= 2) {
        strength = "Weak";
    } else if (score == 3) {
        strength = "Medium";
    } else {
        strength = "Strong";
    }

    Json::Value result;
    result["strength"] = strength;
    result["feedback"] = Json::Value(Json::arrayValue);

    for (const auto& fb : feedback) {
        result["feedback"].append(fb);
    }

    Json::StreamWriterBuilder writer;
    return Json::writeString(writer, result);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <password>" << std::endl;
        return 1;
    }

    std::string password = argv[1];
    std::string result = analyzePassword(password);

    std::cout << result << std::endl;

    return 0;
}
