/*
 * FUN_00402034 at 00402034
 * int __register FUN_00402034(int param_1)
 * Address ranges: 00402034-0040205f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00402034(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 < 0) {
    param_1 = param_1 + 3;
  }
  iVar2 = param_1 >> 2;
  if (iVar2 < 0x401) {
    do {
      iVar1 = *(int *)(DAT_0047d490 + -0xc + iVar2 * 4);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x401);
  }
  return 0;
}

