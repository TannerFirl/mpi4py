# -----------------------------------------------------------------------------

cdef type arraytype
from array import array as arraytype

cdef extern from "Python.h":
    int PySequence_DelItem(object, Py_ssize_t) except -1
    object PySequence_InPlaceRepeat(object, Py_ssize_t)

cdef inline object newarray_int(Py_ssize_t n, int **p):
    cdef object ary = arraytype('i', [0])
    if n <= 0:
        PySequence_DelItem(ary, 0)
    elif n > 1:
        ary = PySequence_InPlaceRepeat(ary, n)
    cdef int *base = NULL
    cdef Py_ssize_t size = 0
    PyObject_AsWriteBuffer(ary, <void**>&base, &size)
    if p != NULL: p[0] = base
    return ary

cdef inline object getarray_int(object ob, int *n, int **p):
    cdef int *base = NULL
    cdef Py_ssize_t i = 0, size = len(ob)
    cdef object ary = newarray_int(size, &base)
    for i from 0 <= i < size:
        base[i] = ob[i]
    if n != NULL: n[0] = <int> size # XXX overflow?
    if p != NULL: p[0] = base
    return ary

cdef inline object chkarray_int(object ob, int n, int **p):
    cdef Py_ssize_t size = n
    cdef object ary = getarray_int(ob, &n, p)
    if size != <Py_ssize_t>n:
        raise ValueError(
            "expecting %d items, got %d" % (size, n))
    return ary

# -----------------------------------------------------------------------------

cdef inline object asarray_Aint(object sequence,
                                MPI_Aint **p, Py_ssize_t size):
     cdef MPI_Aint *array = NULL
     cdef Py_ssize_t i = 0, n = len(sequence)
     if size != n:
          raise ValueError(
              "expecting %d items, got %d" % (size, n))
     cdef object ob = allocate(n*sizeof(MPI_Aint), <void**>&array)
     for i from 0 <= i < n: 
         array[i] = sequence[i]
     p[0] = array
     return ob

cdef inline object asarray_Datatype(object sequence,
                                    MPI_Datatype **p, Py_ssize_t size):
     cdef MPI_Datatype *array = NULL
     cdef Py_ssize_t i = 0, n = len(sequence)
     if size != n:
          raise ValueError(
               "expecting %d items, got %d" % (size, n))
     cdef object ob = allocate(n*sizeof(MPI_Datatype), <void**>&array)
     for i from 0 <= i < n: 
         array[i] = (<Datatype?>sequence[i]).ob_mpi
     p[0] = array
     return ob

# -----------------------------------------------------------------------------

cdef inline object asarray_argv(object sequence, char ***p):
     sequence = list(sequence)
     cdef Py_ssize_t i = 0, n = len(sequence)
     cdef char** array = NULL
     cdef object ob = allocate((n+1)*sizeof(char*), <void**>&array)
     for i from 0 <= i < n:
          sequence[i] = asmpistr(sequence[i], &array[i], NULL)
     array[n] = NULL
     p[0] = array
     return (sequence, ob)

# -----------------------------------------------------------------------------
