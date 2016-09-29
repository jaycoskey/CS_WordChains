/*
 * Test functions that check for word deletions, mutations, and swaps.
 */

#ifndef WORDTRANSFORMTEST_H
#define WORDTRANSFORMTEST_H

#include <cppunit/extensions/HelperMacros.h>

#include "util.hpp"

using word_chains::Util;

class WordTransformTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(WordTransformTest);

    CPPUNIT_TEST(is_deletion_detection_valid);
    CPPUNIT_TEST(is_mutation_detection_valid);
    CPPUNIT_TEST(is_swap_detection_valid);

    CPPUNIT_TEST_SUITE_END();

public:
    WordTransformTest();
    virtual ~WordTransformTest();
    void setUp();
    void tearDown();

private:
    // void testMethod();
    void is_deletion_detection_valid();
    void is_mutation_detection_valid();
    void is_swap_detection_valid();
    // void testFailedMethod();
};

#endif /* WORDTRANSFORMTEST_H */

