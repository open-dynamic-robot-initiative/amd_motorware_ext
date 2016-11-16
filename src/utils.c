#include <amd_motorware_ext/utils.h>

_iq UTILS_removePositionOffset(_iq position, _iq offset, _iq pos_max)
{
	// Remove offset in a way that preserves the range and does not exceed the
	// max. value in subterms of the calculations (which would cause integer
	// overflows and make it explode).
	if (offset < 0)
	{
		_iq off_p_max = offset + pos_max;
		if (position < off_p_max) {
			position -= offset;
		} else {
			position = (position - pos_max) - off_p_max;
		}
	}
	else if (offset > 0)
	{
		_iq off_m_max = offset - pos_max;
		if (position > off_m_max) {
			position -= offset;
		} else {
			position = (position + pos_max) - off_m_max;
		}
	}

	/*
	 * The above code does the same thing than this one, but avoids overflows by
	 * ensuring that subterms never get greater than max_pos.
	 *
		position = positon - offset
		if (position > mrev_max) {
			position -= 2 * mrev_max;
		} else if (position < -mrev_max) {
			position += 2 * mrev_max;
		}
	*/

	return position;
}


_iq UTILS_computeTorque_Nm(EST_Handle estHandle, MATH_vec2 Idq_pu,
		const _iq torque_Flux_sf, const _iq torque_Ls_sf)
{
  _iq Flux_pu = EST_getFlux_pu(estHandle);
  _iq Id_pu = Idq_pu.value[0];
  _iq Iq_pu = Idq_pu.value[1];
  _iq Ld_minus_Lq_pu = _IQ30toIQ(
		  EST_getLs_d_pu(estHandle) - EST_getLs_q_pu(estHandle));
  _iq Torque_Flux_Iq_Nm = _IQmpy(
		  _IQmpy(Flux_pu, Iq_pu),
		  torque_Flux_sf);
  _iq Torque_Ls_Id_Iq_Nm = _IQmpy(
		  _IQmpy(
				  _IQmpy(Ld_minus_Lq_pu, Id_pu),
				  Iq_pu),
		  torque_Ls_sf);
  _iq Torque_Nm = Torque_Flux_Iq_Nm + Torque_Ls_Id_Iq_Nm;

  return(Torque_Nm);
} // end of USER_computeTorque_Nm() function
