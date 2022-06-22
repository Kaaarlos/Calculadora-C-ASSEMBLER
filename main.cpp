#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <windows.h>

using namespace std;

string opc = "";
bool continuarPrograma = true;
float sum1, sum2, resS;
float res1, res2, resR;
float mul1, mul2, resM;
float div1, div2, resD;
int fac1, num, i, resF;
float raiz1, raiz2, rad, tot, euler, resE, e, cuad1, resC;
int valor=2;
int abso, resA, op = 0;
float cubo, resCU;
float expo1,expo2,resEx,aux,i2,inc;
float pi, nume1, resP;
float seno, numerito, resSS, resSS2;
float coseno, numerito1, resSC, resSC2;
float tangente, numerito2, resST, resST2;
float logaritmo, numerito3, resLG , resLG2;

enum opc
{
    OPC_SUMA = 1,
    OPC_RESTA,
    OPC_MUL,
    OPC_DIV,
    OPC_FACT,
    OPC_RAIZ,
    OPC_EULER,
    OPC_CUADR,
    OPC_CUBO,
    OPC_POTEN,
    OPC_PI,
    OPC_SEN,
    OPC_COS,
    OPC_TAN,
    OPC_LOG,
    OPC_SALIR
};

bool isOK(string x)
{

    while(opc.size() > 1 && x[0] == ' ')
        x.erase(x.begin());

    int ini = x[0] == '-';

    for(unsigned int i = ini ; i < x.size() ; ++i)
        if('0' <= x[i] && x[i] <= '9')
            continue;
        else
            return false;

    op = stoi(opc);
    return true;

}

void SetColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    } //End
    return;
}

void gotoxy(int x, int y)
{
    HANDLE hcon= GetStdHandle(STD_OUTPUT_HANDLE); COORD dwPos;
    dwPos.X = x; dwPos.Y = y;
    SetConsoleCursorPosition(hcon,dwPos);
}

void marcoGeneral()
{
    for(int i = 10, j = 4, k = 94 ; i < 53 ; ++i, ++j, --k)
    {
        gotoxy(i, 3); printf("%c", 196);
        gotoxy(i, 7); printf("%c", 196);
        gotoxy(i, 30); printf("%c", 196);

        gotoxy(k, 3); printf("%c", 196);
        gotoxy(k, 7); printf("%c", 196);
        gotoxy(k, 30); printf("%c", 196);

        if (j < 30){
            gotoxy(9, j); printf("%c", 179);
            gotoxy(94, j); printf("%c", 179);
        }
    }

    SetColor(4);
    gotoxy(9, 3); printf("%c", 218);//Esquina superior izquierda
    gotoxy(9, 7); printf("%c", 195);//T superior izquierda
    gotoxy(9, 30); printf("%c", 192);//Esquina inferior izquirda
    gotoxy(94, 3); printf("%c", 191);//Esquina superior derecha
    gotoxy(94, 7); printf("%c", 180);//T superior derecha
    gotoxy(94, 30); printf("%c", 217);//Esquina inferior derecha

    SetColor(4);

    gotoxy(43, 5); printf("Generaci%cn de c%cdigo",162,162);

    SetColor(0);

}

void menu()
{
    SetColor(6);

    gotoxy(42, 8); printf("Calculadora cient%cfica",161);

    SetColor(0);

    for(int i = 12, j = 11 ; i < 92 ; ++i, ++j)
    {
        gotoxy(i, 10); printf("%c",196);
        gotoxy(i, 14); printf("%c", 196);
        gotoxy(i, 18); printf("%c", 196);
        gotoxy(i, 22); printf("%c", 196);
        gotoxy(i, 26); printf("%c", 196);

        if(j < 26){
            //Columnas laterales
            gotoxy(11, j); printf("%c", 179);
            gotoxy(92, j); printf("%c", 179);

            //Intersecciones
            gotoxy(31, j); printf("%c", 179);
            gotoxy(51, j); printf("%c", 179);
            gotoxy(72, j); printf("%c", 179);
        }
    }

    SetColor(2);
    gotoxy(11, 10); printf("%c", 218);//Esquina superior izquierda
    gotoxy(92, 10); printf("%c", 191);//Esquina superior derecha
    gotoxy(11, 26); printf("%c", 192);//Esquina inferior izquierda
    gotoxy(92, 26); printf("%c", 217);//Esquina inferior derecha

    //Intersecciones
    gotoxy(31,14); printf("%c", 197);
    gotoxy(51,14); printf("%c", 197);
    gotoxy(72,14); printf("%c", 197);

    gotoxy(31,18); printf("%c", 197);
    gotoxy(51,18); printf("%c", 197);
    gotoxy(72,18); printf("%c", 197);

    gotoxy(31, 22); printf("%c", 197);
    gotoxy(51, 22); printf("%c", 197);
    gotoxy(72, 22); printf("%c", 197);

    //T's
    //Izquierda
    gotoxy(11,14); printf("%c", 195);
    gotoxy(11,18); printf("%c", 195);
    gotoxy(11,22); printf("%c", 195);
    //Derecha
    gotoxy(92,14); printf("%c", 180);
    gotoxy(92,18); printf("%c", 180);
    gotoxy(92,22); printf("%c", 180);
    //Abajo
    gotoxy(31,26); printf("%c", 193);
    gotoxy(51,26); printf("%c", 193);
    gotoxy(72,26); printf("%c", 193);
    //Arriba
    gotoxy(31,10); printf("%c", 194);
    gotoxy(51,10); printf("%c", 194);
    gotoxy(72,10); printf("%c", 194);

    SetColor(4);
    //Opciones
    gotoxy(18, 12); printf("1. "); SetColor(0); printf("Suma"); SetColor(4);
    gotoxy(37, 12); printf("2. "); SetColor(0); printf("Resta"); SetColor(4);
    gotoxy(53, 12); printf("3. "); SetColor(0); printf("Multiplicaci%cn",162); SetColor(4);
    gotoxy(77, 12); printf("4. "); SetColor(0); printf("Divisi%cn",162); SetColor(4);

    gotoxy(16, 16); printf("5. "); SetColor(0); printf("Factorial"); SetColor(4);
    gotoxy(37, 16); printf("6. "); SetColor(0); printf("Ra%cz",161); SetColor(4);
    gotoxy(57, 16); printf("7. "); SetColor(0); printf("Euler"); SetColor(4);
    gotoxy(77, 16); printf("8. "); SetColor(0); printf("Cuadrado"); SetColor(4);

    gotoxy(18, 20); printf("9. "); SetColor(0); printf("Cubo"); SetColor(4);
    gotoxy(36, 20); printf("10. "); SetColor(0); printf("Potencia"); SetColor(4);
    gotoxy(58, 20); printf("11. "); SetColor(0); printf("PI"); SetColor(4);
    gotoxy(78, 20); printf("12. "); SetColor(0); printf("Seno"); SetColor(4);

    gotoxy(16, 24); printf("13. "); SetColor(0); printf("Coseno"); SetColor(4);
    gotoxy(35, 24); printf("14. "); SetColor(0); printf("Tangente"); SetColor(4);
    gotoxy(54, 24); printf("15. "); SetColor(0); printf("Logaritmo N"); SetColor(4);
    gotoxy(77, 24); printf("16. "); SetColor(0); printf("Salir");

    SetColor(0);

    gotoxy(38, 28); printf("Escoge una opci%cn: ", 162);

}

void limpiar()
{
    for (int i = 11; i < 93 ; ++i)
    {
        for (int k = 8 ; k < 30 ; ++k)
        {
            gotoxy(i,k); printf(" ");
        }
    }
}

void opcInvalida()
{
    for (int i = 57 ; i < 93 ; ++i)
    {
        for (int k = 28 ; k < 30 ; ++k){
            gotoxy(i, k); cout<<" ";
        }
    }
    gotoxy(57, 28); printf("Opci%cn inv%clida", 162, 160);
    gotoxy(57, 29); printf("Ingrese una opci%cn valida", 162);
    Sleep(3000);
    for (int i = 57 ; i < 93 ; ++i)
    {
        for (int k = 28 ; k < 30 ; ++k){
            gotoxy(i, k); cout<<" ";
        }
    }
}

int main()
{
    system("color F0");

    marcoGeneral();

    do
    {
        menu();
        op = 0;
        SetColor(4);
        cout.flush();
        gotoxy(57, 28); cin>>opc;

        if(isOK(opc) && (op > 0 && op < 17))
        {
            if (op != OPC_SALIR){
                limpiar();
                opc = "";
            }
        }
        cin.get();

        switch (op)
        {
            case 1:
                SetColor(0);
                gotoxy(50, 8); printf("Suma");
                gotoxy(35, 12); printf("Ingrese el primer n%cmero: ",163);
                SetColor(4);
                scanf("%f",&sum1);
                SetColor(0);
                gotoxy(35, 14); printf("Ingrese el segundo n%cmero: ",163);
                SetColor(4);
                scanf("%f",&sum2);
                asm volatile("movss _sum1, %xmm0");
                asm volatile("addss _sum2, %xmm0");
                asm volatile("movss %xmm0, _resS");
                SetColor(0);
                gotoxy(43, 16); printf("Resultado: ");
                SetColor(4);
                printf("%.2f \n",resS);
                SetColor(0);
                gotoxy(37, 18); system("pause");
                limpiar();
                break;
            case 2:
                SetColor(0);
                gotoxy(48, 8); printf("Resta");
                gotoxy(35, 12); printf("Ingrese el primer n%cmero: ",163);
                SetColor(4);
                scanf("%f",&res1);
                SetColor(0);
                gotoxy(35, 14); printf("Ingrese el segundo n%cmero: ",163);
                SetColor(4);
                scanf("%f",&res2);
                asm("movss _res1, %xmm0");
                asm("subss _res2, %xmm0");
                asm("movss %xmm0, _resR");
                SetColor(0);
                gotoxy(43, 16); printf("Resultado: ");
                SetColor(4);
                printf("%.2f \n",resR);
                SetColor(0);
                gotoxy(37, 18); system("pause");
                limpiar();
                break;
            case 3:
                SetColor(0);
                gotoxy(46, 8); printf("Multiplicaci%cn",162);
                gotoxy(35, 12); printf("Ingrese el primer n%cmero: ",163);
                SetColor(4);
                scanf("%f",&mul1);
                SetColor(0);
                gotoxy(35, 14); printf("Ingrese el segundo n%cmero: ",163);
                SetColor(4);
                scanf("%f",&mul2);
                asm("movss _mul1, %xmm0");
                asm("mulss _mul2, %xmm0");
                asm("movss %xmm0, _resM");
                SetColor(0);
                gotoxy(43, 16); printf("Resultado: ");
                SetColor(4);
                printf("%.2f \n",resM);
                SetColor(0);
                gotoxy(37, 18); system("pause");
                limpiar();
                break;
            case 4:
                SetColor(0);
                gotoxy(48, 8); printf("Divisi%cn",162);
                gotoxy(35, 12); printf("Ingrese el primer n%cmero: ",163);
                SetColor(4);
                scanf("%f",&div1);
                SetColor(0);
                gotoxy(35, 14); printf("Ingrese el segundo n%cmero: ",163);
                SetColor(4);
                scanf("%f",&div2);
                asm("movss _div1, %xmm0");
                asm("divss _div2, %xmm0");
                asm("movss %xmm0, _resD");
                SetColor(0);
                gotoxy(43, 16); printf("Resultado: ");
                SetColor(4);
                printf("%.2f \n",resD);
                SetColor(0);
                gotoxy(37, 18); system("pause");
                limpiar();
                break;
            case 5:
                SetColor(0);
                gotoxy(48, 8); printf("Factorial");
                gotoxy(35, 11); printf("Ingrese un n%cmero: ",163);
                SetColor(4);
                scanf("%d",&num);
                fac1=1;
                asm("movl _fac1, %eax");
                i=1;
                asm("salto:");
                asm("movl _fac1, %eax");
                asm("movl _num, %ebx");
                asm("imul _i, %eax");
                asm("addl $1, _i");
                asm("movl %eax, _fac1");
                asm("cmpl _i, %ebx");
                asm("jge salto");
                SetColor(0);
                gotoxy(43, 13); printf("Resultado: ");
                SetColor(4);
                printf("%d \n",fac1);
                SetColor(0);
                gotoxy(37, 15); system("pause");
                limpiar();
                break;
            case 6:
                SetColor(0);
                raiz2=1;
                gotoxy(52,8); printf("Ra%cz",161);
                gotoxy(35,11); printf("Ingrese un n%cmero: ",163);
                SetColor(4);
                scanf("%f",&raiz1);
                rad=raiz1, tot=0;
                asm("saltar:");
                tot=rad;
                rad=(raiz1/rad+rad)/valor;
                asm("movl _rad, %eax");
                asm("movl _tot, %ebx");
                asm("cmpl %ebx, %eax");
                asm("movl %eax, _rad");
                asm("jne saltar");
                SetColor(0);
                gotoxy(43,13); printf("Resultado: ");
                SetColor(4);
                printf("%.4f\n", rad);
                SetColor(0);
                gotoxy(37, 15); system("pause");
                limpiar();
                break;
            case 7:
                SetColor(0);
                e=2.718281;
                gotoxy(52,8); printf("Euler");
                gotoxy(35,11); printf("Ingrese un n%cmero: ",163);
                SetColor(4);
                scanf("%f",&euler);
                asm("movss _e, %xmm0");
                asm("movss _euler, %xmm1");
                resE=euler*e;
                asm("mulss %xmm0, %xmm1");
                asm("movss %xmm1, _resE");
                SetColor(0);
                gotoxy(43,13); printf("Resultado: ");
                SetColor(4);
                printf("%lf \n", resE);
                SetColor(0);
                gotoxy(37, 15); system("pause");
                limpiar();
                break;
            case 8:
                SetColor(0);
                gotoxy(52,8); printf("Cuadrado");
                gotoxy(35,11); printf("Ingrese un n%cmero: ",163);
                SetColor(4);
                scanf("%f",&cuad1);
                asm("movss _cuad1, %xmm0");
                asm("mulss _cuad1, %xmm0");
                asm("movss %xmm0, _resC");
                SetColor(0);
                gotoxy(35,13); printf("Resultado: ");
                SetColor(4);
                printf("%.2f \n", resC);
                SetColor(0);
                gotoxy(37, 15); system("pause");
                limpiar();
                break;
            case 9:
                SetColor(0);
                gotoxy(52,8); printf("Cubo");
                gotoxy(35,11); printf("Ingrese un n%cmero: ",163);
                SetColor(4);
                scanf("%f",&cubo);
                asm("movss _cubo, %xmm0");
                asm("mulss _cubo, %xmm0");
                asm("mulss _cubo, %xmm0");
                asm("movss %xmm0, _resCU");
                SetColor(0);
                gotoxy(35,13); printf("Resultado: ");
                SetColor(4);
                printf("%.2f \n", resCU);
                SetColor(0);
                gotoxy(37, 15); system("pause");
                limpiar();
                break;
            case 10:
                SetColor(0);
                aux=1;
                i2=0;
                inc=1;
                gotoxy(52,8); printf("Potencia");
                gotoxy(35,11); printf("Ingrese la base de la potencia: ");
                SetColor(4);
                scanf("%f",&expo1);
                SetColor(0);
                gotoxy(35,13); printf("Dame una potencia: ");
                SetColor(4);
                scanf("%f",&expo2);
                asm("movss _expo1, %xmm0");
                asm("movss _expo2, %xmm2");
                asm("movss _i2, %xmm3");
                asm("saltoto:");
                asm("movss _aux, %xmm1");
                asm("movss _expo1, %xmm0");
                asm("mulss %xmm0, %xmm1");
                asm("movss %xmm1, _aux");
                asm("addss _inc, %xmm3");
                asm("ucomiss %xmm2, %xmm3");
                asm("jg saltoto");
                asm("movss %xmm1, _resEx");
                SetColor(0);
                gotoxy(35,15); printf("Resultado: ");
                SetColor(4);
                printf("%.3f \n", resEx);
                SetColor(0);
                gotoxy(37, 17); system("pause");
                limpiar();
                break;
            case 11:
                SetColor(0);
                pi=3.1416;
                gotoxy(53,8); printf("PI");
                gotoxy(40,11); printf("Ingrese un n%cmero: ",163);
                SetColor(4);
                scanf("%f",&nume1);
                asm("movss _pi, %xmm0");
                asm("movss _nume1, %xmm1");
                asm("mulss %xmm0, %xmm1");
                asm("movss %xmm1, _resP");
                SetColor(0);
                gotoxy(40,13); printf("Resultado: ");
                SetColor(4);
                printf("%.4f \n", resP);
                SetColor(0);
                gotoxy(37, 15); system("pause");
                limpiar();
                break;
            case 12:
                SetColor(0);
                gotoxy(51,8); printf("Seno");
                gotoxy(40,11); printf("Ingrese un n%cmero: ",163);
                SetColor(4);
                scanf("%f",&seno);
                asm("movss _seno, %xmm0");
                resSS2=sin(seno);
                asm volatile("fsin");
                asm("movss %xmm0, _resSS");
                SetColor(0);
                gotoxy(40,13); printf("Resultado: ");
                SetColor(4);
                printf("%.4f \n", resSS2);
                SetColor(0);
                gotoxy(37, 15); system("pause");
                limpiar();
                break;
            case 13:
                SetColor(0);
                gotoxy(50,8); printf("Coseno");
                gotoxy(40,11); printf("Ingrese un n%cmero: ",163);
                SetColor(4);
                scanf("%f",&coseno);
                asm("movss _coseno, %xmm0");
                resSC2=cos(coseno);
                asm volatile("fcos");
                asm("movss %xmm0, _resSC");
                SetColor(0);
                gotoxy(40,13); printf("Resultado: ");
                SetColor(4);
                printf("%.4f \n", resSC2);
                SetColor(0);
                gotoxy(37, 15); system("pause");
                limpiar();
                break;
            case 14:
                SetColor(0);
                gotoxy(49,8); printf("Tangente");
                gotoxy(40,11); printf("Ingrese un n%cmero: ",163);
                SetColor(4);
                scanf("%f",&tangente);
                asm("movss _tangente, %xmm0");
                resST2=tan(tangente);
                asm volatile("fptan");
                asm("movss %xmm0, _resST");
                SetColor(0);
                gotoxy(40,13); printf("Resultado: ");
                SetColor(4);
                printf("%.4f \n", resST2);
                SetColor(0);
                gotoxy(37, 15); system("pause");
                limpiar();
                break;
            case 15:
                SetColor(0);
                gotoxy(45,8); printf("Logaritmo Natural");
                gotoxy(40,11); printf("Ingrese un n%cmero: ",163);
                SetColor(4);
                scanf("%f",&logaritmo);
                asm("movss _logaritmo, %xmm0");
                resLG2=log(logaritmo);
                asm volatile("FYL2X");
                asm("movss %xmm0, _resST");
                SetColor(0);
                gotoxy(40,13); printf("Resultado: ");
                SetColor(4);
                printf("%.4f\n", resLG2);
                SetColor(0);
                gotoxy(37, 15); system("pause");
                limpiar();
                break;
            case 16:
                gotoxy(38, 32); printf("Presiona una tecla para salir...");
                cout<<endl<<endl;
                break;
            default:
                opcInvalida();
                break;
        }
        SetColor(0);
    }while(op != OPC_SALIR);


    return 0;
}
