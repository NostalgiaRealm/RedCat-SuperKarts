/*
 * FUN_00437f14 at 00437f14
 * undefined __register FUN_00437f14(int param_1)
 * Address ranges: 00437f14-00437f5b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00437f14(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x58) != 0) {
    iVar1 = FUN_00438084(*(int *)(param_1 + 0x58));
    if (-1 < iVar1 + -1) {
      iVar3 = 0;
      do {
        iVar2 = FUN_00438094(*(int *)(param_1 + 0x58),iVar3);
        if (((param_1 != iVar2) && (*(char *)(iVar2 + 0x31) != '\0')) &&
           (*(char *)(iVar2 + 0x33) == *(char *)(param_1 + 0x33))) {
          FUN_00437f5c(iVar2,0);
        }
        iVar3 = iVar3 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return;
}

