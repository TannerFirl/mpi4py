#ifndef PyMPI_CONFIG_OPENMPI_H
#define PyMPI_CONFIG_OPENMPI_H

#include "mpi-22.h"
#include "mpi-30.h"

#ifndef OMPI_HAVE_FORTRAN_LOGICAL1
#define OMPI_HAVE_FORTRAN_LOGICAL1 0
#endif
#ifndef OMPI_HAVE_FORTRAN_LOGICAL2
#define OMPI_HAVE_FORTRAN_LOGICAL2 0
#endif
#ifndef OMPI_HAVE_FORTRAN_LOGICAL4
#define OMPI_HAVE_FORTRAN_LOGICAL4 0
#endif
#ifndef OMPI_HAVE_FORTRAN_LOGICAL8
#define OMPI_HAVE_FORTRAN_LOGICAL8 0
#endif

#if !OMPI_HAVE_FORTRAN_LOGICAL1
#define PyMPI_MISSING_MPI_LOGICAL1 1
#endif
#if !OMPI_HAVE_FORTRAN_LOGICAL2
#define PyMPI_MISSING_MPI_LOGICAL2 1
#endif
#if !OMPI_HAVE_FORTRAN_LOGICAL4
#define PyMPI_MISSING_MPI_LOGICAL4 1
#endif
#if !OMPI_HAVE_FORTRAN_LOGICAL8
#define PyMPI_MISSING_MPI_LOGICAL8 1
#endif
#if !OMPI_HAVE_FORTRAN_INTEGER1
#define PyMPI_MISSING_MPI_INTEGER1 1
#endif
#if !OMPI_HAVE_FORTRAN_INTEGER2
#define PyMPI_MISSING_MPI_INTEGER2 1
#endif
#if !OMPI_HAVE_FORTRAN_INTEGER4
#define PyMPI_MISSING_MPI_INTEGER4 1
#endif
#if !OMPI_HAVE_FORTRAN_INTEGER8
#define PyMPI_MISSING_MPI_INTEGER8 1
#endif
#if !OMPI_HAVE_FORTRAN_INTEGER16
#define PyMPI_MISSING_MPI_INTEGER16 1
#endif
#if !OMPI_HAVE_FORTRAN_REAL2
#define PyMPI_MISSING_MPI_REAL2 1
#define PyMPI_MISSING_MPI_COMPLEX4 1
#endif
#if !OMPI_HAVE_FORTRAN_REAL4
#define PyMPI_MISSING_MPI_REAL4 1
#define PyMPI_MISSING_MPI_COMPLEX8 1
#endif
#if !OMPI_HAVE_FORTRAN_REAL8
#define PyMPI_MISSING_MPI_REAL8 1
#define PyMPI_MISSING_MPI_COMPLEX16 1
#endif
#if !OMPI_HAVE_FORTRAN_REAL16
#define PyMPI_MISSING_MPI_REAL16 1
#define PyMPI_MISSING_MPI_COMPLEX32 1
#endif

#if MPI_VERSION==2 && MPI_SUBVERSION<2
#define PyMPI_MISSING_MPI_Comm_errhandler_function 1
#define PyMPI_MISSING_MPI_Win_errhandler_function 1
#define PyMPI_MISSING_MPI_File_errhandler_function 1
#endif

#ifdef OMPI_PROVIDE_MPI_FILE_INTERFACE
#if OMPI_PROVIDE_MPI_FILE_INTERFACE == 0
#include "openmpi-io.h"
#endif
#endif

#if MPI_VERSION < 3 && (defined(OMPI_MAJOR_VERSION) && \
                        defined(OMPI_MINOR_VERSION) && \
                        defined(OMPI_RELEASE_VERSION))

#if ((OMPI_MAJOR_VERSION   * 10000) + \
     (OMPI_MINOR_VERSION   *   100) + \
     (OMPI_RELEASE_VERSION *     1)) >= 10700
/**/
#undef  PyMPI_MISSING_MPI_Message
#undef  PyMPI_MISSING_MPI_MESSAGE_NULL
#undef  PyMPI_MISSING_MPI_MESSAGE_NO_PROC
#undef  PyMPI_MISSING_MPI_Message_c2f
#undef  PyMPI_MISSING_MPI_Message_f2c
#undef  PyMPI_MISSING_MPI_Mprobe
#undef  PyMPI_MISSING_MPI_Improbe
#undef  PyMPI_MISSING_MPI_Mrecv
#undef  PyMPI_MISSING_MPI_Imrecv
/**/
#undef  PyMPI_MISSING_MPI_Ibarrier
#undef  PyMPI_MISSING_MPI_Ibcast
#undef  PyMPI_MISSING_MPI_Igather
#undef  PyMPI_MISSING_MPI_Igatherv
#undef  PyMPI_MISSING_MPI_Iscatter
#undef  PyMPI_MISSING_MPI_Iscatterv
#undef  PyMPI_MISSING_MPI_Iallgather
#undef  PyMPI_MISSING_MPI_Iallgatherv
#undef  PyMPI_MISSING_MPI_Ialltoall
#undef  PyMPI_MISSING_MPI_Ialltoallv
#undef  PyMPI_MISSING_MPI_Ialltoallw
#undef  PyMPI_MISSING_MPI_Ireduce
#undef  PyMPI_MISSING_MPI_Iallreduce
#undef  PyMPI_MISSING_MPI_Ireduce_scatter_block
#undef  PyMPI_MISSING_MPI_Ireduce_scatter
#undef  PyMPI_MISSING_MPI_Iscan
#undef  PyMPI_MISSING_MPI_Iexscan
/**/
#undef  PyMPI_MISSING_MPI_MAX_LIBRARY_VERSION_STRING
#undef  PyMPI_MISSING_MPI_Get_library_version
/**/
#endif /* OMPI < 1.7*/

#if 0
/**/
#undef PyMPI_MISSING_MPI_Neighbor_allgather
#undef PyMPI_MISSING_MPI_Neighbor_allgatherv
#undef PyMPI_MISSING_MPI_Neighbor_alltoall
#undef PyMPI_MISSING_MPI_Neighbor_alltoallv
#undef PyMPI_MISSING_MPI_Neighbor_alltoallw
#undef PyMPI_MISSING_MPI_Ineighbor_allgather
#undef PyMPI_MISSING_MPI_Ineighbor_allgatherv
#undef PyMPI_MISSING_MPI_Ineighbor_alltoall
#undef PyMPI_MISSING_MPI_Ineighbor_alltoallv
#undef PyMPI_MISSING_MPI_Ineighbor_alltoallw
/**/
#endif /* */

#endif /* MPI < 3.0*/

#endif /* !PyMPI_CONFIG_OPENMPI_H */
