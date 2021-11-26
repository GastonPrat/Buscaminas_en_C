#include <stdio.h>
#include "funciones.h"

void rellenar_mapa_base(int filas, int columnas, char **tablero)
{
    for(int i=0;i<filas;i++)
    {
        for(int j=0;j<columnas;j++)
        {
            tablero[i][j] = '0';
        }
        
    }
}

void colocar_minas(int filas, int columnas, int minas, char **tablero)
{
    int posx, posy, i = 0;
    do
    {
        i++;
        posx = 0 + rand() % (filas);
        posy = 0 + rand() % (columnas);
        if(tablero[posx][posy] == 'X')
        {
            i--;
        }
        else
        {
            tablero[posx][posy] = 'X';
        }
        
    }while(i<minas);
}

void colocar_contadores(int filas, int columnas, char **tablero)
{
    int i, j, k, l, cont;
    int x = filas-1;
    int y = columnas-1;
    for(i=1;i<x;i++)//centro del tablero
    {
        for(j=1;j<y;j++)
        {
            if(tablero[i][j] != 88)
            {
                cont = 48;
                for(k=-1;k<=1;k++)
                {
                    for(l=-1;l<=1;l++)
                    {
                        if(tablero[i+k][j+l] == 88)
                        {
                            cont++;
                        }
                    }
                }
                tablero[i][j] = cont;
            }
        }
    }
    if(tablero[0][0] != 88)//esquina superior izquierda
    {
        cont = 48;
        for(k=0;k<=1;k++)
        {
            for(l=0;l<=1;l++)
            {
                if(tablero[k][l] == 88)
                {
                    cont++;
                }
            }
        }
        tablero[0][0] = cont;
    }
    if(tablero[x][0] != 88)//esquina inferior izquierda
    {
        cont = 48;
        for(k=-1;k<=0;k++)
        {
            for(l=0;l<=1;l++)
            {
                if(tablero[x+k][l] == 88)
                {
                    cont++;
                }
            }
        }
        tablero[x][0] = cont;
    }
    if(tablero[0][y] != 88)//esquina superior derecha
    {
        cont = 48;
        for(k=0;k<=1;k++)
        {
            for(l=-1;l<=0;l++)
            {
                if(tablero[k][y+l] == 88)
                {
                    cont++;
                }
            }
        }
        tablero[0][y] = cont;
    }
    if(tablero[x][y] != 88)//esquina inferior derecha
    {
        cont = 48;
        for(k=-1;k<=0;k++)
        {
            for(l=-1;l<=0;l++)
            {
                if(tablero[x+k][y+l] == 88)
                {
                    cont++;
                }
            }
        }
        tablero[x][y] = cont;
    }
    for(j=1;j<y;j++)//barra superior
    {
        i=0;
        if(tablero[i][j] != 88)
        {
            cont = 48;
            for(k=0;k<=1;k++)
            {
                for(l=-1;l<=1;l++)
                {
                    if(tablero[i+k][j+l] == 88)
                    {
                        cont++;
                    }
                }
            }
            tablero[i][j] = cont;
        }
    }
    for(j=1;j<y;j++)//barra superior
    {
        i=x;
        if(tablero[i][j] != 88)
        {
            cont = 48;
            for(k=-1;k<=0;k++)
            {
                for(l=-1;l<=1;l++)
                {
                    if(tablero[i+k][j+l] == 88)
                    {
                        cont++;
                    }
                }
            }
            tablero[i][j] = cont;
        }
    }
    for(i=1;i<x;i++)//barra ixquierda
    {
        j=0;
        if(tablero[i][j] != 88)
        {
            cont = 48;
            for(k=-1;k<=1;k++)
            {
                for(l=0;l<=1;l++)
                {
                    if(tablero[i+k][j+l] == 88)
                    {
                        cont++;
                    }
                }
            }
            tablero[i][j] = cont;
        }
    }
    for(i=1;i<x;i++)//barra derecha
    {
        j=y;
        if(tablero[i][j] != 88)
        {
            cont = 48;
            for(k=-1;k<=1;k++)
            {
                for(l=-1;l<=0;l++)
                {
                    if(tablero[i+k][j+l] == 88)
                    {
                        cont++;
                    }
                }
            }
            tablero[i][j] = cont;
        }
    }



    for(i=0;i<filas;i++)//poner espacios en los lugares lejanos a las minas
    {
        for(j=0;j<columnas;j++)
        {
            if(tablero[i][j] == 48)
            {
                tablero[i][j] = ' ';
            }
        }
        
    }
}

void imprimir_mapa(int filas, int columnas, char **tablero)
{
    int i, j;
    char letra = 'A';
    int largo = filas*columnas;
    printf("\n    ");
    for(i=0;i<columnas;i++)
    {
        printf(" %c  ", letra+i);
    }
    printf("\n   %c",201); 
    for(i=0;i<columnas;i++)
    {
        printf("%c%c%c%c",205,205,205,203);
    }
    printf("\b%c\n",187);
    for(i=0;i<filas-1;i++)
    {
        printf("  %d%c", i+1, 186);
        for(j=0;j<columnas;j++)
        {
            if(tablero[i][j] == 47)
            {
                COLOR_VERDE;
                printf(" %c", tablero[i][j]);
            }
            if(tablero[i][j] == 32)
            {
                COLOR_NORMAL;
                printf(" %c", tablero[i][j]);
            }
            if(tablero[i][j] == 88)
            {
                COLOR_ROJO;
                printf(" %c", tablero[i][j]);
            }
            if(tablero[i][j] == 80)
            {
                COLOR_AZUL;
                printf(" %c", tablero[i][j]);
            }
            if(tablero[i][j] >= 49 && tablero[i][j] <= 57)
            {
                COLOR_AMARILLO;
                printf(" %c", tablero[i][j]);
            }
            
            COLOR_NORMAL;
            printf(" %c", 186);
        }
        printf("\n   %c", 204);
        for(j=0;j<columnas-1;j++)
        {
            printf("%c%c%c%c",205,205,205,206);
        }
        printf("%c%c%c%c\n",205,205,205,185);
    }
    
    printf("  %d%c", i+1, 186);
    for(j=0;j<columnas;j++)
    {
        if(tablero[i][j] == 47)
        {
            COLOR_VERDE;
            printf(" %c", tablero[i][j]);
        }
        if(tablero[i][j] == 32)
        {
            COLOR_NORMAL;
            printf(" %c", tablero[i][j]);
        }
        if(tablero[i][j] == 88)
        {
            COLOR_ROJO;
            printf(" %c", tablero[i][j]);
        }
        if(tablero[i][j] == 80)
        {
            COLOR_AZUL;
            printf(" %c", tablero[i][j]);
        }
        if(tablero[i][j] >= 49 && tablero[i][j] <= 57)
        {
            COLOR_AMARILLO;
            printf(" %c", tablero[i][j]);
        }
        COLOR_NORMAL;
        printf(" %c", 186);
    }
    printf("\n   %c", 200);
    for(j=0;j<columnas-1;j++)
        {
            printf("%c%c%c%c",205,205,205,202);
        }
        printf("%c%c%c%c\n",205,205,205,188);
}

void guardar_mapa(int filas, int columnas, char **tablero_base)
{
    int i, j;
    FILE *mapa;
    mapa = fopen("mapagenerado.txt", "w");

    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            fprintf(mapa, "%c", tablero_base[i][j]);
        }
        if(i<filas-1)
        {
            fprintf(mapa, "\n");
        }
        
    }
    fclose(mapa);

}

int mostrar_campo(int filas, int columnas, int posf, int posc, char **mapa_base, char **tablero)
{
    int res, i, j, k, l;
    if(mapa_base[posf][posc] == 'X')
    {
        res = 1;
        return res;            
    }
    
    if(posc == 0)
    {
        if(posf == 0)
        {
            for(k=0;k<=1;k++)
            {
                for(l=0;l<=1;l++)
                {
                    if(mapa_base[k][l] != 88)
                    {
                        tablero[k][l] = mapa_base[k][l];
                    }
                }
            }
            res = 0;
            return res;
        }
        else if(posf == filas-1)
        {
            for(k=-1;k<=0;k++)
            {
                for(l=0;l<=1;l++)
                {
                    if(mapa_base[(filas-1)+k][l] != 88)
                    {
                        tablero[(filas-1)+k][l] = mapa_base[(filas-1)+k][l];
                    }
                }
            }
        }
        else
        {
            for(k=-1;k<=1;k++)
            {
                for(l=0;l<=1;l++)
                {
                    if(mapa_base[posf+k][l] != 88)
                    {
                        tablero[posf+k][l] = mapa_base[posf+k][l];
                    }
                }
            }
        }
    }
    else if(posc == columnas-1)
    {
        if(posf == 0)
        {
            for(k=0;k<=1;k++)
            {
                for(l=-1;l<=0;l++)
                {
                    if(mapa_base[k][posc+l] != 88)
                    {
                        tablero[k][posc+l] = mapa_base[k][posc+l];
                    }
                }
            }
            res = 0;
            return res;
        }
        else if(posf == filas-1)
        {
            for(k=-1;k<=0;k++)
            {
                for(l=-1;l<=0;l++)
                {
                    if(mapa_base[posf+k][posc+l] != 88)
                    {
                        tablero[posf+k][posc+l] = mapa_base[(filas-1)+k][posc+l];
                    }
                }
            }
        }
        else
        {
            for(k=-1;k<=1;k++)
            {
                for(l=-1;l<=0;l++)
                {
                    if(mapa_base[posf+k][posc+l] != 88)
                    {
                        tablero[posf+k][posc+l] = mapa_base[posf+k][posc+l];
                    }
                }
            }
        }
    }
    if(posf == 0)
    {
        printf("USANDO LA FUNCION CORRECTA\n");
        for(k=0;k<=1;k++)
        {
            for(l=-1;l<=1;l++)
            {
                if(mapa_base[posf+k][posc+l] != 88)
                {
                    tablero[posf+k][posc+l] = mapa_base[posf+k][posc+l];
                }
            }
        }
        printf("LA COMPLETO\n");
    }
    else if(posf == filas-1)
    {
        for(k=-1;k<=0;k++)
        {
            for(l=-1;l<=1;l++)
            {
                if(mapa_base[posf+k][posc+l] != 88)
                {
                    tablero[posf+k][posc+l] = mapa_base[posf+k][posc+l];
                }
            }
        }
    }
    else
    {
        for(k=-1;k<=1;k++)
        {
            for(l=-1;l<=1;l++)
            {
                if(mapa_base[posf+k][posc+l] != 88)
                {
                    tablero[posf+k][posc+l] = mapa_base[posf+k][posc+l];
                }
            }
        }
    }
}

void imprimir_minas(int filas, int  columnas, char **mapa_base, char **tablero)
{
    int i, j;
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            if(mapa_base[i][j] == 'X')
            {
                tablero[i][j] = 'X';
            }
        }
        
    }
}
void juego_perdido(int filas, int columnas, char **tablero)
{
    system("cls");
    printf("\n");
    imprimir_mapa(filas, columnas, tablero);
    printf("\tJuego Perdido, intenta nuevamente.\n");
    system("pause");
    int i, j;
    for(int i=0;i<filas;i++)
    {
        for(int j=0;j<columnas;j++)
        {
            tablero[i][j] = '/';
        }
    }
}

int poner_bandera(int posc, int posf, int filas, int columnas, char **tablero)
{
    if(tablero[posf][posc] == 32)
    {
        return 0;
    }
    if(tablero[posf][posc]>48 && tablero[posf][posc]<57)
    {
        return 0;
    }
    else
    {
        tablero[posf][posc] = 80;
        return 1;
    }
}

int revisar_partida(int minas, int filas, int columnas, char **tablero, char**mapa_base)
{
    int i, j, banderacorrecta = 0;
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            if(tablero[i][j] == 80)
            {
                if(mapa_base[i][j] == 88)
                {
                    banderacorrecta++;
                }
            }
        }
    }
    if(banderacorrecta == minas)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void copia_mapa_ganador(int filas, int columnas, char **tablero, char**mapa_base)
{
    int i, j;
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            if(tablero[i][j] != 80)
            {
                tablero[i][j] = mapa_base[i][j];
            }
        }
    }
}

void juego_ganado(int filas, int columnas, char **tablero)
{
    system("cls");
    printf("\n");
    imprimir_mapa(filas, columnas, tablero);
    printf("\tJuego GANADO, Felicitaciones!!!!!.\n");
    system("pause");
    int i, j;
    for(int i=0;i<filas;i++)
    {
        for(int j=0;j<columnas;j++)
        {
            tablero[i][j] = '/';
        }
    }
}

int quitar_bandera(int posf, int posc, int filas, int columnas, char **tablero)
{
    if(tablero[posf][posc] != 80)
    {
        return 0;
    }
    else
    {
        tablero[posf][posc] = 47;
        return 1;
    }
}
