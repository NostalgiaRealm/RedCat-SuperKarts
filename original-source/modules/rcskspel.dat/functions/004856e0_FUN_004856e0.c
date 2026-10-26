/*
 * FUN_004856e0 at 004856e0
 * undefined FUN_004856e0(void)
 * Address ranges: 004856e0-00485709
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004856e0(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0x14;
  do {
    cVar1 = FUN_00485450();
    if (cVar1 != '\0') {
      *(int *)(param_1 + 0x1ef0) = *(int *)(param_1 + 0x1ef0) + -1;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

