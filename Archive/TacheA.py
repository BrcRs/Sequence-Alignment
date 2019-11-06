cdel = 2
cins = 2
INFINI = -1


def csub(x_i, y_i) :
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
    print("DIST_NAIF_REC(" + str(x) + ", "  + str(y) + ", "+ str(i) + ", "  + str(j) + ", "  + str(c) + ", " + str(dist)+")")

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


print(DIST_NAIF_REC('ATTGTA', 'ATCTTA', 0, 0, 0, INFINI))
