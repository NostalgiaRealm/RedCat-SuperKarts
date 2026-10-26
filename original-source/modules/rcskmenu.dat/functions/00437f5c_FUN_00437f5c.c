/*
 * FUN_00437f5c at 00437f5c
 * undefined __register FUN_00437f5c(int param_1, byte param_2)
 * Address ranges: 00437f5c-00437fad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00437f5c(int param_1,byte param_2)

{
  uint uIDCheckItem;
  HMENU hMenu;
  UINT uCheck;
  
  if (param_2 != *(byte *)(param_1 + 0x2c)) {
    *(byte *)(param_1 + 0x2c) = param_2;
    if ((*(int *)(param_1 + 0x58) != 0) && ((*(byte *)(param_1 + 0x20) & 2) == 0)) {
      uCheck = *(UINT *)(&DAT_0047b868 + (uint)param_2 * 4);
      uIDCheckItem = (uint)*(ushort *)(param_1 + 0x44);
      hMenu = (HMENU)FUN_00436734(*(int *)(param_1 + 0x58));
      CheckMenuItem(hMenu,uIDCheckItem,uCheck);
    }
    if ((param_2 != 0) && (*(char *)(param_1 + 0x31) != '\0')) {
      FUN_00437f14(param_1);
    }
  }
  return;
}

