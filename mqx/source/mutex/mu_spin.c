/**HEADER********************************************************************
* 
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 2004-2008 Embedded Access Inc.;
* All Rights Reserved
*
* Copyright (c) 1989-2008 ARC International;
* All Rights Reserved
*
*************************************************************************** 
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR 
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
* THE POSSIBILITY OF SUCH DAMAGE.
*
**************************************************************************
*
* $FileName: mu_spin.c$
* $Version : 3.0.4.0$
* $Date    : Nov-21-2008$
*
* Comments:
*
*   This file contains the function for setting the limited
*   spin field of the mutex attributes field.
*
*END************************************************************************/

#include "mqx_inc.h"
#if MQX_USE_MUTEXES
#include "mutex.h"
#include "mutx_prv.h"

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : _mutatr_set_spin_limit
* Returned Value   : _mqx_uint MQX_EOK on success or POSIX error code
* Comments         :
*    Used by a task to set the limited spin a mutex attributes structure.
*
*END*----------------------------------------------------------------------*/

_mqx_uint _mutatr_set_spin_limit
   (
      /* [IN] the mutex attributes address */
      MUTEX_ATTR_STRUCT_PTR attr_ptr,

      /* [IN] the limited spin count */
      _mqx_uint             spin_count
   )
{ /* Body */
   _KLOGM(KERNEL_DATA_STRUCT_PTR kernel_data;)

   _KLOGM(_GET_KERNEL_DATA(kernel_data);)
   _KLOGE3(KLOG_mutatr_set_spin_limit, attr_ptr, spin_count);

#if MQX_MUTEX_HAS_POLLING
#if MQX_CHECK_ERRORS
   if (attr_ptr == NULL) {
      _KLOGX2(KLOG_mutatr_set_spin_limit, MQX_EINVAL);
      return(MQX_EINVAL);
   } /* Endif */
#endif
#if MQX_CHECK_VALIDITY
   if (attr_ptr->VALID != MUTEX_VALID) {
      _KLOGX2(KLOG_mutatr_set_spin_limit, MQX_EINVAL);
      return(MQX_EINVAL);
   } /* Endif */
#endif

   attr_ptr->COUNT = spin_count;

   _KLOGX2(KLOG_mutatr_set_spin_limit, MQX_EOK);
   return(MQX_EOK);
#else
   _KLOGX2(KLOG_mutatr_set_spin_limit, MQX_EINVAL);
   return(MQX_EINVAL);
#endif

   
} /* Endbody */
#endif /* MQX_USE_MUTEXES */

/* EOF */
