/*
 * FUN_00449930 at 00449930
 * undefined FUN_00449930(void)
 * Address ranges: 00449930-00449965
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00449930(int *param_1)

{
  int iVar1;
  
  if (*param_1 != 0) {
    iVar1 = 0;
    if (0 < param_1[1]) {
      do {
        FUN_004bc150(*(undefined4 *)(*param_1 + iVar1 * 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_1[1]);
    }
    FUN_004bc150(*param_1);
  }
  return;
}

