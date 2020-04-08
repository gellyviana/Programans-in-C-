#include <iostream>
#include <string>
#include <cstring>
#include <regex>

using namespace std;

int main (int argc, char* argv[])
{
    string texto = "/Ola? Mundo!!! Acho vái lévóç que vou me lascar-se, prova| de calculo. cruel;";
    regex patern("[^0-9a-zA-Z- áàâãéèêíïóôõöúçñÁÀÂÃÉÈÍÏÓÔÕÖÚÇÑ]+");
    texto = regex_replace(texto, patern, "");
    cout << texto << endl;
    return 0;

    
}


