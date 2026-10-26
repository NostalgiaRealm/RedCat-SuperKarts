/*
 * FUN_004657d8 at 004657d8
 * bool __register FUN_004657d8(void)
 * Address ranges: 004657d8-00465802
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_004657d8(void)

{
  int iVar1;
  
  iVar1 = FUN_00415918();
  if (iVar1 == 0) {
    InitCommonControls();
  }
  return iVar1 != 0;
}

