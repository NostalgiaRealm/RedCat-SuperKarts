/*
 * FUN_00401f61 at 00401f61
 * char * __cdecl FUN_00401f61(int param_1)
 * Address ranges: 00401f61-0040221a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char * __cdecl FUN_00401f61(int param_1)

{
  if (param_1 < -0x7fffbffa) {
    if (param_1 == -0x7fffbffb) {
      return s_undefined_error_condition_0042c778;
    }
    if (param_1 == -0x7fffbfff) {
      return s_operation_is_not_supported_0042cdf8;
    }
  }
  else if (param_1 < -0x7ff8ffa8) {
    if (param_1 == -0x7ff8ffa9) {
      return s_one_or_more_invalid_parameters_0042c980;
    }
    if (param_1 == -0x7ff8fff2) {
      return s_application_out_of_free_memory_0042cd2c;
    }
  }
  else if (param_1 < -0x7789ff9b) {
    if (param_1 == -0x7789ff9c) {
      return s_one_or_more_of_the_capability_bi_0042c8f8;
    }
    if (param_1 == -0x7789ffa1) {
      return s_primary_surface_creation_request_0042c8a8;
    }
  }
  else if (param_1 < -0x7789ff7d) {
    if (param_1 == -0x7789ff7e) {
      return s_pointer_is_not_a_dd_object_0042c964;
    }
    if (param_1 == -0x7789ff88) {
      return s_screen_mode_not_supported_0042c948;
    }
  }
  else if (param_1 < -0x7789ff5f) {
    if (param_1 == -0x7789ff60) {
      return s_one_or_more_surfaces_of_the_dd_o_0042c9e4;
    }
    if (param_1 == -0x7789ff6f) {
      return s_pixel_format_is_invalid_0042c9a0;
    }
  }
  else if (param_1 < -0x7789ff2b) {
    if (param_1 == -0x7789ff2c) {
      return s_the_setcooperativelevel_must_be_c_0042ca94;
    }
    if (param_1 == -0x7789ff4c) {
      return s_hardware_does_not_support_alpha_a_0042ca64;
    }
  }
  else if (param_1 < -0x7789ff19) {
    if (param_1 == -0x7789ff1a) {
      return s__hardware__flipping_of_visible_s_0042cb94;
    }
    if (param_1 == -0x7789ff1f) {
      return s_exclusive_mode_necessary_for_thi_0042cb68;
    }
  }
  else if (param_1 < -0x7789feab) {
    if (param_1 == -0x7789feac) {
      return s__hardware__no_hardware_support_f_0042ccb0;
    }
    if (param_1 == -0x7789fec0) {
      return s_surface_does_not_use_an_8_bit_pa_0042ca18;
    }
  }
  else {
    switch(param_1) {
    case -0x7789fe98:
      return s_hardware_needed_for_this_operati_0042ccec;
    case -0x7789fe84:
      return s_application_out_of_video_memory_0042cd4c;
    case -0x7789fe52:
      return s_access_to_surface_denied_by_othe_0042cd9c;
    case -0x7789fe3e:
      return s_access_to_surface_denied_because_0042cdc8;
    case -0x7789fde4:
      return s_previous_blit_is_still_in_progre_0042ce44;
    case -0x7789fdcf:
      return s_direct_draw_invalid_gui_id_0042c92c;
    case -0x7789fdce:
      return s_direct_draw_object_already_creat_0042c734;
    case -0x7789fdcd:
      return s_hardware_only_dd_objects_not_all_0042cae0;
    case -0x7789fdcc:
      return s_application_already_created_a_pr_0042cd6c;
    case -0x7789fdcb:
      return s_there_is_no_software_emulation_f_0042cb2c;
    case -0x7789fdc6:
      return s_dd_is_prevented_from_restoring_s_0042c804;
    case -0x7789fdc5:
      return s_cooperative_level_for_HWND_alrea_0042c794;
    case -0x7789fdc4:
      return s_there_was_no_palette_attached_to_0042cc0c;
    case -0x7789fdc3:
      return s_there_is_no_hardware_support_for_0042cc3c;
    case -0x7789fdbb:
      return s_exclusive_mode_was_already_set_0042c758;
    case -0x7789fdb5:
      return s_surface_was_created_in_different_0042ce68;
    case -0x7789fdb4:
      return s_this_surface_was_implicitly_crea_0042c860;
    case -0x7789fdb3:
      return s_the_surface_being_used_is_not_a_p_0042cc78;
    case -0x7789fdb2:
      return s_display_is_currently_in_an_unsup_0042ce14;
    case -0x7789fdb1:
      return s__hardware__no_mipmap_texture_map_0042cbd0;
    case -0x7789fdb0:
      return s_surface_type_incompatible_with_o_0042c9b8;
    }
  }
  return s_unidentified_error_0042ce90;
}

