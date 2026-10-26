/*
 * FUN_00450678 at 00450678
 * int __register FUN_00450678(int param_1, byte * param_2, int param_3)
 * Address ranges: 00450678-00450792
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00450678(int param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  HPALETTE pHVar5;
  int iVar6;
  PALETTEENTRY *pPVar7;
  int iVar8;
  PALETTEENTRY *pPVar9;
  byte bVar10;
  int local_818;
  LOGPALETTE local_814 [128];
  PALETTEENTRY local_410 [256];
  
  bVar10 = 0;
  pbVar1 = param_2;
  iVar6 = param_3;
  iVar8 = param_3;
  if (-1 < param_3 + -1) {
    do {
      iVar8 = iVar8 + (uint)pbVar1[2] + (uint)pbVar1[1] + (uint)*pbVar1;
      iVar6 = iVar6 + -1;
      pbVar1 = pbVar1 + 4;
    } while (iVar6 != 0);
  }
  iVar6 = FUN_00410210(*(int *)(param_1 + 4));
  if (-1 < iVar6 + -1) {
    local_818 = 0;
    do {
      iVar2 = FUN_00410218(*(int *)(param_1 + 4),local_818);
      if (((iVar8 == *(int *)(iVar2 + 0xc)) && (param_3 == *(int *)(iVar2 + 0x418))) &&
         (uVar3 = FUN_00407ce4((int *)(iVar2 + 0x18),(int *)param_2,param_3 << 2),
         (char)uVar3 != '\0')) {
        FUN_004505e8(iVar2);
        return *(int *)(iVar2 + 0x10);
      }
      local_818 = local_818 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  piVar4 = FUN_0040fe4c((int *)&PTR_FUN_0045050c,'\x01',*(int **)(param_1 + 4));
  piVar4[3] = iVar8;
  FUN_0040282c((undefined4 *)param_2,piVar4 + 6,param_3 << 2);
  piVar4[0x106] = param_3;
  local_814[0].palVersion = 0x300;
  local_814[0].palNumEntries = (WORD)param_3;
  FUN_00450494((undefined4 *)param_2,(uint *)local_410);
  pPVar7 = local_410;
  pPVar9 = local_814[0].palPalEntry;
  for (iVar6 = 0x100; iVar6 != 0; iVar6 = iVar6 + -1) {
    *pPVar9 = *pPVar7;
    pPVar7 = pPVar7 + (uint)bVar10 * -2 + 1;
    pPVar9 = pPVar9 + (uint)bVar10 * -2 + 1;
  }
  pHVar5 = CreatePalette(local_814);
  piVar4[4] = (int)pHVar5;
  FUN_004505e8((int)piVar4);
  return piVar4[4];
}

