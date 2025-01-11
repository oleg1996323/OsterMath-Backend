#pragma once

namespace kernel::codes{
enum CODES{
    NONE = 0,
    BAD_NODE_CREATION = 1,
    NODE_EXISTS = 2,
    NULLPTR_AT_NODE_ARG = 3,
    OWNER_UNDEFINED = 4,
    OWNER_UNEXPECTED_DEFINITION = 5,
    ANON_NODE_MANAGER_NOT_EMPTY = 6
};
}