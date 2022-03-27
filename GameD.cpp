#include <iostream>
#include <string>
#include <ctime>

using std::cout;
using std::cin;
using std::string;
using std::endl; 

void Inicio(int Dificuldade, string Nome) {
		

	if (Dificuldade == 1) {
		
		
		cout << endl;
		cout << Nome << " voce tem uma missao muito importante hoje!\n";
		cout << "voce ira invadir o banco de dados de um grupo terrorista e impedir seus planos!\n";
		cout << "-------------------------------------------------------------cd-----------------";
	}
	cout << "\nEntre o codigo correto pra adentrar o servidor:" << endl;
	cout << "\nNivel atual: " << Dificuldade << endl;
	
}

bool GameD(int LevelDif, int Modo){
	//"const" � usado para impedir o alteramento do valor dentro das variaveis.
	//endl � usado para gerar um quebra de linha, semelhante com o "\n"
	cout << endl;

	int SenhaA = rand() % LevelDif+1*Modo, SenhaB = rand() % LevelDif+1 * Modo, SenhaC = rand() % LevelDif+1 * Modo;

	int Soma = SenhaA + SenhaB + SenhaC;
	int Produto = SenhaA * SenhaB * SenhaC;

	cout << "Tem 3 numeros nessa senha!\n";
	cout << "A soma dos tres valores e: " << Soma << endl; 
	cout << "A muliplicacao dos tres valores e: " << Produto << endl;

	int PalpiteProduto, PalpiteSoma;
	int PalpiteA, PalpiteB, PalpiteC;
	bool Vitoria = true;


	while (Vitoria) {
		//Coletar o palpite do jogador
		cout << "\nDigite a senha: ";
		cin >> PalpiteA >> PalpiteB >> PalpiteC;
		cout << endl;

		PalpiteProduto = PalpiteA * PalpiteB * PalpiteC;
		PalpiteSoma = PalpiteA + PalpiteB + PalpiteC;
		cout << "Soma: " << PalpiteSoma << " / Multiplicacao: " << PalpiteProduto << endl;
		cin.clear(); //limpa erros
		cin.ignore(); //discarta dos buffer


		if (PalpiteSoma == Soma && PalpiteProduto == Produto) {
			cout << "voce passou!" << endl;
			
			Vitoria = false;
			return true;
		}
		else {

			cout << "Senha errada! Tente novamente! Preste atencao." << endl;
			
		}

	}
	return false;


	system("pause > nul");
	



}


int main() {
	int LevelDificuldade = 1, FaseSecreta = 1;
	int Dif = 10;
	bool FaseBonus;
	string NomeORIGEM, Resposta;
	cout << "ola agente, informe seu nick: ";
	cin >> NomeORIGEM;
	srand(time(NULL));
	for (LevelDificuldade = 1; LevelDificuldade <= Dif; ) {
		Inicio(LevelDificuldade, NomeORIGEM);
		bool FaseCom = GameD(LevelDificuldade, FaseSecreta);
		

		
		if (FaseCom == true) {
			++LevelDificuldade;
		}
		system("cls");
		if (LevelDificuldade == 11) {
			cout << "Voce tem a chance de entrar em uma fase bonus, aceita?" << endl;
			cin >> Resposta;
			if (Resposta == "Sim" || Resposta == "ss" || Resposta == "s" || Resposta == "SIM" || Resposta == "sim") {

				Dif = 15;
				FaseBonus = true;
				FaseSecreta = 2;
			}
			else if (Resposta == "Nao" || Resposta == "n�o" || Resposta == "n" || Resposta == "NAO" || Resposta == "nao") {

				cout << "Putz, que pena que voce nao quer.";
				FaseBonus = false;
			}
		}
	}


	if (FaseBonus == false) {
	cout << "\nCaramba... Voce conseguiu! \n";
	cout << "Conseguimos parar os planos do inimigo por ter voce conosco!" << endl;
	cout << "Parabens agente " << NomeORIGEM << "!" << endl;
	}
	else if (FaseBonus == true) {
		cout << "Caramba... Voce conseguiu! \n";
		cout << "...?" << endl;
		cout << "O que e esse teu olhar pra mim " << NomeORIGEM << "?" << endl;
		cout << endl;
		cout << "--Bip BIIP! Cambio " << NomeORIGEM << ", voce finalmente acordou!" << endl;
		cout << NomeORIGEM << ": O que ta acontecendo? aonde estou?" << endl;
		cout << "--BIIIp! Voce acabou de sair do prompt! um lugar bem escuro, certo? HAHA!" << endl;
		cout << endl;
		cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		cout << "\n AAAAAAAAAAAAAH!";
	}
	







	return 0;
}