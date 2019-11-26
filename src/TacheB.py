from TacheA import *

def creer_Matrice(long, larg, val) :
    matrice = [[]] * long
    for i in range(long) :
        matrice[i] = [val] * larg
    return matrice

def DIST_1 (x, y) :
    """
    str * str -> int
    Remplit un tableau a deux dimensions avec toutes les valeurs de D pour
    finalement renvoyer la distance d'edition entre ces deux mots.
    """
    lenX = len(x)
    lenY = len(y)
    # matrice : list(list(int))
    # matrice = [[INFINI] * lenY] * lenX
    matrice = creer_Matrice(lenX, lenY, INFINI)
    matrice[0][0] = min([2*cins, csub(x[0], y[0]), 2*cdel])
    for i in range(lenX) :
        for j in range(lenY) :
            mat_ij = matrice[i][j]
            cas1 = (mat_ij if mat_ij != INFINI else 0 ) + cins
            cas2 = (mat_ij if mat_ij != INFINI else 0 ) + cdel
            if (j+1 < lenY) :
                matrice[i][j+1] = cas1 \
                if cas1 < matrice[i][j+1] or matrice[i][j+1] == INFINI \
                else matrice[i][j+1]

            if (i+1 < lenX) :
                matrice[i+1][j] = cas2 \
                if cas2 < matrice[i+1][j] or matrice[i+1][j] == INFINI \
                else matrice[i+1][j]

            if (i+1 < lenX and j+1 < lenY) :
                cas3 = (mat_ij if mat_ij != INFINI else 0 ) + csub(x[i+1], y[j+1])
                matrice[i+1][j+1] = cas3 \
                if cas3 < matrice[i+1][j+1] or matrice[i+1][j+1] == INFINI \
                else matrice[i+1][j+1]


    afficher_matrice(matrice)
    return matrice[lenX-1][lenY-1]

def dist_1_on_file(filename) :
    """
    str -> int
    Lit deux mots x et y a partir d'un adn file, et retourne la distance entre les deux.
    """
    f = open(filename, 'r')
    x_size = int(f.readline())
    y_size = int(f.readline())
    x = (f.readline()).replace(' ', '')
    y = (f.readline()).replace(' ', '')
    print (x + "" + y, end='')

    f.close()
    ans = DIST_1(x, y)
    print (ans)
    return ans

def afficher_matrice(matrice) :
    for i in range(len(matrice)) :
        print(matrice[i])

def test() :

    print (DIST_1('ATTGTA', 'ATCTTA'))
    assert DIST_1('ATTGTA', 'ATCTTA') == 4

    assert dist_1_on_file("../Instances/Inst_0000010_44.adn") == 10
    assert dist_1_on_file("../Instances/Inst_0000010_7.adn") == 8

    assert dist_1_on_file("../Instances/Inst_0000010_8.adn") == 2
