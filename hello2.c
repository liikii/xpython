#include <Python.h>
/*
The code you have would work fine in Python 2.x, but Py_InitModule is no longer used in Python 3.x. Nowadays, you create a PyModuleDef structure and then pass a reference to it to PyModule_Create.

The structure would look like:

*/

static PyObject*
say_hello(PyObject* self, PyObject* args)
{
    const char* name;

    if (!PyArg_ParseTuple(args, "s", &name))
        return NULL;

    printf("Hello %s!\n", name);

    Py_RETURN_NONE;
}

static PyMethodDef HelloMethods[] =
{
     {"say_hello", say_hello, METH_VARARGS, "Greet somebody."},
     {NULL, NULL, 0, NULL}
};


static struct PyModuleDef cModPyDem =
{
    PyModuleDef_HEAD_INIT,
    "hello2", /* name of module */
    "",          /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    HelloMethods
};


PyMODINIT_FUNC PyInit_hello2(void)
{
    return PyModule_Create(&cModPyDem);
}
// PyMODINIT_FUNC
// inithello(void)
// {
//      (void) Py_InitModule("hello2", HelloMethods);
// }
