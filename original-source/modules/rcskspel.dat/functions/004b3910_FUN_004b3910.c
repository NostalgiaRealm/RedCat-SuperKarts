/*
 * FUN_004b3910 at 004b3910
 * undefined FUN_004b3910(void)
 * Address ranges: 004b3910-004b399c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char * FUN_004b3910(int param_1)

{
  if (param_1 < -0x7787ffcd) {
    if (param_1 == -0x7787ffce) {
      return s_this_function_is_not_valid_for_t_00500240;
    }
    if (param_1 < -0x7ff8fff1) {
      if (param_1 == -0x7ff8fff2) {
        return s_not_enough_memory_free_for_the_d_005002fc;
      }
      if (param_1 == -0x7fffbfff) {
        return s_this_function_is_not_supported_a_00500334;
      }
      if (param_1 == -0x7ffbfef0) {
        return s_object_doesn_t_support_aggregati_00500360;
      }
    }
    else {
      if (param_1 == -0x7ff8ffa9) {
        return s_invalid_parameters_passed_to_thi_00500280;
      }
      if (param_1 == -0x7787fff6) {
        return s_request_failed_because_resources_005002ac;
      }
    }
  }
  else {
    switch(param_1) {
    case -0x7787ffba:
      return s_caller_doesn_t_have_the_priority_005001b4;
    case -0x7787ff9c:
      return s_specified_format_is_not_supporte_0050021c;
    case -0x7787ff88:
      return s_no_sound_driver_is_installed_ava_005001f4;
    case -0x7787ff56:
      return s_unitialized_error___call_the_ini_0050017c;
    }
  }
  return s_error_unidentified_00500168;
}

