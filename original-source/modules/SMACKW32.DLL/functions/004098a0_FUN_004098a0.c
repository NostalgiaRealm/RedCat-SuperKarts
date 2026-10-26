/*
 * FUN_004098a0 at 004098a0
 * undefined __fastcall FUN_004098a0(undefined4 param_1, int * param_2)
 * Address ranges: 004098a0-00409b83
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004098a0(undefined4 param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint unaff_EBP;
  uint uVar8;
  uint *unaff_ESI;
  int *unaff_EDI;
  int *piVar9;
  int *piStack_8;
  
  bVar3 = DAT_0040e9c0;
  bVar2 = (byte)unaff_EBP;
  if (DAT_0040e9c0 < 9) {
    DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
    uVar8 = *unaff_ESI;
    bVar2 = bVar2 | (byte)(uVar8 << (bVar3 - 1 & 0x1f));
    unaff_ESI = unaff_ESI + 1;
    uVar8 = uVar8 >> ((bVar3 - 10 ^ 0xff) & 0x1f);
  }
  else {
    DAT_0040e9c0 = DAT_0040e9c0 - 8;
    uVar8 = unaff_EBP >> 8;
  }
  bVar1 = DAT_0040e9c0;
  bVar3 = (byte)uVar8;
  if (DAT_0040e9c0 < 9) {
    DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
    uVar8 = *unaff_ESI;
    bVar3 = bVar3 | (byte)(uVar8 << (bVar1 - 1 & 0x1f));
    unaff_ESI = unaff_ESI + 1;
    uVar8 = uVar8 >> ((bVar1 - 10 ^ 0xff) & 0x1f);
  }
  else {
    DAT_0040e9c0 = DAT_0040e9c0 - 8;
    uVar8 = uVar8 >> 8;
  }
  bVar1 = DAT_0040e9c0;
  DAT_0040eae0 = CONCAT11(bVar3,bVar2);
  bVar2 = (byte)uVar8;
  if (DAT_0040e9c0 < 9) {
    DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
    uVar8 = *unaff_ESI;
    bVar2 = bVar2 | (byte)(uVar8 << (bVar1 - 1 & 0x1f));
    unaff_ESI = unaff_ESI + 1;
    uVar8 = uVar8 >> ((bVar1 - 10 ^ 0xff) & 0x1f);
  }
  else {
    DAT_0040e9c0 = DAT_0040e9c0 - 8;
    uVar8 = uVar8 >> 8;
  }
  bVar1 = DAT_0040e9c0;
  bVar3 = (byte)uVar8;
  if (DAT_0040e9c0 < 9) {
    DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
    uVar8 = *unaff_ESI;
    bVar3 = bVar3 | (byte)(uVar8 << (bVar1 - 1 & 0x1f));
    unaff_ESI = unaff_ESI + 1;
    uVar8 = uVar8 >> ((bVar1 - 10 ^ 0xff) & 0x1f);
  }
  else {
    DAT_0040e9c0 = DAT_0040e9c0 - 8;
    uVar8 = uVar8 >> 8;
  }
  bVar1 = DAT_0040e9c0;
  DAT_0040eae2 = CONCAT11(bVar3,bVar2);
  bVar2 = (byte)uVar8;
  if (DAT_0040e9c0 < 9) {
    DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
    uVar8 = *unaff_ESI;
    bVar2 = bVar2 | (byte)(uVar8 << (bVar1 - 1 & 0x1f));
    unaff_ESI = unaff_ESI + 1;
    uVar8 = uVar8 >> ((bVar1 - 10 ^ 0xff) & 0x1f);
  }
  else {
    DAT_0040e9c0 = DAT_0040e9c0 - 8;
    uVar8 = uVar8 >> 8;
  }
  bVar1 = DAT_0040e9c0;
  bVar3 = (byte)uVar8;
  if (DAT_0040e9c0 < 9) {
    DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
    uVar8 = *unaff_ESI;
    bVar3 = bVar3 | (byte)(uVar8 << (bVar1 - 1 & 0x1f));
    unaff_ESI = unaff_ESI + 1;
    uVar8 = uVar8 >> ((bVar1 - 10 ^ 0xff) & 0x1f);
  }
  else {
    DAT_0040e9c0 = DAT_0040e9c0 - 8;
    uVar8 = uVar8 >> 8;
  }
  DAT_0040eae4 = CONCAT11(bVar3,bVar2);
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  piStack_8 = (int *)0xfffffffe;
  piVar9 = piStack_8;
  while( true ) {
    while( true ) {
      piStack_8 = piVar9;
      piVar9 = unaff_EDI;
      DAT_0040e9c0 = DAT_0040e9c0 + -1;
      uVar5 = uVar8;
      if (DAT_0040e9c0 == '\0') {
        uVar5 = *unaff_ESI;
        unaff_ESI = unaff_ESI + 1;
        DAT_0040e9c0 = ' ';
      }
      uVar8 = uVar5 >> 1;
      if ((uVar5 & 1) == 0) break;
      if (piStack_8 == (int *)0xfffffffe) {
        unaff_EDI = piVar9 + 1;
      }
      else {
        unaff_EDI = piVar9 + 1;
      }
    }
    if (piStack_8 == (int *)0xffffffff) break;
    uVar5 = *DAT_0040e98c;
    puVar7 = DAT_0040e98c;
    while ((uVar5 & 0x80000000) == 0) {
      DAT_0040e9c0 = DAT_0040e9c0 + -1;
      if (DAT_0040e9c0 == '\0') {
        uVar8 = *unaff_ESI;
        unaff_ESI = unaff_ESI + 1;
        DAT_0040e9c0 = ' ';
      }
      if ((uVar8 & 1) == 0) {
        uVar5 = 4;
      }
      puVar7 = (uint *)((int)puVar7 + uVar5);
      uVar8 = uVar8 >> 1;
      uVar5 = *puVar7;
    }
    uVar6 = *DAT_0040e990;
    puVar7 = DAT_0040e990;
    while ((uVar6 & 0x80000000) == 0) {
      DAT_0040e9c0 = DAT_0040e9c0 + -1;
      if (DAT_0040e9c0 == '\0') {
        uVar8 = *unaff_ESI;
        unaff_ESI = unaff_ESI + 1;
        DAT_0040e9c0 = ' ';
      }
      if ((uVar8 & 1) == 0) {
        uVar6 = 4;
      }
      puVar7 = (uint *)((int)puVar7 + uVar6);
      uVar8 = uVar8 >> 1;
      uVar6 = *puVar7;
    }
    uVar4 = (short)uVar6 << 8 | (ushort)((uVar5 << 0x18) >> 0x18);
    if (DAT_0040eae0 == uVar4) {
      uVar4 = 0;
      param_2[1] = (int)piVar9;
    }
    else if (DAT_0040eae2 == uVar4) {
      uVar4 = 0;
      param_2[2] = (int)piVar9;
    }
    else if (DAT_0040eae4 == uVar4) {
      uVar4 = 0;
      param_2[3] = (int)piVar9;
    }
    *piVar9 = CONCAT31((int3)(((uint)uVar4 << 0x10) >> 8),1);
    unaff_EDI = piVar9 + 1;
    piVar9 = param_2;
    if (piStack_8 != (int *)0xfffffffe) {
      *piStack_8 = ((int)unaff_EDI - (int)piStack_8) * 0x2000;
      piVar9 = param_2;
    }
  }
  if (param_2[1] == 0) {
    param_2[1] = (int)piVar9;
  }
  if (param_2[2] == 0) {
    piVar9 = piVar9 + 1;
    param_2[2] = (int)piVar9;
  }
  if (param_2[3] == 0) {
    param_2[3] = (int)(piVar9 + 1);
  }
  return;
}

