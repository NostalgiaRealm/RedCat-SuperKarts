/*
 * FUN_00443ff0 at 00443ff0
 * undefined FUN_00443ff0(void)
 * Address ranges: 00443ff0-0044419c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00443ff0(float param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  undefined1 local_4c [4];
  float local_48;
  float local_44;
  undefined4 local_40 [16];
  
  iVar1 = DAT_00508638;
  iVar2 = *(int *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20);
  pfVar5 = (float *)FUN_00498a80(local_4c);
  local_70 = *pfVar5;
  local_6c = pfVar5[1];
  local_68 = pfVar5[2];
  iVar2 = iVar2 * 0xa9;
  puVar8 = (undefined4 *)(iVar2 + 0x10 + DAT_006a5c38);
  puVar9 = local_40;
  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
  }
  pfVar5 = (float *)FUN_004a25f0(local_4c,&local_70,local_40);
  local_70 = *pfVar5;
  local_6c = pfVar5[1];
  local_68 = pfVar5[2];
  iVar1 = DAT_00680ba0 + iVar1 * 0x178;
  local_64 = *(float *)(iVar1 + 8);
  local_60 = *(float *)(iVar1 + 0xc);
  local_5c = *(float *)(iVar1 + 0x10);
  fVar3 = (local_70 + *(float *)(iVar2 + 0x50 + DAT_006a5c38)) - local_64;
  local_48 = (local_6c + *(float *)(iVar2 + 0x54 + DAT_006a5c38)) - local_60;
  local_44 = (local_68 + *(float *)(iVar2 + 0x58 + DAT_006a5c38)) - local_5c;
  fVar4 = SQRT(fVar3 * fVar3 + local_48 * local_48 + local_44 * local_44);
  if (fVar4 < 1.0 != 0 || (fVar4 == 1.0) != 0) {
    return CONCAT31((int3)(CONCAT22((short)((uint)DAT_006a5c38 >> 0x10),
                                    (ushort)(fVar4 < 1.0) << 8 | (ushort)NAN(fVar4) << 10 |
                                    (ushort)(fVar4 == 1.0) << 0xe) >> 8),1);
  }
  local_48 = local_48 * param_1;
  local_44 = local_44 * param_1;
  local_58 = fVar3 * param_1 + local_64;
  local_54 = local_48 + local_60;
  local_50 = local_44 + local_5c;
  uVar6 = FUN_004988a0(local_58,local_54,local_50);
  return uVar6 & 0xffffff00;
}

