/*
 * FUN_00437fb0 at 00437fb0
 * undefined __register FUN_00437fb0(int * param_1, byte param_2)
 * Address ranges: 00437fb0-00438026
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00437fb0(int *param_1,byte param_2)

{
  int iVar1;
  uint uIDEnableItem;
  HMENU hMenu;
  UINT uEnable;
  
  if (param_2 == *(byte *)((int)param_1 + 0x2d)) {
    return;
  }
  *(byte *)((int)param_1 + 0x2d) = param_2;
  if (((*(int *)PTR_DAT_0047c9d4 != 2) || (iVar1 = FUN_00438084((int)param_1), iVar1 == 0)) &&
     ((param_1[0x16] == 0 || (*(int *)(param_1[0x16] + 0x60) == 0)))) {
    if ((param_1[0x16] != 0) && ((*(byte *)(param_1 + 8) & 2) == 0)) {
      uEnable = *(UINT *)(&DAT_0047b870 + (uint)param_2 * 4);
      uIDEnableItem = (uint)*(ushort *)(param_1 + 0x11);
      hMenu = (HMENU)FUN_00436734(param_1[0x16]);
      EnableMenuItem(hMenu,uIDEnableItem,uEnable);
    }
    (**(code **)(*param_1 + 0x38))(param_1,0);
    return;
  }
  (**(code **)(*param_1 + 0x38))(param_1,1);
  return;
}

