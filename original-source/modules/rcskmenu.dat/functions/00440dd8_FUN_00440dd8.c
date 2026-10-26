/*
 * FUN_00440dd8 at 00440dd8
 * undefined __register FUN_00440dd8(int * param_1, int param_2)
 * Address ranges: 00440dd8-00440e7d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00440dd8(int *param_1,int param_2)

{
  int iVar1;
  
  (**(code **)(*param_1 + -0x10))(param_1,param_2);
  if ((*(ushort *)(param_1 + 8) & 3) == 0) {
    iVar1 = param_1[0x19];
    if ((*(int *)(iVar1 + 0xc) == 0) || (param_1[0xe] <= *(int *)(iVar1 + 0xc))) {
      if ((*(int *)(iVar1 + 0x14) != 0) && (param_1[0xe] < *(int *)(iVar1 + 0x14))) {
        *(int *)(iVar1 + 0x14) = param_1[0xe];
      }
    }
    else {
      *(int *)(iVar1 + 0xc) = param_1[0xe];
    }
    if ((*(int *)(iVar1 + 8) == 0) || (param_1[0xf] <= *(int *)(iVar1 + 8))) {
      if ((*(int *)(iVar1 + 0x10) != 0) && (param_1[0xf] < *(int *)(iVar1 + 0x10))) {
        *(int *)(iVar1 + 0x10) = param_1[0xf];
      }
    }
    else {
      *(int *)(iVar1 + 8) = param_1[0xf];
    }
    iVar1 = *(int *)(param_2 + 8);
    if ((((iVar1 != 0) && (param_1[0x24] != 0)) && ((*(byte *)((int)param_1 + 0x45) & 4) == 0)) &&
       ((((*(byte *)(iVar1 + 0x18) & 1) == 0 && (*(int *)(iVar1 + 0x10) != 0)) &&
        (*(int *)(iVar1 + 0x14) != 0)))) {
      FUN_00440624(param_1);
    }
  }
  return;
}

