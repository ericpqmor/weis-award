#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    ifstream input;
    ofstream output;
    bool achou;
    int tam, votos[80]={0}, n=0, bixo, aux;
    string s1, s2, entrada, saida, prof[80], s, saux;
    ostringstream convert, convert2;
    char * writable_in;
    char * writable_out;

    cout << "Bem vindo ao corretor automatico do Premio Weis" << endl << "Insira a atual turma de bixos: ";
    cin >> bixo;

    for(int t = bixo; t > bixo - 5; t--)
    {
        convert.str("");
        convert.clear();
        convert << t;
        if(t > bixo - 2)
        {
            for(int i=1; i<=4; i++)
            {
                convert2.str("");
                convert2.clear();
                convert2 << i;

                s1 = convert.str();
                s2 = convert2.str();
                entrada = s1 + "_" + s2 + ".txt";
                saida = "Resultado_" + entrada;

                writable_in = new char[entrada.size() + 1];
                writable_out = new char[saida.size() + 1];
                std::copy(entrada.begin(), entrada.end(), writable_in);
                writable_in[entrada.size()] = '\0';
                std::copy(saida.begin(), saida.end(), writable_out);
                writable_out[saida.size()] = '\0';

                input.open(writable_in);
                output.open(writable_out);

                n = 0;
                for(int i=0; i<80; i++)
                {
                    votos[i] = 0;
                    prof[i] = "";
                }
                s = "Not end";

                while(s != "fim")
                {
                    input >> s;
                    tam = s.size();
                    if(s[tam-1] == ',')
                        s.erase(s.begin() + tam-1);
                    achou = false;
                    for(int i=0;i<80;i++)
                    {
                        if(s == prof[i])
                        {
                            votos[i]++;
                            achou = true;
                            break;
                        }
                    }
                    if(!achou)
                    {
                        prof[n] = s;
                        votos[n]=1;
                        n++;
                    }
                }

                for(int i=0; i<n-1; i++)
                {
                    for(int j=0; j<i; j++)
                    {
                        if(votos[i] > votos[j])
                        {
                            aux = votos[i];
                            saux = prof[i];
                            votos[i] = votos[j];
                            prof[i] = prof[j];
                            votos[j] = aux;
                            prof[j] = saux;
                        }
                    }
                }

                for(int i=0;i<n-1;i++)
                {
                    if(votos[i] != 0)
                        output << prof[i] << ": " << votos[i] << endl;
                }

                input.close();
                output.close();
            }
        }
        else
        {
            s1 = convert.str();
            for(int i=1; i<=6; i++)
            {
                switch (i)
                {
                    case 1:
                        s2 = "_AER.txt";
                        entrada = s1 + s2;
                    break;
                    case 2:
                        s2 = "_AESP.txt";
                        entrada = s1 + s2;
                    break;
                    case 3:
                        s2 = "_CIVIL.txt";
                        entrada = s1 + s2;
                    break;
                    case 4:
                        s2 = "_COMP.txt";
                        entrada = s1 + s2;
                    break;
                    case 5:
                        s2 = "_ELE.txt";
                        entrada = s1 + s2;
                    break;
                    case 6:
                        s2 = "_MEC.txt";
                        entrada = s1 + s2;
                    break;
                }
                saida = "Resultado_" + entrada;

                writable_in = new char[entrada.size() + 1];
                writable_out = new char[saida.size() + 1];
                std::copy(entrada.begin(), entrada.end(), writable_in);
                writable_in[entrada.size()] = '\0';
                std::copy(saida.begin(), saida.end(), writable_out);
                writable_out[saida.size()] = '\0';

                input.open(writable_in);
                output.open(writable_out);

                n = 0;
                for(int i=0; i<80; i++)
                {
                    votos[i] = 0;
                    prof[i] = "";
                }
                s = "Not end";

                while(s != "fim")
                {
                    input >> s;
                    tam = s.size();
                    if(s[tam-1] == ',')
                        s.erase(s.begin() + tam-1);
                    achou = false;
                    for(int i=0;i<80;i++)
                    {
                        if(s == prof[i])
                        {
                            votos[i]++;
                            achou = true;
                            break;
                        }
                    }
                    if(!achou)
                    {
                        prof[n] = s;
                        votos[n]=1;
                        n++;
                    }
                }

                for(int i=0; i<n-1; i++)
                {
                    for(int j=0; j<i; j++)
                    {
                        if(votos[i] > votos[j])
                        {
                            aux = votos[i];
                            saux = prof[i];
                            votos[i] = votos[j];
                            prof[i] = prof[j];
                            votos[j] = aux;
                            prof[j] = saux;
                        }
                    }
                }

                for(int i=0;i<n-1;i++)
                {
                    if(votos[i] != 0)
                        output << prof[i] << ": " << votos[i] << endl;
                }
                input.close();
                output.close();
            }
        }
    }
    cout << endl << "Resultados computados com sucesso!" << endl;
}
