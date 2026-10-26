/*
 * FUN_0040b5d4 at 0040b5d4
 * int __register FUN_0040b5d4(int param_1, int param_2)
 * Address ranges: 0040b5d4-0040b621
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0040b5d4(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_2) {
    iVar1 = FUN_00403dd0(param_1);
    if ((param_2 <= iVar1) && (iVar3 = param_2, DAT_0047d5b8 != '\0')) {
      iVar1 = 1;
      iVar3 = 0;
      if (0 < param_2) {
        do {
          uVar2 = (uint)*(byte *)(param_1 + -1 + iVar1);
          if (((byte)(&DAT_0047b114)[(int)uVar2 >> 3] >> (uVar2 & 7) & 1) != 0) {
            iVar1 = iVar1 + 1;
          }
          iVar1 = iVar1 + 1;
          iVar3 = iVar3 + 1;
        } while (iVar1 <= param_2);
      }
    }
  }
  return iVar3;
}

