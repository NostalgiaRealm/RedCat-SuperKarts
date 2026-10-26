/*
 * FUN_0040b4f8 at 0040b4f8
 * undefined4 __register FUN_0040b4f8(byte * param_1, int param_2)
 * Address ranges: 0040b4f8-0040b56c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040b4f8(byte *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 0;
  if ((param_1 != (byte *)0x0) && (param_1[param_2] != 0)) {
    iVar3 = param_2;
    if (param_2 == 0) {
      if (((byte)(&DAT_0047b114)[(int)(uint)*param_1 >> 3] >> (*param_1 & 7) & 1) != 0) {
        uVar2 = 1;
      }
    }
    else {
      do {
        iVar3 = iVar3 + -1;
        if (iVar3 < 0) break;
      } while (((byte)(&DAT_0047b114)[(int)(uint)param_1[iVar3] >> 3] >> (param_1[iVar3] & 7) & 1)
               != 0);
      uVar1 = param_2 - iVar3 & 0x80000001;
      if ((int)uVar1 < 0) {
        uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
      }
      if (uVar1 == 0) {
        uVar2 = 2;
      }
      else if (((byte)(&DAT_0047b114)[(int)(uint)param_1[param_2] >> 3] >> (param_1[param_2] & 7) &
               1) != 0) {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}

