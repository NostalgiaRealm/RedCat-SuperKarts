/*
 * FUN_004a36c0 at 004a36c0
 * undefined FUN_004a36c0(void)
 * Address ranges: 004a36c0-004a3756
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004a36c0(void)

{
  int iVar1;
  
  iVar1 = DAT_006a5e88;
  if (DAT_006a5e8c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,s___array_hpp_004fc894,0xb9,
                 &DAT_006a5e94,DAT_006a5e84,&DAT_006a5ead);
    iVar1 = DAT_006a5e88;
  }
  for (; iVar1 < DAT_006a5e84; iVar1 = iVar1 + 1) {
    if (*(char *)(DAT_006a5e90 + iVar1) == '\0') goto LAB_004a374c;
  }
  iVar1 = 0;
  if (0 < DAT_006a5e88) {
    do {
      if (*(char *)(DAT_006a5e90 + iVar1) == '\0') {
LAB_004a374c:
        *(undefined1 *)(DAT_006a5e90 + iVar1) = 1;
        DAT_006a5e88 = iVar1;
        return iVar1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_006a5e88);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,s___array_hpp_004fc894,0xce,&DAT_006a5e94
               ,DAT_006a5e84,&DAT_006a5ead);
  return -1;
}

