/* 
Lo unico que rompe el juego es si cuando se espera un input int se ingresa otro tipo de variable, o un char y se ingresa otro tipo

*/

#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

const int tamano= 10;

int longitudBarco1= 5;
int longitudBarco2= 3;

void tiro_errado_frase() {
    srand(time(NULL));
    int num = (rand() % 7) + 1;

    switch (num) {
        case 1:
            cout<<"\nAgua! Pero tranquilo, los peces te lo agradecen.\n";
            break;
        case 2:
            cout<<"\nCasi! Al menos sabes donde no esta el barco.\n";
            break;
        case 3:
            cout<<"\nEse tiro fue directamente al... agua!\n";
            break;
        case 4:
            cout<< "\nTu punteria es perfecta... para evitar barcos!\n";
            break;
        case 5:
            cout<<"\nVaya... que mal tiro...\n";
            break;
        case 6:
            cout<<"\nNada de barcos! Tu disparo fallo.\n";
            break;
        case 7:
            cout<<"\nFallaste! Tu bala esta de excursion submarina.\n";
            break;
    }
}

void tiro_acertado_frase() {
    srand(time(NULL));
    int num = (rand() % 7) + 1;

    switch (num) {
        case 1:
            cout<<"\nPerfecto! Barco enemigo tocado!\n";
            break;
        case 2:
            cout<<"\nAcierto! Ese barco esta en problemas!\n";
            break;
        case 3:
            cout<<"\nLe diste! Barco en llamas!\n";
            break;
        case 4:
            cout<<"\nAcierto! Has dado en un blanco!\n";
            break;
        case 5:
            cout<<"\nImpacto! Barco enemigo tocado!\n";
            break;
        case 6:
            cout<<"\nGolpe maestro! Directo al objetivo!\n";
            break;
        case 7:
            cout<<"\nGolpe directo! El enemigo esta en problemas!\n";
            break;
    }
}

void usuario_gana_juego() {
    srand(time(NULL));
    int num = (rand() % 4) + 1;

    switch (num) {
        case 1:
            cout << "\n¡Felicidades! Has ganado el juego. ¡Los mares estan a tus pies y los peces te saludan como su nuevo rey!\n";
            break;
        case 2:
            cout << "\n¡Victoria! Has derrotado al enemigo. ¡Tus marineros están celebrando y ya estan escribiendo canciones sobre ti!\n";
            break;
        case 3:
            cout << "\n¡Enhorabuena! Has ganado el juego. ¡Las gaviotas estan formando tu nombre en el cielo!\n";
            break;
        case 4:
            cout << "\n¡Eres el campeon! Has hundido la flota enemiga. ¡Las ballenas estan organizando un desfile en tu honor!\n";
            break;
    }
}

void bot_gana_juego() {
    srand(time(NULL));
    int num = (rand() % 4) + 1;

    switch (num) {
        case 1:
            cout << "\n¡Oh no! El bot ha ganado el juego. ¡Tus marineros están buscando un nuevo capitán en la guía telefonica!\n";
            break;
        case 2:
            cout << "\n¡Derrota! El bot ha hundido toda tu flota. ¡Parece que tendrás que tomar clases de navegacion en linea!\n";
            break;
        case 3:
            cout << "\n¡El bot ha ganado! ¡Tus marineros están considerando un motin y hacer al bot su lider!\n";
            break;
        case 4:
            cout << "\n¡Perdiste! El bot ha tomado el control del mar. ¡Los delfines están riéndose de ti!\n";
            break;
    }
}

/////hasta aca texto


void mostrarMatriz(char matriz[tamano][tamano], bool ocultar){
    char letras[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int numeros[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //encabezado numeros
    cout <<"  ";
    for (int i = 0; i < tamano; i++){
        cout<<numeros[i] <<" ";
    }
    cout<<"\n";

    for (int i = 0; i < tamano; i++){
        cout<<letras[i] <<" ";
        for (int j = 0; j < tamano; j++) {
            if(ocultar && matriz[i][j] == 'B'){
                cout <<'X' <<" "; // Ocultar barcos de la ,cuando se pasa true todo x
            }else{
                cout <<matriz[i][j] <<" ";
            }
        }
        cout <<"\n";
    }
}


// barco afuera de la matriz o sobre otro
bool esPosicionValida(char matriz[tamano][tamano], int fila, int columna, int longitud, string direccion){

    if(direccion =="arriba") {//las columnas serian constantes varian las filas
        if(fila - longitud +1 < 0) return false;//si el barco ocupa una fila y esta en la posicion 0 se permite
        for (int i = 0; i < longitud; i++) {
            if(matriz[fila - i][columna] != 'X') return false; //chequeamos que solo se pueda poner un barco donde hay x (-1 porque sube en las filas de la matriz)
        }

    }else if(direccion== "abajo"){
        if(fila + longitud > tamano) return false;//se entiende
        for (int i = 0; i < longitud; i++) {
            if(matriz[fila + i][columna] !='X') return false;
        }

        //las columnas varian filas constantes
    }else if(direccion == "izquierda"){
        if(columna - longitud +1< 0) return false;
        for (int i = 0; i < longitud; i++) {
            if(matriz[fila][columna - i] != 'X') return false; //chequea hacia atras
        }

    } else if(direccion == "derecha"){
        if(columna + longitud > tamano) return false;
        for (int i = 0; i < longitud; i++){
            if(matriz[fila][columna + i] != 'X') return false;
        }
    }else{
        cout<<"Direccion no valida";
        return false; 
    }
    return true;//si llega aca significa que no se cumple ninguna condicion de invalidacion
}



void colocarBarco(char matriz[tamano][tamano], int fila, int columna, int longitud, string direccion) {
    if(direccion == "arriba") {
        for (int i = 0; i < longitud; i++) {
            matriz[fila - i][columna] = 'B';
        }
    
    }else if(direccion== "abajo"){

        for (int i = 0; i < longitud; i++){
            matriz[fila + i][columna] = 'B';
        }

    }else if(direccion== "izquierda") {
        
        for (int i = 0; i < longitud; i++){
            matriz[fila][columna - i]= 'B';
        }

    }else if(direccion== "derecha"){

        for (int i = 0; i < longitud; i++){
            matriz[fila][columna + i] = 'B';
        }
    }
}

void letrasAnumeros(char filaChar,int& fila ){
    char letras[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
            
            for (int i = 0; i < 10; ++i){
                if(filaChar == letras[i]){
                    fila = i;
                    break;
                }
            }
}


// input del usuario y posicionar sus barcos
void posicionarBarcosUsuario(char matriz[tamano][tamano]){
    int fila,columna;
    string direccion;

    for (int i = 0; i < 2; i++){//2 es la cantidad de barcos
    
        int longitud;//seleccionar la longitud del barco que se va a posicionar, la primera vez 1 segunda 2
        if(i == 0){
            longitud=longitudBarco1;
        }else{
            longitud=longitudBarco2;
            } // longitudes definidas como constantes

        bool posicionValida = false;//para q se ejecute aunquesea una vez
        
        while (posicionValida==false){

            cout<<"\nPosicionemos el barco de "<<longitud<<" espacios";
            
            bool columnaValida =false;
            while (!columnaValida){
                cout <<"\nSelecciona la columna (1-10): ";
                cin >> columna;
                if(columna >= 1 && columna <= 10){
                    columnaValida= true;

                }else{
                    cout <<"Columna no valida, ingreesa de nuevo.";
                }
            }
            columna--; // ajustar índice de columna (0-9)
             
           bool filaValida =false;
            while (!filaValida){
                char filaChar;
                cout<<"\nSelecciona la fila (A-J): ";
                cin>> filaChar;
                if(filaChar >= 'A' && filaChar <= 'J') {
                    letrasAnumeros(filaChar, fila);
                    filaValida = true;
                }else {
                    cout <<"Fila no valida, ingresa de nuevo.";
                }
            }

            cout<<"Ingrese la direccion (arriba, abajo, izquierda, derecha): ";
            cin>> direccion;

            if(esPosicionValida(matriz, fila, columna, longitud, direccion)){
                
                colocarBarco(matriz, fila, columna, longitud, direccion);
                posicionValida = true;
            
            }else{
                Sleep(1000);
                cout<<"\nPosicion no valida, intente de nuevo." <<"\n";
            }
        }

        mostrarMatriz(matriz, false); //(ocultar = false)
    }
}


void generarMatrizComputadora(char matriz[tamano][tamano]){
    int fila, columna;
    string direccion;
    for (int i = 0; i < 2; i++){
        int longitud;//seleccionar la longitud del barco que se va a posicionar, la primera vez 1 segunda 2
        
        if(i == 0){
            longitud=longitudBarco1;
        
        }else{
            longitud=longitudBarco2;
            }

        bool posicionValida = false;
        while (posicionValida==false) {
            fila= rand() % tamano; //como rand genera cualquier numero para obtener uno entre 0 y 9 lo dividimos en 10
            columna= rand() % tamano;
            int dir= rand() % 4; //para a direccion 
            switch (dir){
                case 0: direccion="arriba";
                    break; 
                case 1: direccion="abajo";
                    break;
                case 2: direccion= "izquierda";
                    break;
                case 3: direccion= "derecha";
                    break;
            }
            
            if(esPosicionValida(matriz, fila, columna, longitud, direccion)){
                cout<<"\nEl bot esta eligiendo...";
                Sleep(2000);
                colocarBarco(matriz, fila, columna, longitud, direccion);
                posicionValida = true;
            }
        }
    }
}


void disparoUsuario(char matrizComputadora[tamano][tamano]){
    int fila, columna;

    bool columnaValida = false;
    while (!columnaValida){

        cout<<"Ingrese la columna (1-10) para disparar: ";
        cin>> columna;
        
        if(columna >= 1 && columna <= 10) {////////////////////////////////////////////////////////////poner aca && columna==x
            columnaValida = true;
        }else{ 
            cout<<"Columna no válida, intente de nuevo.";
        }
    }

    columna--; // ajustar índice de columna (0-9)

    // validar fila
    bool filaValida = false;
    char letras[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    while (!filaValida){
        char filaChar;
        cout<<"Ingrese la fila (A-J) para disparar: ";
        cin>> filaChar;
            
        
        for (int i=0; i<10;++i){
            if(filaChar==letras[i]){
                filaValida=true;
                letrasAnumeros(filaChar, fila);
                break;
            }else{
                filaValida=false;
            }
        } 
    }  
        if(!filaValida){
            cout <<"Fila no válida, intente de nuevo.";
        }


    if(matrizComputadora[fila][columna] == 'B'){
        matrizComputadora[fila][columna] = 'H'; //impacto en un barco
       
        tiro_acertado_frase();
                
    }else{
        matrizComputadora[fila][columna] = 'A'; //agua
        
        tiro_errado_frase();
    }
}

void disparobot(char matrizUsuario[tamano][tamano]) {
    
    int fila,columna,posibilidad;    

    fila = rand() % tamano;
    columna = rand() % tamano;

    
    char letras[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout<<"\nEl bot dispara en "<<letras[fila]<<numeros[columna] <<"\n";


    if(matrizUsuario[fila][columna] == 'B'){

        matrizUsuario[fila][columna] = 'H'; 
        cout <<"El bot te pego en un barco:\n";

    }else{
        matrizUsuario[fila][columna] = 'A'; 
        cout <<"El bot la erro:\n";        

    }
    //Sleep(2000);
}


bool hayBarcosRestantes(char matriz[tamano][tamano]) {
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            if(matriz[i][j] == 'B') {
                return true;
            }
        }
    }
    return false;
}

//-------------------------------------------------------------------
int main(){
    // inicializar la semilla para el generador de números aleatorios
    srand(time(0));

    // inicializar matrices
    char matrizUsuario[tamano][tamano];
    char matrizComputadora[tamano][tamano];

    // llenar las matrices con 'X'
    for(int i = 0; i < tamano; i++){
        for (int j = 0; j < tamano; j++) {
            matrizUsuario[i][j] = 'X';
            matrizComputadora[i][j] = 'X';
        }
    }
    Sleep(1000);
    cout<<"\n\nVamos a jugar contra el bot!!\n";
    Sleep(2000);

    string empezar;
    cout<<"Tene en cuenta que en los tableros\nA = Agua\nB = Barco\nH = Hundido (esa posicion del barco)\nX = Incognita\nRespeta mayusculas y minusculas\n\nIngresa 'YA' cuando quieras empezar: ";
    cin>>empezar;

    if(empezar!= "YA"){
        return 0;
    }
    Sleep(1000);
    cout << "\nElegi la dificultad (1 = Facil, 2 = Dificil): ";
    int dificultad;
    cin >> dificultad;

    if (dificultad == 1) {
        longitudBarco1 = 8;
        longitudBarco2 = 8;
        cout<<"\nTenes 2 barcos de 8";
    } else if (dificultad == 2) {
        longitudBarco1 = 5;
        longitudBarco2 = 3;
        cout<<"\nTenes 1 barco de 5 y uno de 3";
    } else {
        cout << "\nOpcion de dificultad no válida, se selecciona dificcultad predeterminada (dififcil)\n";
    }

    Sleep(1000);

    cout<<"\nTu tablero:" <<"\n";
    mostrarMatriz(matrizUsuario, false);

    posicionarBarcosUsuario(matrizUsuario);

    generarMatrizComputadora(matrizComputadora);

    cout <<"\n\nA JUGAR";
    Sleep(2000);
    cout<<"\nTablero de la computadora:" <<"\n";
    mostrarMatriz(matrizComputadora, true);//true se ocultan los barcos

    // loop del juego
    while(hayBarcosRestantes(matrizUsuario) && hayBarcosRestantes(matrizComputadora)){
    
        cout <<"\nTurno del usuario\n";
        disparoUsuario(matrizComputadora);
        Sleep(1000);
        cout<<"\n";
        mostrarMatriz(matrizComputadora, true);

        //para saber si gano el usuario
        if(!hayBarcosRestantes(matrizComputadora)){
            cout<<"GANASTE\n";
            usuario_gana_juego();
            break;
        }
        Sleep(2000);
        cout<<"\nTurno de la computadora\n";
        Sleep(1500);
        disparobot(matrizUsuario);
        mostrarMatriz(matrizUsuario, false);

        //si la computadora ganó
        if(!hayBarcosRestantes(matrizUsuario)){
            cout<<"PERDISTE\n";
            bot_gana_juego();
            break;
        }
    }

    return 0;
}
