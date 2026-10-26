/*
 * FUN_004b0190 at 004b0190
 * undefined FUN_004b0190(void)
 * Address ranges: 004b0190-004b031f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char * FUN_004b0190(int param_1)

{
  if (param_1 < -0x7789fe51) {
    if (param_1 == -0x7789fe52) {
      return s_access_to_surface_denied_by_othe_004ff048;
    }
    if (param_1 < -0x7789ff5f) {
      if (param_1 == -0x7789ff60) {
        return s_one_or_more_surfaces_of_the_dd_o_004ff240;
      }
      if (param_1 < -0x7789ffa0) {
        if (param_1 == -0x7789ffa1) {
          return s_primary_surface_creation_request_004ff2f8;
        }
        if (param_1 < -0x7ff8fff1) {
          if (param_1 == -0x7ff8fff2) {
            return s_application_out_of_free_memory_004ff368;
          }
          if (param_1 == -0x7fffbfff) {
            return s_operation_is_not_supported_004ff388;
          }
          if (param_1 == -0x7fffbffb) {
            return s_undefined_error_condition_004ff3a4;
          }
        }
        else if (param_1 == -0x7ff8ffa9) {
          return s_one_or_more_invalid_parameters_004ff348;
        }
      }
      else {
        switch(param_1) {
        case -0x7789ff9c:
          return s_one_or_more_of_the_capability_bi_004ff2c4;
        case -0x7789ff88:
          return s_screen_mode_not_supported_004ff2a8;
        case -0x7789ff7e:
          return s_pointer_is_not_a_dd_object_004ff28c;
        case -0x7789ff6f:
          return s_pixel_format_is_invalid_004ff274;
        }
      }
    }
    else {
      switch(param_1) {
      case -0x7789ff4c:
        return s_hardware_does_not_support_alpha_a_004ff1c4;
      case -0x7789ff2c:
        return s_the_setcooperativelevel_must_be_c_004ff178;
      case -0x7789ff1f:
        return s_exclusive_mode_necessary_for_thi_004ff14c;
      case -0x7789ff1a:
        return s__hardware__flipping_of_visible_s_004ff110;
      case -0x7789fec0:
        return s_surface_does_not_use_an_8_bit_pa_004ff1f4;
      case -0x7789feac:
        return s__hardware__no_hardware_support_f_004ff0d4;
      case -0x7789fe98:
        return s_hardware_needed_for_this_operati_004ff094;
      case -0x7789fe84:
        return s_application_out_of_video_memory_004ff074;
      }
    }
  }
  else {
    switch(param_1) {
    case -0x7789fe3e:
      return s_access_to_surface_denied_because_004fece0;
    case -0x7789fde4:
      return s_previous_blit_is_still_in_progre_004fec8c;
    case -0x7789fdcf:
      return s_direct_draw_invalid_gui_id_004feed4;
    case -0x7789fdce:
      return s_direct_draw_object_already_creat_004ff024;
    case -0x7789fdcd:
      return s_hardware_only_dd_objects_not_all_004fee5c;
    case -0x7789fdcc:
      return s_application_already_created_a_pr_004fed10;
    case -0x7789fdcb:
      return s_there_is_no_software_emulation_f_004fee20;
    case -0x7789fdc6:
      return s_dd_is_prevented_from_restoring_s_004fef38;
    case -0x7789fdc5:
      return s_cooperative_level_for_HWND_alrea_004fef94;
    case -0x7789fdc4:
      return s_there_was_no_palette_attached_to_004fedb4;
    case -0x7789fdc3:
      return s_there_is_no_hardware_support_for_004fed78;
    case -0x7789fdbb:
      return s_exclusive_mode_was_already_set_004ff004;
    case -0x7789fdb5:
      return s_surface_was_created_in_different_004fec64;
    case -0x7789fdb4:
      return s_this_surface_was_implicitly_crea_004feef0;
    case -0x7789fdb3:
      return s_the_surface_being_used_is_not_a_p_004fed40;
    case -0x7789fdb2:
      return s_display_is_currently_in_an_unsup_004fecb0;
    case -0x7789fdb1:
      return s__hardware__no_mipmap_texture_map_004fede4;
    case -0x7789fdb0:
      return s_surface_type_incompatible_with_o_004feea8;
    }
  }
  return s_unidentified_error_004fec50;
}

