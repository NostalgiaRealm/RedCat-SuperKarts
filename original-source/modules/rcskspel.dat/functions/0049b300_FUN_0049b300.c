/*
 * FUN_0049b300 at 0049b300
 * undefined FUN_0049b300(void)
 * Address ranges: 0049b300-0049b342
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0049b300(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_0049b190(param_1);
  if (iVar1 == -1) {
    if (param_2 != 0) {
      if (param_3 != 0) {
        FUN_004a33b0();
        return;
      }
      FUN_004a3760(param_1);
      return;
    }
    FUN_004a3a70(param_1);
  }
  return;
}

