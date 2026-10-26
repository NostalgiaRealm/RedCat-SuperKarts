/*
 * FUN_004abbf0 at 004abbf0
 * undefined FUN_004abbf0(void)
 * Address ranges: 004abbf0-004abc86
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004abbf0(void)

{
  int iVar1;
  
  iVar1 = DAT_006a6298;
  if (DAT_006a629c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,s___array_hpp_004fc894,0xb9,
                 &DAT_006a62a4,DAT_006a6294,&DAT_006a62bd);
    iVar1 = DAT_006a6298;
  }
  for (; iVar1 < DAT_006a6294; iVar1 = iVar1 + 1) {
    if (*(char *)(DAT_006a62a0 + iVar1) == '\0') goto LAB_004abc7c;
  }
  iVar1 = 0;
  if (0 < DAT_006a6298) {
    do {
      if (*(char *)(DAT_006a62a0 + iVar1) == '\0') {
LAB_004abc7c:
        *(undefined1 *)(DAT_006a62a0 + iVar1) = 1;
        DAT_006a6298 = iVar1;
        return iVar1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_006a6298);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,s___array_hpp_004fc894,0xce,&DAT_006a62a4
               ,DAT_006a6294,&DAT_006a62bd);
  return -1;
}

