#include <ncurses.h>
#include "Person.hpp"
#include "Product.hpp"
#include "Stock.hpp"

string fto_string(float x){
    stringstream stream;
    stream << fixed << setprecision(2) << x;
    return stream.str();
}
string getinput(){
	char ch;
	string input;

	while (1){
		ch = getch();
		if (ch == '\n'){
			break;
		}
		if (ch == '\a' || ch == '\b'){
			if (!input.empty()){
				input.pop_back();
			}
		} else {
			input.push_back(ch);
		}
	}

	return input;
}

int main(){
    vector<Client> c;
    vector<Functionary> f;
    vector<Product> p;
    vector<Stock> st;
    Order * pedido = new Order(0, "", true);
    /*int x;
    for(int i = 0; i < 4; ++i){
        cin >> x;
        if(x){
            Functionary * tmp = new Functionary();
            f.push_back(*tmp);
        } else {
            Client * tmp = new Client();
            c.push_back(*tmp);
        }
    }*/
    int l = 1;
    Product * p0 = new Product("arroz carne feijao", 15.00);
    Stock * d0 = new Stock(l++, 50, 20);
    st.push_back(*d0);
    p.push_back(*p0);
    Product * p1 = new Product("macarrao frango feijao", 17.00);
    Stock * d1 = new Stock(l++, 35, 10);
    st.push_back(*d1);
    p.push_back(*p1);
    Product * p2 = new Product("stroggonof de carne", 21.50);
    Stock * d2 = new Stock(l++, 20, 5);
    st.push_back(*d2);
    p.push_back(*p2);
    Product * p3 = new Product("coca cola", 5.00);
    Stock * d3 = new Stock(l++, 60, 25);
    st.push_back(*d3);
    p.push_back(*p3);
    Product * p4 = new Product("sprite", 5.00);
    Stock * d4 = new Stock(l++, 20, 5);
    st.push_back(*d4);
    p.push_back(*p4);
    Product * p5 = new Product("suco de limao", 5.00);
    Stock * d5 = new Stock(l++, 35, 10);
    st.push_back(*d5);
    p.push_back(*p5);
    Product * p6 = new Product("suco de laranja", 5.00);
    Stock * d6 = new Stock(l++, 35, 10);
    st.push_back(*d6);
    p.push_back(*p6);
    Product * p7 = new Product("pudim", 8.50);
    Stock * d7 = new Stock(l++, 10, 3);
    st.push_back(*d7);
    p.push_back(*p7);
    Product * p8 = new Product("sorvete", 4.99);
    Stock * d8 = new Stock(l++, 15, 4);
    st.push_back(*d8);
    p.push_back(*p8);

    initscr();
	noecho();
	cbreak();
	WINDOW * menuwin;
	int y = 24, x = 78;
	menuwin = newwin(y - 4 - 2, x, 1, 1);
	wresize(menuwin, y, x);
	box(menuwin, 0, 0);

	refresh();
	wrefresh(menuwin);

	keypad(menuwin, true);

	vector<string> choices, cpy;
	vector< pair<string, string> > persons;
	string tis[2], tos[3];
	pair<string, string> tmp;
	vector< pair<string, string> >::iterator it;
	int choice, highlight = 0, interfaces = 1, flag[200], fleg[200], qtd[12] = {0};
	for(int i = 0; i < 200; ++i) fleg[i] = flag[i] = 1;

	while(1){
		switch(interfaces){
			case 1:
				if(flag[interfaces]){
					highlight = 0;
					choices.clear();
					choices.push_back("login");
					choices.push_back("cadastrar funcionario");
					choices.push_back("sair");
					flag[interfaces] = 0;
				}
				break;
			case 2:
				if(flag[interfaces]){
					highlight = 0;
					choices.clear();
					choices.push_back("user: ");
					choices.push_back("pass: ");
					choices.push_back("sair");
					flag[interfaces] = 0;
				}
				break;
			case 3:
				if(flag[interfaces]){
					highlight = 0;
					choices.clear();
					choices.push_back("user: ");
					choices.push_back("pass: ");
					choices.push_back("tel: ");
					choices.push_back("voltar");
					choices.push_back("sair");
					flag[interfaces] = 0;
				}
				break;
			case 4:
				if(flag[interfaces]){
					pedido->totalvalue = 0;
					highlight = 1;
					choices.clear();
                    choices.push_back(to_string(st[0].id) + ". " + p[0].name + " (" + fto_string(p[0].price) + ") [" + to_string(st[0].quantity) + "] x 0");
                    choices.push_back(to_string(st[1].id) + ". " + p[1].name + " (" + fto_string(p[1].price) + ") [" + to_string(st[1].quantity) + "] x 0");
                    choices.push_back(to_string(st[2].id) + ". " + p[2].name + " (" + fto_string(p[2].price) + ") [" + to_string(st[2].quantity) + "] x 0");
                    choices.push_back(to_string(st[3].id) + ". " + p[3].name + " (" + fto_string(p[3].price) + ") [" + to_string(st[3].quantity) + "] x 0");
                    choices.push_back(to_string(st[4].id) + ". " + p[4].name + " (" + fto_string(p[4].price) + ") [" + to_string(st[4].quantity) + "] x 0");
                    choices.push_back(to_string(st[5].id) + ". " + p[5].name + " (" + fto_string(p[5].price) + ") [" + to_string(st[5].quantity) + "] x 0");
                    choices.push_back(to_string(st[6].id) + ". " + p[6].name + " (" + fto_string(p[6].price) + ") [" + to_string(st[6].quantity) + "] x 0");
                    choices.push_back(to_string(st[7].id) + ". " + p[7].name + " (" + fto_string(p[7].price) + ") [" + to_string(st[7].quantity) + "] x 0");
                    choices.push_back(to_string(st[8].id) + ". " + p[8].name + " (" + fto_string(p[8].price) + ") [" + to_string(st[8].quantity) + "] x 0");
					choices.push_back("\n");
					choices.push_back("encerrar pedido");
					choices.push_back("voltar");
					choices.push_back("sair");
					choices.push_back("\n");
					choices.push_back("                               total = 0");
					cpy = choices;
					flag[interfaces] = 0;
				}
				break;
			case 5:
				if(flag[interfaces]){
					highlight = 0;
					choices.clear();
					choices.push_back("cadastrar cliente");
					choices.push_back("pagamento com cartao de credito");
					choices.push_back("pagamento em dinheiro");
					choices.push_back("voltar");
					choices.push_back("sair");
					flag[interfaces] = 0;
				}
			case 6:
				if(flag[interfaces]){
					highlight = 0;
					choices.clear();
					choices.push_back("nome: ");
					choices.push_back("tel: ");
					choices.push_back("voltar");
					choices.push_back("sair");
					flag[interfaces] = 0;
				}
				break;
			case 7:
				if(flag[interfaces]){
					highlight = 0;
					choices.clear();
					choices.push_back("senha: ");
					choices.push_back("voltar");
					choices.push_back("sair");
					flag[interfaces] = 0;
				}
				break;
		}

		wclear(menuwin);
		box(menuwin, 0, 0);
		refresh();
		wrefresh(menuwin);

		for(int i = 0; i < (int)choices.size(); ++i){
			if(i == highlight && choices[i][0] != '-') wattron(menuwin, A_REVERSE);
			mvwprintw(menuwin, i+1, 1, choices[i].c_str());
			wattroff(menuwin, A_REVERSE);
		}

		choice = wgetch(menuwin);
		switch(choice){
			case KEY_UP:
				highlight--;
				if(highlight == -1) highlight = 0;
				break;
			case KEY_DOWN:
				highlight++;
				if(highlight == (int)choices.size()) highlight = choices.size()-1;
				break;
			default:
				break;
		}

		if(interfaces == 2 && (highlight == 1 || highlight == 0)){
			bool ok = false;
			if(fleg[highlight]){
				tos[highlight] = getinput();
				fleg[highlight] = 0;
				highlight++;
			}
			if(highlight == 2 && ok == false){
				tmp = make_pair(tos[0], tos[1]);
				ok = true;
				it = find (persons.begin(), persons.end(), tmp);
			    if(it != persons.end()){
					interfaces = 4;
					for(int i = 0; i < 200; ++i) fleg[i] = 1;
				} else {
					for(int i = 0; i < 200; ++i) fleg[i] = flag[i] = 1;
					interfaces = 1;
					wclear(menuwin);
					refresh();
					wrefresh(menuwin);
					printw("senha/usuario ou incorretos\n(pressione qualquer tecla para voltar)");
					refresh();
					getchar();
					wclear(menuwin);
					clear();
					refresh();
				}
			}
		}

		if(interfaces == 3 && (highlight == 2 || highlight == 1 || highlight == 0)){
			bool ok = false;
			if(fleg[highlight]){
				tis[highlight] = getinput();
				fleg[highlight] = 0;
				highlight++;
			}
			if(highlight == 3 && ok == false){
				persons.push_back(make_pair(tis[0], tis[1]));
				for(int i = 0; i < 200; ++i) fleg[i] = flag[i] = 1;
				interfaces = 1;
				ok = true;
			}
		}

		if((choice == '\n') && interfaces == 4 && (choices[highlight][0] - '0' >= 0 && choices[highlight][0] - '0' <= 9)){
			if(st[highlight].quantity > 0){
                pedido->totalvalue += p[highlight].price;
                qtd[highlight]++;
                st[highlight].quantity--;
            }
			choices.back() = "                               total = " + fto_string(pedido->totalvalue) + "$";
			choices[highlight] = (cpy[highlight].substr(0, cpy[highlight].size()-7)) + to_string(st[highlight].quantity) + "] x " + to_string(qtd[highlight]);
		}
		if((choice == 'R' || choice == 'r') && interfaces == 4 && (choices[highlight][0] - '0' >= 0 && choices[highlight][0] - '0' <= 9)){
			if(qtd[highlight] - 1 >= 0){
                qtd[highlight]--;
                st[highlight].quantity++;
                pedido->totalvalue -= p[highlight].price;
            }
			choices.back() = "                               total = " + fto_string(pedido->totalvalue) + "$";
            choices[highlight] = (cpy[highlight].substr(0, cpy[highlight].size()-7)) + to_string(st[highlight].quantity) + "] x " + to_string(qtd[highlight]);
		}

		if((choice == 10) && choices[highlight] == "sair"){
			break;
		}
		if((choice == 10) && choices[highlight] == "voltar"){
			for(int i = 0; i < 200; ++i) fleg[i] = flag[i] = 1;
			interfaces = 1;
		}
		if((choice == 10) && choices[highlight] == "login"){
			interfaces = 2;
		}
		if((choice == 10) && choices[highlight] == "cadastrar funcionario"){
			interfaces = 3;
		}

	}
	wclear(menuwin);
	refresh();
	wrefresh(menuwin);
	printw("press any key to leave");
	refresh();
	getchar();
	refresh();
	endwin();
	return 0;
}
