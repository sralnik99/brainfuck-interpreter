#include <iostream>
#include <cstring>
#include <fstream>

int main(int argc, char** argv) {
    if(argv[1] == NULL) {
        std::cout << "Enter a file please" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    std::string str;
    
    char arr[30000];
    std::memset(arr,0,sizeof(arr));

    char c;
    int i = 0;

    while(file.get(c)) {
        switch (c)
        {
        case '>':
            i++;
            break;
        case '<':
            i--;
            break;
        case '+':
            arr[i]++;
            break;
        case '-':
            arr[i]--;
            break;
        case '.':
            std::putchar(arr[i]);
            break;
        case ',':
            std::cin >> arr[i];
            break;

        case '[':
            std::cerr << "Not implemented, sorry!" << std::endl;
            break;
        case ']':
            std::cerr << "Not implemented, sorry!" << std::endl;
            break; //idk how to implement this, anybody who reads this, help please!!!!!!!!!!!

        default:
            break;
        }
    }

    return 0;
}