/*
 * FUN_0046d9a0 at 0046d9a0
 * undefined FUN_0046d9a0(void)
 * Address ranges: 0046d9a0-0046d9ba
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046d9a0(int param_1)

{
  uint uVar1;
  void *pvVar2;
  
  uVar1 = *(int *)(param_1 + 0x28) << 2;
  if ((int)uVar1 < 0) {
    uVar1 = 0;
  }
  pvVar2 = operator_new(uVar1);
  *(void **)(param_1 + 0x24) = pvVar2;
  return;
}

