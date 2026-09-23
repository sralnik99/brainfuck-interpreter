#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

int main(int argc, char** argv) {
    if(argv[1] == NULL) {
        std::cout << "Enter a file please" << std::endl;
        return 1;
    }
    std::fstream file(argv[1], std::ios::in);

    std::istreambuf_iterator<char> fstart(file), fend;
    std::vector<unsigned char> ctape(fstart, fend);
    file.close();
    
    std::vector<unsigned char> arrtape(30000, 0);

    std::vector<unsigned char>::iterator c = ctape.begin();
    std::vector<unsigned char>::iterator i = arrtape.begin();

    int b = 0;

    for(; c != ctape.end(); ++c) {
        switch (*c)
        {
        case '>':
            ++i;
            break;
        case '<':
            --i;
            break;
        case '+':
            ++*i;
            break;
        case '-':
            --*i;
            break;
        case '.':
            std::cout << *i;
            break;
        case ',':
            std::cin >> *i;
            break;

        case '[':
            if(*i) continue;
            ++b;
            while(b)
                switch(*++c) {
                    case '[': ++b; break;
                    case ']': --b; break;
                }
            break;
        case ']':
            if(!*i) continue;
            ++b;
            while(b)
                switch(*--c) {
                    case '[': --b; break;
                    case ']': ++b; break;
                }
            c--;
            break; 

        default:
            break;
        }
    }

    return 0;
}