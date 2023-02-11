
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>    
#include <pthread.h>
pthread_mutex_t lock;
int v[4]={0, 6, 0 , 15};
int fx(int x){
int y= x*x+5*x-6;
return y;
}
void *bisectie(void *arg){
int *v = (int*) arg;
v[4]--;
if(v[4]==0){
printf("Numar de pasi depasiti");
exit(0);

}
int y=fx(v[2]);
printf("x este:%d \n f(x) este:%d\n", v[2], y);
if(y!=0){ 
printf("a este:%d\n b este:%d \n", v[0], v[1]);
pthread_t thread;


pthread_mutex_lock(&lock);
if(fx(v[0])*y<=0) {
v[1]=v[2];
v[2]=v([0]+v[1])/2;
}
pthread_create(&thread, NULL, bisectie, (void*)v);
pthread_join(thread, NULL);
pthread_mutex_unlock(&lock);

}
int main(){

if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }
pthread_t thread;
pthread_create(&thread, NULL, bisectie, (void*)v);
pthread_join(thread, NULL);
}