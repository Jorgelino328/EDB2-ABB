#include "ArvoreBuscaBinaria.hpp"
//Construtor
ArvoreBuscaBinaria::ArvoreBuscaBinaria() {
    raiz = nullptr;
}

//Helpers e outras funções privadas
NoABB* ArvoreBuscaBinaria::inserirHelper(NoABB* no, int valor) {
    if (no == nullptr){
        std::cout << valor << " adicionado" << std::endl;
        return new NoABB(valor);
    }

    if (valor < no->dado)
        no->esquerda = inserirHelper(no->esquerda, valor);
    else if (valor > no->dado)
        no->direita = inserirHelper(no->direita, valor);
    else
        std::cout << valor << " já está na árvore, não pode ser inserido" << std::endl;
    return no;
}

NoABB* ArvoreBuscaBinaria::removerHelper(NoABB* no, int valor) {
    if (no == nullptr) {
        std::cout << valor << " não está na árvore, não pode ser removido" << std::endl;
        return nullptr;
    }

    if (valor < no->dado) {
        no->esquerda = removerHelper(no->esquerda, valor);
    } else if (valor > no->dado) {
        no->direita = removerHelper(no->direita, valor);
    } else {
        if (no->esquerda == nullptr && no->direita == nullptr) {
            delete no;
            no = nullptr;
            std::cout << valor << " removido" << std::endl;
        } else if (no->esquerda == nullptr) {
            NoABB* temp = no;
            no = no->direita;
            delete temp;
            std::cout << valor << " removido" << std::endl;
        } else if (no->direita == nullptr) {
            NoABB* temp = no;
            no = no->esquerda;
            delete temp;
            std::cout << valor << " removido" << std::endl;
        } else {
            NoABB* mindireita = minNo(no->direita);
            no->dado = mindireita->dado;
            no->direita = removerHelper(no->direita, mindireita->dado);
        }
    }
    return no;
}

std::string ArvoreBuscaBinaria::preOrdemHelper(NoABB* no) {
    std::string traversal;

    if (no == nullptr)
        return traversal;

    traversal += std::to_string(no->dado) + " ";
    traversal += preOrdemHelper(no->esquerda);
    traversal += preOrdemHelper(no->direita);

    return traversal;
}

NoABB* ArvoreBuscaBinaria::buscarHelper(NoABB* no, int valor) {
    if (no == nullptr || no->dado == valor) {
        return no;
    }

    if (valor < no->dado) {
        return buscarHelper(no->esquerda, valor);
    } else {
        return buscarHelper(no->direita, valor);
    }
}

bool ArvoreBuscaBinaria::ehCheiaHelper(NoABB* no) {
    if (no == nullptr) {
        return true;
    }

    if (no->esquerda == nullptr && no->direita == nullptr) {
        return true;
    }

    if (no->esquerda != nullptr && no->direita != nullptr) {
        return ehCheiaHelper(no->esquerda) && ehCheiaHelper(no->direita);
    }

    return false;
}

bool ArvoreBuscaBinaria::ehCompletaHelper(NoABB* no, int index, int numeroNos) {
    if (no == nullptr)
        return (true);
 
    if (index >= numeroNos)
        return (false);

    return (ehCompletaHelper(no->esquerda, 2*index + 1, numeroNos) &&
            ehCompletaHelper(no->direita, 2*index + 2, numeroNos));
    }

void ArvoreBuscaBinaria::imprimeArvore1Helper(NoABB* no, std::string prefixo) {
    if (no == nullptr)
        return;

    if (prefixo.empty()) {
        std::cout << no->dado << "----------------------------------" << std::endl;
    } else {
        std::cout << prefixo << no->dado << "----------------------------" << std::endl;
    }

    imprimeArvore1Helper(no->esquerda, prefixo + "\t\t");
    imprimeArvore1Helper(no->direita, prefixo + "\t\t");
}

void ArvoreBuscaBinaria::imprimeArvore2Helper(NoABB* no, int numeroNos) {
    if (no == nullptr)
        return;

    std::cout << "(" << no->dado << " ";
    imprimeArvore2Helper(no->esquerda,numeroNos);
    std::cout << " ";
    imprimeArvore2Helper(no->direita,numeroNos);
    std::cout << ")";
}

NoABB* ArvoreBuscaBinaria::minNo(NoABB* no) {
    NoABB* current = no;
    while (current->esquerda != nullptr) {
        current = current->esquerda;
    }
    return current;
}

int ArvoreBuscaBinaria::contarNos(NoABB* raiz) {
    if (raiz == nullptr)
        return 0;
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}
 
void ArvoreBuscaBinaria::lerArquivos(std::string arquivo1 , std::string arquivo2){
    int numero;
    std::ifstream arquivo_entrada;
    arquivo_entrada.open(arquivo1);
    if (arquivo_entrada.is_open()) { 
        while(arquivo_entrada >> numero)
            inserir(numero); 
        arquivo_entrada.close();
    }

    std::string linha;
    std::string comando;
    int valor;
    std::ifstream arquivo_comandos;
    arquivo_comandos.open(arquivo2);
    if (arquivo_comandos.is_open()) { 
        while(getline(arquivo_comandos,linha)){
            std::istringstream iss(linha);
            iss >> comando >> valor;
            if(comando == "INSIRA"){
                inserir(valor);
            }
            else if(comando == "REMOVA"){
                remover(valor);
            }
            else if(comando == "BUSCA"){
                buscar(valor);
            }
            else if(comando == "ENESIMO"){
                std::cout << enesimoElemento(valor) << std::endl;
            }
            else if(comando == "POSICAO"){
                std::cout << posicao(valor) << std::endl;
            }
            /*else if(comando == "MEDIANA"){
                std::cout << mediana() << std::endl;
            }*/
            /*else if(comando == "MEDIA"){
                std::cout << media(valor) << std::endl;
            }*/
            else if(comando == "CHEIA"){
                if(ehCheia())
                   std::cout << "A árvore é cheia" << std::endl;
                else
                    std::cout << "A árvore não é cheia" << std::endl;
            }
            else if(comando == "COMPLETA"){
                if(ehCompleta())
                   std::cout << "A árvore é completa" << std::endl;
                else
                    std::cout << "A árvore não é completa" << std::endl;
            }
            else if(comando == "PREORDEM"){
                std::cout << pre_ordem() << std::endl;
            }
            else if(comando == "IMPRIMA"){
                imprimeArvore(valor);
            }

        }
        arquivo_comandos.close();
    }

}

//Funções públicas
void ArvoreBuscaBinaria::inserir(int valor) {
    raiz = inserirHelper(raiz, valor);
}

std::string ArvoreBuscaBinaria::pre_ordem() {
    return preOrdemHelper(raiz);
}

void ArvoreBuscaBinaria::remover(int valor) {
    raiz = removerHelper(raiz, valor);
}

bool ArvoreBuscaBinaria::buscar(int valor) {
    NoABB* noEncontrado = buscarHelper(raiz, valor);
    return noEncontrado != nullptr;
}

bool ArvoreBuscaBinaria::ehCheia() {
    return ehCheiaHelper(raiz);
}

bool ArvoreBuscaBinaria::ehCompleta() {
    int numeroNos = contarNos(raiz);
    return ehCompletaHelper(raiz, 0, numeroNos);
}

void ArvoreBuscaBinaria::imprimeArvore (int s) {
    int numeroNos = contarNos(raiz);

    if(s == 1)
        imprimeArvore1Helper(raiz,"");
    else if (s == 2)
        imprimeArvore2Helper(raiz,numeroNos);
    else
        std::cout << "Erro: Formato Inválido!";
    std::cout << std::endl;
}

void ArvoreBuscaBinaria::ordemNes(NoABB* raiz, int &cont, int n, int &enesimo){
    if (raiz == nullptr) {
        return;
    }    // Percorre a subárvore esquerda
    ordemNes(raiz->esquerda, cont, n, enesimo);
   
    // Verifica se o elemento atual é o n-ésimo elemento
    cont++;
    if (cont == n) {
        enesimo = raiz->dado;
        return;
    }

 // Percorre a subárvore direita
    ordemNes(raiz->direita, cont, n, enesimo);
}

int ArvoreBuscaBinaria::enesimoElemento (int n){
    int cont = 0;  // Contador para rastrear a posição atual no percurso em ordem
    int enesimo = 0; // Variável para armazenar o resultado
    // Realiza o percurso em ordem e atualiza o resultado quando encontrar o n-ésimo elemento
    ordemNes(raiz, cont, n, enesimo);


    return enesimo;
}

bool ArvoreBuscaBinaria::ordemPos(NoABB* raiz, int &cont, int x) {
    if (raiz == nullptr) {
        return false;
    }

    if (ordemPos(raiz->esquerda, cont, x)) {
        return true;
    }

    cont++;
    if (raiz->dado == x) {
        return true;
    }

    return ordemPos(raiz->direita, cont, x);
}

int ArvoreBuscaBinaria::posicao(int x) {
    int cont = 0;  // Inicia o contador como 0

    if (ordemPos(raiz, cont, x)) {
        return cont;  // Retorna a posição incrementada por 1
    }

    return -1;  // Retorna -1 se o elemento não for encontrado na árvore
}
