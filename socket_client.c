#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
/* SOCKET METAVLITES */ 
int sockfd,portno,n,t;

/* METAVLITES PROGRAMMATOS */
int flag,ch,i,pin_size;
int max_pin[2];
float client_numb,server_numb;

struct sockaddr_in serv_addr;
struct hostent *server;    

/* KWDIKAS ERROR HANDLING KAI SOCKET CONNECTION */
if (argc < 3)
{
  fprintf(stderr,"usage %s hostname port\n", argv[0]);
  exit(0);
}
portno = atoi(argv[2]);
sockfd = socket(AF_INET, SOCK_STREAM, 0);

if (sockfd < 0) 
  error("ERROR opening socket");

server = gethostbyname(argv[1]);

if (server == NULL)
{
  fprintf(stderr,"ERROR, no such host\n");
  exit(0);
}

bzero((char *) &serv_addr, sizeof(serv_addr));
serv_addr.sin_family = AF_INET;
bcopy((char *)server->h_addr, 
(char *)&serv_addr.sin_addr.s_addr,
server->h_length);
serv_addr.sin_port = htons(portno);

printf("Trying to connect...\n");

if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  error("ERROR connecting");

printf("Connected.\n");

/* ARXIZEI O KWDIKAS TOU PROGRAMMATOS MAS*/
/* ARXIKOPOIHSH PINAKA */
printf("\n");
printf("-------- TCP - RPC CODE --------\n");
printf("ARXIKOPOIHSH PROGRAMMATOS\n");
printf("\n");
printf("DWSE MOU TO MEGETHOS TOU PINAKA: ");
scanf("%d", &pin_size);

int pinakas[pin_size];

for(i=0; i<pin_size; i++)
{
    printf("DWSE TO %do STOIXEIO TOU PINAKA: ", i+1);
    scanf("%d",&pinakas[i]);
}
/* STELNW TON PINAKA KAI TO MEGETHOS TOU */
/* STON ENDIAMESO CLIENT/SERVER */
send(sockfd, &pin_size, sizeof pin_size, 0);
send(sockfd, &pinakas, sizeof pinakas, 0);
/* ARXIKOPOIHSH FLAG ME '0' */
/* PROKEIMENOU NA GINETE ELEGXOS EXSODOU */
/* APO TON XRHSTH */
flag = 0;
/* ENARKSI LEITOURGIWN PROGRAMMATOS */
do {
printf("\n");
printf("-------- PINAKAS LEITOURGIWN ---------\n");
printf("1. MESOS OROS TOU PINAKA\n");
printf("2. MIN && MAX PINAKA\n");
printf("3. POLLAPLASIASMOS PINAKA ME ARITHMO\n");
printf("4. EXSODOS PROGRAMMATOS\n");
printf("EPILOGH: ");
scanf("%d", &ch);

/* KWDIKAS MESOU OROU PINAKA */
/* STELNOUME STON ENDIAMESO CLIENT/SERVER */
/* THN EPILOGH TOU XRISTI */
/* LAMVANOUME APO TON ENDIAMESO CLIENT/SERVER */
/* TON MESO ORO TOU PINAKA */
if(ch == 1)
{
  send(sockfd, &ch, sizeof ch, 0);               
  recv(sockfd, &server_numb, sizeof server_numb, 0);                    
  printf("MESOS OROUS TOU PINAKA: %.1f\n",server_numb);
}
/* KWDIKAS MIN && MAX PINAKA */
/* STELNOUME STON ENDIAMESO CLIENT/SERVER */
/* THN EPILOGH TOU XRISTI */
/* LAMVANOUME APO TON ENDIAMESO CLIENT/SERVER */
/* PINAKA 2 STOIXEIWN OPOU: */
/* TO MAX EINAI STHN PRWTH THESI TOU PINAKA */
/* TO MIN EINAI STHN DEYTERH THESI TOU PINAKA */
else if(ch == 2)
{
  send(sockfd, &ch, sizeof ch, 0);
  recv(sockfd, &max_pin, sizeof max_pin, 0);                    
  printf("MEGISTH TIMH TOU PINAKA: %d\n",max_pin[0]);
  printf("ELAXISTH TIMH TOU PINAKA: %d\n",max_pin[1]);
}
/* KWDIKAS POLLAPLASIASMOU PINAKA ME FLOAT*/
/* STELNOUME STON ENDIAMESO CLIENT/SERVER */
/* THN EPILOGH TOU XRISTI */
/* TON FLOAT ARITHMO */
/* LAMVANOUME APO TON ENDIAMESO CLIENT/SERVER */
/* TON POLLAPLASIASMENO PINAKA ME TON FLOAT */
else if(ch == 3)
{
  printf("DWSE MOU ENAN PRAGMATIKO ARITHMO: ");
  scanf("%f",&client_numb);
  send(sockfd, &ch, sizeof ch, 0);
  send(sockfd, &client_numb, sizeof client_numb, 0);
  float farray[pin_size];
  recv(sockfd, &farray, sizeof farray, 0);
  
  for(i=0;i<pin_size;i++)
{
    printf("%do STOIXEIO TOU PINAKA = %.1f\n", i+1, farray[i]);
}
}
/* KWDIKAS EXSODOU TOU XRHSTH APO TO PROGRAMMA */
/* STELNOUME STON ENDIAMESO CLIENT/SERVER */
/* THN EPILOGH TOU XRISTI */
/* KANOUME TO FLAG 1 GIA NA FYGEI APO THN DO - WHILE */
/* KAI NA TERMATISTEI TO SOCKET */
else if(ch == 4)
{
  send(sockfd, &ch, sizeof ch, 0);
  printf("GOOD BYE DEAR USER\n");
  printf("SEE YOU SOON...\n");
  flag = 1;
}
/* KWDIKAS LANTHASMENHS EPILOGHS TOU XRHSTH */
else
{
  printf("!!! LATHOS EPILOGH !!!\n");
  printf("!!! PROSPATHISE XSANA !!!\n");
}                
} while (!flag);        

close(sockfd);
return 0;
}
