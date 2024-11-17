#include <type_traits>
#include <iostream>
#include <vector>
#include <numeric>
#include <gtest/gtest.h>
#include "test/test/array_node.h"
#include "array_node.h"
#include "val_node.h"
#include "func_node.h"
#include "string_node.h"
#include "bin_node.h"
#include "aux_functions.h"
#include "def.h"

TEST(SizeDepthMeasure_test,PushDepth){
    SizeDepthMeasure sz_measure;
    sz_measure.push_depth(10);
    sz_measure.push_depth(20);
    EXPECT_ANY_THROW(sz_measure.push_depth(0));
}
TEST(SizeDepthMeasure_test,GetDimensions){
    SizeDepthMeasure sz_measure;
    sz_measure.push_depth(10);
    sz_measure.push_depth(20);
    EXPECT_EQ(sz_measure.dimensions(),2);
    sz_measure.push_depth(30);
    EXPECT_EQ(sz_measure.dimensions(),3);
}
TEST(SizeDepthMeasure_test,IsIterable){
    SizeDepthMeasure sz_measure;
    EXPECT_FALSE(sz_measure.is_iterable());
    EXPECT_FALSE(sz_measure.is_decrement_iterable());
    sz_measure.push_depth(1);
    EXPECT_FALSE(sz_measure.is_iterable());
    EXPECT_FALSE(sz_measure.is_decrement_iterable());
    sz_measure.push_depth(2);
    sz_measure++;
    EXPECT_FALSE(sz_measure.is_iterable());
    EXPECT_TRUE(sz_measure.is_decrement_iterable());
    sz_measure--;
    EXPECT_TRUE(sz_measure.is_iterable());
    EXPECT_FALSE(sz_measure.is_decrement_iterable());
}
TEST(SizeDepthMeasure_test,CurrentIteratorAtDepth){
    SizeDepthMeasure sz_measure;
    EXPECT_FALSE(sz_measure.is_iterable());
    EXPECT_FALSE(sz_measure.is_decrement_iterable());
    sz_measure.push_depth(10);
    sz_measure.push_depth(10);//like 100
    for(int i =0;i<12;++i)
        ++sz_measure;
    EXPECT_TRUE(sz_measure.is_iterable());
    EXPECT_TRUE(sz_measure.is_decrement_iterable());
    EXPECT_EQ(sz_measure.current_iterator(0),1);
    EXPECT_EQ(sz_measure.current_iterator(1),2);
    for(int i =0;i<12+1;++i)
        --sz_measure;
    EXPECT_EQ(sz_measure.current_iterator(0),9);
    EXPECT_EQ(sz_measure.current_iterator(1),9);
    EXPECT_FALSE(sz_measure.is_iterable());
    EXPECT_TRUE(sz_measure.is_decrement_iterable());
    for(int i =0;i<19;++i)
        --sz_measure;
    EXPECT_EQ(sz_measure.current_iterator(0),8);
    EXPECT_EQ(sz_measure.current_iterator(1),0);
    EXPECT_TRUE(sz_measure.is_iterable());
    EXPECT_TRUE(sz_measure.is_decrement_iterable());
}
TEST(SizeDepthMeasure_test,SequencedIterator){
    SizeDepthMeasure sz_measure;
    sz_measure.push_depth(10);
    sz_measure.push_depth(10);
    sz_measure.push_depth(10);//like 1000
    for(int i =0;i<150;++i)
        ++sz_measure;
    EXPECT_TRUE(sz_measure.is_iterable());
    EXPECT_TRUE(sz_measure.is_decrement_iterable());
    EXPECT_EQ(sz_measure.seq_iterator(0),150);
    EXPECT_EQ(sz_measure.seq_iterator(1),50);
    EXPECT_EQ(sz_measure.seq_iterator(),150);
}
TEST(SizeDepthMeasure_test,ResetIterator){
    SizeDepthMeasure sz_measure;
    sz_measure.push_depth(10);
    sz_measure.push_depth(10);
    sz_measure.push_depth(10);//like 1000
    for(int i =0;i<150;++i)
        ++sz_measure;
    EXPECT_EQ(sz_measure.seq_iterator(0),150);
    EXPECT_EQ(sz_measure.seq_iterator(1),50);
    sz_measure.reset_iterator(1);
    EXPECT_EQ(sz_measure.seq_iterator(0),100);
    sz_measure.reset_all_iterators();
    EXPECT_EQ(sz_measure.seq_iterator(),0);
}

// void reset_iterator();
// size_t current_iterator(size_t depth);
// void operator++(int)
// void operator++()
// void operator--(int);
// void operator--();
// bool is_iterable();
// bool is_decrement_iterable();
// size_t size(size_t depth);
// size_t dimensions();
// size_t seq_iterator(int32_t depth) const;