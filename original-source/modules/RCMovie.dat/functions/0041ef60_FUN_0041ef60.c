/*
 * FUN_0041ef60 at 0041ef60
 * undefined __thiscall FUN_0041ef60(void * this, undefined8 * param_1)
 * Address ranges: 0041ef60-0041efa2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0041ef60(void *this,undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  
  if ((*(char *)((int)this + 4) != '\0') &&
     (piVar1 = *(int **)((int)this + 0xd), piVar1 != (int *)0x0)) {
    iVar2 = *piVar1;
    uVar3 = FUN_0041efd0(param_1);
    iVar2 = (**(code **)(iVar2 + 0x28))(piVar1,uVar3);
    if (iVar2 < 0) {
      FUN_004015a6((byte *)s__s__d____Failed_seeking__00437084);
    }
  }
  return;
}

