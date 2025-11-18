#include <iostream>
#include <string>



void do_init(); //forward declaration

void do_add(std::string const& filename)
{
    std::cout<<"[DEBUG] add command received for file:"<<filename<<"\n";
}

void do_commit(std::string const& msg)
{
    std::cout<<"[DEBUG] commit command received with msg:"<<msg<<"\n";
}



int main(int argc, char* argv[])
{
    if(argc<2)
    {
        //early return
        std::cout<<"[DEBUG] not a valid command, see FAQ\n";
        return 0;
    }

    std::string cmd = argv[1];
    if(cmd == "init")
    {
        do_init();
    }
    else if(cmd == "add")
    {
        if(argc<3)
        {
            std::cout<<"[DEBUG] filename missing: add <filename>\n";
            return 1;
        }
        do_add(argv[2]);
    }
    else if(cmd == "commit")
    {
        if(argc<4 || std::string(argv[2]) != "-m")
        {
            std::cout<<"[DEBUG] something missing: commit -m <filename>\n";
            return 1;
        }
        do_commit(argv[3]);
    }
    else {
        std::cout << "Unknown command: " << cmd << "\n";
    }
    return 0;
}
