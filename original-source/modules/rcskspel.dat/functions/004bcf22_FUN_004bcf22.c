/*
 * FUN_004bcf22 at 004bcf22
 * undefined FUN_004bcf22(void)
 * Address ranges: 004bcf22-004bcf6e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004bcf22(int param_1,undefined4 param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  
  bVar4 = param_3 == 0;
  param_1 = param_1 + param_3;
  if (!bVar4) {
    do {
      puVar1 = (undefined1 *)(param_1 + -1);
      param_1 = param_1 + -1;
      iVar2 = FUN_004c1222(*puVar1,param_2);
      if (iVar2 == -1) break;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
    bVar4 = param_3 == 0;
  }
  if (bVar4) {
    uVar3 = 1;
  }
  else {
    if (param_3 == 0) {
      iVar2 = 1;
      do {
        FUN_004c09f0(param_2);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    uVar3 = 0;
  }
  return uVar3;
}

