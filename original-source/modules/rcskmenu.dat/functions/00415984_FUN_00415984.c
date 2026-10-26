/*
 * FUN_00415984 at 00415984
 * undefined __register FUN_00415984(HIMAGELIST param_1, HICON param_2)
 * Address ranges: 00415984-0041598d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00415984(HIMAGELIST param_1,HICON param_2)

{
  ImageList_ReplaceIcon(param_1,-1,param_2);
  return;
}

