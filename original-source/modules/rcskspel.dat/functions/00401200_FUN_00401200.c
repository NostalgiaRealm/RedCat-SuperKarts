/*
 * FUN_00401200 at 00401200
 * undefined FUN_00401200(void)
 * Address ranges: 00401200-004012d6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00401200(int param_1,undefined4 param_2)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (&DAT_00503ef0)[param_1 * 0x47];
  iVar3 = *(int *)(iVar2 * 0xd0 + 0xc + DAT_0067ee20);
  pfVar1 = (float *)(DAT_006a5c38 + iVar3 + 0x78 + iVar3 * 0xa8);
  if (*(float *)(DAT_006a5c38 + iVar3 + 0x78 + iVar3 * 0xa8) < 0.0) {
    *pfVar1 = *pfVar1 + 4096.0;
  }
  iVar3 = *(int *)(iVar2 * 0xd0 + 0xc + DAT_0067ee20);
  pfVar1 = (float *)(DAT_006a5c38 + iVar3 + 0x78 + iVar3 * 0xa8);
  if (4096.0 <= *(float *)(DAT_006a5c38 + iVar3 + 0x78 + iVar3 * 0xa8)) {
    *pfVar1 = *pfVar1 - 4096.0;
  }
  FUN_00414470(param_1);
  FUN_00401030(param_1,param_2);
  FUN_00414750(param_1);
  FUN_00412fd0(iVar2);
  FUN_004130e0(iVar2);
  iVar3 = FUN_00407580(iVar2);
  if (iVar3 == -1) {
    FUN_00413330(iVar2);
  }
  return;
}

