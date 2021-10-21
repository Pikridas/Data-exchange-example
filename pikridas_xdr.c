/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "pikridas.h"

bool_t
xdr_pinakas (XDR *xdrs, pinakas *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->pin.pin_val, (u_int *) &objp->pin.pin_len, 100,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->pin_size))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_megisto (XDR *xdrs, megisto *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->megisto))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->elaxisto))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_f_plus_pin (XDR *xdrs, f_plus_pin *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->pin.pin_val, (u_int *) &objp->pin.pin_len, 100,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->pin_size))
		 return FALSE;
	 if (!xdr_float (xdrs, &objp->fnumber))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_fpin (XDR *xdrs, fpin *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->fpinakas.fpinakas_val, (u_int *) &objp->fpinakas.fpinakas_len, 100,
		sizeof (float), (xdrproc_t) xdr_float))
		 return FALSE;
	return TRUE;
}