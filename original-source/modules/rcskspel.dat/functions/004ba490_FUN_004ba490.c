/*
 * FUN_004ba490 at 004ba490
 * undefined FUN_004ba490(void)
 * Address ranges: 004ba490-004ba53c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004ba490(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (DAT_006ab95c == 0) {
    FUN_004afee0(s__s__d_____draw_mouse__Mouse_is_n_00501ff8,
                 s_C__libraries_dxdraw_Mouse_cpp_00501cc8,0x2de);
  }
  if (DAT_00501c90 == 1) {
    FUN_004afee0(s__s__d_____draw_mouse__You_can_t_c_00501fb4,
                 s_C__libraries_dxdraw_Mouse_cpp_00501cc8,0x2e3);
  }
  if ((DAT_00501c90 == 2) && (DAT_006ab964 == 0)) {
    FUN_004afee0(s__s__d_____draw_mouse__No_mouse_a_00501f80,
                 s_C__libraries_dxdraw_Mouse_cpp_00501cc8,0x2e8);
  }
  uVar1 = *(undefined4 *)(*(int *)(DAT_006ab894 + 8 + DAT_00501c88 * 0xc) + 4 + DAT_00501c8c * 8);
  FUN_004b9f30(param_1);
  FUN_004b64c0(param_1,uVar1,DAT_006ab954,DAT_006ab958,3);
  return;
}

