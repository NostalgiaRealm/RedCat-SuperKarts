/*
 * FUN_00409800 at 00409800
 * int __stdcall FUN_00409800(void)
 * Address ranges: 00409800-00409893
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00409800(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint unaff_EBP;
  uint uVar4;
  uint *unaff_ESI;
  int *unaff_EDI;
  int *piVar5;
  int *piStack_8;
  
  iVar3 = -0x80000000;
  piStack_8 = (int *)0xfffffffe;
  while( true ) {
    while( true ) {
      piVar5 = unaff_EDI;
      DAT_0040e9c0 = DAT_0040e9c0 - 1;
      uVar4 = unaff_EBP;
      if (DAT_0040e9c0 == 0) {
        uVar4 = *unaff_ESI;
        unaff_ESI = unaff_ESI + 1;
        DAT_0040e9c0 = 0x20;
      }
      bVar1 = DAT_0040e9c0;
      unaff_EBP = uVar4 >> 1;
      if ((uVar4 & 1) == 0) break;
      if (piStack_8 == (int *)0xfffffffe) {
        unaff_EDI = piVar5 + 1;
        piStack_8 = piVar5;
      }
      else {
        unaff_EDI = piVar5 + 1;
        piStack_8 = piVar5;
      }
    }
    if (piStack_8 == (int *)0xffffffff) break;
    bVar2 = (byte)unaff_EBP;
    if (DAT_0040e9c0 < 9) {
      DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
      uVar4 = *unaff_ESI;
      bVar2 = bVar2 | (byte)(uVar4 << (bVar1 - 1 & 0x1f));
      unaff_ESI = unaff_ESI + 1;
      unaff_EBP = uVar4 >> ((bVar1 - 10 ^ 0xff) & 0x1f);
    }
    else {
      DAT_0040e9c0 = DAT_0040e9c0 - 8;
      unaff_EBP = uVar4 >> 9;
    }
    iVar3 = CONCAT31((int3)((uint)iVar3 >> 8),bVar2);
    *piVar5 = iVar3;
    unaff_EDI = piVar5 + 1;
    if (piStack_8 != (int *)0xfffffffe) {
      *piStack_8 = (int)unaff_EDI - (int)piStack_8;
    }
  }
  return iVar3;
}

