/*
 * FUN_0044562c at 0044562c
 * undefined __register FUN_0044562c(int param_1)
 * Address ranges: 0044562c-00445663
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044562c(int param_1)

{
  tagRECT local_14;
  
  FUN_0043f054(param_1,&local_14.left);
  InflateRect(&local_14,1,1);
  InvalidateRect(*(HWND *)(*(int *)(param_1 + 0x24) + 0x14c),&local_14,-1);
  return;
}

