#include "pch.h"
#include "../SailBotApplication/SailbotMethods.cpp"
//BoundTo180 tests
//first test from pdf
TEST(BoundTo180Test, PDFTest1) {
  EXPECT_EQ(BoundTo180(360), 0);
}
//
//second test from pdf
TEST(BoundTo180Test, PDFTest2) {
	EXPECT_EQ(BoundTo180(270), -90);
}

//third test from pdf
TEST(BoundTo180Test,PDFTest3) {
	EXPECT_EQ(BoundTo180(-450), -90);
}

//extra tests
TEST(BoundTo180Test, ExtraRandomTest1) {
	EXPECT_EQ(BoundTo180(-630), 90);
}

TEST( BoundTo180Test, ExtraRandomTest2) {
	EXPECT_EQ(BoundTo180(-700), 20);
}

TEST(BoundTo180Test, ExtraRandomTest3) {
	EXPECT_EQ(BoundTo180(700), -20);
}

TEST( BoundTo180Test, ExtraRandomTest4) {
	EXPECT_EQ(BoundTo180(1234), 154);
}

TEST(BoundTo180Test, ExtraRandomTest5) {
	EXPECT_EQ(BoundTo180(-1234), -154);
}

TEST( BoundTo180Test, ExtraCornerTest1) {
	EXPECT_EQ(BoundTo180(-180), -180);
}

TEST( BoundTo180Test, ExtraCornerTest2) {
	EXPECT_EQ(BoundTo180(180), -180);
}

TEST(BoundTo180Test, ExtraCornerTest3) {
	EXPECT_EQ(BoundTo180(-540), -180);
}

TEST(BoundTo180Test, ExtraCornerTest4) {
	EXPECT_EQ(BoundTo180(540), -180);
}
TEST(BoundTo180Test, ExtraCornerTest5) {
	EXPECT_EQ(BoundTo180(-360), 0);
}
//IsAngleBetween tests
//first test from PDF
TEST( IsAngleBetweenTest, PDFTest1) {
	EXPECT_TRUE(IsAngleBetween(-90,180,110));
}

//second test from PDF
TEST( IsAngleBetweenTest, PDFTest2) {
	EXPECT_FALSE(IsAngleBetween(-90, 180, 80));
}

//extra tests
TEST(IsAngleBetweenTest, ExtraRandomTest1) {
	EXPECT_TRUE(IsAngleBetween(-90, -405, 0));
}

TEST(IsAngleBetweenTest, ExtraRandomTest2) {
	EXPECT_TRUE(IsAngleBetween(450, -59, -780));
}

TEST(IsAngleBetweenTest, ExtraRandomTest3) {
	EXPECT_FALSE(IsAngleBetween(450, -61, -780));
}

TEST(IsAngleBetweenTest, ExtraRandomTest4) {
	EXPECT_TRUE(IsAngleBetween(450, 89, -780));
}
TEST(IsAngleBetweenTest, ExtraRandomTest5) {
	EXPECT_FALSE(IsAngleBetween(450, 90, -780));
}

TEST(IsAngleBetweenTest, ExtraCornerTest1) {
	EXPECT_TRUE(IsAngleBetween(-90, 0, 90));
}


TEST(IsAngleBetweenTest, ExtraCornerTest2) {
	EXPECT_FALSE(IsAngleBetween(-90, -90, 90));
}

