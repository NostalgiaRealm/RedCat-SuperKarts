/*
 * FUN_0044fc80 at 0044fc80
 * undefined FUN_0044fc80(void)
 * Address ranges: 0044fc80-0044fdea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_0044fc80(int param_1)

{
  float fVar1;
  float fVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  ushort uVar10;
  
  cVar3 = FUN_00417e90(param_1);
  iVar5 = DAT_0053be28;
  if (cVar3 == '\0') {
    iVar5 = (&DAT_005081bc)[param_1 * 0x1c];
  }
  uVar4 = FUN_004500d0();
  iVar5 = FUN_00497bd0(iVar5,uVar4);
  uVar9 = 0;
  if (iVar5 != 0) {
    FUN_00417e90(param_1);
    iVar6 = FUN_00490ce0();
    FUN_004500d0();
    iVar7 = FUN_00490ce0();
    cVar3 = FUN_00417e90(param_1);
    iVar5 = DAT_0053be28;
    if (cVar3 == '\0') {
      iVar5 = (&DAT_005081bc)[param_1 * 0x1c];
    }
    iVar8 = FUN_004500d0();
    fVar1 = *(float *)(*(int *)(iVar5 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + DAT_006a5c38 + 0x54) -
            *(float *)(DAT_006a5c38 + *(int *)(iVar8 * 0xd0 + DAT_0067ee20 + 0xc) * 0xa9 + 0x54);
    if (fVar1 <= 0.0) {
      fVar1 = -fVar1;
    }
    fVar2 = *(float *)(DAT_006a5ee0 + 0x74 + iVar7 * 0xbc) +
            *(float *)(DAT_006a5ee0 + 0x74 + iVar6 * 0xbc);
    uVar10 = (ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
             (ushort)(fVar1 == fVar2) << 0xe;
    uVar9 = (uint)uVar10;
    if (fVar1 < fVar2) {
      return CONCAT31((uint3)(byte)(uVar10 >> 8),1);
    }
  }
  return uVar9;
}

