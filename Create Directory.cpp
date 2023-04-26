#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void createDirectory(const char* path) {
    int status = system(("mkdir " + string(path)).c_str());
    if (status == -1) {
        cerr << "Error creating directory" << endl;
        exit(EXIT_FAILURE);
    }
}

void writeFile(const char* path, const char* content) {
    FILE* fp = fopen(path, "w");
    if (fp == NULL) {
        cerr << "Error opening file" << endl;
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "%s", content);
    fclose(fp);
}

int main() {
    const char* dirPath = "System-Calls";
    const char* filePath = "System-Calls/Readme.txt";
    const char* fileContent = "Hi there my name is alok darshi";
    
    createDirectory(dirPath);
    writeFile(filePath, fileContent);
    
    return 0;
}
