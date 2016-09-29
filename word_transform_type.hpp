/* 
 * Type of transform relating two words
 */

#ifndef WORD_TRANSFORM_TYPE_HPP
#define WORD_TRANSFORM_TYPE_HPP

namespace word_chains {

enum WordTransformType {
    WTT_Deletion, WTT_Insertion, WTT_Mutation, WTT_Swap
};

}

#endif /* WORD_TRANSFORM_TYPE_HPP */
