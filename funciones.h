#ifndef FUNCIONES_H
#define FUNCIONES_H

//Limpiar pantalla.
//Windows 
#define CLEAR() system("CLS")
//UNIX
//#define CLEAR() system("clear")
#define COLOR_NORMAL printf("\033[0m")
#define COLOR_ROJO printf("\033[1;1;31m")
#define COLOR_VERDE printf("\033[1;32m")
#define COLOR_AMARILLO printf("\033[1;33m")
#define COLOR_AZUL printf("\033[1;1;34m")


int time();
int rand();

void rellenar_mapa_base(int filas, int columnas, char **tablero);
void colocar_minas(int filas, int columnas, int minas, char **tablero);
void colocar_contadores(int filas, int columnas, char **tablero);
void guardar_mapa(int filas, int columnas, char **tablero_base);
void imprimir_mapa(int filas, int columnas, char **tablero);

int mostrar_campo(int filas, int columnas, int posf, int posc, char **mapa_base, char **tablero);
void imprimir_minas(int filas, int  columnas, char **mapa_base, char **tablero);
void juego_perdido(int filas, int columnas, char **tablero);
int poner_bandera(int posc, int posf, int filas, int columnas, char **tablero);
int revisar_partida(int minas, int filas, int columnas, char **tablero, char**mapa_base);
void copia_mapa_ganador(int filas, int columnas, char **tablero, char**mapa_base);
void juego_ganado(int filas, int columnas, char **tablero);
int quitar_bandera(int posf, int posc, int filas, int columnas, char **tablero);
void guardar_partida(int filas, int columnas, char **mapa_base, char **tablero);

#endif