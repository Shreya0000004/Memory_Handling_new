#include "memoryKrea.h"
#include <iostream>

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


