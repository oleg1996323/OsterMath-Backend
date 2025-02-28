// #include "include/test/test_log.h"
// #include <cstdio>
// #include <stdio.h>

// std::filesystem::directory_entry TestLogger::log_dir_ = {std::filesystem::directory_entry(std::filesystem::current_path())};
// std::streambuf* TestLogger::out_buf = std::cout.rdbuf();
// std::streambuf* TestLogger::err_buf = std::cerr.rdbuf();
// std::streambuf* TestLogger::log_buf = std::clog.rdbuf();

// TestLogger TestLogger::test_logger = TestLogger(std::cout);

// TestLogger::TestLogger(std::ostream& stream){
//     set_log_stream(stream);
// }

// TestLogger::TestLogger(const std::filesystem::path& log_dir, const char* test_name){
//     set_log_directory(log_dir);
//     set_log_stream(test_name);
// }

// TestLogger& TestLogger::instance(){
//     return TestLogger::test_logger;
// }

// void TestLogger::set_log_stream(const std::string& test_name){
//     set_log_stream(test_name.c_str());
// }

// void TestLogger::set_log_stream(const char* test_name){
//     if(decltype(log_dir_)(log_dir_.path().filename()).exists() && decltype(log_dir_)(log_dir_.path().filename()).is_directory()){
//         fopen((log_dir_.path()/test_name).c_str(),"w");
//         freopen((log_dir_.path()/test_name).c_str(),"a",stderr);
//         std::unique_ptr<std::ofstream> fstream = std::make_unique<std::ofstream>(log_dir_.path()/test_name,std::ostream::trunc);
//         assert(std::cout.rdbuf());
//         assert(fstream->is_open());
//         std::cout<<"Opened log file: "<<log_dir_.path()/test_name<<std::endl;
//         std::cout.rdbuf(fstream->rdbuf());
//         std::cerr.rdbuf(fstream->rdbuf());
//         std::clog.rdbuf(fstream->rdbuf());
//         std::cout<<"ReadBuf: "<<std::cout.rdbuf()<<std::endl;
//         assert(std::cout.rdbuf()!=out_buf);
//         assert(std::cerr.rdbuf()!=err_buf);
//         stream_ = std::move(fstream);
//         assert(std::cout.rdbuf());
//     }
//     else std::cerr<<"Incorrect directory name: "<<log_dir_.path()<<std::endl;
// }
// void TestLogger::set_log_stream(std::ostream& stream){
//     // std::cout.rdbuf(stream.rdbuf());
//     // std::cerr.rdbuf(stream.rdbuf());
//     // std::clog.rdbuf(stream.rdbuf());
//     stream.sync_with_stdio(true);
// }

// void TestLogger::set_log_directory(const std::filesystem::path& directory){
//     TestLogger::log_dir_.assign(directory);
//     if(!decltype(log_dir_)(log_dir_.path().filename()).exists())
//         assert(std::filesystem::create_directory(log_dir_.path()));
//     if(!decltype(log_dir_)(log_dir_.path().filename()).is_directory())
//         std::cerr<<"Incorrect directory name: "<<log_dir_.path()<<". Cannot create directory."<<std::endl;
// }