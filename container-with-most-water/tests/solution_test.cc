#include <gtest/gtest.h>
#include "../src/solution.h"

// ResultTest

// Check if result object created with default constructor has correct properties values
TEST(Result_Test, Default_Constructor_Sets_Error_To_True_And_Other_To_Zero) {
    Result res;
    EXPECT_TRUE(res.error);
    EXPECT_EQ(res.area, 0);
    EXPECT_EQ(res.l_side, 0);
    EXPECT_EQ(res.r_side, 0);
    EXPECT_EQ(res.width, 0);
}

// Check if result object created with value initialization {} has correct properties values
TEST(Result_Test, Value_Initialization_Sets_Error_To_True_And_Other_To_Zero) {
    Result res{};
    EXPECT_TRUE(res.error);
    EXPECT_EQ(res.area, 0);
    EXPECT_EQ(res.l_side, 0);
    EXPECT_EQ(res.r_side, 0);
    EXPECT_EQ(res.width, 0);
}

// SolutionTest

// Check if result is correct. [1,8,6,2,5,4,8,3,7] should give 49 and error flag set to false
TEST(Solution_Test, Valid_Input_Returns_Correct_Result_And_No_Error_1) {
    Solution solution;
    Result res = solution.max_area({1, 8, 6, 2, 5, 4, 8, 3, 7});
    EXPECT_FALSE(res.error);
    EXPECT_EQ(res.area, 49);
    EXPECT_EQ(res.l_side, 8);
    EXPECT_EQ(res.r_side, 7);
    EXPECT_EQ(res.width, 7);
}

// Check if result is correct. [1,1] should give 1 and error flag set to false
TEST(Solution_Test, Valid_Input_Returns_Correct_Result_And_No_Error_2) {
    Solution solution;
    Result res = solution.max_area({1, 1});
    EXPECT_FALSE(res.error);
    EXPECT_EQ(res.area, 1);
    EXPECT_EQ(res.l_side, 1);
    EXPECT_EQ(res.r_side, 1);
    EXPECT_EQ(res.width, 1);
}

// Check if result is correct. [4,3,2,1,4] should give 1 and error flag set to false
TEST(Solution_Test, Valid_Input_Returns_Correct_Result_And_No_Error_3) {
    Solution solution;
    Result res = solution.max_area({4, 3, 2, 1, 4});
    EXPECT_FALSE(res.error);
    EXPECT_EQ(res.area, 16);
    EXPECT_EQ(res.l_side, 4);
    EXPECT_EQ(res.r_side, 4);
    EXPECT_EQ(res.width, 4);
}

// Check if result is correct. [1,2,1] should give 2 and error flag set to false
TEST(Solution_Test, Valid_Input_Returns_Correct_Result_And_No_Error_4) {
    Solution solution;
    Result res = solution.max_area({1,2,1});
    EXPECT_FALSE(res.error);
    EXPECT_EQ(res.area, 2);
    EXPECT_EQ(res.l_side, 1);
    EXPECT_EQ(res.r_side, 1);
    EXPECT_EQ(res.width, 2);
}

// Check if result is correct. [3,4,1,2,2,4,1,3,2] should give 21 and error flag set to false
TEST(Solution_Test, Valid_Input_Returns_Correct_Result_And_No_Error_5) {
    Solution solution;
    Result res = solution.max_area({3, 4, 1, 2, 2, 4, 1, 3, 2});
    EXPECT_FALSE(res.error);
    EXPECT_EQ(res.area, 21);
    EXPECT_EQ(res.l_side, 3);
    EXPECT_EQ(res.r_side, 3);
    EXPECT_EQ(res.width, 7);
}

// Check if result is correct. [1,100,100,1] should give 21 and error flag set to false
TEST(Solution_Test, Valid_Input_Returns_Correct_Result_And_No_Error_6) {
    Solution solution;
    Result res = solution.max_area({1,100,100,1});
    EXPECT_FALSE(res.error);
    EXPECT_EQ(res.area, 100);
    EXPECT_EQ(res.l_side, 100);
    EXPECT_EQ(res.r_side, 100);
    EXPECT_EQ(res.width, 1);
}

// Check if result is correct. [1,100,100,1] should give 21 and error flag set to false
TEST(Solution_Test, Valid_Input_Returns_Correct_Result_And_No_Error_7) {
    Solution solution;
    Result res = solution.max_area({1,100,100,1});
    EXPECT_FALSE(res.error);
    EXPECT_EQ(res.area, 100);
    EXPECT_EQ(res.l_side, 100);
    EXPECT_EQ(res.r_side, 100);
    EXPECT_EQ(res.width, 1);
}

// Check if result is correct. [5,0,5] should give 21 and error flag set to false
TEST(Solution_Test, Valid_Input_Returns_Correct_Result_And_No_Error_8) {
    Solution solution;
    Result res = solution.max_area({5,0,5});
    EXPECT_FALSE(res.error);
    EXPECT_EQ(res.area, 10);
    EXPECT_EQ(res.l_side, 5);
    EXPECT_EQ(res.r_side, 5);
    EXPECT_EQ(res.width, 2);
}

// Check if result is correct. [1] should give result with error flag set to true
TEST(SolutionTest, Invalid_Input_Returns_Error_1) {
    Solution solver;
    Result res = solver.max_area({1});
    EXPECT_TRUE(res.error);
}

// Check if result is correct. [] should give result with error flag set to true
TEST(SolutionTest, Invalid_Input_Returns_Error_2) {
    Solution solver;
    Result res = solver.max_area({});
    EXPECT_TRUE(res.error);
}
