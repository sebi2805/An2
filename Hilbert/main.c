#include <stdio.h>
#include <stdlib.h>
int putere(int x, int n){
if(n==0)
    return 1;
 else if(n%2==0) {

    if(n>=10) return putere(x, n/4)*putere(x, n/4);
        else return putere(x, n/2)*putere(x, n/2);
 }
 else
    return x*putere(x, (n-1)/2)*putere(x, (n-1)/2);



}
//(XST, YST) STANGA SUS (1, 1), (XDR,YDR) DREAPTA JOS (2^K, 2^K), N ESTE ORDINUL MATRICEI N=K, X SI Y COORDONATELE PCT
//CAUTAM PUNCTUL (X,Y) IMPARTIND DE FIECARE DATA IN 4 PARTI EGALE PANA CAND MATRICEA SE MICSOAREAZA LA O MATRICE DE 2^0X2^0 ADICA DE 1X1
//ATUNCI AVEM SOLUTIA DIRECTA
//IN REST PUTEM OBSERVA CA PT A PARCURGE 1/4 DINTR-O MATRICE 2^K X 2^K AVEM 2^(2(K-1)) PASI (2^K*2^K/4, UNDE 4=2^2, DECI DE AICI PUTEM SPUNE
//CA AVEM 2^(K+K-2), ->FACTOR COMUN ->2^(2(K-1)) )
//PT A AJUNGE IN ZONA 4 TRB SA PARCURGEM 3 ZONE (ZONA 1/2/3), 3* 2^(2(K-1))
//PT ZONE 3 -> 2 ZONE
//PT ZONA 2 -> 1 ZONA
//PT ZONA 1 -> SUNTEM DEJA, 0
int Hilbert(int x, int y, int xst, int yst, int xdr, int ydr, int n ){

if(n<0) return 0;
if(n==0) {
  printf("\n ZONA:X.(%d)(%d)(%d)(%d)", xst, yst, xdr, ydr) ;
    return 0;
    /*
     if(x-xst==0&&y-yst==1)
    if(x-xst==0&&y-yst==0) return 2;
    if(x-xst==1&&y-yst==0) return 3;
    if(x-xst==1&&y-yst==1) return 4;*/


}

if(  y<=(ydr+yst)/2){
    if(x<=(xdr+xst)/2) {

            printf("\n ZONA:1.(%d)(%d)(%d)(%d)", xst, yst, xdr, ydr) ;
            return Hilbert(x, y, xst, yst , (xdr+xst)/2, (ydr+yst)/2, n-1);
    }

    else if(x>(xdr+xst )/2)   {
            printf("\n ZONA:4.(%d)(%d)(%d)(%d)", xst, yst, xdr, ydr);
            return Hilbert(x, y, (xdr+xst)/2+1 ,yst  ,xdr,(ydr+yst)/2 , n-1)+ putere(2, 2*(n-1))*3;}
}
else if(y>(ydr+yst)/2){
    if(x<=(xdr+xst)/2) {
            printf("\n ZONA:2.(%d)(%d)(%d)(%d)", xst, yst, xdr, ydr);
            return Hilbert(x, y,  xst,  (yst+ydr)/2+1, (xdr+xst)/2, ydr , n-1)+ (putere(2, 2*(n-1)));}
    else if(x>(xdr+xst )/2) {
        printf("\n ZONA:3.(%d)(%d)(%d)(%d)", xst, yst, xdr, ydr );
        return Hilbert(x, y,  (xdr+xst)/2+1,  (yst+ydr)/2+1, xdr, ydr , n-1)+ (putere(2, 2*(n-1)))*2;}
}



}





int main()
{

    int k, x, y;
    FILE *fin=fopen("date.in", "r");
    FILE *fout=fopen("date.out", "r+");
    if(fin==NULL||fout==NULL){
        {
            printf("Unul dintre fisiere e stricat.\n");
            exit(0);
        }


    }
    fscanf(fin,"%d%d%d", &k, &x,&y );
    int k2=putere(2, k);
    int raspuns = Hilbert( x, y , 1, 1, k2, k2, k);
    fprintf(fout, "%d", raspuns);
    return 0;
}
