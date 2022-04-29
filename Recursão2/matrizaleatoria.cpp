#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char * argv[]){
    srand(time(NULL));
    size_t nl = 0;
    size_t nc = 0;
    float porcent = 0.0;
    
    if(argc > 3){
        stringstream(argv[1]) >> nl;
        stringstream(argv[2]) >> nc;
        stringstream(argv[3]) >> porcent;
    }else{
        cout << "Digite o número de linhas, colunas e porcentagem de fogo: " << endl;
        cout << "Exemplo: ./matrizaleatoria 10 10 0.5" << endl;
        return 1;
    }

    vector<string> mat(nl, string(nc, '.'));

    int cont = 0;
    for(size_t l = 0; l < nl; l++)
        for(size_t c = 0; c < nc; c++)
            if(rand() % 100 < porcent){
                mat[l][c] = '#';
                cont++;
            }

    cout << nl << " " << nc << " " << 0 << " " << 0 << endl;
    for(size_t i = 0; i < mat.size(); i++)
        cout << mat[i] << endl;
    cout << cont << "/" << nl * nc << "=" << (cont/(float)(nl * nc)) << endl;
}