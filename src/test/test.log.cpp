#include "include/test/test_log.h"

std::filesystem::directory_entry TestLogger::log_dir_ = {std::filesystem::directory_entry(std::filesystem::current_path())};
TestLogger TestLogger::test_logger = TestLogger(std::cout);

TestLogger::TestLogger(std::ostream& stream){
    set_log_stream(stream);
}

TestLogger::TestLogger(const std::filesystem::path& log_dir, const char* test_name){
    set_log_directory(log_dir);
    set_log_stream(test_name);
}

TestLogger& TestLogger::instance(){
    return TestLogger::test_logger;
}

void TestLogger::set_log_stream(const std::string& test_name){
    if(log_dir_.exists() && log_dir_.is_directory()){
        stream_ = std::make_unique<std::ofstream>(log_dir_.path().string()+test_name,std::ostream::trunc);
        std::cout<<log_dir_.path().string()+test_name;
    }
    else std::cerr<<"Incorrect directory name: "<<log_dir_.path()<<std::endl;
}

void TestLogger::set_log_stream(const char* test_name){
    if(log_dir_.exists() && log_dir_.is_directory()){
        stream_ = std::make_unique<std::ofstream>(log_dir_.path()/test_name,std::ostream::trunc);
        std::cout<<log_dir_.path()/test_name;
    }
    else std::cerr<<"Incorrect directory name: "<<log_dir_.path()<<std::endl;
}

void TestLogger::set_log_stream(std::ostream& stream){
    stream_ = std::make_unique<std::ostringstream>();
    stream_->rdbuf(stream.rdbuf());
}

void TestLogger::set_log_directory(const std::filesystem::path& directory){
    TestLogger::log_dir_.assign(directory);
    if(!decltype(log_dir_)(log_dir_.path().filename()).exists())
        std::filesystem::create_directory(log_dir_.path());
    if(!decltype(log_dir_)(log_dir_.path().filename()).is_directory())
        std::cerr<<"Incorrect directory name: "<<log_dir_.path()<<". Cannot create directory."<<std::endl;
}