/*
 * FUN_0048c030 at 0048c030
 * undefined FUN_0048c030(void)
 * Address ranges: 0048c030-0048c13c;0048c157-0048c169
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0048c030(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004d1570;
  local_10 = ExceptionList;
  iVar2 = param_1 * 0xd0;
  iVar3 = DAT_006a5c38 + *(int *)(iVar2 + 0xc + DAT_0067ee20) * 0xa9;
  ExceptionList = &local_10;
  FUN_004977d0(*(undefined4 *)(iVar2 + 0x1c + DAT_0067ee20),*(undefined4 *)(iVar3 + 0x50),
               *(undefined4 *)(iVar3 + 0x54),*(undefined4 *)(iVar3 + 0x58));
  iVar1 = *(int *)(iVar2 + 0xc + DAT_0067ee20);
  iVar3 = DAT_006a5c38 + iVar1 + iVar1 * 0xa8;
  fVar4 = (float10)FUN_00494b70(*(undefined4 *)(iVar3 + 0x50),
                                *(undefined4 *)(DAT_006a5c38 + iVar1 + 0x58 + iVar1 * 0xa8));
  if ((*(int *)(*(int *)(iVar2 + 0x24 + DAT_0067ee20) * 0x50 + 4 + DAT_00680ae0) == 0x32) &&
     ((float10)*(float *)(iVar3 + 0x54) - fVar4 < (float10)1.5)) {
    local_8 = 0;
    FUN_0048da90();
    FUN_0048dce0(param_1,1);
    ExceptionList = local_10;
    return;
  }
  ExceptionList = local_10;
  return;
}

