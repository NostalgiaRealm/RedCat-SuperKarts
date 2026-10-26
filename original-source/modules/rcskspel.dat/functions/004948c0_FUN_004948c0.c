/*
 * FUN_004948c0 at 004948c0
 * undefined FUN_004948c0(void)
 * Address ranges: 004948c0-0049499f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004948c0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = DAT_00680b30;
  if (DAT_00680b34 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,
                 s_______Libs_Win3DLib_Include_arra_004fa4c0,0xb9,&DAT_00680b3c,DAT_00680b2c,
                 &DAT_00680b55);
    iVar1 = DAT_00680b30;
  }
  for (; iVar1 < DAT_00680b2c; iVar1 = iVar1 + 1) {
    if (*(char *)(DAT_00680b38 + iVar1) == '\0') goto LAB_00494994;
  }
  iVar1 = 0;
  if (0 < DAT_00680b30) {
    do {
      if (*(char *)(DAT_00680b38 + iVar1) == '\0') goto LAB_00494994;
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_00680b30);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,
               s_______Libs_Win3DLib_Include_arra_004fa4c0,0xce,&DAT_00680b3c,DAT_00680b2c,
               &DAT_00680b55);
  iVar1 = -1;
LAB_0049494e:
  FUN_004afce0(s_loading_chunk___d_004faf78,iVar1);
  FUN_004949c0(param_1);
  FUN_00494d20(param_2);
  return iVar1;
LAB_00494994:
  *(undefined1 *)(DAT_00680b38 + iVar1) = 1;
  DAT_00680b30 = iVar1;
  goto LAB_0049494e;
}

