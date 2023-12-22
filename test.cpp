#include <gtest/gtest.h>
#include "Include/funkcijos.h"  // Include your Studentai class header file
#include <cmath>
vector <Studentai> stud;
vector<Studentai> kieti;
vector<Studentai> vargsai;
Studentai duomenys;
int studentu_kiekis = 0;
double roundToTwoDecimalPlaces(double value);

class StudentaiTest : public ::testing::Test {
protected:
    Studentai student;

    void SetUp() override {
        // Optional: Code here will be called immediately after the constructor (right before each test).
    }

    void TearDown() override {
        // Optional: Code here will be called immediately after each test (right before the destructor).
    }
};

double roundToTwoDecimalPlaces(double value) {
    return std::round(value * 100.0) / 100.0;
}

TEST_F(StudentaiTest, TestVidurkisWithNoHomework) {
student.setEgzaminas(8);
student.Vidurkis();
EXPECT_DOUBLE_EQ(roundToTwoDecimalPlaces(student.getVid()), 4.8);  // 0.6 * 8
}

TEST_F(StudentaiTest, TestVidurkisWithHomework) {
student.setEgzaminas(8);
// Assuming setNd() method to set homework scores
student.addNd(4);  // Example homework scores
student.addNd( 6);  // Example homework scores
student.addNd( 8);  // Example homework scores
student.Vidurkis();
EXPECT_DOUBLE_EQ(roundToTwoDecimalPlaces(student.getVid()), 7.20);  // (4+6+8)/3 * 0.4 + 0.6 * 8
}

TEST_F(StudentaiTest, TestMedianaOddNumber) {
student.setEgzaminas(8);
student.addNd(3);
student.addNd( 7);
student.addNd(5);
student.Mediana();
EXPECT_DOUBLE_EQ(roundToTwoDecimalPlaces(student.getMed()), 6.8);  // (5 * 0.4 + 0.6 * 8)
}

TEST_F(StudentaiTest, TestMedianaEvenNumber) {
student.setEgzaminas(8);
student.addNd(3);
student.addNd( 7);
student.addNd( 5);
student.addNd( 9);
student.Mediana();
EXPECT_DOUBLE_EQ(roundToTwoDecimalPlaces(student.getMed()), 7.2);  // ((5+7)/2 * 0.4 + 0.6 * 8)
}

TEST_F(StudentaiTest, TestMedianaWithNoHomework) {
student.setEgzaminas(8);
student.Mediana();
EXPECT_DOUBLE_EQ(roundToTwoDecimalPlaces(student.getMed()), 4.8);  // 0.6 * 8
}

// Additional tests can be added as necessary