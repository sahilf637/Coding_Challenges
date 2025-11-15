#include<iostream>
#include<fstream>
#include<string>
#include<assert.h>

using namespace std;

string opt = "clwm";
void countBytes(ifstream &file){

    file.seekg(0, ios::end);
    size_t size = file.tellg();
    cout<<size<<" ";

    file.seekg(0, ios::beg);

    // stringstream buffer;
    // buffer << file.rdbuf();

    // string content = buffer.str();
    // cout<<content.size()<<" ";
}

void countLines(ifstream &file){
    int count = 0;
    string line;
    while(getline(file, line)){
        count++;
    }
    cout<<count<<" ";

    file.clear();
    file.seekg(0, ios::beg);
}

void countWords(ifstream &file){
    int count = 0;
    string word;
    while(file >> word){
        ++count;
    }
    cout<<count<<" ";
    file.clear();
    file.seekg(0, ios::beg);
}

void countCharacters(ifstream &file){
    int count = 0;
    string word;
    while(file >> word){
        count += word.size();
    }
    cout<<count<<" ";
}

int main(int argc, char *argv[]){
    if(argc < 2){
        cout<<"Invalid arguments\n";
        return 1;
    }
    int idx = -1;
    string fg = argv[1];
    
    assert(opt.find(fg[1]));
    if((fg.size() == 2) && (fg[0] == '-') && (opt.find(fg[1]))){
        idx = 0;
    }

    ifstream file(argv[idx + 2]);
    // assert(file.is_open());
    if(!file.is_open()){
        cout<<"Unable to open file";
        perror("Reason");
        exit(1);
    }

    string param = (idx == -1)?"-a":argv[1];
    switch (param[1])
    {
        case 'c':
        countBytes(file);
        break;

        case 'l':
        countLines(file);
        break;

        case 'w':
        countWords(file);
        break;

        case 'm':
        countCharacters(file);
        break;

        case 'a':
        countBytes(file);
        countLines(file);
        countWords(file);
        countCharacters(file);
        break;

        default:
        cout<<"Some error\n";
    }
    cout<<argv[idx + 2]<<"\n";
    file.close();
    return 0;
}