#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ItemBiblioteca.h"
#include <QMessageBox>
#include <QInputDialog>


Biblioteca biblioteca;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Livro *livro1 = new Livro("Dom Quixote", "Miguel de Cervantes", 863);
    Ebook *livro2 = new Ebook("Crime e Castigo", "Fiódor Dostoiévski", 67);
    Livro *livro3 = new Livro("O Pequeno Príncipe", "Antoine de Saint-Exupéry", 101);
    Ebook *livro4 = new Ebook("1984", "George Orwell", 38);
    Livro *livro5 = new Livro("Cem Anos de Solidão", "Gabriel García Márquez", 457);
    Ebook *livro6 = new Ebook("Orgulho e Preconceito", "Jane Austen", 79);
    Livro *livro7 = new Livro("O Senhor dos Anéis", "J.R.R. Tolkien", 1200);
    Ebook *livro8 = new Ebook("A Metamorfose", "Franz Kafka", 55);
    Livro *livro9 = new Livro("O Hobbit", "J.R.R. Tolkien", 300);
    Ebook *livro10 = new Ebook("A Revolução dos Bichos", "George Orwell", 48);

    biblioteca.adicionarItem(livro1);
    biblioteca.adicionarItem(livro2);
    biblioteca.adicionarItem(livro3);
    biblioteca.adicionarItem(livro4);
    biblioteca.adicionarItem(livro5);
    biblioteca.adicionarItem(livro6);
    biblioteca.adicionarItem(livro7);
    biblioteca.adicionarItem(livro8);
    biblioteca.adicionarItem(livro9);
    biblioteca.adicionarItem(livro10);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_CadLivro_clicked()
{
    bool ok;
    QString tipo = QInputDialog::getItem(this, tr("Cadastro de Livro"),
                                         tr("Tipo de Livro:"), QStringList() << "Livro Físico" << "E-Book", 0, false, &ok);

    if (ok && !tipo.isEmpty()) {
        QString titulo = QInputDialog::getText(this, tr("Cadastro de Livro"),
                                               tr("Título:"), QLineEdit::Normal, "", &ok);

        if (ok && !titulo.isEmpty()) {
            QString autor = QInputDialog::getText(this, tr("Cadastro de Livro"),
                                                  tr("Autor:"), QLineEdit::Normal, "", &ok);

            if (ok && !autor.isEmpty()) {
                if (tipo == "Livro Físico") {
                    int numPaginas = QInputDialog::getInt(this, tr("Cadastro de Livro"),
                                                          tr("Número de Páginas:"), 1, 1, 10000, 1, &ok);

                    if (ok) {
                        Livro *livro = new Livro(titulo.toStdString(), autor.toStdString(), numPaginas);
                        biblioteca.adicionarItem(livro);
                        QMessageBox::information(this, tr("Sucesso"), tr("Livro Físico cadastrado com sucesso!"));
                    }
                } else if (tipo == "E-Book") {
                    int tamanhoMB = QInputDialog::getInt(this, tr("Cadastro de Livro"),
                                                         tr("Tamanho do Arquivo (MB):"), 1, 1, 10000, 1, &ok);

                    if (ok) {
                        Ebook *ebook = new Ebook(titulo.toStdString(), autor.toStdString(), tamanhoMB);
                        biblioteca.adicionarItem(ebook);
                        QMessageBox::information(this, tr("Sucesso"), tr("E-Book cadastrado com sucesso!"));
                    }
                }
            }
        }
    }
}

void MainWindow::on_pushButton_CadCliente_clicked()
{
    bool ok;
    QString nome = QInputDialog::getText(this, tr("Cadastro de Cliente"),
                                         tr("Nome:"), QLineEdit::Normal, "", &ok);

    if (ok && !nome.isEmpty()) {
        int id = QInputDialog::getInt(this, tr("Cadastro de Cliente"),
                                      tr("Matrícula:"), 1, 1, 10000, 1, &ok);

        if (ok) {
            Cliente *cliente = new Cliente(nome.toStdString(), id);
            biblioteca.adicionarCliente(cliente);
            QMessageBox::information(this, tr("Sucesso"), tr("Cliente cadastrado com sucesso!"));
        }
    }
}

void MainWindow::on_pushButton_Operacoes_clicked()
{
    bool ok;
    QStringList operacoes;
    operacoes << "Empréstimo de Livro" << "Devolução de Livro";
    QString operacao = QInputDialog::getItem(this, tr("Operações"),
                                             tr("Selecione a operação:"), operacoes, 0, false, &ok);

    if (ok && !operacao.isEmpty()) {
        if (operacao == "Empréstimo de Livro") {
            QStringList nomesClientes;
            for (size_t i = 0; i < biblioteca.getClientes().size(); i++) {
                nomesClientes << QString::fromStdString(biblioteca.getClientes()[i]->getNome());
            }
            QString nomeCliente = QInputDialog::getItem(this, tr("Empréstimo de Livro"),
                                                        tr("Selecione o cliente:"), nomesClientes, 0, false, &ok);

            if (ok && !nomeCliente.isEmpty()) {
                Cliente* clienteSelecionado = NULL;
                for (size_t i = 0; i < biblioteca.getClientes().size(); i++) {
                    if (QString::fromStdString(biblioteca.getClientes()[i]->getNome()) == nomeCliente) {
                        clienteSelecionado = biblioteca.getClientes()[i];
                        break;
                    }
                }

                QStringList titulosLivros;
                for (size_t i = 0; i < biblioteca.getItens().size(); i++) {
                    titulosLivros << QString::fromStdString(biblioteca.getItens()[i]->getTitulo());
                }
                QString tituloLivro = QInputDialog::getItem(this, tr("Empréstimo de Livro"),
                                                            tr("Selecione o livro:"), titulosLivros, 0, false, &ok);

                if (ok && !tituloLivro.isEmpty()) {
                    ItemBiblioteca* livroSelecionado = NULL;
                    for (size_t i = 0; i < biblioteca.getItens().size(); i++) {
                        if (QString::fromStdString(biblioteca.getItens()[i]->getTitulo()) == tituloLivro) {
                            livroSelecionado = biblioteca.getItens()[i];
                            break;
                        }
                    }

                    if (clienteSelecionado && livroSelecionado!=NULL) {
                        biblioteca.emprestarLivro(clienteSelecionado, livroSelecionado);
                    } else {
                        QMessageBox::warning(this, tr("Erro"), tr("Cliente ou livro não encontrado."));
                    }
                }
            }
        } else if (operacao == "Devolução de Livro") {
            QStringList nomesClientes;
            for (size_t i = 0; i < biblioteca.getClientes().size(); i++) {
                nomesClientes << QString::fromStdString(biblioteca.getClientes()[i]->getNome());
            }
            QString nomeCliente = QInputDialog::getItem(this, tr("Devolução de Livro"),
                                                        tr("Selecione o cliente:"), nomesClientes, 0, false, &ok);

            if (ok && !nomeCliente.isEmpty()) {
                Cliente* clienteSelecionado = NULL;
                for (size_t i = 0; i < biblioteca.getClientes().size(); i++) {
                    if (QString::fromStdString(biblioteca.getClientes()[i]->getNome()) == nomeCliente) {
                        clienteSelecionado = biblioteca.getClientes()[i];
                        break;
                    }
                }

                QStringList titulosLivros;
                auto& emprestimos = clienteSelecionado->getEmprestimos();
                for (size_t i = 0; i < emprestimos.size(); i++) {
                    titulosLivros << QString::fromStdString(emprestimos[i]->getTitulo());
                }
                QString tituloLivro = QInputDialog::getItem(this, tr("Devolução de Livro"),
                                                            tr("Selecione o livro a ser devolvido:"), titulosLivros, 0, false, &ok);

                if (ok && !tituloLivro.isEmpty()) {
                    ItemBiblioteca* livroSelecionado = NULL;
                    for (size_t i = 0; i < emprestimos.size(); i++) {
                        if (QString::fromStdString(emprestimos[i]->getTitulo()) == tituloLivro) {
                            livroSelecionado = emprestimos[i];
                            break;
                        }
                    }


                    if (clienteSelecionado && livroSelecionado) {
                        biblioteca.devolverLivro(clienteSelecionado, livroSelecionado);
                    } else {
                        QMessageBox::warning(this, tr("Erro"), tr("Cliente ou livro não encontrado."));
                    }
                }
            }
        }
    }
}



void MainWindow::on_pushButton_Buscar_clicked()
{
    bool ok;
    QString criterio = QInputDialog::getItem(this, tr("Buscar Item"),
                                             tr("Buscar por:"), QStringList() << "Título" << "Autor", 0, false, &ok);

    if (ok && !criterio.isEmpty()) {
        QString prompt = tr("Digite o %1:").arg(criterio);
        QString valor = QInputDialog::getText(this, tr("Buscar Item"), prompt, QLineEdit::Normal, "", &ok);

        if (ok && !valor.isEmpty()) {
            QString resultado;
            const vector<ItemBiblioteca*> &itens = biblioteca.getItens();
            for (size_t i = 0; i < itens.size(); i++) {
                ItemBiblioteca *item = itens[i];
                if ((criterio == "Título" && QString::fromStdString(item->getTitulo()) == valor) ||
                    (criterio == "Autor" && QString::fromStdString(item->getAutor()) == valor)) {
                    resultado += QString::fromStdString(item->getTitulo()) + " por " + QString::fromStdString(item->getAutor()) + "\n";
                }
            }

            if (resultado.isEmpty()) {
                QMessageBox::information(this, tr("Resultado da Busca"), tr("Nenhum item encontrado."));
            } else {
                QMessageBox::information(this, tr("Resultado da Busca"), resultado);
            }
        }
    }
}


void MainWindow::on_pushButton_Relatorios_clicked() {
    bool ok;
    QStringList relatorios;
    relatorios << "Relatório de Livros" << "Relatório de Clientes";
    QString relatorio = QInputDialog::getItem(this, tr("Gerar Relatório"),
                                              tr("Selecione o relatório:"), relatorios, 0, false, &ok);

    if (ok && !relatorio.isEmpty()) {
        QString resultado;

        if (relatorio == "Relatório de Livros") {
            const vector<ItemBiblioteca*> &itens = biblioteca.getItens();
            for (size_t i = 0; i < itens.size(); i++) {
                Livro *livro = dynamic_cast<Livro*>(itens[i]);
                Ebook *ebook = dynamic_cast<Ebook*>(itens[i]);

                resultado += "Título: " + QString::fromStdString(itens[i]->getTitulo()) + "\n";
                resultado += "Autor: " + QString::fromStdString(itens[i]->getAutor()) + "\n";

                if (livro) {
                    resultado += "N° de Páginas: " + QString::number(livro->getNumPaginas()) + " páginas\n";
                } else if (ebook) {
                    resultado += "Tamanho: " + QString::number(ebook->getTamanhoMB()) + " MB\n";
                }

                resultado += "\n";
            }
        } else if (relatorio == "Relatório de Clientes") {
            const vector<Cliente*> &clientes = biblioteca.getClientes();
            for (size_t i = 0; i < clientes.size(); i++) {
                Cliente *cliente = clientes[i];
                resultado += "Nome: " + QString::fromStdString(cliente->getNome()) + " (Matrícula: " + QString::number(cliente->getId()) + ")\n";

                vector<ItemBiblioteca*>& emprestimos = cliente->getEmprestimos();
                if (!emprestimos.empty()) {
                    resultado += "  Livros em posse:\n";
                    for (size_t j = 0; j < emprestimos.size(); j++) {
                        resultado += "    - " + QString::fromStdString(emprestimos[j]->getTitulo()) + " por " +
                                     QString::fromStdString(emprestimos[j]->getAutor()) + "\n";

                        Livro *livro = dynamic_cast<Livro*>(emprestimos[j]);
                        Ebook *ebook = dynamic_cast<Ebook*>(emprestimos[j]);

                        if (livro) {
                            resultado += "        N° de Páginas: " + QString::number(livro->getNumPaginas()) + " páginas\n";
                        } else if (ebook) {
                            resultado += "        Tamanho: " + QString::number(ebook->getTamanhoMB()) + " MB\n";
                        }
                    }
                } else {
                    resultado += "  Nenhum livro em posse.\n";
                }

                resultado += "\n";
            }
        }

        if (resultado.isEmpty()) {
            QMessageBox::information(this, tr("Relatório"), tr("Nenhum dado encontrado."));
        } else {
            ScrollableMessageBox messageBox(tr("Relatório"), resultado, this);
            messageBox.exec();
        }
    }
}

