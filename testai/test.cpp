#include <gtest/gtest.h>
#include "../Include/funkcijos.h"  // Include your Studentai class header file

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

TEST_F(StudentaiTest, TestVidurkisWithNoHomework) {
student.setEgzaminas(8);
student.Vidurkis();
EXPECT_DOUBLE_EQ(student.getVid(), 4.8);  // 0.6 * 8
}

TEST_F(StudentaiTest, TestVidurkisWithHomework) {
student.setEgzaminas(8);
// Assuming setNd() method to set homework scores
student.setNd({4, 6, 8});  // Example homework scores
student.Vidurkis();
EXPECT_DOUBLE_EQ(student.getVid(), 5.52);  // (4+6+8)/3 * 0.4 + 0.6 * 8
}

TEST_F(StudentaiTest, TestMedianaOddNumber) {
student.setEgzaminas(8);
student.setNd({3, 7, 5});
student.Mediana();
EXPECT_DOUBLE_EQ(student.getMed(), 5.8);  // (5 * 0.4 + 0.6 * 8)
}

TEST_F(StudentaiTest, TestMedianaEvenNumber) {
student.setEgzaminas(8);
student.setNd({3, 7, 5, 9});
student.Mediana();
EXPECT_DOUBLE_EQ(student.getMed(), 6.2);  // ((5+7)/2 * 0.4 + 0.6 * 8)
}

TEST_F(StudentaiTest, TestMedianaWithNoHomework) {
student.setEgzaminas(8);
student.Mediana();
EXPECT_DOUBLE_EQ(student.getMed(), 4.8);  // 0.6 * 8
}

// Additional tests can be added as necessary