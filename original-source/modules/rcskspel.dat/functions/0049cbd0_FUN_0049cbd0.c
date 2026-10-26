/*
 * FUN_0049cbd0 at 0049cbd0
 * undefined FUN_0049cbd0(void)
 * Address ranges: 0049cbd0-0049cc88
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0049cbd0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DAT_006a5ba8;
  if (DAT_006a5bac == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,
                 s_______Libs_Win3DLib_Include_arra_004fa4c0,0xb9,&DAT_006a5bb4,DAT_006a5ba4,
                 &DAT_006a5bcd);
    iVar1 = DAT_006a5ba8;
  }
  for (; iVar1 < DAT_006a5ba4; iVar1 = iVar1 + 1) {
    if (*(char *)(DAT_006a5bb0 + iVar1) == '\0') goto LAB_0049cc7c;
  }
  iVar1 = 0;
  if (0 < DAT_006a5ba8) {
    do {
      if (*(char *)(DAT_006a5bb0 + iVar1) == '\0') goto LAB_0049cc7c;
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_006a5ba8);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,
               s_______Libs_Win3DLib_Include_arra_004fa4c0,0xce,&DAT_006a5bb4,DAT_006a5ba4,
               &DAT_006a5bcd);
  iVar1 = -1;
LAB_0049cc5a:
  FUN_0049cc90(param_1);
  return iVar1;
LAB_0049cc7c:
  *(undefined1 *)(DAT_006a5bb0 + iVar1) = 1;
  DAT_006a5ba8 = iVar1;
  goto LAB_0049cc5a;
}

