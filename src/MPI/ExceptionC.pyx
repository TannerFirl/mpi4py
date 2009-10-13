cdef extern from "Python.h":
    ctypedef class __builtin__.RuntimeError [object PyBaseExceptionObject]:
        pass

cdef class Exception(RuntimeError):

    """
    Exception
    """

    cdef int ob_mpi

    def __cinit__(self, int ierr=0):
        if ierr < MPI_SUCCESS:      ierr = MPI_ERR_UNKNOWN
        if ierr > MPI_ERR_LASTCODE: ierr = MPI_ERR_UNKNOWN
        self.ob_mpi = ierr
        RuntimeError.__init__(self, ierr)

    def __richcmp__(Exception self, int error, int op):
        cdef int ierr  = self.ob_mpi
        if op == 0: return ierr <  error
        if op == 1: return ierr <= error
        if op == 2: return ierr == error
        if op == 3: return ierr != error
        if op == 4: return ierr >  error
        if op == 5: return ierr >= error

    def __nonzero__(self):
        return self.ob_mpi != MPI_SUCCESS

    def __int__(self):
        if not mpi_active():
            return self.ob_mpi
        return self.Get_error_code()

    def __repr__(self):
        return "MPI.Exception(%d)" % self.ob_mpi

    def __str__(self):
        if not mpi_active():
            return "error code: %d" % self.ob_mpi
        return self.Get_error_string()

    def Get_error_code(self):
        """
        Error code
        """
        cdef int errorcode = MPI_SUCCESS
        errorcode = self.ob_mpi
        return errorcode

    property error_code:
        """error code"""
        def __get__(self):
            return self.Get_error_code()

    def Get_error_class(self):
        """
        Error class
        """
        cdef int errorclass = MPI_SUCCESS
        CHKERR( MPI_Error_class(self.ob_mpi, &errorclass) )
        return errorclass

    property error_class:
        """error class"""
        def __get__(self):
            return self.Get_error_class()

    def Get_error_string(self):
        """
        Error string
        """
        cdef char string[MPI_MAX_ERROR_STRING+1]
        cdef int resultlen = 0
        CHKERR( MPI_Error_string(self.ob_mpi, string, &resultlen) )
        return tompistr(string, resultlen)

    property error_string:
        """error string"""
        def __get__(self):
            return self.Get_error_string()
