/*
 * FUN_00428cc0 at 00428cc0
 * undefined FUN_00428cc0(void)
 * Address ranges: 00428cc0-00428d7a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00428cc0(void)

{
  char cVar1;
  DWORD DVar2;
  undefined4 uVar3;
  int iVar4;
  uint extraout_ECX;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 uVar13;
  undefined8 uVar14;
  undefined4 *puVar15;
  int iVar16;
  undefined4 uVar17;
  uint3 uVar5;
  uint3 uVar9;
  
  DVar2 = GetTickCount();
  iVar12 = 0;
  if (DAT_00508610 != -1 && -1 < DAT_00508610 + 1) {
    puVar11 = &DAT_005081bc;
    piVar10 = &DAT_0053a22c;
    do {
      if ((0 < *piVar10) && (5000 < (int)(DVar2 - *piVar10))) {
        *piVar10 = 0;
        cVar1 = FUN_00417e90(iVar12);
        uVar13 = DAT_0053be28;
        if (cVar1 == '\0') {
          uVar13 = *puVar11;
        }
        uVar3 = uVar13;
        FUN_0048a480(uVar13);
        uVar14 = FUN_0048a890(uVar3);
        uVar9 = (uint3)((ulonglong)uVar14 >> 0x28);
        uVar7 = CONCAT31(uVar9,1);
        uVar5 = (uint3)((ulonglong)uVar14 >> 8);
        uVar3 = CONCAT31(uVar5,1);
        uVar6 = extraout_ECX & 0xffffff00;
        iVar8 = (uint)uVar9 << 8;
        iVar4 = (uint)uVar5 << 8;
        uVar17 = 0x41a00000;
        puVar15 = &DAT_0067da60;
        iVar16 = iVar12;
        FUN_0048a480(uVar13,&DAT_0067da60,iVar4,iVar12,iVar8,uVar6,0x41a00000,uVar3,uVar7);
        FUN_0048a570(uVar13,puVar15,iVar4,iVar16,iVar8,uVar6,uVar17,uVar3,uVar7);
      }
      iVar12 = iVar12 + 1;
      piVar10 = piVar10 + 1;
      puVar11 = puVar11 + 0x1c;
    } while (iVar12 < DAT_00508610 + 1);
  }
  return;
}

