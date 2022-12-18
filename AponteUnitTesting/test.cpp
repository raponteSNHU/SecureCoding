// Uncomment the next line to use precompiled headers
#include "pch.h"
// uncomment the next line if you do not use precompiled headers
//#include "gtest/gtest.h"
//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
        //  initialize random seed
        srand(time(nullptr));
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    { // create a new collection to be used in the test
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        collection->clear();
        // free the pointer
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99 count times to the collection
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called
TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    // is the collection created
    ASSERT_TRUE(collection);

    // if empty, the size must be 0
    ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer
TEST_F(CollectionTest, AlwaysFail)
{
    FAIL();
}
*/

// TODO: Create a test to verify adding a single value to an empty collection
TEST_F(CollectionTest, CanAddToEmptyVector)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());
    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);

    add_entries(1);

    // is the collection still empty?
    EXPECT_FALSE(collection->empty());
    // if not empty, what must the size be?
    ASSERT_EQ(collection->size(), 1);
}

// TODO: Create a test to verify adding five values to collection
TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());
    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);

    add_entries(5);

    // is the collection still empty?
    EXPECT_FALSE(collection->empty());
    // if not empty, what must the size be?
    ASSERT_EQ(collection->size(), 5);
}

// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, IsMaxSizeGreaterThanOrEqualToEntry) 
{
    //Test for 0
    // is the collection empty?
    ASSERT_TRUE(collection->empty());
    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
    // if empty, the max size must equal the collection size
    ASSERT_GE(collection->max_size(), collection->size());

    //Test for 1
    add_entries(1);
    // is the collection still empty?
    EXPECT_FALSE(collection->empty());
    // if not empty, what must the size be?
    EXPECT_EQ(collection->size(), 1);
    // the max size must be greater than or equal to 1
    ASSERT_GE(collection->max_size(), collection->size());

    //Test for 5
    add_entries(4);
    // is the collection still empty?
    EXPECT_FALSE(collection->empty());
    // if not empty, what must the size be?
    EXPECT_EQ(collection->size(), 5);
    // the max size must be greater than or equal to 5
    ASSERT_GE(collection->max_size(), collection->size());

    //Test for 10
    add_entries(5);
    // is the collection still empty?
    EXPECT_FALSE(collection->empty());
    // if not empty, what must the size be?
    EXPECT_EQ(collection->size(), 10);
    // the max size must be greater than or equal to 10
    ASSERT_GE(collection->max_size(), collection->size());
}

// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, IsCapacityGreaterThanOrEqualToEntry)
{
    //Test for 0
    // is the collection empty?
    ASSERT_TRUE(collection->empty());
    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
    // if empty, the capacity must equal the collection size
    ASSERT_GE(collection->capacity(), collection->size());

    //Test for 1
    add_entries(1);
    // is the collection still empty?
    EXPECT_FALSE(collection->empty());
    // if not empty, what must the size be?
    EXPECT_EQ(collection->size(), 1);
    // the capacity must be greater than or equal to 1
    ASSERT_GE(collection->capacity(), collection->size());

    //Test for 5
    add_entries(4);
    // is the collection still empty?
    EXPECT_FALSE(collection->empty());
    // if not empty, what must the size be?
    EXPECT_EQ(collection->size(), 5);
    // the capacity must be greater than or equal to 5
    ASSERT_GE(collection->capacity(), collection->size());

    //Test for 10
    add_entries(5);
    // is the collection still empty?
    EXPECT_FALSE(collection->empty());
    // if not empty, what must the size be?
    EXPECT_EQ(collection->size(), 10);
    // the capacity must be greater than or equal to 10
    ASSERT_GE(collection->capacity(), collection->size());
}

// TODO: Create a test to verify resizing increases the collection
TEST_F(CollectionTest, DoesResizeIncreaseCollection)
{
    //Resize from 0 to 10
    // is the collection empty?
    ASSERT_TRUE(collection->empty());
    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);

    //Resize to 10
    collection->resize(10);
    // is the collection still empty?
    EXPECT_FALSE(collection->empty());
    // if not empty, what must the size be?
    ASSERT_EQ(collection->size(), 10);
}

// TODO: Create a test to verify resizing decreases the collection
TEST_F(CollectionTest, DoesResizeDecreaseCollection)
{
    //Resize from 20 to 5
    //Add 20 entries
    add_entries(20);
    // is the collection still empty?
    EXPECT_FALSE(collection->empty());
    // if not empty, what must the size be?
    ASSERT_EQ(collection->size(), 20);

    //Resize to 5
    collection->resize(5);
    // is the collection empty?
    EXPECT_FALSE(collection->empty());
    // if not empty, what must the size be?
    ASSERT_EQ(collection->size(), 5);
}

// TODO: Create a test to verify resizing decreases the collection to zero
TEST_F(CollectionTest, DoesResizeDecreaseCollectionToZero)
{
    //Resize from 20 to 0
    //Add 20 entries
    add_entries(20);
    // is the collection still empty?
    EXPECT_FALSE(collection->empty());
    // if not empty, what must the size be?
    ASSERT_EQ(collection->size(), 20);

    //Resize to 0
    collection->resize(0);
    // is the collection empty?
    EXPECT_TRUE(collection->empty());
    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

// TODO: Create a test to verify clear erases the collection
TEST_F(CollectionTest, DoesClearEraseCollection)
{
    // Add 20 entries
    add_entries(20);
    // is the collection still empty?
    EXPECT_FALSE(collection->empty());
    // if not empty, what must the size be?
    ASSERT_EQ(collection->size(), 20);

    // Clear collection
    collection->clear();
    // is the collection empty?
    EXPECT_TRUE(collection->empty());
    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

// TODO: Create a test to verify erase(begin,end) erases the collection
TEST_F(CollectionTest, DoesEraseEraseCollection)
{
    // Add 20 entries
    add_entries(20);
    // is the collection still empty?
    EXPECT_FALSE(collection->empty());
    // if not empty, what must the size be?
    ASSERT_EQ(collection->size(), 20);

    // Clear collection with erase
    collection->erase(collection->begin(), collection->end());
    // is the collection empty?
    EXPECT_TRUE(collection->empty());
    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

// TODO: Create a test to verify reserve increases the capacity but not the size of the collection
TEST_F(CollectionTest, ReserveIncreasesCapacityButNotSize)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());
    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
    // the capacity must be greater than or equal to size
    ASSERT_GE(collection->capacity(), collection->size());

    // Add 20 entries
    add_entries(20);
    // is the collection still empty?
    EXPECT_FALSE(collection->empty());
    // if not empty, what must the size be?
    ASSERT_EQ(collection->size(), 20);

    // Specify capacity by calling reserve
    collection->reserve(40);
    // is the collection empty?
    EXPECT_FALSE(collection->empty());
    // if not empty, the size must be 20
    EXPECT_EQ(collection->size(), 20);
    // the capacity should be 40
    ASSERT_EQ(collection->capacity(), 40);

    // Specify a lower capacity than size with reserve
    collection->reserve(10);
    // is the collection empty?
    EXPECT_FALSE(collection->empty());
    // if not empty, the size must be 20
    EXPECT_EQ(collection->size(), 20);
    // the capacity should not be 10 because the size is greater
    EXPECT_NE(collection->capacity(), 10);
    // however, the capacity should still be greater than or equal to the size which is 20
    ASSERT_GE(collection->capacity(), collection->size());
}

// TODO: Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
// NOTE: This is a negative test
TEST_F(CollectionTest, OutOfRangeExceptionThrownWithAtOutOfBounds)
{
    // Add 20 entries
    add_entries(20);
    // is the collection still empty?
    EXPECT_FALSE(collection->empty());
    // if not empty, what must the size be?
    ASSERT_EQ(collection->size(), 20);

    // Check if out of range exception is thrown
    // Beyond Upper Bound
    EXPECT_THROW(collection->at(20), std::out_of_range);
    // Beyond Lower Bound
    ASSERT_THROW(collection->at(-1), std::out_of_range);
}

// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative
// Positive Test: Determine if size of collection shrinks with pop_back
TEST_F(CollectionTest, DoesPopBackDecreaseCollection)
{
    //Add 20 entries
    add_entries(20);
    // is the collection still empty?
    EXPECT_FALSE(collection->empty());
    // if not empty, what must the size be?
    ASSERT_EQ(collection->size(), 20);

    // Decrease collection size by 1 using pop_back
    collection->pop_back();
    // is the collection empty?
    EXPECT_FALSE(collection->empty());
    // if not empty, the size must be 19
    ASSERT_EQ(collection->size(), 19);
}

// Negative Test: Out of range exception is thrown after a pop back
TEST_F(CollectionTest, OutOfRangeThrownAfterPopBack)
{
    // Push back a specific value
    collection->push_back(10);
    // first element must equal 10
    EXPECT_EQ(collection->at(0), 10);
    // Decrease collection size by 1 using pop_back
    collection->pop_back();
    // the size of the collection must be 0
    ASSERT_EQ(collection->size(), 0);
    // Out_of_range is thrown after a pop_back if testing for element that was deleted
    EXPECT_THROW(collection->at(0), std::out_of_range);
}