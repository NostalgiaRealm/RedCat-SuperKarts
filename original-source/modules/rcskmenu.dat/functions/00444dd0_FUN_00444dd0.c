/*
 * FUN_00444dd0 at 00444dd0
 * undefined __register FUN_00444dd0(int param_1, undefined4 param_2)
 * Address ranges: 00444dd0-00444e0d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00444dd0(int param_1,undefined4 param_2)

{
  bool bVar1;
  BOOL BVar2;
  undefined2 uVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  
  uVar3 = (undefined2)((uint)param_2 >> 0x10);
  if (((*(byte *)(param_1 + 0x40) & 0x10) != 0) && (*(int *)(param_1 + 0x24) != 0)) {
    bVar1 = FUN_00445a20(param_1);
    uVar3 = extraout_var;
    if (bVar1) {
      BVar2 = IsWindowVisible(*(HWND *)(param_1 + 0x14c));
      uVar3 = extraout_var_00;
      if (BVar2 != 0) {
        FUN_0044562c(param_1);
        uVar3 = extraout_var_01;
      }
    }
  }
  FUN_004426ec(param_1,CONCAT22(uVar3,0xb011));
  return;
}

