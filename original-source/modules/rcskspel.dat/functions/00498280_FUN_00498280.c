/*
 * FUN_00498280 at 00498280
 * undefined FUN_00498280(void)
 * Address ranges: 00498280-0049833a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00498280(void)

{
  int iVar1;
  
  iVar1 = DAT_00680ba8;
  if (DAT_00680bac == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,
                 s_______Libs_Win3DLib_Include_arra_004fa4c0,0xb9,&DAT_00680bb4,DAT_00680ba4,
                 &DAT_00680bcd);
    iVar1 = DAT_00680ba8;
  }
  for (; iVar1 < DAT_00680ba4; iVar1 = iVar1 + 1) {
    if (*(char *)(DAT_00680bb0 + iVar1) == '\0') goto LAB_0049832e;
  }
  iVar1 = 0;
  if (0 < DAT_00680ba8) {
    do {
      if (*(char *)(DAT_00680bb0 + iVar1) == '\0') goto LAB_0049832e;
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_00680ba8);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,
               s_______Libs_Win3DLib_Include_arra_004fa4c0,0xce,&DAT_00680bb4,DAT_00680ba4,
               &DAT_00680bcd);
  iVar1 = -1;
LAB_0049830a:
  FUN_004afce0(s_Camera__d_added__This_pointer_____004fb3a0,iVar1,DAT_00680ba0 + iVar1 * 0x178);
  return iVar1;
LAB_0049832e:
  *(undefined1 *)(DAT_00680bb0 + iVar1) = 1;
  DAT_00680ba8 = iVar1;
  goto LAB_0049830a;
}

