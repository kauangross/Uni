#include <iostream>
#include <string>
#include <stack>
using namespace std;

class HistoricoNavegacao {
private:
    stack<string> historico;

public:
    // Construtor
    HistoricoNavegacao() {
        historico.push("www.unisinos.com.br"); // Aba inicial
    }

    void visitarPagina(const string& url) {
        historico.push(url);
    }

    void voltarPagina() {
        if (!historico.empty()) {
            cout << endl << "Voltando de: " << historico.top() << endl;
            historico.pop();
        } else {
            cout << endl << "Nenhuma aba aberta!" << endl;
        }
    }

    void paginaAtual() const {
        if (!historico.empty()) {
            cout << endl << "Pagina atual: " << historico.top() << endl;
        } else {
            cout << endl << "Nenhuma aba aberta!" << endl;
        }
    }

    void exibirHistorico() const {
        stack<string> copiaHistorico = historico;
       
        if (!historico.empty()) {
            cout << endl << "Historico de navegacao:" << endl;
            while (!copiaHistorico.empty()) {
                cout << copiaHistorico.top() << endl;
                copiaHistorico.pop();
            }
        } else
            cout << endl << "Historico vazio!" << endl;

        
    }
};

void menu(); // Protótipo

int main() {
    HistoricoNavegacao navegador;
    string url;
    int r = 0;

    while (r != 5){
        cout << endl;
        menu();
        cin >> r;
        switch (r)
        {
        case 1: // Visitar página
            cout << endl << "Digite a url do site: ";
            cin >> url;
            navegador.visitarPagina(url);
            break;
        case 2: // Voltar
            navegador.voltarPagina();
            break;
        case 3: // Página atual
            navegador.paginaAtual();
            break;
        case 4: // Histórico
            navegador.exibirHistorico();
            break;
        default: // Sair
            cout << "Saindo...";
            break;
        }
    }
    return 0;
}

void menu(){
    cout << endl <<
            "1. Visitar uma nova pagina." << endl <<
            "2. Voltar para a pagina anterior." << endl <<
            "3. Verificar a pagina atual." << endl <<
            "4. Exibir todo o historico de paginas." << endl <<
            "5. Sair." << endl;
}