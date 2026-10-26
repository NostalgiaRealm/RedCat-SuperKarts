/*
 * FUN_004122f5 at 004122f5
 * undefined __cdecl FUN_004122f5(int param_1, byte * param_2, int param_3, int param_4)
 * Address ranges: 004122f5-00412589
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004122f5(int param_1,byte *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  LONG LVar4;
  tagRECT local_28;
  tagRECT local_18;
  int local_8;
  
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____draw_control_text__con_00434410);
  }
  GetClientRect(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c),&local_18);
  GetWindowRect(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c),&local_28);
  if (*(int *)(param_3 + 0x90) == 0) {
    FUN_0040187a((byte *)s__s__d_____draw_control_text__try_0043446c);
  }
  local_8 = FUN_004152a3();
  FUN_004152ad(param_3);
  if (param_4 == 0) {
    local_28.left = local_28.left + (local_18.right + 1) / 2;
    local_28.top = local_28.top + (local_18.bottom + 1) / 2;
    iVar1 = FUN_00416f83((char *)param_2);
    local_28.left = local_28.left - iVar1 / 2;
    iVar1 = FUN_0041708c();
    iVar2 = local_28.top - iVar1 / 2;
    LVar4 = local_28.left;
    local_28.top = iVar2;
    iVar1 = FUN_00412061();
    FUN_0041635e(iVar1,LVar4,iVar2,param_2);
  }
  else if (param_4 == 1) {
    local_28.top = local_28.top + local_18.bottom / 2;
    iVar1 = FUN_0041708c();
    iVar2 = local_28.top - iVar1 / 2;
    iVar3 = local_28.left + 8;
    local_28.left = iVar3;
    local_28.top = iVar2;
    iVar1 = FUN_00412061();
    FUN_0041635e(iVar1,iVar3,iVar2,param_2);
  }
  else if (param_4 == 2) {
    local_28.top = local_28.top + local_18.bottom / 2;
    iVar1 = FUN_0041708c();
    local_28.top = local_28.top - iVar1 / 2;
    local_28.left = local_28.left + local_18.right;
    iVar1 = FUN_00416f83((char *)param_2);
    iVar2 = (local_28.left - iVar1 / 2) + -8;
    LVar4 = local_28.top;
    local_28.left = iVar2;
    iVar1 = FUN_00412061();
    FUN_0041635e(iVar1,iVar2,LVar4,param_2);
  }
  else {
    local_28.left = local_28.left + local_18.right / 2;
    local_28.top = local_28.top + local_18.bottom / 2;
    iVar1 = FUN_00416f83((char *)param_2);
    local_28.left = local_28.left - iVar1 / 2;
    iVar1 = FUN_0041708c();
    iVar2 = local_28.top - iVar1 / 2;
    LVar4 = local_28.left;
    local_28.top = iVar2;
    iVar1 = FUN_00412061();
    FUN_0041635e(iVar1,LVar4,iVar2,param_2);
  }
  FUN_004152ad(local_8);
  return;
}

