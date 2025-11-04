#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void countBytes(ifstream &file){

    file.seekg(0, ios::end);
    size_t size = file.tellg();
    cout<<size<<" bytes\n";

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
    cout<<count<<"\n";
}

void countWords(ifstream &file){
    int count = 0;
    string word;
    while(file >> word){
        ++count;
    }
    cout<<count<<"\n";
}

void countCharacters(ifstream &file){
    int count = 0;
    string word;
    while(file >> word){
        count += word.size();
    }
    cout<<count<<"\n";
}

int main(int argc, char *argv[]){
    if(argc < 3){
        cout<<"Invalid arguments\n";
        return 1;
    }
    ifstream file(argv[2]);
    // assert(file.is_open());
    if(!file.is_open()){
        cout<<"Unable to open file";
        perror("Reason");
        exit(1);
    }

    string param = argv[1];
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

        default:
        cout<<"Some error\n";
    }
    cout<<argv[2]<<"\n";
    file.close();
    return 0;
}