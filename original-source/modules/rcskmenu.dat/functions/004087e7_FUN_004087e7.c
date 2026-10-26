/*
 * FUN_004087e7 at 004087e7
 * undefined __register FUN_004087e7(void)
 * Address ranges: 004087e7-00408841
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004087e7(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  int extraout_EDX;
  int *unaff_EBX;
  int unaff_EBP;
  byte *pbVar5;
  
  pbVar5 = (byte *)(unaff_EBP + -0x51);
  do {
    uVar1 = FUN_00405ec9(*unaff_EBX,unaff_EBX[1],10,10,0);
    bVar4 = (char)uVar1 + 0x30;
    if (0x39 < bVar4) {
      bVar4 = (char)uVar1 + 0x37;
    }
    pbVar5 = pbVar5 + -1;
    *pbVar5 = bVar4;
    iVar2 = FUN_00405dd4(*unaff_EBX,unaff_EBX[1],10,10,0);
    *unaff_EBX = iVar2;
    unaff_EBX[1] = extraout_EDX;
  } while (iVar2 != 0 || extraout_EDX != 0);
  uVar3 = (unaff_EBP + -0x51) - (int)pbVar5;
  uVar1 = *(uint *)(unaff_EBP + -0x20);
  if (uVar1 < 0x11) {
    iVar2 = uVar1 - uVar3;
    if (uVar3 <= uVar1 && iVar2 != 0) {
      do {
        pbVar5 = pbVar5 + -1;
        *pbVar5 = 0x30;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    return;
  }
  return;
}

