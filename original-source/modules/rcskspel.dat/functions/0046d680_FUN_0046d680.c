/*
 * FUN_0046d680 at 0046d680
 * undefined FUN_0046d680(void)
 * Address ranges: 0046d680-0046d6b4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046d680(uint param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = __ftol();
  param_1 = iVar1 << 0x18 | 0xffffff;
  piVar2 = (int *)FUN_0046c510();
  (**(code **)(*piVar2 + 0x28))(&param_1);
  return;
}

