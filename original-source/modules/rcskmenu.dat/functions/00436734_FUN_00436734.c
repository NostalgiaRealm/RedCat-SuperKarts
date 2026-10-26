/*
 * FUN_00436734 at 00436734
 * undefined4 __register FUN_00436734(int param_1)
 * Address ranges: 00436734-0043677c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00436734(int param_1)

{
  undefined4 uVar1;
  HMENU pHVar2;
  
  if (*(int *)(param_1 + 0x28) == 0) {
    uVar1 = FUN_00403024(*(int **)(param_1 + 4),(int)&PTR_FUN_0043553c);
    if ((char)uVar1 == '\0') {
      pHVar2 = CreateMenu();
      *(HMENU *)(param_1 + 0x28) = pHVar2;
    }
    else {
      pHVar2 = CreatePopupMenu();
      *(HMENU *)(param_1 + 0x28) = pHVar2;
    }
    if (*(int *)(param_1 + 0x28) == 0) {
      FUN_004358cc((undefined4 *)PTR_PTR_0047c650);
    }
    FUN_00436528(param_1);
  }
  return *(undefined4 *)(param_1 + 0x28);
}

