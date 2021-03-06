// This file implements the IPropertyChange Interface and Gateway for Python.
// Generated by makegw.py

#include "PythonCOM.h"
#include "PythonCOMServer.h"
#include "propsys.h"
#include "PyIObjectWithPropertyKey.h"
#include "PyIPropertyChange.h"
#include "PyPROPVARIANT.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIPropertyChange::PyIPropertyChange(IUnknown *pdisp):
	PyIObjectWithPropertyKey(pdisp)
{
	ob_type = &type;
}

PyIPropertyChange::~PyIPropertyChange()
{
}

/* static */ IPropertyChange *PyIPropertyChange::GetI(PyObject *self)
{
	return (IPropertyChange *)PyIObjectWithPropertyKey::GetI(self);
}

// @pymethod <o PyPROPVARIANT>|PyIPropertyChange|ApplyToPropVariant|Applies the change to a variant value
PyObject *PyIPropertyChange::ApplyToPropVariant(PyObject *self, PyObject *args)
{
	IPropertyChange *pIPC = GetI(self);
	if ( pIPC == NULL )
		return NULL;
	PROPVARIANT *origval;
	PROPVARIANT changedval;
	// @pyparm <o PyPROPVARIANT>|OrigVal||The value to be modified
	if (!PyArg_ParseTuple(args, "O&:ApplyToPropVariant",
		PyWinObject_AsPROPVARIANT, &origval))
		return NULL;

	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPC->ApplyToPropVariant(*origval, &changedval);
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPC, IID_IPropertyChange );
	return PyWinObject_FromPROPVARIANT(changedval);
}

// @object PyIPropertyChange|Interface used to specify a change to a property
static struct PyMethodDef PyIPropertyChange_methods[] =
{
	{ "ApplyToPropVariant", PyIPropertyChange::ApplyToPropVariant, 1 }, // @pymeth ApplyToPropVariant|Applies the change to a variant value
	{ NULL }
};

PyComTypeObject PyIPropertyChange::type("PyIPropertyChange",
		&PyIObjectWithPropertyKey::type, // @base PyIPropertyChange|PyIObjectWithPropertyKey
		sizeof(PyIPropertyChange),
		PyIPropertyChange_methods,
		GET_PYCOM_CTOR(PyIPropertyChange));
