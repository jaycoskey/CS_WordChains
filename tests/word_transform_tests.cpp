/*
 * Test functions that check for word deletions, mutations, and swaps.
 */

#include "word_transform_tests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(WordTransformTest);

WordTransformTest::WordTransformTest() { }
WordTransformTest::~WordTransformTest() { }
void WordTransformTest::setUp() { }
void WordTransformTest::tearDown() { }

void WordTransformTest::is_deletion_detection_valid() {
    CPPUNIT_ASSERT(Util::isDeletionOf("hello", "ello"));
    CPPUNIT_ASSERT(Util::isDeletionOf("hello", "helo"));
    CPPUNIT_ASSERT(Util::isDeletionOf("hello", "hell"));
    CPPUNIT_ASSERT(Util::isDeletionOf("at", "a"));

    CPPUNIT_ASSERT(!Util::isDeletionOf("same", "same"));
    CPPUNIT_ASSERT(!Util::isDeletionOf("a", "the"));
    CPPUNIT_ASSERT(!Util::isDeletionOf("fame", "am"));
}

void WordTransformTest::is_mutation_detection_valid() {
    CPPUNIT_ASSERT(Util::isMutationOf("hello", "jello"));
    CPPUNIT_ASSERT(Util::isMutationOf("amble", "ample"));
    CPPUNIT_ASSERT(Util::isMutationOf("hone", "honk"));
    CPPUNIT_ASSERT(Util::isMutationOf("a", "i"));

    CPPUNIT_ASSERT(!Util::isMutationOf("same", "same"));
    CPPUNIT_ASSERT(!Util::isMutationOf("a", "the"));
    CPPUNIT_ASSERT(!Util::isMutationOf("dine", "time"));
    CPPUNIT_ASSERT(!Util::isMutationOf("dine", "tint"));
}

void WordTransformTest::is_swap_detection_valid() {
    CPPUNIT_ASSERT(Util::isSwapOf("abba", "baba"));
    CPPUNIT_ASSERT(Util::isSwapOf("abba", "abab"));
    CPPUNIT_ASSERT(Util::isSwapOf("no", "on"));

    CPPUNIT_ASSERT(!Util::isSwapOf("same", "same"));
    CPPUNIT_ASSERT(!Util::isSwapOf("a", "the"));
    CPPUNIT_ASSERT(!Util::isSwapOf("ned", "eno"));
    CPPUNIT_ASSERT(!Util::isSwapOf("nono", "onon"));
}
