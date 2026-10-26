/*
 * FUN_00446fa8 at 00446fa8
 * undefined __register FUN_00446fa8(int param_1)
 * Address ranges: 00446fa8-00446fcb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00446fa8(int param_1)

{
  bool bVar1;
  
  bVar1 = FUN_00433874(param_1);
  if ((bVar1) && (*(int *)(param_1 + 100) != 0)) {
    ImageList_DragLeave(*(HWND *)(param_1 + 100));
    *(undefined4 *)(param_1 + 100) = 0;
  }
  return;
}

