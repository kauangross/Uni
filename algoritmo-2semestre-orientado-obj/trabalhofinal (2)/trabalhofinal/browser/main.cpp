#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class HtmlLoader {
public:
    class Content { // classe interna content
    public:
        std::string Conteudo;
        std::string Formatacao;

        Content(const std::string& conteudo, const std::string& formatacao)
            : Conteudo(conteudo), Formatacao(formatacao){}
    };

    HtmlLoader(const std::string filePath){
        std::ifstream html(filePath); // Abre o arquivo
        if(!html.is_open()){
            std::cout << "Erro ao abrir o arquivo!" << std::endl;
        }

        while(std::getline(html, file_content)){ // Armazena o conte�do

            if (file_content.find("<title>") != std::string::npos) {
                // Remove as tags do texto
                std::string tagRemove = "<title>";
                std::string closingtagRemove = "</title>";
                std::string::size_type i = file_content.find(tagRemove);
                if (i != std::string::npos)
                    file_content.erase(i, tagRemove.length());

                i = file_content.find(closingtagRemove);

                if (i != std::string::npos)
                    file_content.erase(i, closingtagRemove.length());

                title = file_content;


            } else if (file_content.find("<h1>") != std::string::npos) {
                // Remove as tags do texto
                std::string tagRemove = "<h1>";
                std::string closingtagRemove = "</h1>";
                std::string::size_type i = file_content.find(tagRemove);
                if (i != std::string::npos)
                    file_content.erase(i, tagRemove.length());

                i = file_content.find(closingtagRemove);

                if (i != std::string::npos)
                    file_content.erase(i, closingtagRemove.length());

                if(file_content.size() > 74){
                    std::string sub_str;
                    sub_str = file_content.substr(74, file_content.size());

                    file_content.erase(74, file_content.size());

                    addContent(file_content, "h1");
                    addContent(sub_str, "h1");
                } else
                    addContent(file_content, "h1"); // Estancia e adiciona o objeto no vetor



            } else if(file_content.find("<h2>") != std::string::npos) {
                // Remove as tags do texto
                std::string tagRemove = "<h2>";
                std::string closingtagRemove = "</h2>";
                std::string::size_type i = file_content.find(tagRemove);
                if (i != std::string::npos)
                    file_content.erase(i, tagRemove.length());

                i = file_content.find(closingtagRemove);

                if (i != std::string::npos)
                    file_content.erase(i, closingtagRemove.length());

                if(file_content.size() > 74){
                    std::string sub_str;
                    sub_str = file_content.substr(74, file_content.size());

                    file_content.erase(74, file_content.size());

                    addContent(file_content, "h2");
                    addContent(sub_str, "h2");
                } else
                    addContent(file_content, "h2"); // Estancia e adiciona o objeto no vetor


            } else if (file_content.find("<p>") != std::string::npos) {
                // Remove as tags do texto
                std::string tagRemove = "<p>";
                std::string closingtagRemove = "</p>";
                std::string::size_type i = file_content.find(tagRemove);
                if (i != std::string::npos)
                    file_content.erase(i, tagRemove.length());

                i = file_content.find(closingtagRemove);

                if (i != std::string::npos)
                    file_content.erase(i, closingtagRemove.length());

                if(file_content.size() > 74){
                    std::string sub_str;
                    sub_str = file_content.substr(74, file_content.size());

                    file_content.erase(74, file_content.size());

                    addContent(file_content, "p");
                    addContent(sub_str, "p");
                } else
                    addContent(file_content, "p"); // Estancia e adiciona o objeto no vetor
            }
        }

        html.close(); // fechar html
    }

    ~HtmlLoader() { // libera memoria dos ponteiros do vetor
        for (Content* content : HtmlContent) {
            delete content;
        }
        HtmlContent.clear();
    }

    // Retorna o vetor
    std::vector<Content*> getContent() const{
        return HtmlContent;
    }

    // Adiciona o conte�do do html no vector
    void addContent(const std::string& content, const std::string& formatacao) {
        HtmlContent.push_back(new Content(content, formatacao));
    }

    void showContent() const {
        std::cout << std::endl << std::endl << "Conteudo HTML:" << std::endl;
        for (const auto& content : HtmlContent) {
            std::cout << content->Conteudo << "\n\n" << content->Formatacao << std::endl;

        }
        std::cout << std::endl << std::endl;
    }

    std::string getTitle(){
        return title;
    }

private:
    std::vector<Content*> HtmlContent; // Vector com o conte�do e suas formata��es
    std::string file_content; // Conte�do bruto
    std::string title;
};

class Tab {
public:
    Tab(const std::string& title, sf::Font& font)
        : title(title), font(font), isHtmlPage(false){
        // Um ret�ngulo simples para representar o conte�do de uma aba
        content.setSize(sf::Vector2f(600, 400));
        content.setFillColor(sf::Color::White);
        content.setPosition(100, 150);

        // Configura��o do t�tulo da aba
        text.setFont(font);
        text.setString(title);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);
        text.setPosition(content.getPosition().x + 10, content.getPosition().y + 10);
    }

    // Cria a p�gina html
    Tab(std::string t, sf::Font& font, const std::vector<HtmlLoader::Content*>& htmlcontent, sf::RenderWindow& window)
    :  title(t), font(font), isHtmlPage(true) {
        // Um ret�ngulo simples para representar o conte�do de uma aba
        content.setSize(sf::Vector2f(600, 400));
        content.setFillColor(sf::Color::White);
        content.setPosition(100, 150);

        // Configura a formata��o do texto
        float offsetY = content.getPosition().y + 10;
        for(auto* i : htmlcontent){

            text.setFont(font);
            text.setString(i->Conteudo);

            // Formata��es
            if (i->Formatacao == "title") {
                text.setCharacterSize(24);
                text.setFillColor(sf::Color::Black);
            } else if (i->Formatacao == "h1") {
                text.setCharacterSize(24);
                text.setFillColor(sf::Color::Black);
            } else if (i->Formatacao == "h2") {
                text.setCharacterSize(20);
                text.setFillColor(sf::Color::Black);
            } else if (i->Formatacao == "p") {
                text.setCharacterSize(16);
                text.setFillColor(sf::Color::Black);
            }

            text.setPosition(content.getPosition().x + 10, offsetY);
            offsetY += text.getCharacterSize() + 10;

            vector_text.push_back(text);
        }
    }

    // Desenhar aba normal
    void draw(sf::RenderWindow& window) {
        window.draw(content);
        window.draw(text);
    }

    // Desenhar aba html
    void drawHtmlPage(sf::RenderWindow& window) {
        window.draw(content);

        for(sf::Text i : vector_text){
            window.draw(i);
        }
    }

    std::string getTitle(){
        return title;
    }

    bool isHtmlPage;
private:
    sf::RectangleShape content;
    sf::Text text;
    sf::Font& font;
    std::string title;

    std::vector<sf::Text> vector_text;
};


class BrowserWindow {
public:
    BrowserWindow() : window(sf::VideoMode(800, 600), "Simulador de Navegador - SFML") {
        if (!font.loadFromFile("tuffy.ttf")) {
            std::cerr << "Erro ao carregar a fonte!" << std::endl;
        }

        addTab("Aba Inicial");
        selectedTab = tabs.begin();  // Apontar para a primeira aba

        // Inicializar o bot�o "Nova Aba" na parte superior da janela
        newTabButton.setSize(sf::Vector2f(100, 30));
        newTabButton.setPosition(10, 10); // Posi��o no topo da janela
        newTabButton.setFillColor(sf::Color(34, 139, 34));

        newTabButtonText.setFont(font);
        newTabButtonText.setString("Nova Aba");
        newTabButtonText.setCharacterSize(20);
        newTabButtonText.setFillColor(sf::Color::White);
        newTabButtonText.setPosition(newTabButton.getPosition().x + 10, newTabButton.getPosition().y + 5);

        // Inicializar o bot�o "Remover Aba" na parte superior da janela
        closeTabButton.setSize(sf::Vector2f(125 , 30));
        closeTabButton.setPosition(120, 10); // Posi��o no topo da janela
        closeTabButton.setFillColor(sf::Color(165, 42, 42));

        closeTabButtonText.setFont(font);
        closeTabButtonText.setString("Remover aba");
        closeTabButtonText.setCharacterSize(20);
        closeTabButtonText.setFillColor(sf::Color::White);
        closeTabButtonText.setPosition(newTabButton.getPosition().x + 120, newTabButton.getPosition().y + 5);

        // Inicializar mensagem de notifica��o
        notification.setFont(font);
        notification.setCharacterSize(20);
        notification.setFillColor(sf::Color::White);
        notification.setPosition(newTabButton.getPosition().x + 285, newTabButton.getPosition().y + 100);


        // Inicializar o bot�o "Carregar P�gina Html" na parte superior da janela
        addHtmlButton.setSize(sf::Vector2f(200, 30));
        addHtmlButton.setFillColor(sf::Color(255, 255, 255));
        addHtmlButton.setPosition(255, 10); // Posi��o no topo da janela

        addHtmlText.setFont(font);
        addHtmlText.setString("Carregar P�gina Html");
        addHtmlText.setCharacterSize(20);
        addHtmlText.setFillColor(sf::Color::Black);
        addHtmlText.setPosition(addHtmlText.getPosition().x + 265, newTabButton.getPosition().y + 5);


        tabWidth = 200.0f; // Largura das abas
    }

    void run() {
        while (window.isOpen()) {
            processEvents();
            render();
        }
    }

private:
    sf::RenderWindow window;
    std::list<Tab> tabs;
    std::list<Tab>::iterator selectedTab;
    sf::Font font;
    sf::Text tabText;

    sf::RectangleShape newTabButton;
    sf::Text newTabButtonText;

    sf::RectangleShape closeTabButton;
    sf::Text closeTabButtonText;

    sf::Text notification;

    sf::RectangleShape addHtmlButton;
    sf::Text addHtmlText;

    float tabWidth;

    int notify = 0;

    void addTab(const std::string& title) {
        notify = 0; // seta as notifica��es
        if (tabs.size() < 4) { // Se for menor ou igual a tr�s, pode criar uma nova aba
            Tab newTab(title, font);  // Constru�mos o objeto `Tab`
            tabs.push_back(newTab);  // Adicionamos o objeto `Tab` na lista
            if (tabs.size() == 1) {
                selectedTab = tabs.begin();// Seleciona a aba rec�m-criada se for a �nica
            } else
                ++selectedTab;
        } else {
            std::cout << "Limite de abas atingido" << std::endl;
            notify = 2; // Define a chamada da notifica��o de limite de abas
        }
    }

    void closeTab() {
        notify = 0; // seta as notifica��es
        if (tabs.size() != 0){ // Se houver pelo menos uma aba aberta
            auto tabtoremove = selectedTab;

            // Ajusta `selectedTab` para o pr�ximo item, se houver, ou o anterior caso a aba removida seja a �ltima
            if (std::next(selectedTab) != tabs.end()) {
                ++selectedTab; // Pr�xima aba, se existir
            } else if (selectedTab != tabs.begin()) {
                --selectedTab; // Aba anterior, se estiver na �ltima
            } else {
                selectedTab = tabs.end(); // Se for a �nica aba, ficar� vazio ap�s a remo��o
            }
            tabs.erase(tabtoremove); // Remove a p�gina atual
        } else {
            std::cout << "Nenhuma aba aberta" << std::endl;
            notify = 1;
        }
    }

    void addHtmlPage(std::string title, const std::vector<auto*>& htmlcontent){
        notify = 0; // seta as notifica��es

        if (tabs.size() < 4) { // Se for menor ou igual a tr�s, pode criar uma nova aba
            Tab newHtmlTab(title, font, htmlcontent, window);  // Constru�mos o objeto `Tab`
            tabs.push_back(newHtmlTab);// Adicionamos o objeto `Tab` na lista
            if (tabs.size() == 1) {
                selectedTab = tabs.begin();// Seleciona a aba rec�m-criada se for a �nica
            } else
                ++selectedTab;
        } else {
            std::cout << "Limite de abas atingido" << std::endl;
            notify = 2; // Define a chamada da notifica��o de limite de abas
        }
    }

    void processEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Verificar cliques do mouse
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

                    // Verificar se o clique est� dentro dos limites da janela
                    if (window.getViewport(window.getView()).contains(event.mouseButton.x, event.mouseButton.y)) {

                        // Verificar se o bot�o "Nova Aba" foi clicado
                        if (newTabButton.getGlobalBounds().contains(mousePos)) {
                            addTab("Nova Aba " + std::to_string(tabs.size() + 1));
                        }

                        // Verificar se o bot�o "Remover Aba" foi clicado
                        if (closeTabButton.getGlobalBounds().contains(mousePos)) {
                            closeTab();
                        }

                        // Verificar se o bot�o "Carregar P�gina HTML" foi clicado
                        if (addHtmlButton.getGlobalBounds().contains(mousePos)) {
                            notify = 0;
                            if(tabs.size() < 4){
                                HtmlLoader fileHtml("../html.txt");
                                fileHtml.showContent();
                                addHtmlPage(fileHtml.getTitle(), fileHtml.getContent());
                            } else
                                notify = 2; // Aviso de limite de aba
                        }

                        // Verificar se alguma aba foi clicada para selecion�-la
                        int index = 0;
                        for (auto it = tabs.begin(); it != tabs.end(); ++it, ++index) {
                            sf::FloatRect tabRect(index * tabWidth, 50, tabWidth, 30);
                            if (tabRect.contains(mousePos)) {
                                selectedTab = it;
                                break;
                            }
                        }
                    }
                }
            }

            // Navega��o pelas abas usando as setas do teclado
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Right) {
                    if (selectedTab != std::prev(tabs.end())) {
                        ++selectedTab;
                    } else {
                        selectedTab = tabs.begin();  // Voltar para a primeira aba
                    }
                }
                if (event.key.code == sf::Keyboard::Left) {
                    if (selectedTab != tabs.begin()) {
                        --selectedTab;
                    } else {
                        selectedTab = std::prev(tabs.end());  // Ir para a �ltima aba
                    }
                }
            }
        }
    }

    void render() {
        window.clear(sf::Color(50, 50, 50));

        // Renderizar o bot�o "Nova Aba" na parte superior
        window.draw(newTabButton);
        window.draw(newTabButtonText);

        // Renderizar o bot�o "Remover Aba" ao lado do bot�o "Nova Aba"
        window.draw(closeTabButton);
        window.draw(closeTabButtonText);

        // Rendenizar o bot�o "Carregar P�gina HTML" ao lado do bot�o "Remover aba"
        window.draw(addHtmlButton);
        window.draw(addHtmlText);

        // Renderizar as abas logo abaixo do bot�o
        int index = 0;
        for (auto it = tabs.begin(); it != tabs.end(); ++it, ++index) {
            sf::RectangleShape tabShape(sf::Vector2f(tabWidth, 30));
            tabShape.setPosition(index * tabWidth, 50); // Posi��o ajustada abaixo do bot�o
            tabShape.setFillColor((it == selectedTab) ? sf::Color(100, 100, 250) : sf::Color(200, 200, 200));
            window.draw(tabShape);

            // Desenhar o t�tulo da aba
            tabText.setFont(font);
            if(!it->isHtmlPage){ // Se a aba n�o for html
                tabText.setString("Aba " + std::to_string(index + 1));
            } else { // Se for html
                tabText.setString(it->getTitle());
                //
            }
            tabText.setCharacterSize(20);
            tabText.setFillColor(sf::Color::Black);
            tabText.setPosition(index * tabWidth + 10, 52); // Ajuste de posi��o do texto
            window.draw(tabText);
        }

        // Renderizar o conte�do da aba selecionada, se houver abas dispon�veis
        if (!tabs.empty() && selectedTab != tabs.end()) {
            if (selectedTab->isHtmlPage) {
                selectedTab->drawHtmlPage(window);
            } else {
                selectedTab->draw(window);
            }
        }

        // Rendenizar mensagem de limite de abas atingido ou nenhuma aba aberta
        if (notify == 1) {
            notification.setString("Nenhuma aba aberta");
            window.draw(notification);
        } else if (notify == 2) {
            notification.setString("Limite de abas atingido");
            window.draw(notification);
        }

        window.display();
    }
};

int main() {
    BrowserWindow browser;
    browser.run();

    return 0;
}
