/*
 * FUN_00408160 at 00408160
 * undefined FUN_00408160(void)
 * Address ranges: 00408160-00408264
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 FUN_00408160(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float local_4;
  
  iVar4 = 0;
  local_4 = 100.0;
  iVar1 = (&DAT_00505108)[param_1 * 9];
  iVar5 = *(int *)(iVar1 * 0xd0 + 0x24 + DAT_0067ee20) * 0x50;
  if (0 < *(int *)(iVar5 + 0x24 + DAT_00680ae0)) {
    do {
      iVar2 = FUN_004944a0(iVar4);
      if (iVar1 != iVar2) {
        iVar2 = iVar2 * 0xd0;
        iVar3 = DAT_006a5c38 + *(int *)(iVar2 + 0xc + DAT_0067ee20) * 0xa9;
        fVar6 = (float10)FUN_00407f50(param_1,*(undefined4 *)(iVar3 + 0x50),
                                      *(undefined4 *)(iVar3 + 0x54),*(undefined4 *)(iVar3 + 0x58));
        if ((((float10)-1024.0 < fVar6) && (fVar6 < (float10)1024.0)) &&
           (*(float *)(iVar2 + 0xa4 + DAT_0067ee20) < local_4)) {
          local_4 = *(float *)(iVar2 + 0xa4 + DAT_0067ee20) - 3.0;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(iVar5 + 0x24 + DAT_00680ae0));
  }
  return (float10)local_4;
}

