/*
 * FUN_00418ad0 at 00418ad0
 * undefined FUN_00418ad0(void)
 * Address ranges: 00418ad0-00418c04
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00418ad0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  
  iVar2 = (*(code *)**(undefined4 **)(param_1 + 0x48))();
  if (iVar2 != 0) {
    FUN_00418730(param_3);
    FUN_004be6c9();
    iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x54) + 4) + param_3 * 0x10);
    iVar3 = __ftol();
    fVar5 = (float10)FUN_0048f4d0();
    if ((float10)((float)(iVar3 + iVar1) * 0.001) <= fVar5 - (float10)*(float *)(param_1 + 0x58)) {
      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x54) + 4) + 8 + param_3 * 0x10);
      iVar3 = __ftol();
      iVar4 = FUN_004be6c9();
      FUN_0049dd20(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x4c) + 4) + (iVar4 % iVar2) * 4));
      FUN_0049d780(0);
      FUN_0049d4d0(iVar3 + iVar1);
      fVar5 = (float10)FUN_0048f4d0();
      *(float *)(param_1 + 0x58) = (float)fVar5;
    }
  }
  return;
}

