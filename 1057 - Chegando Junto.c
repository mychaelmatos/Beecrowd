#include <bits/stdc++.h>
#define Backtracking(i, a, N) for (int i = a; i<N; i++)

using namespace std;

typedef pair <int, int> Pontos; 

struct Estados{
	int percorridos;
    Pontos A;
    Pontos B;
    Pontos C;
    Estados(Pontos aux_A, Pontos aux_B, Pontos aux_C, int aux_percorridos){
        A = aux_A;
        B = aux_B;
        C = aux_C;
        percorridos = aux_percorridos;
    }
    Estados(){ }    
};

typedef queue <Estados> FILA;

char matriz[9][9];    
bool resolucao[9][9][9][9][9][9];   
int resposta, N;
int linha [] = {-1, 1, 0, 0};   
int coluna [] = {0, 0, -1, 1};  
Pontos A, B, C;

bool Se_puder ( Pontos push ){   
    if (push.first >= 0 && push.first < N && push.second >= 0 && push.second < N)
        return  matriz[push.first][push.second] != '#';
    return 0;
}  

bool Final ( Estados fim ){   
    return matriz[fim.A.first][fim.A.second]=='X' && matriz[fim.B.first][fim.B.second]=='X' && matriz[fim.C.first][fim.C.second]=='X';
}

bool Se_forem_iguais ( Pontos A2, Pontos B2, Pontos C2 ){
    return !( A2 == B2 || A2 == C2 || B2 == C2 );   
}

bool Validar_operacoes ( Estados D ){ 
	if(!resolucao[D.A.first][D.A.second][D.B.first][D.B.second][D.C.first][D.C.second] && Se_forem_iguais(D.A, D.B, D.C))
	    return resolucao[D.A.first][D.A.second][D.B.first][D.B.second][D.C.first][D.C.second] = 1;
    return 0;
}

void Operacao (){

    FILA dados;   
    Estados atual, encerrado;
    atual = Estados(A, B, C, 0);
    resolucao[A.first][A.second][B.first][B.second][C.first][C.second] = true;    
	dados.push(atual);  
    Pontos nA, nB, nC;
	bool At, Bt, Ct;  
    
	while( !dados.empty() ){  
        atual = dados.front();
		dados.pop();    
        if (Final(atual)) 
			resposta = min(resposta, atual.percorridos);   
        Backtracking (c, 0, 4){
            nA.first = atual.A.first + linha[c]; nA.second = atual.A.second + coluna[c];
            nB.first = atual.B.first + linha[c]; nB.second = atual.B.second + coluna[c];
            nC.first = atual.C.first + linha[c]; nC.second = atual.C.second + coluna[c];
            At = Se_puder(nA);
            Bt = Se_puder(nB);
            Ct = Se_puder(nC);
            if ( At ||  Bt ||  Ct ){
                if (At){	
                    if ( !Bt && !Ct && nA != atual.B && nA != atual.C )	encerrado.A = nA;
                    else if ( Bt && !Ct && nA != atual.C )	encerrado.A = nA;
                    else if ( Ct && !Bt && nA != atual.B )	encerrado.A = nA;
                    else if ( Bt &&  Ct )	encerrado.A = nA;
                    else  encerrado.A = atual.A;
                } else  encerrado.A = atual.A;  

                if (Bt){
                    if ( !At && !Ct && nB != atual.A && nB != atual.C )	encerrado.B = nB;	
                    else if ( At && !Ct && nB != atual.C )	encerrado.B = nB;	
                    else if ( Ct && !At && nB != atual.A ) encerrado.B = nB;
                    else if ( At &&  Ct ) encerrado.B = nB;
                    else  encerrado.B = atual.B;
                } else  encerrado.B = atual.B;

                if (Ct){
                    if ( !At && !Bt && nC != atual.B && nC != atual.A )	encerrado.C = nC;
                    else if ( At && !Bt && nC != atual.B )	encerrado.C = nC;
                    else if ( Bt && !At && nC != atual.A )	encerrado.C = nC;
                    else if ( At &&  Bt ) encerrado.C = nC;	
                    else  encerrado.C = atual.C;
                } else  encerrado.C = atual.C;

                encerrado.percorridos = atual.percorridos + 1;               
				if ( Validar_operacoes(encerrado)) 
					dados.push( encerrado ); 
            }
        }
    }
}

int main(){

    int contador = 0;
	int numerodecasos;    
    char auxiliar;

    cin >> numerodecasos;

    while ( contador < numerodecasos) {
        resposta = 1000;
        cout << "Case "<< ++contador << ": ";
        cin >> N;
        memset (resolucao, 0, sizeof resolucao);  
        Backtracking (i, 0, N) {
		    Backtracking (j, 0, N) {             
				cin >> auxiliar;                
				matriz[i][j] = auxiliar;                
				if(auxiliar == 'A')                      
					A = Pontos(i, j);				    
				if(auxiliar == 'B')
                    B = Pontos(i, j);               
			    if(auxiliar == 'C')
                    C = Pontos(i, j);
            }
        }
        Operacao();
        if (resposta != 1000)
            cout << resposta << "\n";      
		else
            cout << "trapped\n";
    }
    return 0;
}
