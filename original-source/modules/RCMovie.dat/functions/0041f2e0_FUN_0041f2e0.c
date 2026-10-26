/*
 * FUN_0041f2e0 at 0041f2e0
 * undefined __thiscall FUN_0041f2e0(void * this, int param_1)
 * Address ranges: 0041f2e0-0041f31f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0041f2e0(void *this,int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  *(int *)((int)this + 0x2c) = param_1;
  if (param_1 == 1) {
    uVar2 = DAT_00438438;
    pvVar1 = (void *)FUN_0041f140((int)this);
    FUN_0041f0e0(pvVar1,uVar2);
    return;
  }
  uVar2 = DAT_00438418;
  if (param_1 != 2) {
    uVar2 = DAT_00438434;
  }
  pvVar1 = (void *)FUN_0041f140((int)this);
  FUN_0041f0e0(pvVar1,uVar2);
  return;
}

