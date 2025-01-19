// #pragma once
// #include "shared_stream.h"
// #include <cstdio>
// #include <iostream>

// class SharedFstream: public SharedStream{
// public:
//     SharedFstream();
//     SharedFstream(const SharedFstream& other);
//     SharedFstream(const std::string& filename, std::ios_base::openmode om = std::ios_base::out | std::ios_base::in);
//     SharedFstream(const char* filename, std::ios_base::openmode om = std::ios_base::out | std::ios_base::in);
//     ~SharedFstream();
//     bool is_open() const;
//     bool open(const char* filename, std::ios_base::openmode om = std::ios_base::in);
//     bool open(const std::string& filename, std::ios_base::openmode = std::ios_base::in);
// };