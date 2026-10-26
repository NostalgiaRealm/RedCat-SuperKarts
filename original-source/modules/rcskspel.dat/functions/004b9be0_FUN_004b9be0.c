/*
 * FUN_004b9be0 at 004b9be0
 * undefined FUN_004b9be0(void)
 * Address ranges: 004b9be0-004b9c25
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b9be0(int param_1)

{
  if (DAT_006ab95c != 0) {
    FUN_004afee0(s__s__d_____set_mouse_type__Can_t_c_00501d1c,
                 s_C__libraries_dxdraw_Mouse_cpp_00501cc8,0x55);
  }
  if ((0 < param_1) && (param_1 < 3)) {
    DAT_00501c90 = param_1;
    return;
  }
  FUN_004afee0(s__s__d_____set_mouse_type__Unknow_00501ce8,s_C__libraries_dxdraw_Mouse_cpp_00501cc8,
               0x5f,param_1);
  return;
}

