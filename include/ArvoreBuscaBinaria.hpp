#ifndef ARVORE_BUSCA_BINARIA_HPP
#define ARVORE_BUSCA_BINARIA_HPP
#include <iostream>
#include <string>
#include <limits>
#include <queue>
#include <fstream>
#include <sstream>

#include "NoABB.hpp"

class ArvoreBuscaBinaria
{
private:
    NoABB *raiz; //<! atributo que salva a raiz da ABB

    /**
     * @brief Função auxiliar da função inserir(), recebe um nó da ABB e um valor inteiro
     * e usa recursão até encontrar um nó livre para fazer a inserção.
     *
     * @param no O ponteiro para o nó da árvore usado como raiz na função.
     * @param valor O valor a ser inserido na ABB
     * @return NoABB* O ponteiro para o nó da árvore final, usado na recursão.
     */
    NoABB *inserirHelper(NoABB *no, int valor);

    /**
     * @brief Função auxiliar da função pre_ordem(), recebe um nó da ABB, e  usa recursão
     * para organizar os itens da ABB em ordem de visitação, retornando uma string com a
     * respectiva lista de nós.
     *
     * @param no O ponteiro para o nó da árvore usado como raiz na função.
     * @return std::string
     */
    std::string preOrdemHelper(NoABB *no);

    /**
     * @brief Função auxiliar da função remover(), recebe um nó da ABB, e  usa recursão
     * para substituir os valor dos nós filhos até que o nó a em questão esteja em uma
     * folha e possa ser removido.
     *
     * @param no O ponteiro para o nó da árvore usado como raiz na função.
     * @param valor O valor do nó a ser removido
     * @return NoABB* O ponteiro para o nó da árvore final, usado na recursão.
     */
    NoABB *removerHelper(NoABB *no, int valor);

    /**
     * @brief Função que recebe um nó e usa recursão para encontrar o menor nó da ABB
     *
     * @param no O ponteiro para o nó da árvore usado como raiz na função.
     * @return NoABB* O ponteiro para o nó da árvore final, usado na recursão.
     */
    NoABB *minNo(NoABB *no);

    /**
     * @brief Função auxiliar da função buscar(), que recebe um nó e um valor,
     * e usa recursão para buscar esse valor na ABB.
     *
     * @param no O ponteiro para o nó da árvore usado como raiz na função.
     * @param valor O valor a ser buscado
     * @return NoABB* O ponteiro para o nó da árvore final, usado na recursão.
     */
    NoABB *buscarHelper(NoABB *no, int valor);

    /**
     * @brief Função auxiliar da função ehCheia(), que recebe um nó
     * e usa recursão para checar se a ABB é uma ABB cheia, ou não.
     *
     * @param no O ponteiro para o nó da árvore usado como raiz na função.
     * @return true quando a ABB for cheia,
     * @return false quando a ABB não for cheia
     */
    bool ehCheiaHelper(NoABB *no);

    /**
     * @brief Função auxiliar da função ehCompleta(), que recebe um nó
     * e usa recursão para checar se a ABB é uma ABB completa, ou não.
     *
     * @param raiz O ponteiro para a raiz da árvore.
     * @param index Contador usado para comparar com o número de nós
     * @param numeroNos é o número de nós da ABB
     * @return true quando a ABB for completa,
     * @return false quando a ABB não for completa
     */
    bool ehCompletaHelper(NoABB *raiz, int index, int numeroNos);

    /**
     * @brief Função que recebe um nó e conta o número total de nós
     * na ABB, retornando um inteiro.
     *
     * @param no O ponteiro para o nó da árvore usado como raiz na função.
     * @return int O número de nós final
     */
    int contarNos(NoABB *no);

    /**
     * @brief Função auxiliar da função imprimeArvore(), que recebe um nó raiz
     * e uma string 'prefixo', e imprime a ABB no formato 1, com linhas horizontais.
     *
     * @param raiz O ponteiro para a raiz da árvore.
     * @param prefixo define a quantidade de linhas ao lado de cada valor
     */
    void imprimeArvore1Helper(NoABB *raiz, std::string prefixo);

    /**
     * @brief Função auxiliar da função imprimeArvore(), que recebe um nó raiz
     * e uma inteiro com o número de nós na ABB, e imprime a ABB no formato 2,
     * com os nós em parenteses.
     *
     * @param raiz O ponteiro para a raiz da árvore.
     * @param numeroNos define o número de nós total da ABB
     */
    void imprimeArvore2Helper(NoABB *raiz, int numeroNos);

    /**
     * @brief Percorre a árvore em ordem e encontra o n-ésimo elemento.
     *
     * @param raiz O ponteiro para a raiz da árvore.
     * @param cont O contador da posição atual em ordem.
     * @param n O número do elemento.
     * @param enesimo n-ésimo numero.
     */
    void ordemNes(NoABB *raiz, int &cont, int n, int &enesimo);

    /**
     * @brief Retorna a posição ocupada pelo elemento x em um percurso em ordem
     * simétrica na ABB.
     *
     * @param raiz
     * @param cont
     * @param x
     * @return true
     * @return false
     */
    bool ordemPos(NoABB *raiz, int &cont, int x);

    /**
     * @brief Função auxiliar da função media() ?
     *
     * @param raiz
     * @return double
     */
    double media(NoABB *raiz);

public:
    /**
     * @brief Construtor do objeto Arvore Busca Binaria
     *
     */
    ArvoreBuscaBinaria();

    /**
     * @brief Função para a ler os arquivos de teste
     *
     * @param arquivo1 O arquivo de entrada
     * @param arquivo2 O arquivo de comandos
     */
    void lerArquivos(std::string arquivo1, std::string arquivo2);

    /**
     * @brief Função que insere um valor na ABB. Usa a função inserirHelper()
     *
     * @param valor O valor a ser inserido
     */
    void inserir(int valor);

    /**
     * @brief Função que organiza os dados da ABB em sequência de visitação.
     * Usa a função preOrdemHelper()
     *
     * @return std::string O string com os valores ordenados
     */
    std::string pre_ordem();

    /**
     * @brief Funçao que remove um nó da ABB
     *
     * @param valor O valor do nó a ser removido
     */
    void remover(int valor);

    /**
     * @brief Função que busca um valor na ABB. Usa a função buscarHelper()
     *
     * @param valor O valor a ser buscado
     * @return true quando o valor é encontrado,
     * @return false quando o valor não é encontrado
     */
    bool buscar(int valor);

    /**
     * @brief Função que checa caso a ABB é uma ABB cheia ou não. Usa a função ehCheiaHelper().
     *
     * @return true quando a função é cheia,
     * @return false quando a função não é cheia.
     */
    bool ehCheia();

    /**
     * @brief Função que checa quando a ABB é uma ABB completa ou não.
     * Usa a função ehCompletaHelper()
     *
     * @return true quando a ABB é completa,
     * @return false quando a ABB não é completa.
     */
    bool ehCompleta();

    /**
     * @brief Função que imprime a árvore em dois possíveis formatos
     * Usa a função imprimeArvore1Helper() ou imprimeArvore2Helper()
     * dependendo do formato
     *
     * @param s O formato da impressão
     */
    void imprimeArvore(int s);

    /**
     * @brief Função que retorna o n-ésimo elemento do percurso
     * em ordem da ABB.
     *
     * @param n A "n-ésima" posição a ser encontrada
     * @return int O número encontrado na posição n
     */
    int enesimoElemento(int n);

    /**
     * @brief Função que retorna a posição ocupada pelo elemento x em um percurso em ordem
     * simétrica na ABB
     *
     * @param x O número cuja a posição queremos achar
     * @return int A posição do número x
     */
    int posicao(int x);

    /**
     * @brief Função que calcula a mediana da ABB
     *
     * @return int A mediana da ABB
     */
    int mediana();

    /**
     * @brief Função que calcula a media da ABB
     *
     * @param x
     * @return double A média da ABB
     */
    double media(int x);
};

#endif
