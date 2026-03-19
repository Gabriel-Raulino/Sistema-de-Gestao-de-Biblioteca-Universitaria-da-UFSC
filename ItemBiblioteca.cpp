#include "ItemBiblioteca.h"


ItemBiblioteca::ItemBiblioteca(string titulo, string autor)
    : m_titulo(titulo), m_autor(autor) {}

ItemBiblioteca::~ItemBiblioteca() {}

string ItemBiblioteca::getTitulo() {
    return m_titulo;
}

string ItemBiblioteca::getAutor() {
    return m_autor;
}


Livro::Livro(string titulo, string autor, int numPaginas)
    : ItemBiblioteca(titulo, autor), m_numPaginas(numPaginas) {}

string Livro::getTitulo() {
    return m_titulo;
}

string Livro::getAutor() {
    return m_autor;
}

int Livro::getNumPaginas() {
    return m_numPaginas;
}

void Livro::mostrarInformacoes()  {
    QString info = "Livro: " + QString::fromStdString(m_titulo) + " por " +
                   QString::fromStdString(m_autor) + ", " + QString::number(m_numPaginas) + " páginas.";
    QMessageBox::information(NULL, "Informações do Livro", info);
}


Ebook::Ebook(string titulo, string autor, int tamanhoMB)
    : ItemBiblioteca(titulo, autor), m_tamanhoMB(tamanhoMB) {}

string Ebook::getTitulo()  {
    return m_titulo;
}

string Ebook::getAutor()  {
    return m_autor;
}

int Ebook::getTamanhoMB()  {
    return m_tamanhoMB;
}

void Ebook::mostrarInformacoes()  {
    QString info = "Ebook: " + QString::fromStdString(m_titulo) + " por " +
                   QString::fromStdString(m_autor) + ", " + QString::number(m_tamanhoMB) + " MB.";
    QMessageBox::information(NULL, "Informações do Ebook", info);
}


Cliente::Cliente(string nome, int id)
    : m_nome(nome), m_id(id) {}

string Cliente::getNome() {
    return m_nome;
}

int Cliente::getId() {
    return m_id;
}

vector<ItemBiblioteca*>& Cliente::getEmprestimos() {
    return m_emprestimos;
}

void Cliente::adicionarEmprestimo(ItemBiblioteca* item) {
    m_emprestimos.push_back(item);
}


Biblioteca::Biblioteca() {}

Biblioteca::~Biblioteca() {
    for (size_t i = 0; i < m_itens.size(); i++) {
        delete m_itens[i];
    }
    for (size_t i = 0; i < m_clientes.size(); i++) {
        delete m_clientes[i];
    }
}

void Biblioteca::adicionarItem(ItemBiblioteca* item) {
    m_itens.push_back(item);
}

void Biblioteca::adicionarCliente(Cliente* cliente) {
    m_clientes.push_back(cliente);
}

vector<ItemBiblioteca*> Biblioteca::getItens() {
    return m_itens;
}

vector<Cliente*> Biblioteca::getClientes() {
    return m_clientes;
}

void Biblioteca::emprestarLivro(Cliente* cliente, ItemBiblioteca* item) {
    bool clienteEncontrado = false;
    bool itemEncontrado = false;


    for (size_t i = 0; i < m_clientes.size(); i++) {
        if (m_clientes[i] == cliente) {
            clienteEncontrado = true;

            for (size_t j = 0; j < m_itens.size(); j++) {
                if (m_itens[j] == item) {
                    itemEncontrado = true;

                    m_itens.erase(m_itens.begin() + j);

                    m_clientes[i]->adicionarEmprestimo(item);

                    QMessageBox::information(NULL, "Empréstimo de Livro",
                                             QString::fromStdString("Livro emprestado para " + cliente->getNome()));
                    break;
                }
            }

            if (!itemEncontrado) {
                QMessageBox::warning(NULL, "Erro", "Livro não encontrado na biblioteca.");
            }
            break;
        }
    }

    if (!clienteEncontrado) {
        QMessageBox::warning(NULL, "Erro", "Cliente não encontrado na biblioteca.");
    }
}


void Biblioteca::devolverLivro(Cliente* cliente, ItemBiblioteca* item) {
    bool clienteEncontrado = false;
    bool itemEncontrado = false;

    for (size_t i = 0; i < m_clientes.size(); i++) {
        if (m_clientes[i] == cliente) {
            clienteEncontrado = true;

            vector<ItemBiblioteca*>& emprestimos = m_clientes[i]->getEmprestimos();

            for (size_t j = 0; j < emprestimos.size(); j++) {
                if (emprestimos[j] == item) {
                    itemEncontrado = true;

                    emprestimos.erase(emprestimos.begin() + j);

                    m_itens.push_back(item);

                    QMessageBox::information(NULL, "Devolução de Livro",
                                             QString::fromStdString("Livro devolvido por " + cliente->getNome()));
                    break;
                }
            }

            if (!itemEncontrado) {
                QMessageBox::warning(NULL, "Erro", "Livro não está emprestado para este cliente.");
            }
            break;
        }
    }

    if (!clienteEncontrado) {
        QMessageBox::warning(NULL, "Erro", "Cliente não encontrado na biblioteca.");
    }
}
