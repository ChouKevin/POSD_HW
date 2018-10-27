
#if !defined(PROCESSFILE_H)
#define PROCESSFILE_H

#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

class ProcessFile{
    public:
        ProcessFile(){
        }
        vector<string>* readFile(string filePath){
            string line;
            vector<string>* lines = new vector<string>();
            fstream myfile(filePath);
            if (myfile.is_open()){
                while(getline(myfile, line)){
                    lines->push_back(line);
                }
            }
            myfile.close();
            return lines;
        }
};

#endif // PROCESSFILE_H