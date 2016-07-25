// File: catch_test_wrapper.hpp

// The catch library triggers a Visual C++ compiler warning.
// Warning: sound-structures-cpp\src\catch.hpp(8042): warning C28251: 
// Inconsistent annotation for 'OutputDebugStringA': this instance has no 
// annotations.

// The purpose of this file is to include catch.hpp without the warning.
// Other files will include this file instead of including catch.hpp 
// directly.

#pragma warning( push )
#pragma warning( disable : 28251)

#include "catch.hpp"

#pragma warning( pop )
