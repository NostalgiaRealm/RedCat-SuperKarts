/*
 * FUN_004a75e0 at 004a75e0
 * undefined FUN_004a75e0(void)
 * Address ranges: 004a75e0-004a7676
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004a75e0(void)

{
  int iVar1;
  
  iVar1 = DAT_006a5ee8;
  if (DAT_006a5eec == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,s___array_hpp_004fc894,0xb9,
                 &DAT_006a5ef4,DAT_006a5ee4,&DAT_006a5f0d);
    iVar1 = DAT_006a5ee8;
  }
  for (; iVar1 < DAT_006a5ee4; iVar1 = iVar1 + 1) {
    if (*(char *)(DAT_006a5ef0 + iVar1) == '\0') goto LAB_004a766c;
  }
  iVar1 = 0;
  if (0 < DAT_006a5ee8) {
    do {
      if (*(char *)(DAT_006a5ef0 + iVar1) == '\0') {
LAB_004a766c:
        *(undefined1 *)(DAT_006a5ef0 + iVar1) = 1;
        DAT_006a5ee8 = iVar1;
        return iVar1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_006a5ee8);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,s___array_hpp_004fc894,0xce,&DAT_006a5ef4
               ,DAT_006a5ee4,&DAT_006a5f0d);
  return -1;
}

