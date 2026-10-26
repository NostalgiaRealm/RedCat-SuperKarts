/*
 * FUN_00461904 at 00461904
 * undefined FUN_00461904(void)
 * Address ranges: 00461904-00461956
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00461904(int *param_1)

{
  undefined1 uVar1;
  int extraout_ECX;
  int extraout_ECX_00;
  int iVar2;
  int extraout_EDX;
  int iVar3;
  
  if ((char)param_1[0xd5] == '\x01') {
    FUN_00458c44(*(undefined4 *)(*(int *)PTR_DAT_0047c670 + 0x88));
    iVar2 = extraout_ECX;
    iVar3 = extraout_EDX;
  }
  else {
    uVar1 = (**(code **)(*(int *)param_1[0xd0] + 0xb4))();
    iVar3 = *(int *)(*(int *)PTR_DAT_0047c670 + 0x7c);
    *(undefined1 *)(iVar3 + 0x18) = uVar1;
    iVar2 = extraout_ECX_00;
  }
  *(undefined1 *)((int)param_1 + 0x34f) = 1;
  *(undefined1 *)(param_1 + 0xb5) = 1;
  FUN_0042eb18(param_1,iVar3,iVar2);
  return;
}

