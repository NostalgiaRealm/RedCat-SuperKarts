/*
 * FUN_0046745c at 0046745c
 * undefined4 __register FUN_0046745c(int param_1, int param_2)
 * Address ranges: 0046745c-004674ab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0046745c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = FUN_004674c4(param_1);
  if (-1 < iVar1 + -1) {
    iVar4 = 0;
    do {
      iVar2 = FUN_004674ac(param_1,iVar4);
      if ((iVar2 == *(int *)(param_2 + 0x24)) && (param_1 == *(int *)(param_2 + 0x90))) {
        uVar3 = FUN_004674ac(param_1,iVar4);
        return uVar3;
      }
      iVar4 = iVar4 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return 0;
}

