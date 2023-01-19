#!/usr/bin/python3
"""
Matrix 2D
"""


def rotate_2d_matrix(matrix):
    """girar la matriz de dos dimensiones 90 grados en el sentido de las agujas del reloj
    Argumentos:
        matriz (lista[[lista]]): una matriz
    """
    p = len(matrix)
    for i in range(int(p / 2)):
        y = (p - i - 1)
        for j in range(i, y):
            x = (p - 1 - j)
            # número actual
            tmp = matrix[i][j]
            # cambiar arriba por izquierda
            matrix[i][j] = matrix[x][i]
            # cambiar a la izquierda por abajo
            matrix[x][i] = matrix[y][x]
            # cambiar abajo por la derecha
            matrix[y][x] = matrix[j][y]
            # cambiar a la derecha por arriba
            matrix[j][y] = tmp