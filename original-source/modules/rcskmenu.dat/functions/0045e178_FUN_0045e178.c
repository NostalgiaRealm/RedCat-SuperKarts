/*
 * FUN_0045e178 at 0045e178
 * undefined FUN_0045e178(void)
 * Address ranges: 0045e178-0045e1c7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045e178(int *param_1,int *param_2)

{
  HWND pHVar1;
  uint uVar2;
  int iVar3;
  
  FUN_004258a4(param_1,param_2);
  param_2[1] = param_2[1] | 0xb;
  if ((param_1[0x82] != 0) && (*(char *)(param_1[0x82] + 0x54) != '\0')) {
    param_2[2] = param_2[2] | 0x20;
    iVar3 = -0x10;
    pHVar1 = (HWND)FUN_00445724((int *)param_1[9]);
    uVar2 = GetWindowLongA(pHVar1,iVar3);
    uVar2 = uVar2 & 0xfdffffff;
    iVar3 = -0x10;
    pHVar1 = (HWND)FUN_00445724((int *)param_1[9]);
    SetWindowLongA(pHVar1,iVar3,uVar2);
  }
  return;
}

