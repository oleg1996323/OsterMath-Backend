#include "include/test/test_log.h"
#include <cstdio>
#include <stdio.h>
#include "include/test/shared_fstream.h"

std::filesystem::directory_entry TestLogger::log_dir_ = {std::filesystem::directory_entry(std::filesystem::current_path())};

TestLogger TestLogger::test_logger = TestLogger(std::cout);

TestLogger::TestLogger(std::ostream& stream):stream_(&sh_buf_){
    set_log_stream(stream);
    sh_buf_.add_stream(stdout);
    sh_buf_.add_stream(stderr);
}

TestLogger::TestLogger(const std::filesystem::path& log_dir, const char* test_name):stream_(&sh_buf_){
    set_log_directory(log_dir);
    set_log_stream(test_name);
    sh_buf_ = SharedFstream((log_dir/test_name).string().c_str());
    sh_buf_.add_stream(stdout);
    sh_buf_.add_stream(stderr);
    //TODO: combine FILE* and std::fstream/std::iostream (rdbuf or struct - see more later)
}

TestLogger& TestLogger::operator=(TestLogger&& logger){
    if(this!=&logger){
        std::swap(sh_buf_,logger.sh_buf_);
    }
    return *this;
}

TestLogger& TestLogger::instance(){
    return TestLogger::test_logger;
}

void TestLogger::set_log_stream(const std::string& test_name){
    set_log_stream(test_name.c_str());
}

void TestLogger::set_log_stream(const char* test_name){
    if(decltype(log_dir_)(log_dir_.path().filename()).exists() && decltype(log_dir_)(log_dir_.path().filename()).is_directory()){
        SharedFstream fstream;
        fstream.open(log_dir_.path()/test_name,std::ostream::trunc);
        assert(fstream.is_open());
        std::cout<<"Opened log file: "<<log_dir_.path()/test_name<<std::endl;
        sh_buf_ = std::move(fstream);
    }
    else std::cerr<<"Incorrect directory name: "<<log_dir_.path()<<std::endl;
}
void TestLogger::set_log_stream(std::ostream& stream){
    std::cout.rdbuf(stream.rdbuf());
    std::cerr.rdbuf(stream.rdbuf());
    std::clog.rdbuf(stream.rdbuf());
    stream.sync_with_stdio(true);
}

void TestLogger::set_log_directory(const std::filesystem::path& directory){
    TestLogger::log_dir_.assign(directory);
    if(!decltype(log_dir_)(log_dir_.path().filename()).exists())
        assert(std::filesystem::create_directory(log_dir_.path()));
    if(!decltype(log_dir_)(log_dir_.path().filename()).is_directory())
        std::cerr<<"Incorrect directory name: "<<log_dir_.path()<<". Cannot create directory."<<std::endl;
}