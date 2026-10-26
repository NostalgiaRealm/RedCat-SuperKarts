/*
 * FUN_00428690 at 00428690
 * undefined FUN_00428690(void)
 * Address ranges: 00428690-00428714
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00428690(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  if (((DAT_0053ba24 != 0) && (DAT_0053b9f0 != 0)) &&
     (fVar3 = (float10)FUN_0048f4e0(), (float10)12.0 <= (float10)1.0 / fVar3)) {
    iVar2 = 0;
    do {
      iVar1 = FUN_00428460();
      if (iVar1 == -1) {
        return;
      }
      FUN_00428490(iVar1,param_1,param_2,param_3,param_4,param_5,param_6);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 2);
  }
  return;
}

