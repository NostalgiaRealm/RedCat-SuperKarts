/*
 * FUN_004086de at 004086de
 * uint __register FUN_004086de(uint param_1, undefined4 param_2, byte * param_3)
 * Address ranges: 004086de-00408726
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_004086de(uint param_1,undefined4 param_2,byte *param_3)

{
  uint uVar1;
  int unaff_EBP;
  byte *unaff_ESI;
  int unaff_EDI;
  
  if ((char)param_1 == '*') {
    uVar1 = *(uint *)(unaff_EBP + -8);
    if (uVar1 <= *(uint *)(unaff_EBP + 8)) {
      *(int *)(unaff_EBP + -8) = *(int *)(unaff_EBP + -8) + 1;
    }
    if (unaff_ESI == param_3) {
LAB_00408632:
      uVar1 = FUN_004089e4(unaff_EDI - *(int *)(unaff_EBP + -4));
      return uVar1;
    }
    param_1 = CONCAT31((int3)(uVar1 >> 8),*unaff_ESI);
  }
  else {
    while ((0x2f < (byte)param_1 && ((byte)param_1 < 0x3a))) {
      if (unaff_ESI == param_3) goto LAB_00408632;
      param_1 = (uint)*unaff_ESI;
      unaff_ESI = unaff_ESI + 1;
    }
  }
  return param_1;
}

