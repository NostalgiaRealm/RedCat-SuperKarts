/*
 * FUN_0049fbc0 at 0049fbc0
 * undefined FUN_0049fbc0(void)
 * Address ranges: 0049fbc0-0049fc56
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0049fbc0(void)

{
  int iVar1;
  
  iVar1 = DAT_006a5c40;
  if (DAT_006a5c44 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,s___array_hpp_004fc894,0xb9,
                 &DAT_006a5c4c,DAT_006a5c3c,&DAT_006a5c65);
    iVar1 = DAT_006a5c40;
  }
  for (; iVar1 < DAT_006a5c3c; iVar1 = iVar1 + 1) {
    if (*(char *)(DAT_006a5c48 + iVar1) == '\0') goto LAB_0049fc4c;
  }
  iVar1 = 0;
  if (0 < DAT_006a5c40) {
    do {
      if (*(char *)(DAT_006a5c48 + iVar1) == '\0') {
LAB_0049fc4c:
        *(undefined1 *)(DAT_006a5c48 + iVar1) = 1;
        DAT_006a5c40 = iVar1;
        return iVar1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_006a5c40);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,s___array_hpp_004fc894,0xce,&DAT_006a5c4c
               ,DAT_006a5c3c,&DAT_006a5c65);
  return -1;
}

