/*
 * FUN_00408727 at 00408727
 * VARIANTARG * __register FUN_00408727(byte param_1)
 * Address ranges: 00408727-0040874d;00408792-004087e6;004088a9-004089d8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

VARIANTARG * FUN_00408727(byte param_1)

{
  int *piVar1;
  ulonglong uVar2;
  ushort uVar3;
  _union_2683 *p_Var4;
  undefined4 uVar5;
  uint3 uVar10;
  int iVar6;
  VARIANTARG *pVVar7;
  uint uVar8;
  VARIANTARG *pVVar9;
  byte extraout_CL;
  uint uVar11;
  uint uVar12;
  byte bVar13;
  char cVar14;
  int extraout_EDX;
  short sVar15;
  int unaff_EBP;
  code *unaff_ESI;
  byte *pbVar16;
  
  bVar13 = param_1 & 0xdf;
  uVar5 = 1;
  uVar8 = *(uint *)(unaff_EBP + -8);
  if (*(uint *)(unaff_EBP + 8) < uVar8) goto LAB_00408794;
  *(int *)(unaff_EBP + -8) = *(int *)(unaff_EBP + -8) + 1;
  unaff_ESI = (code *)(*(int *)(unaff_EBP + 0xc) + uVar8 * 8);
  pVVar7 = *(VARIANTARG **)&((VARIANTARG *)unaff_ESI)->n1;
  uVar10 = (uint3)((uint)pVVar7 >> 8);
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch(*(undefined1 *)((int)&((VARIANTARG *)unaff_ESI)->n1 + 4)) {
  case 0:
    if (bVar13 == 0x44) {
      if ((int)pVVar7 < 0) {
        uVar5 = FUN_0040886e(-(int)pVVar7);
        *(undefined1 *)((int)&((VARIANTARG *)((int)unaff_ESI + -0x10))->n1 + 0xf) = 0x2d;
        return (VARIANTARG *)CONCAT31((int3)((uint)uVar5 >> 8),0x2d);
      }
    }
    else if (bVar13 != 0x55) {
      if (bVar13 == 0x58) {
        uVar8 = 0x10;
        goto LAB_00408873;
      }
      goto switchD_00408747_caseD_1;
    }
    uVar8 = 10;
    goto LAB_00408873;
  default:
    goto switchD_00408747_caseD_1;
  case 2:
    if (bVar13 == 0x53) {
      return pVVar7;
    }
    goto switchD_00408747_caseD_1;
  case 3:
    uVar3 = 0;
    goto LAB_00408969;
  case 4:
    if (bVar13 != 0x53) goto switchD_00408747_caseD_1;
    p_Var4 = &pVVar7->n1;
    pVVar7 = (VARIANTARG *)CONCAT31(uVar10,*(byte *)p_Var4);
    uVar8 = (uint)*(byte *)p_Var4;
    goto LAB_0040891f;
  case 5:
    if (bVar13 != 0x50) goto switchD_00408747_caseD_1;
    *(undefined4 *)(unaff_EBP + -0x20) = 8;
    uVar8 = 0x10;
LAB_00408873:
    pbVar16 = (byte *)(unaff_EBP + -0x61);
    do {
      uVar2 = ZEXT48(pVVar7);
      pVVar9 = (VARIANTARG *)(uVar2 / uVar8);
      cVar14 = (char)((uint)pVVar7 % uVar8);
      bVar13 = cVar14 + 0x30;
      if (0x39 < bVar13) {
        bVar13 = cVar14 + 0x37;
      }
      pbVar16 = pbVar16 + -1;
      *pbVar16 = bVar13;
      pVVar7 = pVVar9;
    } while (pVVar9 != (VARIANTARG *)0x0);
    uVar12 = (unaff_EBP + -0x61) - (int)pbVar16;
    uVar11 = *(uint *)(unaff_EBP + -0x20);
    if (uVar11 < 0x11) {
      iVar6 = uVar11 - uVar12;
      pVVar7 = (VARIANTARG *)0x0;
      if (uVar12 <= uVar11 && iVar6 != 0) {
        pVVar7 = (VARIANTARG *)CONCAT31((int3)(uVar2 / uVar8 >> 8),0x30);
        do {
          pbVar16 = pbVar16 + -1;
          *pbVar16 = 0x30;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      return pVVar7;
    }
    return (VARIANTARG *)0x0;
  case 6:
    if (bVar13 == 0x53) {
      pVVar9 = (VARIANTARG *)((uint)uVar10 << 8);
      iVar6 = *(int *)(unaff_EBP + -0x20);
      if (iVar6 != 0) {
        do {
          if (iVar6 == 0) {
            return pVVar9;
          }
          iVar6 = iVar6 + -1;
          p_Var4 = &pVVar7->n1;
          pVVar7 = (VARIANTARG *)((int)&pVVar7->n1 + 1);
        } while (*(char *)p_Var4 != '\0');
      }
      return pVVar9;
    }
switchD_00408747_caseD_1:
    do {
      uVar5 = 0;
LAB_00408794:
      iVar6 = FUN_004089d9(uVar5);
      pVVar7 = (VARIANTARG *)
               FUN_00408584(iVar6,*(byte **)(unaff_EBP + -0x14),
                            *(int *)(unaff_EBP + -0x24) - (int)*(byte **)(unaff_EBP + -0x14));
      bVar13 = extraout_CL;
switchD_00408747_caseD_10:
      piVar1 = (int *)(unaff_EBP + -0x30);
      *piVar1 = *(int *)&pVVar7->n1;
      *(ULONG *)(unaff_EBP + -0x2c) = (pVVar7->n1).decVal.Hi32;
      if (bVar13 == 0x44) {
        if ((*(uint *)(unaff_EBP + -0x2c) & 0x80000000) != 0) {
          iVar6 = *piVar1;
          *piVar1 = -*piVar1;
          *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + (uint)(iVar6 != 0);
          *(int *)(unaff_EBP + -0x2c) = -*(int *)(unaff_EBP + -0x2c);
          uVar5 = FUN_004087e7();
          *(undefined1 *)((int)&((VARIANTARG *)((int)unaff_ESI + -0x10))->n1 + 0xf) = 0x2d;
          return (VARIANTARG *)CONCAT31((int3)((uint)uVar5 >> 8),0x2d);
        }
code_r0x004087e7:
        uVar5 = 10;
        goto LAB_004087ec;
      }
      if (bVar13 == 0x55) goto code_r0x004087e7;
    } while (bVar13 != 0x58);
    uVar5 = 0x10;
LAB_004087ec:
    pbVar16 = (byte *)(unaff_EBP + -0x51);
    do {
      uVar8 = FUN_00405ec9(*piVar1,*(uint *)(unaff_EBP + -0x2c),uVar5,uVar5,0);
      bVar13 = (char)uVar8 + 0x30;
      if (0x39 < bVar13) {
        bVar13 = (char)uVar8 + 0x37;
      }
      pbVar16 = pbVar16 + -1;
      *pbVar16 = bVar13;
      iVar6 = FUN_00405dd4(*piVar1,*(uint *)(unaff_EBP + -0x2c),uVar5,uVar5,0);
      *piVar1 = iVar6;
      *(int *)(unaff_EBP + -0x2c) = extraout_EDX;
    } while (iVar6 != 0 || extraout_EDX != 0);
    uVar11 = (unaff_EBP + -0x51) - (int)pbVar16;
    uVar8 = *(uint *)(unaff_EBP + -0x20);
    if (uVar8 < 0x11) {
      iVar6 = uVar8 - uVar11;
      pVVar7 = (VARIANTARG *)0x0;
      if (uVar11 <= uVar8 && iVar6 != 0) {
        pVVar7 = (VARIANTARG *)0x30;
        do {
          pbVar16 = pbVar16 + -1;
          *pbVar16 = 0x30;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      return pVVar7;
    }
    return (VARIANTARG *)0x0;
  case 10:
    unaff_ESI = FUN_00403d38;
    goto LAB_004088f6;
  case 0xb:
    pVVar9 = pVVar7;
    if (bVar13 != 0x53) goto switchD_00408747_caseD_1;
    break;
  case 0xc:
    uVar3 = 1;
LAB_00408969:
    uVar10 = (uint3)uVar3;
    sVar15 = uVar3 << 8;
    if ((bVar13 == 0x47) || (sVar15 = (short)CONCAT31(uVar10,1), bVar13 == 0x45)) {
      uVar11 = *(uint *)(unaff_EBP + -0x20);
      uVar8 = 3;
      if (0x12 < uVar11) {
        uVar11 = 0xf;
      }
    }
    else {
      sVar15 = (short)CONCAT31(uVar10,2);
      if ((bVar13 != 0x46) && (sVar15 = (short)CONCAT31(uVar10,3), bVar13 != 0x4e)) {
        unaff_ESI = (code *)pVVar7;
        if (bVar13 != 0x4d) goto switchD_00408747_caseD_1;
        sVar15 = (short)CONCAT31(uVar10,4);
      }
      uVar11 = 0x12;
      uVar8 = *(uint *)(unaff_EBP + -0x20);
      if ((0x12 < uVar8) && (uVar8 = 2, bVar13 == 0x4d)) {
        uVar8 = (uint)DAT_0047d4f8;
      }
    }
    pVVar7 = (VARIANTARG *)
             FUN_0040c372((undefined1 *)(unaff_EBP + -0x71),pVVar7,(char)((ushort)sVar15 >> 8),uVar8
                          ,uVar11,(byte)sVar15);
    return pVVar7;
  case 0xd:
    if (bVar13 != 0x53) goto switchD_00408747_caseD_1;
    if ((pVVar7->n1).n2.vt < 2) {
      return pVVar7;
    }
    pVVar7 = (VARIANTARG *)FUN_004085dc((int *)(unaff_EBP + -0xc),pVVar7);
    pVVar9 = *(VARIANTARG **)(unaff_EBP + -0xc);
    break;
  case 0xf:
    unaff_ESI = FUN_00403d98;
LAB_004088f6:
    if (bVar13 != 0x53) goto switchD_00408747_caseD_1;
    (*unaff_ESI)(unaff_EBP + -0x10,pVVar7);
    pVVar7 = *(VARIANTARG **)(unaff_EBP + -0x10);
    pVVar9 = pVVar7;
    break;
  case 0x10:
    goto switchD_00408747_caseD_10;
  }
  if (pVVar9 == (VARIANTARG *)0x0) {
    return pVVar7;
  }
  uVar8 = *(uint *)((int)&pVVar9[-1].n1 + 0xc);
LAB_0040891f:
  if (*(uint *)(unaff_EBP + -0x20) < uVar8) {
    return pVVar7;
  }
  return pVVar7;
}

