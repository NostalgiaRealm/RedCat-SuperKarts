/*
 * FUN_00405af0 at 00405af0
 * char * __cdecl FUN_00405af0(int param_1)
 * Address ranges: 00405af0-00405bb0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char * __cdecl FUN_00405af0(int param_1)

{
  if (param_1 < -0x7ffbfeef) {
    if (param_1 == -0x7ffbfef0) {
      return s_object_doesn_t_support_aggregati_0042f080;
    }
    if (param_1 == -0x7fffbfff) {
      return s_this_function_is_not_supported_a_0042f154;
    }
  }
  else if (param_1 < -0x7ff8ffa8) {
    if (param_1 == -0x7ff8ffa9) {
      return s_invalid_parameters_passed_to_thi_0042efec;
    }
    if (param_1 == -0x7ff8fff2) {
      return s_not_enough_memory_free_for_the_d_0042f0a4;
    }
  }
  else {
    switch(param_1) {
    case -0x7787fff6:
      return s_request_failed_because_resources_0042ef78;
    case -0x7787ffce:
      return s_this_function_is_not_valid_for_t_0042f018;
    case -0x7787ffba:
      return s_caller_doesn_t_have_the_priority_0042f0dc;
    case -0x7787ff9c:
      return s_specified_format_is_not_supporte_0042efc8;
    case -0x7787ff88:
      return s_no_sound_driver_is_installed_ava_0042f058;
    case -0x7787ff56:
      return s_unitialized_error___call_the_ini_0042f11c;
    }
  }
  return s_error_unidentified_0042f180;
}

