/*
 * FUN_0040f310 at 0040f310
 * undefined4 __stdcall FUN_0040f310(undefined4 * param_1, uint * param_2, uint * param_3)
 * Address ranges: 0040f310-0040f522
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040f310(undefined4 *param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint local_48 [16];
  char *local_8;
  
  iVar1 = FUN_0040f241();
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else {
    _strncpy((char *)local_48,(char *)param_3,0x3f);
    FUN_00427e4d(local_48);
    FUN_004015a6((byte *)s__s___s_00432fac);
    FUN_0041f7a0((uint *)(DAT_0043d7c8 + 0x10 + iVar1 * 0xd8),param_2);
    FUN_0041f7a0((uint *)(DAT_0043d7c8 + 0x74 + iVar1 * 0xd8),param_3);
    puVar3 = FUN_0041fb70(local_48,&DAT_00432fb4);
    if (puVar3 != (uint *)0x0) {
      FUN_004015a6((byte *)s_3dfx_driver_found__d_00432fbc);
      DAT_00432bfc = iVar1;
    }
    iVar4 = FUN_00427da0((byte *)param_3,s_DD3Dfx_00432fd4,(void *)0x6);
    if (iVar4 == 0) {
      FUN_004015a6((byte *)s_dd3ddfx_driver_found__d_00432fdc);
      DAT_00432bfc = iVar1;
    }
    iVar4 = FUN_00427da0((byte *)param_3,&DAT_00432ff8,(void *)0x3);
    if (iVar4 == 0) {
      FUN_004015a6((byte *)s_Righteous_dd3ddfx_driver_found___00432ffc);
      DAT_00432bfc = iVar1;
    }
    iVar4 = FUN_00427da0((byte *)param_3,s_mnstr2_00433020,(void *)0x6);
    if (iVar4 == 0) {
      FUN_004015a6((byte *)s_Monster_2_driver_found__d_00433028);
      DAT_00432bfc = iVar1;
    }
    iVar4 = FUN_00427da0((byte *)param_3,s_display_00433044,(void *)0x6);
    if (iVar4 != 0) {
      iVar4 = __strcmpi((char *)param_3,&DAT_0043304c);
      if (iVar4 == 0) {
        FUN_004015a6((byte *)s_secondary_driver_found__d_00433054);
        DAT_00432bf8 = iVar1;
      }
    }
    local_8 = _strrchr((char *)param_3,0x2e);
    if (local_8 != (char *)0x0) {
      iVar4 = __strcmpi((char *)param_3,&DAT_00433070);
      if (iVar4 == 0) {
        FUN_004015a6((byte *)s_secondary_driver_found__d_00433078);
        DAT_00432bf8 = iVar1;
      }
    }
    if (param_1 != (undefined4 *)0x0) {
      puVar5 = (undefined4 *)(DAT_0043d7c8 + iVar1 * 0xd8);
      *puVar5 = *param_1;
      puVar5[1] = param_1[1];
      puVar5[2] = param_1[2];
      puVar5[3] = param_1[3];
    }
    uVar2 = 1;
  }
  return uVar2;
}

