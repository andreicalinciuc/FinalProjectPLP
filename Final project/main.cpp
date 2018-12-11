#include <iostream>
#include "HtmlParsing.h"


using namespace std;




int main() {

    HtmlParsing l;
    l.ReadFile();
    l.CreateCSSFile();
    l.CheckComand();

    return 0;
}