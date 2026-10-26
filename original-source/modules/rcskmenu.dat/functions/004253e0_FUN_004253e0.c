/*
 * FUN_004253e0 at 004253e0
 * undefined __register FUN_004253e0(int * param_1, int param_2)
 * Address ranges: 004253e0-004254af
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004253e0(int *param_1,int param_2)

{
  int iVar1;
  undefined4 extraout_ECX;
  ushort uVar2;
  
  iVar1 = *(int *)(param_2 + 8);
  uVar2 = *(ushort *)(iVar1 + 0x10);
  if ((*(uint *)(iVar1 + 0x10) & 0x1000) != 0) {
    uVar2 = uVar2 | 0x1000;
  }
  if ((*(uint *)(iVar1 + 0x10) & 0x20) != 0) {
    uVar2 = uVar2 | 0x20;
  }
  FUN_00418a14((int *)param_1[0x7d],*(int *)(iVar1 + 0x18));
  FUN_004188b4(param_1[0x7d]);
  FUN_004188d0(param_1[0x7d]);
  if ((-1 < *(int *)(iVar1 + 8)) && ((uVar2 & 1) != 0)) {
    FUN_00417ea0(*(int **)(param_1[0x7d] + 0x14),0x8000000d);
    FUN_004176d0(*(int **)(param_1[0x7d] + 0xc),-0x7ffffff2,extraout_ECX);
  }
  if (*(int *)(iVar1 + 8) < 0) {
    FUN_00418538((int *)param_1[0x7d],(RECT *)(iVar1 + 0x1c));
  }
  else {
    (**(code **)(*param_1 + 0xb8))(param_1,*(undefined4 *)(iVar1 + 8),iVar1 + 0x1c,uVar2);
  }
  if ((uVar2 & 0x10) != 0) {
    DrawFocusRect(*(HDC *)(iVar1 + 0x18),(RECT *)(iVar1 + 0x1c));
  }
  FUN_00418a14((int *)param_1[0x7d],0);
  return;
}

