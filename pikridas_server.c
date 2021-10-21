#include "pikridas.h"

/* SYNARTHSH YPOLOGISMOU MESOU OROU DIANISMATOS */
/* LHPSH DEDOMENWN APO RPC - CLIENT MESW THS MAIN */

float * mesos_1_svc(pinakas *argp, struct svc_req *rqstp)
{
    
static float  result;
  
float sum=0.0;
int i;

printf("KLITHIKE H SYNARTHSH EVRESHS MESOU OROU DIANISMATOS...\n");
/* YPOLOGISMOS MESOU OROU DIANISMATOS */
for(i=0; i < argp->pin_size; i++)
  sum += argp->pin.pin_val[i];

result = sum/argp->pin_size;
printf("MESOS OROS DIANISMATOS: %.1f\n",result);
printf("\n");
return &result; // EPISTROFH APOTELESMATOS STON RCP - CLIENT
}

/* SYNARTHSH YPOLOGISMOU MESOU OROU DIANISMATOS */
/* LHPSH DEDOMENWN APO RPC - CLIENT MESW THS MAIN */

megisto * maximum_1_svc(pinakas *argp, struct svc_req *rqstp)
{

static megisto  result;

int i;

printf("KLITHIKE H SYNARTHSH EVRESHS MEGALYTEROU KAI MIKROTEROU ARITHMOU DIANISMATOS...\n");

result.megisto=-999999;
result.elaxisto=999999;
/* YPOLOGISMOS MEGISTHS KAI ELAXISTHS TIMHS DIANISMATOS */
for(i=0; i < argp->pin_size; i++)
  if(argp->pin.pin_val[i] > result.megisto)
    result.megisto = argp->pin.pin_val[i];

for(i=0; i < argp->pin_size; i++)
  if(argp->pin.pin_val[i] < result.elaxisto)
    result.elaxisto = argp->pin.pin_val[i];

printf("MEGISTH TIMH DIANISMATOS: %d\n",result.megisto);
printf("ELAXISTH TIMH DIANISMATOS: %d\n",result.elaxisto);

printf("\n");
return &result;// EPISTROFH APOTELESMATOS STON RCP - CLIENT
}

/* SYNARTHSH YPOLOGISMOU MESOU OROU DIANISMATOS */
/* LHPSH DEDOMENWN APO RPC - CLIENT MESW THS MAIN */

fpin * farray_1_svc(f_plus_pin *argp, struct svc_req *rqstp)
{

static fpin result;

int i;

printf("KLITHIKE H SYNARTHSH POLLAPLASIAMSOU PRAGMATIKOU ARITHMOU ME DIANISMA...\n");

result.fpinakas.fpinakas_len=argp->pin_size;
result.fpinakas.fpinakas_val=(float *)malloc(argp->pin_size*sizeof(float));

printf("PRAGMATIKOS ARITHMOS: %.1f\n", argp->fnumber);
/* YPOLOGISMOS POLLAPLASIASMOU DIANISMATOS */
for(i=0;i<argp->pin_size;i++)
{
  result.fpinakas.fpinakas_val[i] = argp->fnumber*argp->pin.pin_val[i];
  printf("%do STOIXEIO TOU PINAKA: %.1f\n",i+1,result.fpinakas.fpinakas_val[i]);
}

printf("\n");
return &result; // EPISTROFH APOTELESMATOS STON RCP - CLIENT
}
