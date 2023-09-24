#include "memoryKrea.h"
#include <iostream>
#include <stdexcept>
#include <limits>

// Implement Student class constructor
Student::Student(const std::string& n, int a,
    double lrMarks, double nrMarks, double vaMarks, double essayMarks,
    double entrance, double tenth, double twelfth, bool extraCurriculars,
    const std::string& ec, int es, const std::string& tgs, const std::string& tgs12, bool rec)
    : name(n), age(a), logicalReasoningMarks(lrMarks),
    numericalReasoningMarks(nrMarks), verbalAnalysisMarks(vaMarks),
    essayWritingMarks(essayMarks), entranceScore(entrance), tenthGradeMarks(tenth),
    twelfthGradeMarks(twelfth), hasExtraCurricular(extraCurriculars),
    extraCurricular(ec), essayScore(es), tenthGradeSchool(tgs), twelfthGradeSchool(tgs12),
    teacherRecommendation(rec) {}

// Implement getter functions for Student class
std::string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

double Student::getLogicalReasoningMarks() const {
    return logicalReasoningMarks;
}

double Student::getNumericalReasoningMarks() const {
    return numericalReasoningMarks;
}

double Student::getVerbalAnalysisMarks() const {
    return verbalAnalysisMarks;
}

double Student::getEssayWritingMarks() const {
    return essayWritingMarks;
}

double Student::getEntranceScore() const {
    return entranceScore;
}

double Student::getTenthGradeMarks() const {
    return tenthGradeMarks;
}

double Student::getTwelfthGradeMarks() const {
    return twelfthGradeMarks;
}

bool Student::hasExtraCurricularActivities() const {
    return hasExtraCurricular;
}

std::string Student::getExtraCurricular() const {
    return extraCurricular;
}

int Student::getEssayScore() const {
    return essayScore;
}

std::string Student::getTenthGradeSchool() const {
    return tenthGradeSchool;
}

std::string Student::getTwelfthGradeSchool() const {
    return twelfthGradeSchool;
}

bool Student::hasPositiveTeacherRecommendation() const {
    return teacherRecommendation;
}

// Implement isEligible and isAdmitted functions for Student class
bool Student::isEligible() const {
    // Example eligibility criteria:
    // The student must have scores of at least 60 in logical reasoning, numerical reasoning, and verbal analysis.
    // The student must have an essay score of at least 50.
    return (logicalReasoningMarks >= 60) &&
           (numericalReasoningMarks >= 60) &&
           (verbalAnalysisMarks >= 60) &&
           (essayScore >= 50);
}

bool Student::isAdmitted() const {
    // Example admission criteria:
    // The student must be eligible (as per the eligibility criteria above).
    // The student's entrance score must be at least 70.
    // The student must have positive teacher recommendations.
    return (isEligible()) &&
           (entranceScore >= 70) &&
           (teacherRecommendation);
}

// Implement destructor for Student class
Student::~Student() {
    // Destructor should release any dynamically allocated resources.
    // No dynamic memory allocation in the class, so nothing to release.
}

// Implement isNumeric function
bool isNumeric(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

// Implement getValidBoolInput function
bool getValidBoolInput(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::cin >> input;
        if (input == "true" || input == "false") {
            return input == "true";
        } else {
            std::cout << "Invalid input. Enter 'true' or 'false'." << std::endl;
        }
    }
}

// Implement getValidIntInput function
int getValidIntInput(const std::string& prompt, int min, int max) {
    while (true) {
        std::cout << prompt;
        int value;
        std::cin >> value;

        if (std::cin.fail()) {
            // Handle invalid input (non-integer)
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer." << std::endl;
        } else if (value >= min && value <= max) {
            return value;
        } else {
            std::cout << "Invalid input. Enter an integer between " << min << " and " << max << "." << std::endl;
        }
    }
}

// Implement getValidDoubleInput function
double getValidDoubleInput(const std::string& prompt, double min, double max) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::cin >> input;

        if (isNumeric(input)) {
            double value = std::stod(input);
            if (value >= min && value <= max) {
                return value;
            }
        }

        std::cout << "Invalid input. Enter a number between " << min << " and " << max << "." << std::endl;
    }
}

// Implement getValidStringInput function
std::string getValidStringInput(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::cin.ignore();
        std::getline(std::cin, input);
        if (!input.empty()) {
            return input;
        } else {
            std::cout << "Invalid input. Please enter a non-empty string." << std::endl;
        }
    }
}

// Implement StudentList constructor
StudentList::StudentList() : head(nullptr), tail(nullptr) {}

// Implement addStudent function
void StudentList::addStudent(Student* student) {
    Node* newNode = new Node(student);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Implement displayStudents function
void StudentList::displayStudents() const {
    Node* current = head;
    while (current != nullptr) {
        displayStudent(*current->data);
        current = current->next;
    }
}

// Implement deleteStudents function
void StudentList::deleteStudents() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp->data;
        delete temp;
    }
    head = tail = nullptr;
}

// Implement destructor for StudentList class
StudentList::~StudentList() {
    deleteStudents();
}

// Implement displayStudent function
void StudentList::displayStudent(const Student& student) const {
    std::cout << "\nAdmission Status for " << student.getName() << ":\n";
    std::cout << "Age: " << student.getAge() << " years" << std::endl;
    // ... (display other student information and admission status)
}

