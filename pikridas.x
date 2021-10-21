 struct pinakas
{
	int pin <100>;
	int pin_size;
};

struct megisto
{
	int megisto;
	int elaxisto;
};

struct f_plus_pin
{
	int pin <100>;
	int pin_size;
	float fnumber;
};

struct fpin
{
	float fpinakas <100>;
};

program MESOS_PROG
{
	version MESOS_VERS
	{
		float mesos(pinakas) = 1;
	} = 1;
} = 0x45017946;

program MAXIMUM_PROG
{
	version MAXIMUM_VERS
	{
		megisto maximum(pinakas) = 2;
	} = 1;
} = 0x45017947;


program FARRAY_PROG
{
	version FARRAY_VERS
	{
		fpin farray(f_plus_pin) = 3;
	} = 1;
} = 0x45017948;
