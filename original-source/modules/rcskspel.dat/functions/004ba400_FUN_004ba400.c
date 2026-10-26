/*
 * FUN_004ba400 at 004ba400
 * undefined FUN_004ba400(void)
 * Address ranges: 004ba400-004ba489
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004ba400(undefined4 param_1)

{
  if (DAT_006ab95c == 0) {
    FUN_004afee0(s__s__d_____draw_mouse__Mouse_is_n_00501ff8,
                 s_C__libraries_dxdraw_Mouse_cpp_00501cc8,0x2c2);
  }
  if (DAT_00501c90 == 1) {
    FUN_004afee0(s__s__d_____draw_mouse__You_can_t_c_00501fb4,
                 s_C__libraries_dxdraw_Mouse_cpp_00501cc8,0x2c7);
  }
  if ((DAT_00501c90 == 2) && (DAT_006ab964 == 0)) {
    FUN_004afee0(s__s__d_____draw_mouse__No_mouse_a_00501f80,
                 s_C__libraries_dxdraw_Mouse_cpp_00501cc8,0x2cc);
  }
  if ((DAT_00501c6c != -1) && (DAT_00501c70 != -1)) {
    FUN_004ba1b0(param_1);
  }
  return;
}

