#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

// Function to create a new file in a new directory and write some text to it
void create_file(string dir_name, string file_name, string file_content) {
    int dir_status = mkdir(dir_name.c_str());  // create a new directory
    if (dir_status == -1) {
        perror("mkdir error");
        exit(EXIT_FAILURE);
    }

    string file_path = dir_name + "/" + file_name;

    ofstream file(file_path);
    if (!file.is_open()) {
        perror("open error");
        exit(EXIT_FAILURE);
    }

    file << file_content;  // write some text to the file
    file.close();

    cout << "File created successfully!" << endl;
}

// Function to read the contents of a file and print them to the console
void read_file(string file_path) {
    ifstream file(file_path);
    if (!file.is_open()) {
        perror("open error");
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(file, line)) {  // read the contents of the file
        cout << line << endl;  // print the contents to the console
    }

    file.close();
}

// Function to copy a file to a new location
void copy_file(string source_path, string dest_path) {
    ifstream source_file(source_path, ios::binary);
    if (!source_file.is_open()) {
        perror("open error");
        exit(EXIT_FAILURE);
    }

    ofstream dest_file(dest_path, ios::binary);
    if (!dest_file.is_open()) {
        perror("open error");
        exit(EXIT_FAILURE);
    }

    dest_file << source_file.rdbuf();  // copy the contents of the source file to the destination file

    source_file.close();
    dest_file.close();

    cout << "File copied successfully!" << endl;
}

// Function to delete a file
void delete_file(string file_path) {
    int status = unlink(file_path.c_str());  // delete the file
    if (status == -1) {
        perror("unlink error");
        exit(EXIT_FAILURE);
    }

    cout << "File deleted successfully!" << endl;
}

// Function to delete a directory
void delete_directory(string dir_path) {
    int status = rmdir(dir_path.c_str());  // delete the directory
    if (status == -1) {
        perror("rmdir error");
        exit(EXIT_FAILURE);
    }

    cout << "Directory deleted successfully!" << endl;
}

int main() {


    #ifndef ONLINE_JUDGE
                        freopen("inputf.in", "r", stdin);
                        freopen("outputf.out", "w", stdout);
                        #endif
    
   
     create_file("mydi", "myfile.txt", "Hio there my name is alok darshi and iam a student of IIT dhanbad");

     read_file("mydir/myfile_copy.txt");

     copy_file("mydi/myfile.txt", "mydir/myfile_copy.txt");

     delete_file("mydi/myfile.txt");

     delete_directory("mydi");

    return 0;
}
