#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

void do_init()
{
    if(fs::exists(".myGit"))
    {
        std::cout<<"Repository already initialized\n";
        return;
    }
    fs::create_directory(".mygit");

    // Create subdirectories like git does
    fs::create_directory(".myGit/objects");
    fs::create_directory(".myGit/refs");

    //create head file
    std::ofstream head(".myGit/HEAD");
    head<<"ref: refs/master\n";
    head.close();
    std::cout<<"Initialized empty git repository inside .myGit/\n";

}
