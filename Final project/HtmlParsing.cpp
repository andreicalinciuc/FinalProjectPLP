//
// Created by andrei on 10.12.2018.
//

#include "HtmlParsing.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;
struct elements {
    string tag;
    string str;

} e[5000];


string ReplaceAll(std::string str, const std::string &from, const std::string &to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

string GetTag(char tag[1024]) {
    char name_tag[1024] = "\0";
    int size = 0;
    bzero(name_tag, 1024);

    for (int i = 0; i < strlen(tag); i++)
        if (tag[0] == '/') {
            if (tag[i] != ' ' && tag[i]!=':') {
                name_tag[size++] = tag[i];

            } else {

                break;
            }
        }
    return name_tag;
}

string GetValues(char lines[1024]) {
    char name_tag[1024] = "\0";
    int size = 0;
    bzero(name_tag, 1024);
    int poz_rec = 0;
    for (int i = 0; i < strlen(lines); i++) {
        if (lines[i] == ' ' || lines[i] == '<') {

            poz_rec = i;
            break;
        }

    }
    if (lines[poz_rec + 1] == '-') {
        return name_tag;

    }

    for (int i = poz_rec; i < strlen(lines); i++)
        name_tag[size++] = lines[i];


    return name_tag;

}

void HtmlParsing::ReadFile() {
    FILE *fp = fopen("../date.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    char *list = NULL;
    char *tag = NULL;
    size_t len = 0;
    int cnt = 0;
    ofstream myfile;
    myfile.open("../dates.txt");
    while ((getline(&list, &len, fp)) != -1) {

        strcat(line, list);
        tag = list;
        e[cnt].tag = GetTag(tag);
        if (e[cnt].tag.size() > 0)
            myfile << e[cnt].tag << endl;

        e[cnt].str = GetValues(list);
        myfile << e[cnt].str << endl;

        cnt++;


    }
    fclose(fp);
}


void HtmlParsing::CheckComand() {
    ofstream myfile;
    myfile.open("../test.html");
    myfile << "<!DOCTYPE html>\n" << endl <<
           "<html>\n" << endl <<
           "<head>" << endl << "<link rel=\"stylesheet\" type=\"text/css\" href=\"Design.css\">"

                               "</head>" << endl <<
           "<body>" << endl;

    ifstream file("../dates.txt");
    if (file.is_open()) {
        string line;
        int h1=0;
        int h3=0;
        int div=1;
        while (getline(file, line)) {


            string r = line.substr(0, 3);
            if (r == "///") {
                h3=1;
                div=0;
                myfile << "<h1>" << line.substr(3, line.length()) << "</h1>" << endl;
            } else if (r == "//-") {
                div=0;
                myfile << "<h3>" << line.substr(3, line.length()) << "</h3>" << endl;
            } else if(line.size()!=0){
                if(h3!=1){
                    string str = ReplaceAll(line, "<", "&lt;");
                    str = ReplaceAll(str, "/>", "/&gt;");
                    myfile << "<pre>" << str << "</pre>" << endl;
                }
                else
                {
                    h3=0;
                    string str = ReplaceAll(line, "<", "&lt;");
                    str = ReplaceAll(str, "/>", "/&gt;");
                    myfile << "<h4>" << str << "</h4>" << endl;
                }

            }
        }
        file.close();
    }

    myfile << "\n"
              "</body>\n" << endl <<
           "</html>" << endl;
    myfile.close();


}




