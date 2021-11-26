/* Se utiliza el comando "gcc" para compilar el siguiente programa. */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

//Limpiar pantalla.
//Windows 
#define CLEAR() system("CLS")
//UNIX
//#define CLEAR() system("clear")

void jugar_partida_nueva(int minas, int filas, int columnas, char **mapa_base, char **tablero);

int main(int argc, char* argv[])
{
    int entrada;
    do
    {
        system("cls");
        printf("\n");
        printf("\n   |_|_|_|     |_|   |_|    |_|_|_|    |_|_|_|     |_|_|     |_|_   _|_|   |_|_|_|   |_|_     |_|     |_|_|      |_|_|_| ");
        printf("\n   |_|   |_|   |_|   |_|   |_|        |_|        |_|   |_|   |_|_|_|_|_|     |_|     |_||_|_  |_|   |_|   |_|   |_|  ");
        printf("\n   |_|_|_|     |_|   |_|    |_|_|     |_|        |_|_|_|_|   |_| |_| |_|     |_|     |_|  |_|_|_|   |_|_|_|_|     |_|_|");
        printf("\n   |_|   |_|   |_|___|_|        |_|   |_|        |_|   |_|   |_|     |_|    _|_|_    |_|    |_|_|   |_|   |_|         |_|");
        printf("\n   |_|_|_|       |_|_|     |_|_|_|     |_|_|_|   |_|   |_|   |_|     |_|   |_|_|_|   |_|      |_|   |_|   |_|    |_|_|_| \n");
        printf("\t\t\t By - Gaston Emanuel Prat\n");
        printf("\n\n\t\t[1] JUGAR.");
        printf("\n\t\t[2] Salir.\n");
        printf("\t\t Ingrese una opcion: ");
        scanf("%d", &entrada);
        
        switch (entrada)
        {
        case 1:
            srand(time(NULL));
            CLEAR();
            int filas, columnas, totalminas;
            printf("\nIngrese un valor para las Filas y Columnas del mapa a crear.\n");
            printf("Limite de Columnas: de 4 a 26\n");
            printf("Limite de Filas: de 2 a 9\n");
            printf("Cuantas Columnas tendra? ");
            scanf("%d", &columnas);
            while (columnas>26 || columnas<4)
            {
                printf("El valor no es correcto, debe estar entre 4 y 26.\n");
                printf("Ingrese el valor de Columnas nuevamente: ");
                scanf("%d", &columnas);
            }
            printf("Y cuantas Filas? ");
            scanf("%d", &filas);
            while (filas>9 || filas<2)
            {
                printf("El valor no es correcto, debe estar entre 2 y 9.\n");
                printf("Ingrese el valor de Filas nuevamente: ");
                scanf("%d", &filas);
            }
            totalminas = (filas*columnas)/7;
            char **mapa_base;
            mapa_base = (char **) malloc(sizeof(char*)*filas);
            for(int i=0;i<filas;i++)
            {
                mapa_base[i] = (char *) malloc(sizeof(char)*columnas);
            }
            if(mapa_base == NULL)
            {
                printf("No se a podido reservar espacio en memoria.\n");
                return 0;
            }
            
            char **tablero;
            tablero = (char **) malloc(sizeof(char*)*filas);
            for(int i=0;i<filas;i++)
            {
                tablero[i] = (char *) malloc(sizeof(char)*columnas);
            }
            if(tablero == NULL)
            {
                printf("No se a podido reservar espacio en memoria.\n");
                return 0;
            }
            for(int i=0;i<filas;i++)
            {
                for(int j=0;j<columnas;j++)
                {
                    tablero[i][j] = '/';
                }
                
            }
            printf("\nSe crearan %d minas de forma aleatoria.\n", totalminas);

            rellenar_mapa_base(filas, columnas, mapa_base);

            colocar_minas(filas, columnas, totalminas, mapa_base);
            printf("Las minas se crearon correctamente\n");
            colocar_contadores(filas, columnas, mapa_base);
            jugar_partida_nueva(totalminas, filas, columnas, mapa_base, tablero);

            free(mapa_base);
            free(tablero);
            break;
        default:
            break;
        }

    } while(entrada !=2);
    CLEAR();
    return 0;
}

void jugar_partida_nueva(int minas, int filas,int columnas, char **mapa_base, char **tablero)
{
    
    int posc, posf, op, perdio = 0;
    char col;
    int cantbanderas = minas;
    int gano = 0;
    int banderacolocada = 0;
    do
    {
        CLEAR();
        printf("\tTotal de minas: %d\tTotal de Banderas: %d\n", minas, cantbanderas);
        
        imprimir_mapa(filas, columnas, tablero);
        printf("\n\t[1] Jugar Turno.\t[2] Poner Bandera.\t[3] Quitar Bandera.\n");
        printf("\t\t[4] Salir.\n");
        printf("\t\t\tIngrese Opcion: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\tPara jugar debe escribir la FILA y luego la COLUMNA.\n");
            printf("\tEjemplo->\tFILA: 2\tCOLUMNA: C\n\n");
            printf("\tFILA: ");
            scanf("%d", &posf);
            if(posf<1 || posf>filas)
            {
                printf("Esa posisicon no existe, intente otra vez.\n");
                system("pause");
                break;
            }
            posf -= 1;
            printf("\tCOLUMNA: ");
            scanf("%c", &col);
            scanf("%c", &col);
            if(col >= 97)
            {
                posc = col;
                posc -= 97;
            }
            else
            {
                posc = col;
                posc -= 65;
            }
            if(posc<0 || posc >=columnas)
            {
                printf("Esa posisicon no existe, intente otra vez.\n");
                system("pause");
                break;
            }
            perdio = mostrar_campo(filas, columnas, posf, posc, mapa_base, tablero);
            if(perdio == 1)
            {
                imprimir_minas(filas, columnas, mapa_base, tablero);
                juego_perdido(filas, columnas, tablero);
                perdio = 0;
            }
            break;
        case 2:
            if(cantbanderas == 0)
            {
                printf("No hay mas bandera para colocar!.\n");
                system("pause");
                break;
            }
            printf("\tPara colocar una bandera debe escribir FILA y COLUMNA.\n");
            printf("\tEjemplo->\tFILA: 2\tCOLUMNA: C\n\n");
            printf("\tFILA: ");
            scanf("%d", &posf);
            if(posf<1 || posf>filas)
            {
                printf("Esa posisicon no existe, intente otra vez.\n");
                system("pause");
                break;
            }
            posf -= 1;
            printf("\tCOLUMNA: ");
            scanf("%c", &col);
            scanf("%c", &col);
            if(col >= 97)
            {
                posc = col;
                posc -= 97;
            }
            else
            {
                posc = col;
                posc -= 65;
            }
            if(posc<0 || posc >=columnas)
            {
                printf("Esa posisicon no existe, intente otra vez.\n");
                system("pause");
                break;
            }
            banderacolocada = poner_bandera(posc, posf, filas, columnas, tablero);
            if(banderacolocada == 1)
            {
                cantbanderas -= 1;
                gano = revisar_partida(minas, filas, columnas, tablero, mapa_base);
                if(gano == 1)
                {
                    copia_mapa_ganador(filas, columnas, tablero, mapa_base);
                    juego_ganado(filas, columnas, tablero);
                }
                break;
            }
            else
            {
                printf("No se puede colocar una bandera en esa posicion.\n");
                system("pause");
                break;
            }
        case 3:
            if(cantbanderas == minas)
            {
                printf("No hay banderas para quitar!!!\n");
                system("pause");
                break;
            }
            printf("\tPara quitar una bandera debe escribir FILA y COLUMNA.\n");
            printf("\tEjemplo->\tFILA: 2\tCOLUMNA: C\n\n");
            printf("\tFILA: ");
            scanf("%d", &posf);
            if(posf<1 || posf>filas)
            {
                printf("Esa posisicon no existe, intente otra vez.\n");
                system("pause");
                break;
            }
            posf -= 1;
            printf("\tCOLUMNA: ");
            scanf("%c", &col);
            scanf("%c", &col);
            if(col >= 97)
            {
                posc = col;
                posc -= 97;
            }
            else
            {
                posc = col;
                posc -= 65;
            }
            if(posc<0 || posc >=columnas)
            {
                printf("Esa posisicon no existe, intente otra vez.\n");
                system("pause");
                break;
            }
            int banderaquitada = quitar_bandera(posf, posc, filas, columnas, tablero);
            if(banderaquitada == 0)
            {
                printf("No hay una bandera para quitar en esa posicion.\n");
                system("pause");
                break;
            }
            cantbanderas++;
            break;
        default:
            break;
        }
    } while(op != 4);

    if(op == 4)
    {
        for(int i=0;i<filas;i++)
        {
            for(int j=0;j<columnas;j++)
            {
                tablero[i][j] = '/';
            }
        }
    }
    
}