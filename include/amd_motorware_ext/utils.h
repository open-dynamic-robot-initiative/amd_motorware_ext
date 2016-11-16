#ifndef AMDMWEXT_UTILS_H_
#define AMDMWEXT_UTILS_H_

#include "sw/modules/math/src/32b/math.h"
#include "sw/modules/est/src/32b/est.h"

#ifdef __cplusplus
extern "C" {
#endif


//! \brief Remove offset from position in an overflow safe way
//!
//! Remove the offset from the position and preserve the range of the result
//! (position is periodic and lies within [-max_pos, +max_pos].  The
//! computations are done such that integer overflows are avoided, i.e. this
//! also works if values are near to the max. value of the used IQ values.
//! Note that this is important as pos_max may go up to 100 while the max. for
//! IQ24 is 127!
//!
//! \param position The actual position in range [-pos_max, +pos_max]
//! \param offset The offset between actual and desired zero position
//! \param pos_max The maximum position.  When going beyond that value, the
//!                position rolls over to -max_pos.
//! \returns Position with offset removed.
_iq UTILS_removePositionOffset(_iq position, _iq offset, _iq pos_max);


//! \brief Computes Torque in Nm
//!
//! This is a modified version of the function from user.c which does not need a
//! CTRL_Handle.
_iq UTILS_computeTorque_Nm(EST_Handle estHandle, MATH_vec2 Idq_pu,
		const _iq torque_Flux_sf, const _iq torque_Ls_sf);


#ifdef __cplusplus
}
#endif // extern "C"

#endif  // ifndef AMDMWEXT_UTILS_H_
