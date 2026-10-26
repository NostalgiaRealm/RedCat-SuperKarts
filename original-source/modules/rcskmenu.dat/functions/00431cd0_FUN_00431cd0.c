/*
 * FUN_00431cd0 at 00431cd0
 * undefined __register FUN_00431cd0(int param_1)
 * Address ranges: 00431cd0-00431ceb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00431cd0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0041e184(*(int *)(param_1 + 0x88));
  if (iVar1 == 0) {
    LoadIconA((HINSTANCE)0x0,&DAT_00007f00);
  }
  return;
}

