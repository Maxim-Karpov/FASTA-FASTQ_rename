#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
//using namespace std;

std::string filename;
std::string trim_mode;
int trim_len;
std::string file_type;
void print_info();
void rename(std::string fn, std::string ft);
int length;
std::string out_filename;

int main(int argc, char **argv) {
  if (argc == 1){
  print_info();
  }
  for (int i =  1; i<argc; i+=2) {
      if (strcmp(argv[i],"-i")==0 && argv[i+1]) {
        filename = argv[i+1];
        std::cout << "filename: " << filename << "\n" ;
        }
      else if (strcmp(argv[i],"-ft")==0 && argv[i+1]) {
        file_type = argv[i+1];
        std::cout << "file_type: " << file_type << "\n" ;
        }
      else {
        print_info();
      }

  }
  if (!filename.empty()){
    std::cout << "\n renaming " << file_type << " file" << "\n";
    rename(filename, file_type);
  }
}

void print_info(){
      std::cout << "\n";
      std::cout << "***** Fast FASTA renamer *****" << "\n";
      std::cout << "Input requires both arguments:" << "\n";
      std::cout << "  -i    input file" << "\n";
      std::cout << "  -ft file type (fasta|fastq)" << "\n";
      std::cout << "\n";
}

void rename(std::string fn, std::string ft){
    std::ifstream infile(fn);
    std::string out_filename;
    if (ft == "fastq"){
        out_filename = "renamed_output.fastq";
    }
    else if (ft == "fasta"){
        out_filename = "renamed_output.fasta";
    }
    std::ofstream outfile(out_filename);
  
    if (!infile.is_open() || !outfile.is_open()) {
        std::cerr << "Error: Unable to open file(s)!" << std::endl;
        return;
    }
    
    std::string line;

    if (ft == "fasta"){
        int i = 1;
        while (std::getline(infile, line)) {

            if (!line.empty() && line[0] == '>'){
                outfile << ">" << i << "\n";
                i = i+1;
            }
            else {
                outfile << line << "\n";
            }
        }
  }
  
    if (ft == "fastq"){
          int i = 1;
          while (std::getline(infile, line)) {
          int length = line.length();
            if (!line.empty() && line[0] == '@' && length < 59){
                outfile << ">" << i << "\n";
                i = i+1;
            }
            else if (line == "+"){
                outfile << line << "\n";
            }
            else {
                outfile << line << "\n";
            }
        }
  
  }
  
    infile.close();
    outfile.close();
    return;
}
