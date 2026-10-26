/*
 * FUN_00448fc4 at 00448fc4
 * undefined __register FUN_00448fc4(int param_1)
 * Address ranges: 00448fc4-0044903b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00448fc4(int param_1)

{
  int iVar1;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar2;
  
  FUN_004498c0(DAT_0047d7a8,(HWND)0x0);
  FUN_00449074(param_1);
  ReleaseDC(*(HWND *)(param_1 + 0x5c),*(HDC *)(param_1 + 0x58));
  iVar1 = *(int *)(param_1 + 0x60);
  if (*(char *)(*(int *)(iVar1 + 0x14) + 0x10) == '\x01') {
    iVar2 = (int)*(uint *)(param_1 + 0xc) >> 1;
    if (iVar2 < 0) {
      iVar2 = iVar2 + (uint)((*(uint *)(param_1 + 0xc) & 1) != 0);
    }
    *(int *)(iVar1 + 0x20) = iVar2 + *(int *)(param_1 + 0x54);
  }
  else {
    iVar2 = (int)*(uint *)(param_1 + 0xc) >> 1;
    if (iVar2 < 0) {
      iVar2 = iVar2 + (uint)((*(uint *)(param_1 + 0xc) & 1) != 0);
    }
    *(int *)(iVar1 + 0x20) = iVar2 + *(int *)(param_1 + 0x50);
  }
  FUN_00448f04(param_1,*(int *)(*(int *)(param_1 + 0x60) + 0x14),extraout_ECX);
  FUN_00447930(param_1,*(int *)(*(int *)(param_1 + 0x60) + 0x14),extraout_ECX_00);
  *(undefined4 *)(param_1 + 0x60) = 0;
  return;
}

