#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "pikridas.h"
/* SYNARTHSH H OPOIA DEXETAI */
/* APO THN MAIN TON PINAKA KAI TO MEGETHOS TOU */
/* WSTE NA TA STEILEI STON RPC SERVER NA YPOLOGISEI*/
/* TON MESO ORO TOU DIANISMATOS */

float mesos_prog_1(char *host,int pin_size, int *pin)
{
	CLIENT *clnt;
	float  *result_1;
	pinakas mesos_1_arg;
    
#ifndef	DEBUG
	clnt = clnt_create (host, MESOS_PROG, MESOS_VERS, "udp");
	if (clnt == NULL) 
{
      clnt_pcreateerror (host);
      exit (1);
}
#endif	/* DEBUG */
/* DYNAMIKI DESMEYSH TOU PINAKA POU ELAVE APO THN MAIN */
/* EKXWRHSH TOU PINAKA APO THN MAIN */ 
/* STON DYNAMIKO DESMEYMENO PINAKA THS SYNARTHSHS */

    mesos_1_arg.pin.pin_len=pin_size;
    mesos_1_arg.pin_size=pin_size;
    mesos_1_arg.pin.pin_val=(int *) malloc(pin_size*sizeof(int));
    mesos_1_arg.pin.pin_val=pin;
    
	result_1 = mesos_1(&mesos_1_arg, clnt);
	if (result_1 == (float *) NULL) 
{
		clnt_perror (clnt, "call failed");
}
	else
{
        return *result_1;
}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}

/* SYNARTHSH H OPOIA DEXETAI */
/* APO THN MAIN TON PINAKA KAI TO MEGETHOS TOU */
/* WSTE NA TA STEILEI STON RPC SERVER NA YPOLOGISEI*/
/* THN MIN && MAX TIMH TOU DIANISMATOS */

int * maximum_prog_1(char *host,int pin_size, int *pin)
{
	int *max_pin;
    CLIENT *clnt;
	megisto  *result_1;
	pinakas  maximum_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, MAXIMUM_PROG, MAXIMUM_VERS, "udp");
	if (clnt == NULL) 
{
      clnt_pcreateerror (host);
      exit (1);
}
#endif	/* DEBUG */
/* DYNAMIKI DESMEYSH TOU PINAKA POU ELAVE APO THN MAIN */
/* EKXWRHSH TOU PINAKA APO THN MAIN */ 
/* STON DYNAMIKO DESMEYMENO PINAKA THS SYNARTHSHS */
/* H SYNARTISI STELNEI TON PINAKA */
/* ME THN ELAXISTI KAI TIN MEGISTH TIMH STON SERVER */
/* DEN KANEI YPOLOGISMO */
/* EKXWROUNTAI DYO TIMES STIS THESEIS TOU PINAKA */

    maximum_1_arg.pin.pin_len=pin_size;
    maximum_1_arg.pin_size=pin_size;
    maximum_1_arg.pin.pin_val=(int *) malloc(pin_size*sizeof(int));
    maximum_1_arg.pin.pin_val=pin;
    
    max_pin=(int *) malloc(2*sizeof(int));
    
	result_1 = maximum_1(&maximum_1_arg, clnt);
	if (result_1 == (megisto *) NULL) 
{
		clnt_perror (clnt, "call failed");
}
	else
{
        max_pin[0] = result_1->megisto;
		max_pin[1] = result_1->elaxisto;				
		
        return max_pin;
}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}

/* SYNARTHSH H OPOIA DEXETAI */
/* APO THN MAIN TON PINAKA KAI TO MEGETHOS TOU */
/* KATHWS KAI ENAN PRAGMATIKO ARITHMO */
/* WSTE NA TA STEILEI STON RPC SERVER NA YPOLOGISEI*/
/* TON POLLAPLASIAMSO TOU DIANISMATIS ME TON FLOAT */

float * farray_prog_1(char *host,int pin_size,int *pin,float fnumber)
{
    float *float_array;
	CLIENT *clnt;
	fpin  *result_1;
	f_plus_pin  farray_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, FARRAY_PROG, FARRAY_VERS, "udp");
	if (clnt == NULL) 
{
      clnt_pcreateerror (host);
      exit (1);
}
#endif	/* DEBUG */
/* DYNAMIKI DESMEYSH TOU PINAKA POU ELAVE APO THN MAIN */
/* EKXWRHSH TOU PINAKA APO THN MAIN */ 
/* STON DYNAMIKO DESMEYMENO PINAKA THS SYNARTHSHS */
/* EKXWRHSH TIS FLOAT TIMHS SE METAVLITH TOU STRUCT */
/* H SYNARTISI STELNEI TON PINAKA */
/* STON SERVER GIA NA YPOLOGISEI TON POLLAPLASIASMO*/

    farray_1_arg.pin.pin_len=pin_size;
    farray_1_arg.pin_size=pin_size;
    farray_1_arg.pin.pin_val=(int *) malloc(pin_size*sizeof(int));
    farray_1_arg.pin.pin_val=pin;
    farray_1_arg.fnumber=fnumber;
    
    result_1 = farray_1(&farray_1_arg, clnt);
    
    float_array = (float *) malloc(pin_size*sizeof(float));
    float_array = result_1->fpinakas.fpinakas_val;
    
	if (result_1 == (fpin *) NULL)
{
		clnt_perror (clnt, "call failed");
}
	else
{
        return float_array;
}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main (int argc, char *argv[])
{
/* METAVLITES SOCKET */
char *host;
int sockfd, newsockfd, portno, clilen, n, flag;

/* METAVLITES TOU PROGRAMMATOS */
int ch,pin_size,i,sum,max,min;
float fnumber;
float server_numb;
float *float_array;
int *max_pin;

/* ELENXOS TCP SYNDESIS */
struct sockaddr_in serv_addr, cli_addr;
//shell arguments
if (argc < 2) 
{
  printf ("usage: %s server_host\n", argv[0]);
  fprintf(stderr,"ERROR, no port provided\n");
  exit (1);
}

host = argv[1];
printf("Host: %s\n",host);
//server-side connection
sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (sockfd < 0)
  error("ERROR opening socket");

bzero((char *) &serv_addr, sizeof(serv_addr));

portno = atoi(argv[2]);
printf("Portno: %d\n",portno);
serv_addr.sin_family = AF_INET;

serv_addr.sin_port = htons(portno);

serv_addr.sin_addr.s_addr = INADDR_ANY;

if (bind(sockfd, (struct sockaddr *) &serv_addr,
    sizeof(serv_addr)) < 0)
      error("ERROR on binding");

listen(sockfd,5);
/* PRGAMTOPOIHSH TCP SINDESHS ME XRHSH THS FORK() */
/* WSTE NA YPARXEI H DYNATOTHTA SINDESHS ME POLLAPLOUS CLIENTS */
for (;;)  
{
  printf("Waiting for a connection...\n");
  clilen = sizeof(cli_addr);
  newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
  if (newsockfd < 0)
    error("ERROR on accept");
  
  if (fork() == 0)
{
    close (sockfd);
    printf("Connected.\n");
/* APO TON SOCKET CLIENT LAMVANONTAI O PINAKAS KAI TO MAGETHOS TOU */
    flag = 0;
    recv(newsockfd,&pin_size, sizeof pin_size, 0);
    int pinakas[pin_size];
    recv(newsockfd, &pinakas, sizeof pinakas, 0);                   
    
    do {
        recv(newsockfd, &ch, sizeof ch, 0);  // LHPSH APOFASHS LEITOURGIAS XRISTI                     
						
        if(ch == 1)
{                               
          server_numb = mesos_prog_1 (host,pin_size,pinakas); // KLHSH CLIENT - RPC SYNARTHSHS 
          printf("APOTELESMA MESOU OROU: %.1f\n", server_numb); // APOTELESMA APO SERVER - RPC
          send(newsockfd, &server_numb, sizeof server_numb, 0); // APOSTOLH APOTELESMATOS STON SOCKET - CLIENT
}	
        else if(ch == 2)
{
          max_pin = maximum_prog_1 (host,pin_size,pinakas); // KLHSH CLIENT - RPC SYNARTHSHS
          printf("MEGISTH TIMH: %d\n", max_pin[0]); // APOTELESMA APO SERVER - RPC ( MEGISTH TIMI )
          printf("ELAXISTH TIMH: %d\n", max_pin[1]); // APOTELESMA APO SERVER - RPC ( ELAXISTH TIMI )
          send(newsockfd, max_pin, 2*sizeof(int), 0); // APOSTOLH APOTELESMATOS STON SOCKET - CLIENT
}
        else if(ch == 3)
{
         recv(newsockfd, &fnumber, sizeof fnumber, 0); // LHPSH FLOAT ARITHMOU APO TON SOCKET - CLIENT
         float_array = farray_prog_1 (host,pin_size,pinakas,fnumber); // KLHSH CLIENT - RPC SYNARTHSHS
         
         printf("PRAGMATIKOS ARITHMOS: %.1f\n", fnumber); // EKTYPWSH PRAGMATIKOU ARITHMOU
         
         for(i=0; i<pin_size; i++)
         {
           printf("%do STOIXEIO TOU FLOAT PINAKA: %.1f\n",i+1,float_array[i]); // APOTELESMA APO SERVER - RPC
         }
         send(newsockfd, float_array, pin_size*sizeof(float), 0); // APOSTOLH APOTELESMATOS STON SOCKET - CLIENT
}        
        else
{
          flag=1; //AN O XRHSTHS DEN EPILEKSEI TIS LEITOURGIES 1 - 3 TOTE
                  
}
        } while (!flag); // O RPC - CLIENT TERMATIZEI THN LEITOURGIA TOU, H FORK PARAMENEI ANOIKTH

  exit (0);
} // KLEISIMO FORK
 close(newsockfd);
} // KLEISIMO FOR EPANALIPSIS
exit (0);
} // KLEISIMO MAIN
