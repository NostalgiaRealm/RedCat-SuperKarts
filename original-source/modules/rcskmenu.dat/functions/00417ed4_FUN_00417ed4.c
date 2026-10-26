/*
 * FUN_00417ed4 at 00417ed4
 * undefined4 __register FUN_00417ed4(int param_1)
 * Address ranges: 00417ed4-00417fa0;00417fa8-00417fb1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00417ed4(int param_1)

{
  byte bVar1;
  int *piVar2;
  HBRUSH pHVar3;
  undefined4 uVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  LOGBRUSH local_14;
  int local_8;
  
  local_8 = *(int *)(param_1 + 0x10);
  if (*(int *)(local_8 + 8) == 0) {
    puStack_18 = (undefined1 *)0x417ef7;
    FUN_00416b10(DAT_0047d6d0);
    puStack_1c = &LAB_00417fa1;
    uStack_20 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_20;
    if (*(int *)(local_8 + 8) == 0) {
      piVar2 = *(int **)(local_8 + 0x18);
      if (piVar2 == (int *)0x0) {
        local_14.lbHatch = 0;
        bVar1 = *(byte *)(local_8 + 0x1c);
        if (bVar1 == 0) {
          local_14.lbStyle = 0;
          puStack_18 = &stack0xfffffffc;
        }
        else if (bVar1 == 1) {
          local_14.lbStyle = 1;
          puStack_18 = &stack0xfffffffc;
        }
        else {
          local_14.lbStyle = 2;
          local_14.lbHatch = (bVar1 & 0x7f) - 2;
          puStack_18 = &stack0xfffffffc;
        }
      }
      else {
        local_14.lbStyle = 3;
        puStack_18 = &stack0xfffffffc;
        (**(code **)(*piVar2 + 0x68))(piVar2,1);
        local_14.lbHatch = (**(code **)(**(int **)(local_8 + 0x18) + 0x60))();
      }
      local_14.lbColor = FUN_00417210(*(uint *)(local_8 + 0x14));
      pHVar3 = CreateBrushIndirect(&local_14);
      *(HBRUSH *)(local_8 + 8) = pHVar3;
    }
    *in_FS_OFFSET = uStack_20;
    puStack_18 = (undefined1 *)0x417fa8;
    puStack_1c = (undefined1 *)0x417fa0;
    uVar4 = FUN_00416b1c(DAT_0047d6d0);
    return uVar4;
  }
  return *(undefined4 *)(local_8 + 8);
}

