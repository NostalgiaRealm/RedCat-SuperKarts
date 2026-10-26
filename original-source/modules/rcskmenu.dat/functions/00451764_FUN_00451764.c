/*
 * FUN_00451764 at 00451764
 * undefined __register FUN_00451764(int * param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 00451764-0045196b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_00451764(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  HPALETTE hpal;
  HANDLE h;
  undefined4 *puVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  undefined4 extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar4;
  undefined4 extraout_EDX_01;
  uint *puVar5;
  int *piVar6;
  int *piVar7;
  uint *puVar8;
  int *piVar9;
  byte bVar10;
  UINT iStart;
  UINT cEntries;
  tagPALETTEENTRY *pPalEntries;
  undefined1 *pv;
  int local_c34 [12];
  uint local_c04 [256];
  tagPALETTEENTRY local_804 [256];
  undefined1 local_404 [4];
  int local_400;
  int local_3fc;
  ushort local_3f2;
  int local_3c4;
  int local_3c0;
  int local_3bc;
  
  bVar10 = 0;
  piVar7 = (int *)(param_4 + -4);
  pPalEntries = local_804;
  cEntries = 0x100;
  iStart = 0;
  hpal = (HPALETTE)(**(code **)(*param_1 + 0x24))();
  GetPaletteEntries(hpal,iStart,cEntries,pPalEntries);
  FUN_0045043c(local_804,local_c04);
  puVar5 = local_c04;
  puVar8 = (uint *)(*piVar7 + 0x94);
  for (iVar2 = 0x100; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar8 = *puVar5;
    puVar5 = puVar5 + (uint)bVar10 * -2 + 1;
    puVar8 = puVar8 + (uint)bVar10 * -2 + 1;
  }
  FUN_0045272c((int *)*piVar7);
  pv = local_404;
  iVar2 = 0x400;
  h = (HANDLE)(**(code **)(*param_1 + 0x60))();
  iVar2 = GetObjectA(h,iVar2,pv);
  if (iVar2 == 0x18) {
    if (local_3f2 == 0x10) {
      FUN_004502d4(5,5,5,local_c34);
      piVar6 = local_c34;
      piVar9 = (int *)(*piVar7 + 0x494);
      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar9 = *piVar6;
        piVar6 = piVar6 + (uint)bVar10 * -2 + 1;
        piVar9 = piVar9 + (uint)bVar10 * -2 + 1;
      }
    }
    else {
      FUN_004502d4(8,8,8,local_c34);
      piVar6 = local_c34;
      piVar9 = (int *)(*piVar7 + 0x494);
      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar9 = *piVar6;
        piVar6 = piVar6 + (uint)bVar10 * -2 + 1;
        piVar9 = piVar9 + (uint)bVar10 * -2 + 1;
      }
    }
    FUN_00452624((int *)*piVar7,local_400,local_3fc,(uint)local_3f2);
    uVar3 = extraout_ECX;
    uVar4 = extraout_EDX;
  }
  else {
    if (iVar2 != 0x54) {
      return;
    }
    if (local_3f2 < 0x18) {
      if (local_3f2 < 9) {
        FUN_004502d4(8,8,8,local_c34);
        piVar6 = local_c34;
        piVar9 = (int *)(*piVar7 + 0x494);
        for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar9 = *piVar6;
          piVar6 = piVar6 + (uint)bVar10 * -2 + 1;
          piVar9 = piVar9 + (uint)bVar10 * -2 + 1;
        }
      }
      else {
        FUN_004502d4(local_3c4,local_3c0,local_3bc,local_c34);
        piVar6 = local_c34;
        piVar9 = (int *)(*piVar7 + 0x494);
        for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar9 = *piVar6;
          piVar6 = piVar6 + (uint)bVar10 * -2 + 1;
          piVar9 = piVar9 + (uint)bVar10 * -2 + 1;
        }
      }
    }
    else {
      FUN_004502d4(8,8,8,local_c34);
      piVar6 = local_c34;
      piVar9 = (int *)(*piVar7 + 0x494);
      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar9 = *piVar6;
        piVar6 = piVar6 + (uint)bVar10 * -2 + 1;
        piVar9 = piVar9 + (uint)bVar10 * -2 + 1;
      }
    }
    FUN_00452624((int *)*piVar7,local_400,local_3fc,(uint)local_3f2);
    uVar3 = extraout_ECX_00;
    uVar4 = extraout_EDX_00;
  }
  puVar1 = (undefined4 *)FUN_00451eac((int *)*piVar7,uVar4,uVar3);
  FUN_00402b54(puVar1,*(uint *)(*piVar7 + 0x7c),0);
  piVar7 = (int *)FUN_00451e40(*piVar7,extraout_EDX_01,extraout_ECX_01);
  FUN_00418458(piVar7,0,0,param_1);
  return;
}

