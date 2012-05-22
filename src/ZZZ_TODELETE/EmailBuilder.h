#ifndef __EMAILBUILDER_H__
#define __EMAILBUILDER_H__

#include <dirent.h>
#include <errno.h>
#include <queue>
#include <vector>
#include <string>
#include <sys/stat.h>

class EmailBuilder {
    EmailBuilder() {}
    EmailBuilder(const EmailBuilder&);
    EmailBuilder& operator=(const EmailBuilder&);

    bool is_directory(std::string& dir_name) {
        struct stat fileInfo;
        stat(dir_name.c_str(), &fileInfo);
        return S_ISDIR(fileInfo.st_mode);
    }

  public:
    static EmailBuilder& Instance()
    {
        static EmailBuilder singleton;
        return singleton;
    }

    bool BuildEmailDataBase(const std::string& base_dir, Graph& g, std::vector<Email>& emails)
    {
        std::queue<std::string> directories;
        directories.push(base_dir);

        std::set<std::string> discovered_files;
        while(!directories.empty()) {
            std::string& directory_name(directories.front());

            DIR *dp;
            struct dirent *dirp;
            if((dp = opendir(directory_name.c_str())) == NULL) {
                std::cout<<"Unable to open directory '"<<directory_name<<"'"<<std::endl;
            } else {
                while ((dirp = readdir(dp)) != NULL) {
                    std::string filename(directory_name+dirp->d_name);
                    if(dirp->d_name == std::string(".") || dirp->d_name == std::string("..")) continue;
                    else if(is_directory(filename)) {
                        std::cout<<"[DIR] "<<dirp->d_name<<std::endl;
                        directories.push(filename + "/");
                    } else {
                        int index = g.FindOrInsertAsset(directory_name + dirp->d_name);
                        emails.push_back(Email(index, filename));
                    }
                }
            }

            directories.pop();
            closedir(dp);
        }
        return true;
    }
};

#endif
