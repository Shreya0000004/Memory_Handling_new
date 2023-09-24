/*
Concepts from memory allocation added :
 
1. StudentList Class:
We introduced a StudentList class to manage a linked list of Student objects.
This class handles adding students to the list, displaying their information, and cleaning up memory when the program exits.
2. Dynamic Memory Allocation:
Instead of creating Student objects directly, we create them dynamically on the heap using the new operator. Example: Student* student = new Student(...)
3. Pointers:
We use pointers (Student*) to reference dynamically allocated Student objects and to traverse the linked list.
4. Linked List:
We use a linked list data structure to store and manage multiple student objects (Node* for nodes and head and tail pointers).
5. Adding Students to the List:
Inside the input loop, we create a new Student object and add it to the StudentList using the addStudent method.
6. Displaying Students:
The StudentList class has a displayStudents method that iterates through the linked list and displays the information of each student.
7. Cleaning Up Memory:
We've added a deleteStudents method in the StudentList class to release the memory allocated for Student objects when the program exits. This helps prevent memory leaks.
8. Input Loop:
We use a loop to continuously accept input for multiple students until the user enters "exit" as the student's name.
Overall, these additions and changes enhance the code by allowing you to manage multiple student records efficiently using dynamic memory allocation and a linked list data structure. It also ensures proper memory cleanup when the program finishes execution.
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>

class Student {
private:
    std::string name;
    int age;
    double logicalReasoningMarks;
    double numericalReasoningMarks;
    double verbalAnalysisMarks;
    double essayWritingMarks;
    double entranceScore;
    double tenthGradeMarks;
    double twelfthGradeMarks;
    bool hasExtraCurricular;
    std::string extraCurricular;
    int essayScore;
    std::string tenthGradeSchool;
    std::string twelfthGradeSchool;
    bool teacherRecommendation;

public:
    // Constructor
    Student(const std::string& n, int a,
        double lrMarks, double nrMarks, double vaMarks, double essayMarks,
        double entrance, double tenth, double twelfth, bool extraCurriculars,
        const std::string& ec, int es, const std::string& tgs, const std::string& tgs12, bool rec)
        : name(n), age(a), logicalReasoningMarks(lrMarks),
        numericalReasoningMarks(nrMarks), verbalAnalysisMarks(vaMarks),
        essayWritingMarks(essayMarks), entranceScore(entrance), tenthGradeMarks(tenth),
        twelfthGradeMarks(twelfth), hasExtraCurricular(extraCurriculars),
        extraCurricular(ec), essayScore(es), tenthGradeSchool(tgs), twelfthGradeSchool(tgs12),
        teacherRecommendation(rec) {}

    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    double getLogicalReasoningMarks() const {
        return logicalReasoningMarks;
    }

    double getNumericalReasoningMarks() const {
        return numericalReasoningMarks;
    }

    double getVerbalAnalysisMarks() const {
        return verbalAnalysisMarks;
    }

    double getEssayWritingMarks() const {
        return essayWritingMarks;
    }

    double getEntranceScore() const {
        return entranceScore;
    }

    double getTenthGradeMarks() const {
        return tenthGradeMarks;
    }

    double getTwelfthGradeMarks() const {
        return twelfthGradeMarks;
    }

    bool hasExtraCurricularActivities() const {
        return hasExtraCurricular;
    }

    std::string getExtraCurricular() const {
        return extraCurricular;
    }

    int getEssayScore() const {
        return essayScore;
    }

    std::string getTenthGradeSchool() const {
        return tenthGradeSchool;
    }

    std::string getTwelfthGradeSchool() const {
        return twelfthGradeSchool;
    }

    bool hasPositiveTeacherRecommendation() const {
        return teacherRecommendation;
    }

    // Function to check if the student is eligible
    bool isEligible() const {
        // Example eligibility criteria:
        // The student must have scores of at least 60 in logical reasoning, numerical reasoning, and verbal analysis.
        // The student must have an essay score of at least 50.
        return (logicalReasoningMarks >= 60) &&
               (numericalReasoningMarks >= 60) &&
               (verbalAnalysisMarks >= 60) &&
               (essayScore >= 50);
    }

    // Function to check if the student is admitted
    bool isAdmitted() const {
        // Example admission criteria:
        // The student must be eligible (as per the eligibility criteria above).
        // The student's entrance score must be at least 70.
        // The student must have positive teacher recommendations.
        return (isEligible()) &&
               (entranceScore >= 70) &&
               (teacherRecommendation);
    }
};

// Function to check if a string is numeric
bool isNumeric(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

// Function to get a valid boolean input
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

// Function to get a valid integer input within a range
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

// Function to get a valid double input within a range
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

// Function to get a valid string input
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

class Node {
public:
    Student* data;
    Node* next;

    Node(Student* student) : data(student), next(nullptr) {}
};

class StudentList {
private:
    Node* head;
    Node* tail;

public:
    StudentList() : head(nullptr), tail(nullptr) {}

    void addStudent(Student* student) {
        Node* newNode = new Node(student);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void displayStudents() const {
        Node* current = head;
        while (current != nullptr) {
            displayStudent(*current->data);
            current = current->next;
        }
    }

    void deleteStudents() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp->data;
            delete temp;
        }
        head = tail = nullptr;
    }

    ~StudentList() {
        deleteStudents();
    }

    void displayStudent(const Student& student) const {
        std::cout << "\nAdmission Status for " << student.getName() << ":\n";
        std::cout << "Age: " << student.getAge() << " years" << std::endl;
        // ... (display other student information and admission status)
    }
};

int main() {
    StudentList studentList;

    while (true) {
        std::string name;
        int age;
        double logicalReasoningMarks;
        double numericalReasoningMarks;
        double verbalAnalysisMarks;
        double essayWritingMarks;
        double entranceScore;
        double tenthGradeMarks;
        double twelfthGradeMarks;
        bool hasExtraCurricular;
        std::string extraCurricular;
        int essayScore;
        std::string tenthGradeSchool;
        std::string twelfthGradeSchool;
        bool teacherRecommendation;

        // Ask if the user wants to continue entering more students
        char choice;
        std::cout << "Do you want to continue entering more students? (y/n): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the newline character

        if (choice != 'y' && choice != 'Y') {
            break; // Exit the input loop
        }

        std::cout << "Enter student's name: ";
        std::getline(std::cin, name);
        if (name == "exit") {
            break; // Exit input loop
        }

        age = getValidIntInput("Enter student's age: ", 1, 120);
        logicalReasoningMarks = getValidDoubleInput("Enter student's logical reasoning marks (0-100): ", 0, 100);
        numericalReasoningMarks = getValidDoubleInput("Enter student's numerical reasoning marks (0-100): ", 0, 100);
        verbalAnalysisMarks = getValidDoubleInput("Enter student's verbal analysis marks (0-100): ", 0, 100);
        essayWritingMarks = getValidDoubleInput("Enter student's essay writing marks (0-100): ", 0, 100);
        entranceScore = getValidDoubleInput("Enter student's entrance score (0-100): ", 0, 100);
        tenthGradeMarks = getValidDoubleInput("Enter student's 10th grade marks (0-100): ", 0, 100);
        twelfthGradeMarks = getValidDoubleInput("Enter student's 12th grade marks (0-100): ", 0, 100);
        hasExtraCurricular = getValidBoolInput("Does the student have any extra-curricular activities? (true/false): ");
        if (hasExtraCurricular) {
            extraCurricular = getValidStringInput("Enter the type of extra-curricular activities (e.g., sports-music): ");
        } else {
            extraCurricular = "";
        }
        essayScore = getValidIntInput("Enter student's essay score (0-100): ", 0, 100);
        tenthGradeSchool = getValidStringInput("Enter the name of the 10th grade school: ");
        twelfthGradeSchool = getValidStringInput("Enter the name of the 12th grade school: ");
        teacherRecommendation = getValidBoolInput("Did the student receive positive teacher recommendations? (true/false): ");

        // Create a Student object
        Student* student = new Student(name, age, logicalReasoningMarks,
            numericalReasoningMarks, verbalAnalysisMarks, essayWritingMarks,
            entranceScore, tenthGradeMarks, twelfthGradeMarks,
            hasExtraCurricular, extraCurricular, essayScore,
            tenthGradeSchool, twelfthGradeSchool, teacherRecommendation);

        // Add the student to the list
        studentList.addStudent(student);

        // Display eligibility and admittance for the student
        std::cout << "\nAdmission Status for " << student->getName() << ":\n";
        std::cout << "Age: " << student->getAge() << " years" << std::endl;

        // Check eligibility
        if (student->isEligible()) {
            std::cout << "Eligibility: Eligible for acceptance into the next stage." << std::endl;
        } else {
            std::cout << "Eligibility: Not eligible for acceptance into the next stage." << std::endl;
        }

        // Check admission status
        if (student->isAdmitted()) {
            std::cout << "Admission Status: Congratulations! You are admitted to the university." << std::endl;
        } else {
            std::cout << "Admission Status: Sorry, you are not admitted to the university." << std::endl;
        }
    }

    // Clean up dynamically allocated memory
    studentList.deleteStudents();

    return 0;
}

