/*
 * FUN_00402e0c at 00402e0c
 * undefined1 __register FUN_00402e0c(int param_1, int param_2)
 * Address ranges: 00402e0c-00402e32
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_00402e0c(int param_1,int param_2)

{
  uint uVar1;
  short sVar2;
  
  sVar2 = 0;
  if (param_2 != 0) {
    uVar1 = (uint)**(byte **)(param_1 + -0x2c);
    if (uVar1 == *(uint *)(param_2 + -4)) {
      do {
        sVar2 = (((*(byte **)(param_1 + -0x2c))[uVar1] ^ *(byte *)(param_2 + -1 + uVar1)) & 0xdf) *
                0x100;
        if ((char)((ushort)sVar2 >> 8) != '\0') goto LAB_00402e2f;
        uVar1 = uVar1 - 1;
      } while (uVar1 != 0);
      sVar2 = sVar2 + 1;
    }
  }
LAB_00402e2f:
  return (char)sVar2;
}

