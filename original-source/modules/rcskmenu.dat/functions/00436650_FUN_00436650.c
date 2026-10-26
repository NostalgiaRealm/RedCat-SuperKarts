/*
 * FUN_00436650 at 00436650
 * undefined __register FUN_00436650(int * param_1)
 * Address ranges: 00436650-004366d1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00436650(int *param_1)

{
  HMENU pHVar1;
  int iVar2;
  undefined4 uVar3;
  UINT uPosition;
  UINT uFlags;
  
  if ((*(byte *)(param_1 + 8) & 8) != 0) {
    return;
  }
  if ((*(byte *)(param_1 + 8) & 2) == 0) {
    if ((int *)param_1[0x18] == (int *)0x0) {
      while( true ) {
        pHVar1 = (HMENU)FUN_00436734((int)param_1);
        iVar2 = GetMenuItemCount(pHVar1);
        if (iVar2 < 1) break;
        uFlags = 0x400;
        uPosition = 0;
        pHVar1 = (HMENU)FUN_00436734((int)param_1);
        RemoveMenu(pHVar1,uPosition,uFlags);
      }
      if ((param_1[0x16] == 0) &&
         (uVar3 = FUN_00403024((int *)param_1[0x19],(int)&PTR_FUN_00435264), (char)uVar3 != '\0')) {
        DestroyMenu((HMENU)param_1[10]);
        param_1[10] = 0;
      }
      else {
        FUN_00436528((int)param_1);
      }
      (**(code **)(*param_1 + 0x38))(param_1,0);
      return;
    }
    FUN_00436650((int *)param_1[0x18]);
    return;
  }
  *(undefined1 *)(param_1 + 0x1a) = 1;
  return;
}

