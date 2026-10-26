/*
 * FUN_00405cfe at 00405cfe
 * undefined4 __stdcall FUN_00405cfe(undefined4 * param_1, uint * param_2, uint * param_3)
 * Address ranges: 00405cfe-00405e1c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00405cfe(undefined4 *param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *_Str1;
  undefined4 *puVar4;
  
  iVar1 = FUN_00405cd3();
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else {
    FUN_004015a6((byte *)s__s___s_0042f1cc);
    FUN_0041f7a0((uint *)(DAT_0043d41c + 0x10 + iVar1 * 0xd8),param_2);
    FUN_0041f7a0((uint *)(DAT_0043d41c + 0x74 + iVar1 * 0xd8),param_3);
    iVar3 = __strcmpi((char *)param_3,s_SB16_VXD_0042f1d4);
    if (iVar3 == 0) {
      FUN_004015a6((byte *)s_sb16_driver_found__d_0042f1e0);
      DAT_0042ef70 = iVar1;
    }
    _Str1 = _strrchr((char *)param_3,0x2e);
    if (_Str1 != (char *)0x0) {
      iVar3 = __strcmpi(_Str1,&DAT_0042f1f8);
      if (iVar3 == 0) {
        FUN_004015a6((byte *)s_secondary_driver_found__d_0042f200);
        DAT_0042ef74 = iVar1;
      }
    }
    if (param_1 != (undefined4 *)0x0) {
      puVar4 = (undefined4 *)(DAT_0043d41c + iVar1 * 0xd8);
      *puVar4 = *param_1;
      puVar4[1] = param_1[1];
      puVar4[2] = param_1[2];
      puVar4[3] = param_1[3];
    }
    uVar2 = 1;
  }
  return uVar2;
}

