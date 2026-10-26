/*
 * FUN_0040b02c at 0040b02c
 * undefined4 __register FUN_0040b02c(int * param_1)
 * Address ranges: 0040b02c-0040b0aa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040b02c(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *param_1;
  if (iVar1 < -0x3fffff6d) {
    if (iVar1 == -0x3fffff6e) {
LAB_0040b090:
      return CONCAT31((int3)((uint)iVar1 >> 8),6);
    }
    if (iVar1 < -0x3fffff71) {
      if (iVar1 == -0x3fffff72) {
        return 0xc0000007;
      }
      if (iVar1 == -0x3ffffffb) {
        return 0xb;
      }
      if (iVar1 == -0x3fffff74) {
        return 4;
      }
      iVar1 = iVar1 + 0x3fffff73;
      if (iVar1 == 0) {
        return 9;
      }
    }
    else {
      uVar2 = iVar1 + 0x3fffff71;
      iVar1 = iVar1 + 0x3fffff6f;
      if (uVar2 < 2) goto LAB_0040b090;
      if (iVar1 == 0) {
        return 8;
      }
    }
  }
  else if (iVar1 < -0x3fffff69) {
    if (iVar1 == -0x3fffff6a) {
      return 0xc000000c;
    }
    if (iVar1 == -0x3fffff6d) {
      return 9;
    }
    if (iVar1 == -0x3fffff6c) {
      return 3;
    }
    iVar1 = iVar1 + 0x3fffff6b;
    if (iVar1 == 0) {
      return 5;
    }
  }
  else {
    if (iVar1 == -0x3fffff03) {
      return 0xe;
    }
    iVar1 = iVar1 + 0x3ffffec6;
    if (iVar1 == 0) {
      return 0xd;
    }
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),0x16);
}

