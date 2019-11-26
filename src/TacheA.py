#!/usr/bin/python3.6.7
import glob
import time
#from memory_profiler import memory_usage

cdel = 2
cins = 2
INFINI = -1


def csub(x_i, y_i) :
    """
    char * char -> int
    Retourne le cout de la substitution (x_i, y_i).
    """
    if (x_i == y_i) :
        return 0
    if ((x_i == 'A' and y_i == 'T') or (x_i == 'G' and y_i == 'C') or (x_i == 'C' and y_i == 'G')or (x_i == 'T' and y_i == 'A')) :
        return 3
    return 4


def DIST_NAIF(x, y) :
    """
    str*str->int
    """
    return DIST_NAIF_REC(x, y, 0, 0, 0, INFINI)

def DIST_NAIF_REC (x, y, i, j, c, dist) :
    """
    str*str*int*int*int*int -> int
    Enumerer tous les alignements possibles de deux mots x et y
    """
    #print("DIST_NAIF_REC(" + str(x) + ", "  + str(y) + ", "+ str(i) + ", "  + str(j) + ", "  + str(c) + ", " + str(dist)+")")

    if (i==len(x) and j==len(y) ) :
        if (dist == INFINI or c < dist) :
            dist = c
    else :
        if (i < len(x) and j < len(y)) :
            dist = DIST_NAIF_REC(x, y, i+1, j+1, c + csub(x[i], y[j]), dist )
        if (i < len(x)) :
            dist = DIST_NAIF_REC(x, y, i+1, j, c + cdel, dist)
        if (j < len(y)) :
            dist = DIST_NAIF_REC(x, y, i, j+1, c + cins, dist)
    #print(dist)
    return dist




#file_object = open(<str : filename>, <str : mode : r / w / a / r+>)

def dist_on_file(filename) :
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

    return DIST_NAIF_REC(x, y, 0, 0, 0, INFINI)

def test() :

    assert DIST_NAIF_REC('ATTGTA', 'ATCTTA', 0, 0, 0, INFINI) == 4


    assert dist_on_file("../Instances/Inst_0000010_44.adn") == 10
    assert dist_on_file("../Instances/Inst_0000010_7.adn") == 8

    assert dist_on_file("../Instances/Inst_0000010_8.adn") == 2

# 0.3% de memoire utilisee, 100% de la RAM
def testminute() :

    dir_list = glob.glob("../Instances/*.adn")
    dir_list.sort()
    #print (dir_list)

    for f in dir_list :
        print ("_" * len(f) + "\n" + f)
        start_time = time.time()
        dist_on_file(f)
        elapsed_time = time.time() - start_time
        estimate = round(elapsed_time, 2)
        if elapsed_time > 60 :
            min = str(estimate//60)
            sec = str(estimate%60)
            print ("Temps d'execution : " + min + "m " + sec + "s\n")
            return


        print ("Temps d'execution : " + str(estimate) + "s\n")
