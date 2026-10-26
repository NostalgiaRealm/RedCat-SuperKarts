/*
 * FUN_00415be0 at 00415be0
 * undefined FUN_00415be0(void)
 * Address ranges: 00415be0-00415ce3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00415be0(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  uint3 uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  undefined4 local_40 [8];
  float local_20;
  float local_18;
  
  if (DAT_0053ba08 == 0) {
    if (DAT_0053ba70 == 1) {
      uVar12 = 0;
      goto LAB_00415c20;
    }
  }
  else if (DAT_0053ba70 != 1) {
    uVar12 = 0;
    goto LAB_00415c20;
  }
  uVar12 = 1;
LAB_00415c20:
  iVar7 = FUN_00493430(*(undefined4 *)(param_1 * 0xd0 + 0x1c + DAT_0067ee20),0,uVar12);
  iVar8 = FUN_00404be0(iVar7,0);
  pfVar1 = (float *)(iVar7 * 0x50 + 8 + DAT_00680ae0);
  fVar3 = *pfVar1;
  pfVar2 = (float *)(iVar8 * 0x50 + 8 + DAT_00680ae0);
  fVar4 = pfVar1[2];
  fVar5 = *pfVar2;
  fVar6 = pfVar2[2];
  iVar7 = *(int *)(param_1 * 0xd0 + 0xc + DAT_0067ee20);
  puVar10 = (undefined4 *)(DAT_006a5c38 + iVar7 * 0xa9 + 0x10);
  puVar11 = local_40;
  for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar11 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar11 = puVar11 + 1;
  }
  fVar3 = local_20 * (fVar5 - fVar3) + local_18 * (fVar6 - fVar4);
  uVar9 = (uint3)(CONCAT22((short)((uint)(iVar7 * 0x15) >> 0x10),
                           (ushort)(fVar3 < 0.0) << 8 | (ushort)NAN(fVar3) << 10 |
                           (ushort)(fVar3 == 0.0) << 0xe) >> 8);
  if (fVar3 < 0.0) {
    return (uint)uVar9 << 8;
  }
  return CONCAT31(uVar9,1);
}

