/*
 * FUN_00436a1c at 00436a1c
 * undefined __register FUN_00436a1c(void)
 * Address ranges: 00436a1c-00436ded;00436df5-0043727c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00436a1c(void)

{
  ushort uVar1;
  undefined1 *puVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  HBITMAP pHVar9;
  LPRECT ptVar10;
  HDC pHVar11;
  uint uVar12;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  uint uVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  uint *in_FS_OFFSET;
  bool bVar16;
  byte bVar17;
  int in_stack_00000004;
  uint in_stack_ffffffbc;
  UINT UVar18;
  UINT UVar19;
  uint uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  int local_8;
  
  bVar17 = 0;
  puStack_18 = &stack0xfffffffc;
  local_8 = 0;
  puStack_1c = &LAB_0043727d;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = (uint)&uStack_20;
  puVar2 = &stack0xfffffffc;
  if (*(char *)(in_stack_00000004 + -0x21) == '\0') {
    FUN_00418538(*(int **)(in_stack_00000004 + -0x28),(RECT *)(in_stack_00000004 + -0x20));
    puVar2 = puStack_18;
  }
  puStack_18 = puVar2;
  if (*(int *)(in_stack_00000004 + -0x2c) == 0) {
    uVar7 = FUN_00403024(*(int **)(in_stack_00000004 + -0x2c),(int)&PTR_FUN_0043553c);
    if ((char)uVar7 == '\0') {
      *(undefined1 *)(in_stack_00000004 + -0x2d) = 0;
    }
    else {
      *(undefined1 *)(in_stack_00000004 + -0x2d) =
           *(undefined1 *)(*(int *)(in_stack_00000004 + -0x2c) + 0x50);
    }
  }
  else {
    *(undefined1 *)(in_stack_00000004 + -0x2d) = 0;
  }
  *(int *)(in_stack_00000004 + -0x10) = *(int *)(in_stack_00000004 + -0x20) + 1;
  iVar5 = *(int *)(in_stack_00000004 + -0x1c) + 1;
  bVar16 = iVar5 == 0;
  *(int *)(in_stack_00000004 + -0xc) = iVar5;
  FUN_00403ee0(*(uint **)(*(int *)(in_stack_00000004 + -0x34) + 0x24),(uint *)&DAT_00437294);
  if (bVar16) {
    FUN_00418538(*(int **)(in_stack_00000004 + -0x28),(RECT *)(in_stack_00000004 + -0x20));
    *(undefined4 *)(in_stack_00000004 + -0x10) = 0;
    *(undefined4 *)(in_stack_00000004 + -8) = 0xfffffffc;
    *(undefined1 *)(in_stack_00000004 + -0x35) = 0;
    goto LAB_00436f7c;
  }
  uVar7 = extraout_ECX;
  if (*(int *)(in_stack_00000004 + -0x3c) == 0) {
LAB_00436b39:
    uVar4 = 0;
  }
  else {
    iVar5 = *(int *)(*(int *)(in_stack_00000004 + -0x34) + 0x34);
    if (iVar5 < 0) {
LAB_00436b12:
      if (*(char *)(*(int *)(in_stack_00000004 + -0x34) + 0x2c) == '\0') goto LAB_00436b39;
      piVar8 = *(int **)(*(int *)(in_stack_00000004 + -0x34) + 0x40);
      if (piVar8 != (int *)0x0) {
        cVar3 = (**(code **)(*piVar8 + 0x1c))();
        uVar7 = extraout_ECX_01;
        if (cVar3 == '\0') goto LAB_00436b39;
      }
    }
    else {
      iVar6 = FUN_00433bb0(*(int **)(in_stack_00000004 + -0x3c));
      uVar7 = extraout_ECX_00;
      if (iVar6 <= iVar5) goto LAB_00436b12;
    }
    uVar4 = 1;
  }
  *(undefined1 *)(in_stack_00000004 + -0x3d) = uVar4;
  if (*(char *)(in_stack_00000004 + -0x3d) == '\0') {
    piVar8 = *(int **)(*(int *)(in_stack_00000004 + -0x34) + 0x40);
    if (piVar8 != (int *)0x0) {
      cVar3 = (**(code **)(*piVar8 + 0x1c))();
      uVar7 = extraout_ECX_02;
      if (cVar3 == '\0') goto LAB_00436b71;
    }
    if ((*(int *)(in_stack_00000004 + -0x3c) == 0) || (*(char *)(in_stack_00000004 + 8) != '\0')) {
      *(undefined4 *)(in_stack_00000004 + -8) = *(undefined4 *)(in_stack_00000004 + -0x10);
      *(undefined4 *)(in_stack_00000004 + -4) = *(undefined4 *)(in_stack_00000004 + -0xc);
    }
    else {
      *(int *)(in_stack_00000004 + -8) =
           *(int *)(in_stack_00000004 + -0x10) +
           *(int *)(*(int *)(in_stack_00000004 + -0x3c) + 0x28);
      *(int *)(in_stack_00000004 + -4) =
           *(int *)(in_stack_00000004 + -0xc) + *(int *)(*(int *)(in_stack_00000004 + -0x3c) + 0x24)
      ;
    }
    *(undefined1 *)(in_stack_00000004 + -0x35) = 0;
  }
  else {
LAB_00436b71:
    *(undefined1 *)(in_stack_00000004 + -0x35) = 1;
    if (*(char *)(in_stack_00000004 + -0x3d) == '\0') {
      *(int *)(in_stack_00000004 + -8) = *(int *)(in_stack_00000004 + -0x10) + 0x10;
      *(int *)(in_stack_00000004 + -4) = *(int *)(in_stack_00000004 + -0xc) + 0x10;
    }
    else {
      *(int *)(in_stack_00000004 + -8) =
           *(int *)(in_stack_00000004 + -0x10) +
           *(int *)(*(int *)(in_stack_00000004 + -0x3c) + 0x28);
      *(int *)(in_stack_00000004 + -4) =
           *(int *)(in_stack_00000004 + -0xc) + *(int *)(*(int *)(in_stack_00000004 + -0x3c) + 0x24)
      ;
    }
    if (*(char *)(*(int *)(in_stack_00000004 + -0x34) + 0x2c) != '\0') {
      *(int *)(in_stack_00000004 + -8) = *(int *)(in_stack_00000004 + -8) + 1;
      *(int *)(in_stack_00000004 + -4) = *(int *)(in_stack_00000004 + -4) + 1;
      uVar7 = FUN_00417e98(*(int *)(*(int *)(in_stack_00000004 + -0x28) + 0x14));
      *(undefined4 *)(in_stack_00000004 + -0x44) = uVar7;
      if ((*(byte *)(in_stack_00000004 + 0xc) & 1) == 0) {
        uVar7 = FUN_00417e98(*(int *)(*(int *)(in_stack_00000004 + -0x28) + 0x14));
        *(undefined4 *)(in_stack_00000004 + -0x44) = uVar7;
        uVar7 = FUN_0041e8ac(0x8000000f,0x80000014);
        FUN_00417e74(*(int **)(*(int *)(in_stack_00000004 + -0x28) + 0x14),uVar7);
        FUN_00418538(*(int **)(in_stack_00000004 + -0x28),(RECT *)(in_stack_00000004 + -0x10));
      }
      else {
        FUN_00417ea0(*(int **)(*(int *)(in_stack_00000004 + -0x28) + 0x14),0x8000000f);
        FUN_00418538(*(int **)(in_stack_00000004 + -0x28),(RECT *)(in_stack_00000004 + -0x10));
      }
      FUN_00417ea0(*(int **)(*(int *)(in_stack_00000004 + -0x28) + 0x14),
                   *(undefined4 *)(in_stack_00000004 + -0x44));
      *(int *)(in_stack_00000004 + -0x10) = *(int *)(in_stack_00000004 + -0x10) + 1;
      *(int *)(in_stack_00000004 + -0xc) = *(int *)(in_stack_00000004 + -0xc) + 1;
      uVar7 = extraout_ECX_03;
    }
    if (*(char *)(in_stack_00000004 + -0x3d) == '\0') {
      puVar14 = (undefined4 *)(in_stack_00000004 + -0x10);
      puVar15 = (undefined4 *)(in_stack_00000004 + -0x58);
      for (iVar5 = 4; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar15 = *puVar14;
        puVar14 = puVar14 + (uint)bVar17 * -2 + 1;
        puVar15 = puVar15 + (uint)bVar17 * -2 + 1;
      }
      iVar5 = (**(code **)(**(int **)(*(int *)(in_stack_00000004 + -0x34) + 0x40) + 0x2c))();
      if (iVar5 < *(int *)(in_stack_00000004 + -8) - *(int *)(in_stack_00000004 + -0x10)) {
        iVar5 = (**(code **)(**(int **)(*(int *)(in_stack_00000004 + -0x34) + 0x40) + 0x2c))();
        uVar12 = (*(int *)(in_stack_00000004 + -8) - *(int *)(in_stack_00000004 + -0x10)) - iVar5;
        iVar5 = (int)uVar12 >> 1;
        if (iVar5 < 0) {
          iVar5 = iVar5 + (uint)((uVar12 & 1) != 0);
        }
        *(int *)(in_stack_00000004 + -0x10) = iVar5 + *(int *)(in_stack_00000004 + -0x10) + 1;
        iVar5 = (**(code **)(**(int **)(*(int *)(in_stack_00000004 + -0x34) + 0x40) + 0x2c))();
        *(int *)(in_stack_00000004 + -8) = iVar5 + *(int *)(in_stack_00000004 + -0x10);
      }
      iVar5 = (**(code **)(**(int **)(*(int *)(in_stack_00000004 + -0x34) + 0x40) + 0x20))();
      if (iVar5 < *(int *)(in_stack_00000004 + -4) - *(int *)(in_stack_00000004 + -0xc)) {
        iVar5 = (**(code **)(**(int **)(*(int *)(in_stack_00000004 + -0x34) + 0x40) + 0x20))();
        uVar12 = (*(int *)(in_stack_00000004 + -4) - *(int *)(in_stack_00000004 + -0xc)) - iVar5;
        iVar5 = (int)uVar12 >> 1;
        if (iVar5 < 0) {
          iVar5 = iVar5 + (uint)((uVar12 & 1) != 0);
        }
        *(int *)(in_stack_00000004 + -0xc) = iVar5 + *(int *)(in_stack_00000004 + -0xc) + 1;
        iVar5 = (**(code **)(**(int **)(*(int *)(in_stack_00000004 + -0x34) + 0x40) + 0x20))();
        *(int *)(in_stack_00000004 + -4) = iVar5 + *(int *)(in_stack_00000004 + -0xc);
      }
      FUN_004186bc(*(int **)(in_stack_00000004 + -0x28),in_stack_00000004 + -0x10,
                   *(int **)(*(int *)(in_stack_00000004 + -0x34) + 0x40));
      puVar14 = (undefined4 *)(in_stack_00000004 + -0x58);
      puVar15 = (undefined4 *)(in_stack_00000004 + -0x10);
      for (iVar5 = 4; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar15 = *puVar14;
        puVar14 = puVar14 + (uint)bVar17 * -2 + 1;
        puVar15 = puVar15 + (uint)bVar17 * -2 + 1;
      }
    }
    else {
      iVar5 = *(int *)(*(int *)(in_stack_00000004 + -0x34) + 0x34);
      if (iVar5 < 0) {
LAB_00436cf2:
        piVar8 = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',uVar7);
        *(int **)(in_stack_00000004 + -0x48) = piVar8;
        uVar12 = *in_FS_OFFSET;
        *in_FS_OFFSET = (uint)&stack0xffffffd4;
        (**(code **)(**(int **)(in_stack_00000004 + -0x48) + 0x3c))
                  (*(int **)(in_stack_00000004 + -0x48),1);
        pHVar9 = LoadBitmapA((HINSTANCE)0x0,&DAT_00007ff8);
        FUN_0041d86c(*(int **)(in_stack_00000004 + -0x48),pHVar9);
        *(undefined4 *)(in_stack_00000004 + -0x44) =
             *(undefined4 *)(*(int *)(*(int *)(in_stack_00000004 + -0x28) + 0xc) + 0x18);
        FUN_004176d0(*(int **)(*(int *)(in_stack_00000004 + -0x28) + 0xc),-0x7fffffee,
                     extraout_ECX_05);
        piVar8 = *(int **)(in_stack_00000004 + -0x48);
        iVar5 = (**(code **)(**(int **)(in_stack_00000004 + -0x48) + 0x20))();
        uVar13 = (*(int *)(in_stack_00000004 + -4) - *(int *)(in_stack_00000004 + -0xc)) - iVar5;
        iVar5 = (int)uVar13 >> 1;
        if (iVar5 < 0) {
          iVar5 = iVar5 + (uint)((uVar13 & 1) != 0);
        }
        iVar6 = iVar5 + *(int *)(in_stack_00000004 + -0xc) + 1;
        iVar5 = (**(code **)(**(int **)(in_stack_00000004 + -0x48) + 0x2c))();
        uVar13 = (*(int *)(in_stack_00000004 + -8) - *(int *)(in_stack_00000004 + -0x10)) - iVar5;
        iVar5 = (int)uVar13 >> 1;
        if (iVar5 < 0) {
          iVar5 = iVar5 + (uint)((uVar13 & 1) != 0);
        }
        FUN_00418458(*(int **)(in_stack_00000004 + -0x28),
                     iVar5 + *(int *)(in_stack_00000004 + -0x10) + 1,iVar6,piVar8);
        FUN_004176d0(*(int **)(*(int *)(in_stack_00000004 + -0x28) + 0xc),
                     *(int *)(in_stack_00000004 + -0x44),extraout_ECX_06);
        *in_FS_OFFSET = uVar12;
        FUN_00402eac(*(int **)(in_stack_00000004 + -0x48));
        return;
      }
      iVar6 = FUN_00433bb0(*(int **)(in_stack_00000004 + -0x3c));
      uVar7 = extraout_ECX_04;
      if (iVar6 <= iVar5) goto LAB_00436cf2;
      FUN_00433ea4(*(int **)(in_stack_00000004 + -0x3c),*(undefined4 *)(in_stack_00000004 + -0x28),
                   *(undefined4 *)(in_stack_00000004 + -0x10),
                   *(undefined1 *)(*(int *)(in_stack_00000004 + -0x34) + 0x2d),
                   *(undefined4 *)(*(int *)(in_stack_00000004 + -0x34) + 0x34),
                   *(undefined4 *)(in_stack_00000004 + -0xc));
    }
    if (*(char *)(*(int *)(in_stack_00000004 + -0x34) + 0x2c) != '\0') {
      *(int *)(in_stack_00000004 + -8) = *(int *)(in_stack_00000004 + -8) + -1;
      *(int *)(in_stack_00000004 + -4) = *(int *)(in_stack_00000004 + -4) + -1;
    }
  }
LAB_00436f7c:
  *(int *)(in_stack_00000004 + -0x10) = *(int *)(in_stack_00000004 + -0x10) + -1;
  *(int *)(in_stack_00000004 + -0xc) = *(int *)(in_stack_00000004 + -0xc) + -1;
  *(int *)(in_stack_00000004 + -8) = *(int *)(in_stack_00000004 + -8) + 2;
  *(int *)(in_stack_00000004 + -4) = *(int *)(in_stack_00000004 + -4) + 2;
  if ((*(char *)(*(int *)(in_stack_00000004 + -0x34) + 0x2c) != '\0') ||
     ((*(char *)(in_stack_00000004 + -0x21) != '\0' &&
      (*(char *)(in_stack_00000004 + -0x35) != '\0')))) {
    UVar19 = 0xf;
    UVar18 = *(UINT *)(&DAT_0047b8d8 +
                      (uint)*(byte *)(*(int *)(in_stack_00000004 + -0x34) + 0x2c) * 4);
    ptVar10 = (LPRECT)(in_stack_00000004 + -0x10);
    pHVar11 = (HDC)FUN_00418994(*(int **)(in_stack_00000004 + -0x28));
    DrawEdge(pHVar11,ptVar10,UVar18,UVar19);
  }
  if (*(char *)(in_stack_00000004 + -0x21) != '\0') {
    if (*(char *)(in_stack_00000004 + -0x35) != '\0') {
      *(int *)(in_stack_00000004 + -0x20) = *(int *)(in_stack_00000004 + -8) + 1;
    }
    if ((*(char *)(in_stack_00000004 + -0x59) == '\0') || (*(char *)(in_stack_00000004 + 8) == '\0')
       ) {
      FUN_00417ea0(*(int **)(*(int *)(in_stack_00000004 + -0x28) + 0x14),0x8000000d);
    }
    FUN_00418538(*(int **)(in_stack_00000004 + -0x28),(RECT *)(in_stack_00000004 + -0x20));
  }
  if ((*(char *)(in_stack_00000004 + 8) != '\0') && (*(char *)(in_stack_00000004 + -0x59) != '\0'))
  {
    if (*(char *)(in_stack_00000004 + -0x21) == '\0') {
      if ((*(byte *)(in_stack_00000004 + 0xc) & 0x40) != 0) {
        UVar19 = 0xf;
        UVar18 = 4;
        ptVar10 = (LPRECT)(in_stack_00000004 + -0x20);
        pHVar11 = (HDC)FUN_00418994(*(int **)(in_stack_00000004 + -0x28));
        DrawEdge(pHVar11,ptVar10,UVar18,UVar19);
      }
    }
    else {
      UVar19 = 0xf;
      UVar18 = 2;
      ptVar10 = (LPRECT)(in_stack_00000004 + -0x20);
      pHVar11 = (HDC)FUN_00418994(*(int **)(in_stack_00000004 + -0x28));
      DrawEdge(pHVar11,ptVar10,UVar18,UVar19);
    }
    if (*(char *)(in_stack_00000004 + -0x21) == '\0') {
      OffsetRect((LPRECT)(in_stack_00000004 + -0x20),0,-1);
    }
  }
  if ((*(char *)(in_stack_00000004 + -0x21) == '\0') ||
     (*(char *)(in_stack_00000004 + -0x35) == '\0')) {
    *(int *)(in_stack_00000004 + -0x20) = *(int *)(in_stack_00000004 + -8) + 1;
  }
  *(int *)(in_stack_00000004 + -0x20) = *(int *)(in_stack_00000004 + -0x20) + 2;
  *(int *)(in_stack_00000004 + -0x18) = *(int *)(in_stack_00000004 + -0x18) + -1;
  *(uint *)(in_stack_00000004 + -0x60) =
       (uint)(*(ushort *)(&DAT_0047b8d0 + (uint)*(byte *)(in_stack_00000004 + -0x2d) * 2) | 0x60);
  if ((*(char *)(in_stack_00000004 + -0x61) != '\0') &&
     ((*(byte *)(in_stack_00000004 + 0xd) & 1) != 0)) {
    *(uint *)(in_stack_00000004 + -0x60) = *(uint *)(in_stack_00000004 + -0x60) | 0x100000;
  }
  puVar14 = (undefined4 *)(in_stack_00000004 + -0x20);
  puVar15 = (undefined4 *)(in_stack_00000004 + -0x58);
  for (iVar5 = 4; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar15 = *puVar14;
    puVar14 = puVar14 + (uint)bVar17 * -2 + 1;
    puVar15 = puVar15 + (uint)bVar17 * -2 + 1;
  }
  if ((*(byte *)(in_stack_00000004 + 0xc) & 0x20) != 0) {
    FUN_0041799c(*(int **)(*(int *)(in_stack_00000004 + -0x28) + 0xc),1);
  }
  FUN_004367c4(*(int *)(in_stack_00000004 + -0x34),*(int **)(in_stack_00000004 + -0x28),
               *(int *)(*(int *)(in_stack_00000004 + -0x34) + 0x24),
               *(uint *)(in_stack_00000004 + -0x60) | 0x500,*(char *)(in_stack_00000004 + -0x21),
               (LPRECT)(in_stack_00000004 + -0x20));
  uVar12 = (*(int *)(in_stack_00000004 + -0x4c) - *(int *)(in_stack_00000004 + -0x54)) -
           (*(int *)(in_stack_00000004 + -0x14) - *(int *)(in_stack_00000004 + -0x1c));
  iVar5 = (int)uVar12 >> 1;
  if (iVar5 < 0) {
    iVar5 = iVar5 + (uint)((uVar12 & 1) != 0);
  }
  OffsetRect((LPRECT)(in_stack_00000004 + -0x20),0,iVar5);
  if (((*(char *)(in_stack_00000004 + 8) != '\0') && (*(char *)(in_stack_00000004 + -0x21) != '\0'))
     && (*(char *)(in_stack_00000004 + -0x59) != '\0')) {
    OffsetRect((LPRECT)(in_stack_00000004 + -0x20),1,0);
  }
  FUN_004367c4(*(int *)(in_stack_00000004 + -0x34),*(int **)(in_stack_00000004 + -0x28),
               *(int *)(*(int *)(in_stack_00000004 + -0x34) + 0x24),
               *(uint *)(in_stack_00000004 + -0x60),*(char *)(in_stack_00000004 + -0x21),
               (LPRECT)(in_stack_00000004 + -0x20));
  uVar1 = *(ushort *)(*(int *)(in_stack_00000004 + -0x34) + 0x54);
  if ((uVar1 != 0) && (*(char *)(in_stack_00000004 + 8) == '\0')) {
    *(undefined4 *)(in_stack_00000004 + -0x20) = *(undefined4 *)(in_stack_00000004 + -0x18);
    *(int *)(in_stack_00000004 + -0x18) = *(int *)(in_stack_00000004 + -0x50) + -10;
    ptVar10 = (LPRECT)(in_stack_00000004 + -0x20);
    cVar3 = *(char *)(in_stack_00000004 + -0x21);
    in_stack_ffffffbc = 2;
    FUN_00435978(uVar1,&local_8);
    FUN_004367c4(*(int *)(in_stack_00000004 + -0x34),*(int **)(in_stack_00000004 + -0x28),local_8,
                 in_stack_ffffffbc,cVar3,ptVar10);
  }
  *in_FS_OFFSET = in_stack_ffffffbc;
  FUN_00403b50(&local_8);
  return;
}

