#ifndef MEMORY_H
#define MEMORY_H

#include <string>

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
    Student(const std::string& n, int a,
            double lrMarks, double nrMarks, double vaMarks, double essayMarks,
            double entrance, double tenth, double twelfth, bool extraCurriculars,
            const std::string& ec, int es, const std::string& tgs, const std::string& tgs12, bool rec);

    std::string getName() const;
    int getAge() const;
    double getLogicalReasoningMarks() const;
    double getNumericalReasoningMarks() const;
    double getVerbalAnalysisMarks() const;
    double getEssayWritingMarks() const;
    double getEntranceScore() const;
    double getTenthGradeMarks() const;
    double getTwelfthGradeMarks() const;
    bool hasExtraCurricularActivities() const;
    std::string getExtraCurricular() const;
    int getEssayScore() const;
    std::string getTenthGradeSchool() const;
    std::string getTwelfthGradeSchool() const;
    bool hasPositiveTeacherRecommendation() const;

    bool isEligible() const;
    bool isAdmitted() const;

    ~Student();
};

class StudentList {
private:
    class Node {
    public:
        Student* data;
        Node* next;
        Node(Student* student) : data(student), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    StudentList();
    void addStudent(Student* student);
    void displayStudents() const;
    void deleteStudents();
    ~StudentList();

private:
    void displayStudent(const Student& student) const;
};

bool isNumeric(const std::string& str);
bool getValidBoolInput(const std::string& prompt);
int getValidIntInput(const std::string& prompt, int min, int max);
double getValidDoubleInput(const std::string& prompt, double min, double max);
std::string getValidStringInput(const std::string& prompt);

#endif

