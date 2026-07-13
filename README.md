# 📚 Library Management System (C++ / Qt Framework) / Sistema de Gestão de Biblioteca

<details>
<summary>🇺🇸 <b>Read in English</b></summary>
<br>

This project is a library automation system developed as part of the Computer Engineering course at UFSC. The software uses the **Qt** framework to provide a functional graphical user interface, allowing the management of hybrid collections (physical and digital), customer registration, and dynamic control of loans and returns.

### 🚀 Technical Features

#### 🧠 Object-Oriented Programming (OOP)
The project applies advanced OOP concepts to ensure code scalability and organization:
* **Polymorphism:** Use of an abstract base class (`ItemBiblioteca`) with pure virtual methods, allowing uniform handling of different media types.
* **Inheritance:** Specialization of `Livro` (Physical) and `Ebook` (Digital) classes, each with specific attributes like page count or size in MB.
* **Encapsulation:** Protection of sensitive customer and item data, accessed only via getter and setter methods.

#### 🛠️ Memory Management
* Implementation of **Custom Destructors** in the `Biblioteca` class to iterate through pointer vectors and perform manual memory release (`delete`), preventing memory leaks.
* Use of `dynamic_cast` for safe object type identification at runtime during report generation.

#### 💻 Graphical User Interface (GUI)
* Developed with **Qt Widgets**, using the *Signals & Slots* system to process button events and user inputs.
* Interface themed with the visual identity of the **University Library (BU-UFSC)**.

### ⚙️ Features
* **Item Registration:** Support for Physical Books and E-books with data validation.
* **Customer Management:** User registration with a unique ID (Enrollment number) and possession history.
* **Loan System:** Logic for transferring item possession between the library's collection and the customer's personal list.
* **Dynamic Reports:** Generation of detailed lists of available books and the current status of each registered customer.

### 🚀 How to Run

1. Ensure you have **Qt Creator** and a C++ compiler (such as MinGW or GCC) installed on your system.
2. Clone this repository to your local machine.
3. Open the `LibrarySistem.pro` file inside Qt Creator.
4. Configure the build kit (C++17 recommended).
5. Compile and run the project.

### 📂 File Structure
* `ItemBiblioteca.h / .cpp`: Definition and implementation of class logic and inheritance.
* `mainwindow.h / .cpp / .ui`: GUI control logic, user interaction, and layout design developed in Qt Designer.
* `main.cpp`: Main application entry point.
* `LibrarySistem.pro`: Qt project configuration file (C++17).
* `resource.qrc` / `images/`: Resource files containing icons and visual assets for the interface.

---
**Developed by:** Gabriel Raulino Dal Pont

</details>

<details>
<summary>🇧🇷 <b>Ler em Português (BR)</b></summary>
<br>

Este projeto é um sistema de automação para bibliotecas desenvolvido como parte do curso de Engenharia de Computação na UFSC. O software utiliza o framework **Qt** para oferecer uma interface gráfica funcional, permitindo o gerenciamento de acervos híbridos (físicos e digitais), cadastro de clientes e controle dinâmico de empréstimos e devoluções.

### 🚀 Diferenciais Técnicos

#### 🧠 Programação Orientada a Objetos (POO)
O projeto aplica conceitos avançados de POO para garantir a escalabilidade e organização do código:
* **Polimorfismo:** Uso de classe base abstrata (`ItemBiblioteca`) com métodos virtuais puros, permitindo o tratamento uniforme de diferentes tipos de mídia.
* **Herança:** Especialização das classes `Livro` (Físico) e `Ebook` (Digital), cada uma com atributos específicos como número de páginas ou tamanho em MB.
* **Encapsulamento:** Proteção de dados sensíveis dos clientes e itens, acessados apenas via métodos *getter* e *setter*.

#### 🛠️ Gerenciamento de Memória
* Implementação de **Destrutores Customizados** na classe `Biblioteca` para percorrer vetores de ponteiros e realizar a liberação manual de memória (`delete`), evitando *memory leaks*.
* Uso de `dynamic_cast` para identificação segura de tipos de objetos em tempo de execução durante a geração de relatórios.

#### 💻 Interface Gráfica (GUI)
* Desenvolvido com **Qt Widgets**, utilizando o sistema de *Signals & Slots* para processar eventos de botões e entradas de usuário.
* Interface tematizada com a identidade visual da **Biblioteca Universitária (BU-UFSC)**.

### ⚙️ Funcionalidades
* **Cadastro de Itens:** Suporte para Livros Físicos e E-books com validação de dados.
* **Gestão de Clientes:** Registro de usuários com ID único (Matrícula) e histórico de posse.
* **Sistema de Empréstimos:** Lógica de transferência de posse de itens entre o acervo da biblioteca e a lista pessoal do cliente.
* **Relatórios Dinâmicos:** Geração de listagens detalhadas de livros disponíveis e situação atual de cada cliente cadastrado.

### 🚀 Como Executar

1. Certifique-se de ter o **Qt Creator** e um compilador C++ (como MinGW ou GCC) instalados.
2. Clone este repositório.
3. Abra o arquivo `LibrarySistem.pro` no Qt Creator.
4. Compile e execute o projeto.

### 📂 Estrutura do Repositório
* `ItemBiblioteca.h / .cpp`: Definição e implementação da lógica de classes e herança.
* `mainwindow.h / .cpp / .ui`: Lógica de controle da interface gráfica, interação com o usuário e design desenvolvido no Qt Designer.
* `main.cpp`: Arquivo principal de execução da aplicação.
* `LibrarySistem.pro`: Arquivo de configuração do projeto Qt (C++17).
* `resource.qrc` / `images/`: Arquivos de recursos contendo imagens e assets visuais da interface.

---
**Desenvolvido por:** Gabriel Raulino Dal Pont

</details>
