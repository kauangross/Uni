#include <iostream>
using namespace std;
#include <typeinfo>
#include <vector>

// Não consegui aplicar os investimentos, várias dúvidas
// Não fiz a função de apagar as contas

// Classe base
class ContaBancaria {
private:
    string titular;
    
protected:
    double saldo;
    int numeroConta;
    int Id; // 1 = corrente, 2 = poupança, 3 = Investimento

public: 
    // Construtor: nome e saldo inicial
    ContaBancaria(string tit, double sal, int num, int id) : titular(tit), saldo(sal), numeroConta(num), Id(id){
        cout << "Conta Criada!" << endl;
    }
    // Destrutor
    ~ContaBancaria(){
        cout << "Conta apagada!" << endl;
    }

    // Método para depositar
    void Deposito(double valor){
        saldo += valor;
        cout << "Valor depositado: R$" << valor << endl;
        cout << "Saldo da conta: R$" << saldo << endl;
    }

    // Método para sacar
    virtual void Saque(double valor){
        if(valor <= saldo){
            saldo -= valor;
            cout << "Valor sacado: R$" << valor << endl;
        } else
            cout << "saldo insuficiente." << endl;
    }

    // Exibe os detalhes da conta
    void exibirDetalhes(){
        cout << "Titular da conta: " << titular << endl;
        cout << "Saldo: R$: " << saldo << endl;
        cout << "Numero da conta: " << numeroConta << endl;
    }

    int getNumeroConta(){
        return numeroConta;
    }

    double getSaldo(){
        return saldo;
    }

    int getId(){
        return Id;
    }
};

// Classe derivada : Conta corrente
class ContaCorrente : public ContaBancaria {
private:
    double LimiteChequeEspecial; // Limite de saque caso saldo esteja zerado

public: 
    // Construtor
    ContaCorrente(string tit, double sal, int num, int id, double salEspecial) : ContaBancaria(tit, sal, num, id), LimiteChequeEspecial(salEspecial){
        cout << "Cheque especial definido!" << endl;
    }

    // SAQUE com limite saque especial
    void Saque(double valor) override{
        if (valor <= saldo + LimiteChequeEspecial)
        {
            saldo -= valor;
        } else
            cout << "Erro!" << endl << "Valor de saque maior do que o limite de cheque especial." << endl;
    }
};

class ContaPoupanca : public ContaBancaria {
protected:
    double taxaRendimento;

public:
    // Construtor conta poupança
    ContaPoupanca(string tit, double sal, int num, int id, double taxRendimento) : ContaBancaria(tit, sal, num, id), taxaRendimento(taxRendimento){
        cout << "Conta poupanca criada!" << endl;
    }

    double aplicarRendimento(double saldo_inicial) {
        saldo += saldo_inicial * taxaRendimento;
        return saldo;
    }
};

class ContaInvestimento : public ContaBancaria {
private:
    double taxaRendimento;
    int risco; 

public:
    // Construtor conta investimento
    ContaInvestimento(string tit, double sal, int num, int id, double taxRendimento, int ris) : ContaBancaria(tit, sal, num, id), taxaRendimento(taxRendimento), risco(ris){
        cout << "Conta investimento criada!" << endl;
    }

    void aplicarRendimento() {
        saldo += saldo * taxaRendimento;
        if (risco >= 4)
        {
            saldo -= saldo * taxaRendimento;
        }
    }
};

class Banco {
private:
    ContaBancaria *contas[100];
    vector<ContaCorrente> contas_corrente;
    vector<ContaPoupanca> contas_poupanca;
    vector<ContaInvestimento> contas_investimento;

    int qntContas = 0;
    int aux_id_taxa[200];

public:
    ~Banco(){}

    void adicionarConta(){
        if (qntContas < 100){
            int a;
            string aux_titular;
            double aux_saldo;
            double aux_limiteCheque;
            double aux_taxRendimento;
            int aux_risco;

            cout << "Tipo da conta: " << endl;
            cout << "[1]: Corrente" << endl;
            cout << "[2]: Poupanca" << endl;
            cout << "[3]: Investimento" << endl;

            
            cin >> a;
            switch (a)
            {
            case 1:
                cout << "Titular: ";
                cin >> aux_titular;
                cout << "Saldo: ";
                cin >> aux_saldo;
                cout << "Limite Cheque Especial: ";
                cin >> aux_limiteCheque;
                fflush(stdin); // limpa o buffer

                contas_corrente.push_back(ContaCorrente(aux_titular, aux_saldo, (qntContas+1), 1, aux_limiteCheque));

                //contas[qntContas] = new ContaCorrente(aux_titular, aux_saldo, (qntContas+1), 1, aux_limiteCheque);
                contas_corrente[0].exibirDetalhes();
                break;
            case 2:
                cout << "Titular: ";
                cin >> aux_titular;
                cout << "Saldo: ";
                cin >> aux_saldo;
                cout << "Taxa de Rendimento: ";
                cin >> aux_taxRendimento;
                fflush(stdin); // limpa o buffer

                aux_id_taxa[0] = aux_taxRendimento;
                aux_id_taxa[1] = qntContas;

                contas[qntContas] = new ContaPoupanca(aux_titular, aux_saldo, (qntContas+1), 2, aux_taxRendimento);
                
                contas[qntContas]->exibirDetalhes();
                break;

            case 3:
                cout << "Titular: ";
                cin >> aux_titular;
                cout << "Saldo: ";
                cin >> aux_saldo;
                cout << "Taxa de Rendimento: ";
                cin >> aux_taxRendimento;
                cout << "Taxa de Risco: ";
                cin >> aux_risco;
                fflush(stdin); // limpa o buffer

                contas[qntContas] = new ContaInvestimento(aux_titular, aux_saldo, (qntContas+1), 3, aux_taxRendimento, aux_risco);
                contas[qntContas]->exibirDetalhes();
                break;
            default:
                break;
            }
            // Incrementa quantidade
            qntContas++;
            cout << endl << "Qnt de contas: " << qntContas << endl;
        } else
            cout << "Quantidade de contas atingiu o maximo!" << endl;
    }

    void apagarConta(int numeroConta){
        for (int i = 0; i < qntContas; i++)
        {
            if (contas[i]->getNumeroConta() == numeroConta)
            {
                qntContas--;
            }
        }
    }

    void transferir(int contaOrigem, int contaDestino, double valor){
        int conta1, conta2;

        // Encontra as contas
        for (int i = 0; i < qntContas; i++)
        {
            // Encontra as duas contas e guarda o numero da conta
            if (contas[i]->getNumeroConta() == contaOrigem)
            {
                conta1 = contaOrigem;
            }
            if (contas[i]->getNumeroConta() == contaDestino)
            {
                conta2 = contaDestino;
                continue;
            }
        }
        // Realiza a transferencia
        if (valor <= contas[conta1-1]->getSaldo()) // Verifica se o saldo não é menor do que o valor
        {
            contas[conta1-1]->Saque(valor); // tira da conta
            contas[conta2-1]->Deposito(valor); // coloca na outra conta
        } else
            cout << "Saldo insuficiente para a transferencia." << endl;
    }

    void exibirContas(){
        for (int i = 0; i < qntContas; i++)
        {
            cout << "Conta " << (i + 1) << endl;
            contas[i]->exibirDetalhes(); 
        }
    }

    // Chama o deposito da conta
    void Deposito(int contaDeposito, double valorDeposito){
        contas[contaDeposito-1]->Deposito(valorDeposito);
    }

    // Chama o saque da conta
    void Saque(int contaSaque, double valorSaque){
        contas[contaSaque-1]->Saque(valorSaque);
    }

    double getSaldo(int conta){
        double saldo;
        saldo = contas[conta-1]->getSaldo();
        return saldo;
    }

    int getQntContas(){
        return qntContas;
    }

    /*void Rendimento(int conta){
        if (contas[conta-1]->getId() == 2)
        {
            int aux_taxa;
            for (int i = 0; i < 100; i++)
            {
                if (contas[conta-1]->getId == (aux_id_taxa * 2 + 1))
                {
                    aux_taxa = (aux_id_taxa *2);
                }
                
            }
            contas[conta-1]->Deposito(contas[conta-1]->getSaldo * aux_taxa);
        } else if (contas[conta-1]->getId() == 3)
        {
            int aux_taxa;
            for (int i = 0; i < 100; i++)
            {
                if (contas[conta-1]->getId == (aux_id_taxa *2) + 1)
                {
                    aux_taxa = (aux_id_taxa * 2);
                }
            }
            contas[conta-1]->Deposito(contas[conta-1]->getSaldo * aux_taxa);
        } else
            cout << "Conta nao permite rendimentos" << endl;
        
        
    }*/
};

void menu(){
    cout << "MENU: " << endl;
    cout << "[1] Criar conta" << endl;
    cout << "[2] Exibir contas" << endl;
    cout << "[3] Depositar" << endl;
    cout << "[4] Saque" << endl;
    cout << "[5] Transferencia" << endl;
    cout << "[6] Aplicar investimento" << endl;
    cout << "[7] Sair" << endl;
}

int main()
{
    Banco *banco = new Banco(); 
    //ContaPoupanca *conta_poupanca = new ContaPoupanca("example", 0, 0 , 0);
    int r, qntContas; 
    int aux_conta, aux_conta2; // Saque e depósito
    double aux_valor, aux_saldo, aux_rendimento;
    
    fflush(stdin);

    menu();

    cin >> r;
    do {
        switch (r)
        {
        case 1: // Criar conta
            banco->adicionarConta();
            qntContas = banco->getQntContas();
            break;
        case 2: // Contas do banco
            banco->exibirContas();
            break;
        case 3: // Depósito
            fflush(stdin);
            cout << "Digite o número da conta: ";
            cin >> aux_conta;
            cout << "Digite o valor do deposito: ";
            cin >> aux_valor;

            if (aux_conta <= qntContas)
            {
                banco->Deposito(aux_conta, aux_valor);   
            } else
                cout << "ERRO" << endl;
            cout << endl;                     
            break;
        case 4: // Saque
            cout << "Digite a conta: ";
            cin >> aux_conta;
            cout << "Digite o valor do saque: ";
            cin >> aux_valor;

            if (aux_conta <= qntContas)
            {
                banco->Saque(aux_conta, aux_valor);
            } else
                cout << "ERRO" << endl;
            cout << endl;
            break;
        case 5: // Transferencia entre contas
            fflush(stdin);
            cout << "Conta origem da transferencia: ";
            cin >> aux_conta;
            cout << "Conta destino da transferencia: ";
            cin >> aux_conta2;
            cout << "Valor da transferencia: ";
            cin >> aux_valor;

            if (aux_conta <= qntContas && aux_conta2 <= qntContas)
            {
                banco->transferir(aux_conta, aux_conta2, aux_valor);
            } else
                cout << "Erro!" << endl << endl;
            
                
            break;
        case 6: // Aplicar investimento
            /*cout << "Conta: ";
            cin >> aux_conta;

            aux_saldo = banco->getSaldo(aux_conta); // Pega o saldo da conta

            banco->Rendimento(aux_conta);

            //aux_valor = banco->aplicarRendimento(aux_saldo); // Descobre o valor de rendimento

            //banco->Deposito(aux_conta, aux_valor); // Aplica um depósito com o valor do rendimento
            cout << endl << "Rendimento aplicado!" << endl;
            */
            cout << "Recurso indisponivel!!" << endl;
            break;
        }

        menu();   
        
        fflush(stdin);
        cin >> r;
        fflush(stdin);
    } while(r != 7);

    delete[] banco;
    return 0;
}