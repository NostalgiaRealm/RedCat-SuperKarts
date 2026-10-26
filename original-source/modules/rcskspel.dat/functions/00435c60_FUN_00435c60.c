/*
 * FUN_00435c60 at 00435c60
 * undefined FUN_00435c60(void)
 * Address ranges: 00435c60-00435d4e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00435c60(float *param_1)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float local_c;
  undefined4 local_8;
  float local_4;
  
  piVar1 = (int *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20);
  local_c = *(float *)(*(int *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + DAT_006a5c38 +
                      0x50);
  local_8 = *(undefined4 *)(*piVar1 * 0xa9 + DAT_006a5c38 + 0x54);
  local_4 = *(float *)(*piVar1 * 0xa9 + DAT_006a5c38 + 0x58);
  iVar2 = *(int *)((&DAT_00503ef0)[(int)param_1[2] * 0x47] * 0xd0 + 0xc + DAT_0067ee20);
  fVar3 = *(float *)(DAT_006a5c38 + iVar2 + 0x50 + iVar2 * 0xa8) - local_c;
  fVar4 = *(float *)(DAT_006a5c38 + iVar2 + 0x58 + iVar2 * 0xa8) - local_4;
  fVar3 = fVar3 * fVar3 + fVar4 * fVar4;
  if (fVar3 < 10000.0) {
    fVar4 = (float)FUN_0040ec30((&DAT_00503ef0)[(int)param_1[2] * 0x47],&local_c);
    param_1[1] = fVar4;
    *param_1 = fVar3;
  }
  return;
}

