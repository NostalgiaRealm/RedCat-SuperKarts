/*
 * FUN_00443a64 at 00443a64
 * undefined __register FUN_00443a64(int * param_1, int param_2)
 * Address ranges: 00443a64-00443b20
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00443a64(int *param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  BOOL BVar4;
  
  if (((((char)param_1[0x4e] == '\0') || ((*(byte *)(param_1 + 0x10) & 0x10) == 0)) ||
      (param_1[9] == 0)) || ((*(byte *)(*(int *)(param_2 + 8) + 0x18) & 8) != 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((*(byte *)(*(int *)(param_2 + 8) + 0x18) & 2) == 0) {
    BVar4 = IsWindowVisible((HWND)param_1[0x53]);
    if (BVar4 == 0) goto LAB_00443aa9;
    bVar2 = true;
  }
  else {
LAB_00443aa9:
    bVar2 = false;
  }
  if ((*(byte *)(*(int *)(param_2 + 8) + 0x18) & 1) == 0) {
    BVar4 = IsWindowVisible((HWND)param_1[0x53]);
    if (BVar4 != 0) {
      bVar3 = true;
      goto LAB_00443ad1;
    }
  }
  bVar3 = false;
LAB_00443ad1:
  if ((bVar1) && (bVar2 || bVar3)) {
    FUN_0044562c((int)param_1);
  }
  if ((*(byte *)((int)param_1 + 0x45) & 2) == 0) {
    FUN_00445a2c((int)param_1);
  }
  FUN_00440dd8(param_1,param_2);
  if ((bVar1) && ((bVar2 || bVar3 || ((*(byte *)(*(int *)(param_2 + 8) + 0x18) & 0xc0) != 0)))) {
    FUN_0044562c((int)param_1);
  }
  return;
}

