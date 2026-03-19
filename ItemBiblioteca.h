#ifndef ITEMBIBLIOTECA_H
#define ITEMBIBLIOTECA_H

#include <string>
#include <vector>
#include <QMessageBox>
#include <QInputDialog>

using namespace std;

class ItemBiblioteca {
protected:
    string m_titulo;
    string m_autor;

public:
    ItemBiblioteca(string titulo, string autor);
    ~ItemBiblioteca();

    string getTitulo();
    string getAutor();

    virtual void mostrarInformacoes() = 0;
};

class Livro : public ItemBiblioteca {
private:
    int m_numPaginas;

public:
    Livro(string titulo, string autor, int numPaginas);
    string getTitulo();
    string getAutor();
    int getNumPaginas();
    void mostrarInformacoes();
};

class Ebook : public ItemBiblioteca {
private:
    int m_tamanhoMB;

public:
    Ebook(string titulo, string autor, int tamanhoMB);
    string getTitulo();
    string getAutor();
    int getTamanhoMB();
    void mostrarInformacoes();
};

class Cliente {
private:
    string m_nome;
    int m_id;
    vector<ItemBiblioteca*> m_emprestimos;

public:
    Cliente(string nome, int id);
    string getNome();
    int getId();
    vector<ItemBiblioteca*>& getEmprestimos();
    void adicionarEmprestimo(ItemBiblioteca* item);
};

class Biblioteca {
private:
    vector<ItemBiblioteca*> m_itens;
    vector<Cliente*> m_clientes;

public:
    Biblioteca();
    ~Biblioteca();

    void adicionarItem(ItemBiblioteca* item);
    void adicionarCliente(Cliente* cliente);
    vector<ItemBiblioteca*> getItens();
    vector<Cliente*> getClientes();
    void emprestarLivro(Cliente* cliente, ItemBiblioteca* item);
    void devolverLivro(Cliente* cliente, ItemBiblioteca* item);
};

#endif // ITEMBIBLIOTECA_H
