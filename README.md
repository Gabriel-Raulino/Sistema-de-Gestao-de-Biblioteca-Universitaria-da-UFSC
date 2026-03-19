# 📚 Sistema de Gestão de Biblioteca (C++ / Qt Framework)

Este projeto é um sistema de automação para bibliotecas desenvolvido como parte do curso de Engenharia de Computação na UFSC. O software utiliza o framework **Qt** para oferecer uma interface gráfica funcional, permitindo o gerenciamento de acervos híbridos (físicos e digitais), cadastro de clientes e controle dinâmico de empréstimos e devoluções.

## 🚀 Diferenciais Técnicos

### 🧠 Programação Orientada a Objetos (POO)
O projeto aplica conceitos avançados de POO para garantir a escalabilidade e organização do código:
* **Polimorfismo:** Uso de classe base abstrata (`ItemBiblioteca`) com métodos virtuais puros, permitindo o tratamento uniforme de diferentes tipos de mídia.
* **Herança:** Especialização das classes `Livro` (Físico) e `Ebook` (Digital), cada uma com atributos específicos como número de páginas ou tamanho em MB.
* **Encapsulamento:** Proteção de dados sensíveis dos clientes e itens, acessados apenas via métodos *getter* e *setter*.

### 🛠️ Gerenciamento de Memória
* Implementação de **Destrutores Customizados** na classe `Biblioteca` para percorrer vetores de ponteiros e realizar a liberação manual de memória (`delete`), evitando *memory leaks*.
* Uso de `dynamic_cast` para identificação segura de tipos de objetos em tempo de execução durante a geração de relatórios.

### 💻 Interface Gráfica (GUI)
* Desenvolvido com **Qt Widgets**, utilizando o sistema de *Signals & Slots* para processar eventos de botões e entradas de usuário.
* Interface tematizada com a identidade visual da **Biblioteca Universitária (BU-UFSC)**.

## ⚙️ Funcionalidades
* **Cadastro de Itens:** Suporte para Livros Físicos e E-books com validação de dados.
* **Gestão de Clientes:** Registro de usuários com ID único (Matrícula) e histórico de posse.
* **Sistema de Empréstimos:** Lógica de transferência de posse de itens entre o acervo da biblioteca e a lista pessoal do cliente.
* **Relatórios Dinâmicos:** Geração de listagens detalhadas de livros disponíveis e situação atual de cada cliente cadastrado.

## 📂 Estrutura do Repositório
* `ItemBiblioteca.h / .cpp`: Definição e implementação da lógica de classes e herança.
* `mainwindow.h / .cpp`: Lógica de controle da interface gráfica e interação com o usuário.
* `mainwindow.ui`: Design da interface desenvolvido no Qt Designer.
* `LibrarySistem.pro`: Arquivo de configuração do projeto Qt (C++17).

## 🔧 Como Executar
1.  Certifique-se de ter o **Qt Creator** e um compilador C++ (como MinGW ou GCC) instalados.
2.  Clone este repositório.
3.  Abra o arquivo `LibrarySistem.pro` no Qt Creator.
4.  Compile e execute o projeto.

---
**Desenvolvido por:** Gabriel Raulino Dal Pont
