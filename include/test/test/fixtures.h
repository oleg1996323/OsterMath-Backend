#pragma once
#include "data.h"
#include "var_node.h"

class DataBaseDefault:public testing::Test{
    protected:
	void SetUp()
	{
        db_ = std::make_shared<BaseData>("Any");
        root_ = db_->add_variable("root")->node();
    }
	void TearDown()
	{	}

    std::shared_ptr<BaseData> db_;
    VariableNode* root_;
};