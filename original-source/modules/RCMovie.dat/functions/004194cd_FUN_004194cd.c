/*
 * FUN_004194cd at 004194cd
 * undefined __cdecl FUN_004194cd(int * param_1, int * param_2)
 * Address ranges: 004194cd-004195c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004194cd(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  undefined1 local_70 [104];
  int local_8;
  
  FUN_0041fe16(local_70,(byte *)s___99s_00435f9c);
  if (*(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + 0x180) + 4) < 1) {
    local_8 = *param_1 + 1;
  }
  else {
    local_8 = ((*param_1 + 1) * *(int *)(DAT_0043db88 + 0x80)) /
              *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + 0x180) + 4);
  }
  if (0x65 < local_8) {
    local_8 = 100;
  }
  local_70[local_8] = 0;
  if (param_1[0x13] == 0) {
    FUN_00415dd1(param_1[5]);
    FUN_00415e01(param_1[4]);
  }
  else {
    FUN_00415dd1(param_1[7]);
    FUN_00415e01(param_1[6]);
  }
  pbVar4 = &DAT_00435fa4;
  iVar2 = param_2[1] + param_1[0xc] * param_1[0x11];
  iVar3 = *param_2;
  iVar1 = FUN_00412061();
  FUN_0041635e(iVar1,iVar3,iVar2,pbVar4);
  return;
}

