/*
 * FUN_004440b0 at 004440b0
 * int __register FUN_004440b0(int param_1)
 * Address ranges: 004440b0-004440e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004440b0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_0044401c(param_1);
  if ((0 < iVar1) && (iVar3 = iVar1 + -1, -1 < iVar3)) {
    do {
      iVar2 = FUN_0040f6b0(*(undefined4 **)(param_1 + 0x140),iVar3);
      if (*(char *)(iVar2 + 0x47) == '\0') {
        iVar1 = iVar1 + -1;
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != -1);
  }
  return iVar1;
}

