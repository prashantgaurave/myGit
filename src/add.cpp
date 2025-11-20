#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

void do_add(std::string const& filename)
{
    if(!fs::exists(filename) || !fs::exists(".myGit"))
    {
        std::cout<<"[DEBUG] file not found or repository not initialized\n";
        return;
    }
    fs::path src = filename;

    fs::path destFolder = ".myGit/objects";

    if(!fs::exists(destFolder))
    {
        return;
    }

    fs::path dest = destFolder / src.filename();

    fs::copy_file(src,dest,fs::copy_options::overwrite_existing);

}




